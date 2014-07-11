import numpy as np
import random
from collections import defaultdict
import pylab

# http://datasciencelab.wordpress.com/2014/01/15/improved-seeding-for-clustering-with-k-means/

class KMeans():
    def __init__(self, K, X = None, N = 0):
        self.K = K
        if X == None:
            if N == 0:
                raise Exception("X == None, N == 0")
            else:
                self.N = N
                self.X = self.generate(N, K)
        else:
            self.X = X
            self.N = len(X)

    # dim = 2
    def generate(self, N, K):
        centroids_mu = [(np.random.uniform(-1.0, 1.0), np.random.uniform(-1.0, 1.0)) for k in xrange(K)]
        centroids_var = [np.random.uniform(0.05, 0.5) for k in xrange(K)]
        def generate(k):
            return (np.random.normal(centroids_mu[k][0], centroids_var[k]),
                np.random.normal(centroids_mu[k][1], centroids_var[k]))
        n = N / K
        X = [generate(k)
            for i in xrange(n)
            for k in xrange(K)]
        X += [generate(np.random.randInt(K)) for i in xrange(n*K, N)]
        assert len(X) == N
        return np.array(X)

    def init_centroids(self, K, X):
        return np.array(random.sample(X, K))

    def calc_dist(self, centroids, X):
        d = np.array([(np.argmin([np.linalg.norm(x - c) for c in centroids]),
                        np.min([np.linalg.norm(x - c) for c in centroids]))
                    for x in X])
        return (d[:, 0], d[:, 1])
                
    def reevaluate_centers(self, K, assignments, X):
        return np.array([np.average(X[assignments == k], axis = 0)
                for k in range(K)])
    
    def cluster(self, TOLERANCE = 0.1):
        K, X = self.K, self.X
        centroids = self.init_centroids(K, X)
        last_dist_sum = float("inf")
        assignments, dist_cache = self.calc_dist(centroids, X)
        dist_sum = sum(dist_cache)
        while abs(dist_sum - last_dist_sum) > TOLERANCE:
            last_dist_sum = dist_sum
            centroids = self.reevaluate_centers(K, assignments, X)
            assignments, dist_cache = self.calc_dist(centroids, X)
            dist_sum = sum(dist_cache)
        self.centroids = centroids
        self.assignments = assignments

    def plot(self):
        if not hasattr(self, "centroids"):
            self.centroids = self.init_centroids(self.K, self.X)
        pylab.plot(self.centroids[:, 0], self.centroids[:, 1], 'ko')
        if not hasattr(self, "assignments"):
            self.assignments = np.array([0] * len(self.X))
        for k in xrange(self.K):
            pylab.plot(self.X[self.assignments == k, 0], self.X[self.assignments == k, 1], '+')
        pylab.show()


class KMeansPlusPlus(KMeans):
    def init_centroids(self, K, X):
        # instead of random sample
        # choose centroids to be distant from each other
        centroids = [random.sample(X, 1)[0].tolist()]
        for k in xrange(K-1):
            dist = self.calc_dist(centroids, X)[1]
            dist = dist / sum(dist)
            s, p = 0.0, np.random.random()
            for (ix, d) in enumerate(dist):
                s += d
                if s >= p:
                    centroids += [X[ix].tolist()]
                    break
        return np.array(centroids)
