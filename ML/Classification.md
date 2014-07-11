# Naive Bayes
* use **log-odds** to erase X term in the formula

# Decision Tree
Decision tree assume that out decision boundaries are **parallel to the axes**.
* One could still try to use a decision tree on text data(high dimensional) by doing Feature
  selection
* Decision Trees are likely to be a better fit for problems where you have a
  **small number of features** (say < 100 features) and **plenty (say > 100,000) train
  examples**. In such a case, your data permits you to learn more complex decision
  rules. Here variance is a smaller concern and one would likely be better off
  opting for Decision Trees with their high expressive power and low **bias**.
  

[R](http://www.quora.com/Data-Mining/What-are-the-advantages-of-logistic-regression-over-decision-trees)


# Logistic Regression
* Naive Bayes fits feature weights independently while logistic regression accounts for **correlations** among features (how?)
* A Chi-square test is really a descriptive  test, akin to a correlation
* Logistic regression use likelihodd on an odds scale: log-odd (logit function) (So, a log-linear model?)
	* the logit function is used to transform a probabilistic, constrained to fall within the interval (0, 1), into a real number ranging over (-∞, +∞). The inverse function of the logit is *sigmoid* or *logistic* function .
	* logistic regression is a *generalized linear model* where the link function is the logit funciton. 
* The logistic model says that the log-odds follows a linear model; S-shape.
* lbfgs
* Logistic regression estimation obeys the maximum entropy principle
* Binary logistic regression is equivalent to a one-layer, single-output neural network with a logistic activation function trained under log loss. This is sometimes called classification with a single neuron.

## why use odds ratios (why no always use probability)
* odds ratio represents the **constant effect** of a predictor X, on the likelihood that one outcome will occur. Since we often want a **measure of the unqiue effect of each X on Y**
* 
## relate to Linear Discriminant analysis

## Multinomial Logistic Regression

## Max-Ent?

## others
*  Linear Classifier works better in high dimension which have better
   hyperplane, liblinear;
   (TODO while in low-dimension, svm will work better?  Especially when features
   are not independent, polynomial kernel works better ?)
* Logistic regression is intrinsically simple, it has low variance and so is
  less prone to over-fitting. Decision trees can be scaled up to be very
  complex, are are more liable to over-fit. Pruning is applied to avoid this.
  

# SVM
* Most simple SVMs have a linear kernel, but in practice **non-linear kernels** were moe robust
* SVMs are based on concept of Lagrange multipliers (optimization under constraint). They are not only performing a **gradient descent**(while logistic regression do, which is straightforward to program and test), but they also enforce a separation of the variables from different classes, despite them being extremely close one to another.
* In the SVM, you pay a **hinge loss** for misclassifying points, and in
  logistic regression you pay a **log-loss**.
* SVM use sparse model
