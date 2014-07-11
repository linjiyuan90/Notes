each focus on a small set of data(increase bias but reduce variance)
guarantee different function are not correlated, thus have similar results.



# boostrap
* each data set is expected to have the fraction (1 - 1/e) (≈63.2%) of the
  unique examples of D, the rest beign duplicates.

# bagging(boostrap aggregating)
* also reduce **variance** and helps to avoid overfitting
* generate m new training sets, each of same size, by sampling from D uniformaly
  **with replacement**.

# boosting (iterative improving)
* for reducing **bias**
* reweight data points and hypotheses

# classification tree
* calculuate information gain
* stump
* **unstable** (bagging leads to "improvements for unstable procedures")
* high variance
* only concern ranking of features, not the value the feature

# Random Forest
* each tree in the esamble is build from a sample **drawn with replacement** (i.e., a
boostrap sample) from the training set.
* when spliting a node during the construction of the tree, the split that is
  chosen is no longer the best split among all features. Instead, the split that
  is picked is the best split among a **random subset** of the features.
* As a result of this randomness, the **bias** of the forest usually slightly
  increases(with respect to the bias of a single non-random tree) but, due to
  averaging, its **variance** also decreases, usually more than compensating for
  the increase in bias, hence yielding an overall better model.
## sth
* it's a bagging technique?
* randomness turn out to be useful
* parallel
* model averaging
* consistent problem?
* if too deep, lead to overfitting?
* if the largest gain is sufficient, and the depth is below maximum, the recurse
  for left and right part.
* random to avoid correlation, (decorrelate). Simply re-running the same
  learning algorithm on different subsets of the data can result in highly
  correlated predictors, which limits the amount of **variance reduction** that is possible.

# Gradient Boosting
Each iteration,  move forward the descent gradient direciton (error residual?)

sum of predictors, weighted by step size alpha

Learn the residual error?

start with constant "mean" predictor.

* use a simple regression model to start
* **sequential models** predict the **error residual** of the previous predictions
* Overall prediction given by a weighted sum of the collection

# AdaBoost
* tends not to overfit
* author of AdaBoost develop margin thoery;  margin for boosting is not the same
  as the margin for svm
* AdaBoost seems to maximize the margin, the generated margin is at least  half
  of the maximized one
* optimal AdaBoost, non-optimal AdaBoost (this one converges to the maximize
  margin)
* each weak classifier can learn a **subcategory** (e.g. movie, dramma) of the
  big category(e.g. entertainment)! (think is as "rule of thumb")
* is it parittion the region?
* distribution over examples at time t, at each iteration, only distribution
  change, no the weak classifier's prediction on examples! At each iteration,
  it's jumping around the distribution simplex.
* take adaboost to dynamical systems to analyse the margin property
* adaptive, do not need to know gamma or T a priori
[The Dynamics of AdaBoost]

## theory
* brief 
	* how to choose examples on each round?
	  * concentrate on "hardes" examples 
	  * distribution over examples (subset examples) 
  * how to combine?
* assumption
  * "weak learning assumption" (consistently better than random guess)
* probably approximately correct(PAC) learning model

## Analysis of test error based on margins theory
* test error continues to drop even after training error is zero!. Occam’s razor
  got wrong in this case.

## sth
* if artificially add noise, adaboost will focus on these hardest examples, which
  adaboost doesn't perform well
* the error drops exponentially
* the number of voting reflects confidence
  margin = strength of  vote = (weighted fraction voting correctly) - (weighted
  fraction voting incorrectly)
* same classifer on each round?

# Boosting vs. Bagging

# Analysis
* essemble error upper bound is much better than original error (if each
  component has better than a guess),  if the classifiers are **indenpendent**
* reduce variance?

# Others
* **stochastic gradient boosting**, which combines gradient boosting with
  bootstrap averaging (bagging), **subsampling**
* stagewise additive model, boosting are an example of this.
