# Feature Engineering
* text data has distinguish characteristic
* featuring by words is high dimension, and many of the features are related.
  The same thought can be expressed using many different terms or one term can have very different meanings.
  synonymy & polysemy
* sparse
## Feature Selection
* with respect to supervised learning like text categoriaztion, supervision is availble for the feature selection process.
## Feature Transformation
* LSI with SVD
  SVD produces the rank-K matrix X' that minimizes the distance from X in terms of the spectral norm and the Frobenius norm. Although X is typcially sparse, X' is generally not sparse. Thus, **X' can be viewed as a smoothed version of X**, obtained by propagting the co-occurring terms in the document corpus.
** updating LSI model
	<<On updating problems in latent semantic indexing>>
* PLSA
* NMF

# Text Clustering
## agglomerative clustering
## partitionning algorithm
## standard parametric modeling based methods such as EM-algorithm
## sth
* In non-probabilistic clustering methods, the memebership of documents to clusters is **deterministic** in nature.


# LDA
* A word's ambiguity is resolved by its latent topic, which is inferred from
  doc-wide.
* what LDA differs to PLSI is the doc-topic distribution is not a parameter, but
  a value generated from prior. So, does the learning algorithm learn the
  doc-topic distribtion for each doc?
* This generative process defines a joint probability distribution over both the observed and hidden random variables
* **LDA is sensitive to noise**, which means the head/foot will influence the
  learned topices. Is that means LDA is robust or not?
## inference
LDA only inference the hyper-paramters?
two approaches of inference:
* sampling-based
Instead of directly estimating the topic-word distributions φ and the topic
distributions  θ  for each document, another approach is to directly estimate
the posterior distribution over z (the assignment of word tokens to topics),
given the observed words w, while marginalizing out φ and θ.
* variational

## Infinite Latent Dirichlet Allocation
The **HDP** can be directly applied to produce a **nonparametric LDA** with an
**infinite** number of topics.
Each document j has its own DP(Dirichlet Process)

* Cluster(topics) are **shared** across documents by imposing DP prior on base distritbuion

* what's shared topics? Between different collections?
