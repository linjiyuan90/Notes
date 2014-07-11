
# Hierarchical Bayesian Modeling
* enable the borrowing of statistical strength for small data size.
* model with common prior


# sth

LDA's main advantage over the PLSI method is that it's not quite as susceptible to overfitting.  This is generally true of Baysian methods which reducees the number of model parameters to be estimated, and therefore work much better for smaller data sets.

But if prior distribution is not well-chosen, the preformance is quite bad. 


# Bayesian vs. Frequentist
As we gather an infinite amount of evidence, say as N→∞, our Bayesian results (often) align with frequentist results.
## fitting
* Bayesian approach does not overfit (if done properly)
* Since Bayesian approaches do not overfit, there is (theoretically) no reason
  to use samll models anymore.


# Nonparametric
* Mostly suitable to when dimention of parameters is **unbounded**, not for fixed
  but unknown! The latter should use a prior on the number of the parameters!
* By integrating out parameters, Bayesian models do not suffer from overfitting,
  thus it is conceivable to consider models with infinite numbers of parameters,
  aka Bayesian nonparametric models. (Not infinite numbers of models, each has
  its specific number of parameters)
  http://videolectures.net/mlss07_teh_dp/
* let the data speak for themselves
* broad class of priors that aloows data to "speak for itself"
* side-step model selection adn averaging
## how do we deal with very large parameter spaces
* marginalize out all but a finite number of paramters
* define infinite space implicity (akin to the kernel trick) using either
Kolmogorov Consistency Theorem or de Finetti's Theorem
## process
### Dirichlet Process
A Dirichlet process(DP) is an "infinitely decimated" Dirichlet
distribution. Each decimation step involves drawing from a Beta distribution(a
Dirichlet with 2 components) and multiplying into the relevant entry.
* Dirichlet process is a stochastic process, meaning that technically speaking
  it is an infinite sequence of random variables, rather than a single random
  distribution
* DP can be thought of as inifinite dimentional Dirichlet Distributions
* A Dirichlet Process is a distribution over probability measures such that
  marginals on finite partitions are Dirichlet distributed.
* used for
 * density estimation
 * semiparametric modeling
 * sidestepping model selection/averaging
* Posterior Dirichlet Process
* atom
* EM is generaly used for inference in a mixture model, but G is nonparametric,
making EM diffcult
#### Dirichlet Process Mixture Model
[Neal][2] describes a finite mixture models with K components while letting K goes to
infinity to view the DP mixture model.
### Guassian Process
  for function estimation (regression, classification)
### Chinese Restaurant Process
* A different perspective on the Dirichlet process
* It's a distribution over partitions
* CRP exhibits the clustering propertity of the DP
### Pitman-Yor Process
	* intend to create more new tables, suitable for text scenario.
### Stick-breaking Construction
###	Indian  Buffet Process
###	Beta Process
### Hierarchy Dirichlet Process
Each group's proportions π are sampled from global proportions β.

Cowans(2004, 2006) has shown that the HDP provides statistical justification for
the intuition behind tf-idf.
<Information retrieval using hierarchical Dirichlet processes>
<Probabilistic Document Modelling>

## Distance Dependent Chinese Restaurant Processes
A flexible class of distributions over **partitions** that allows for **dependencies**
betweent the elements.
Including dependencies arising from time, space and network connectivity.


### sth
think G as a prior process, H as likelihood?
Then estimate posterior process G.
* a stochastic process is a collection of random varaibles from sam measure space.

## consistency


# Reference
1. [Bayesian nonparametrics in document and language modeling](http://www.youtube.com/watch?v=FO0fgVS9OmE)
[2]: Markov Chain Sampling Methods for Dirichlet Process Mixture Models
