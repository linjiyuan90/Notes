## MCMC
* Inference the posterior which is hard to inference directly constructing a markov chain

# Gibbs Sampling
* no accept rate, transition with probability 1
* why the equilibrium distribution is exactly the desired distribution? why not other distribution?
Since the transition probability is constructed from the true structure of the problem?
* With label data, just don't sample for them, keep they as "ground truth".
* The strategy of integrating out some of the parameters for model inference is often refered to as "collapsed"
## procedure
* Define the joint distribution of all variables(observed, unobservered), parameterized by hyperparameters.
* simplify the expression for the joint distribution (marginalizing/integrating out some variables! Some can't be integerated since the probability formula needs it, mainly because of dependency.)
* define how to sample from the conditional distribution

## issue
* what if sampling not changing the counts?
* what to store for each samples? Desired label, assignments. It's necessary to store some parameters which can be estimated later from data assignments.
* variables from same distritbution(with same parameters) should be sampled together with same parameters, and then integrate out the parameters. Sampling separately won't work for this variables.
