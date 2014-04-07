
# distribution
* Binomial distirbution & Bernoulli Model
  ```
  Ber(theta)  // for counts?
  Bin(k|n, theta)  // for sequence?
  ```

* gamma distribution
gamma function Γ(x+1) = xΓ(x)
Avoid to calculate gamma directly, because it's slow.

* [Beta distribution](http://www.math.uah.edu/stat/special/Beta.html)
Defined in **[0, 1]** with two shape parameters. It's *conjugate prior* for *Bernoulli*, *binomial*, *geometric*.
B(a, b) is the *Beta function*.
It's a special case of **Dirichlet Distribution** in which case the simplex is
the unit interval (0, 1).

* Dirichlet Distribution
  * combing entries of probability vectors preserves Dirichlet property(so can be
    marginalized out?) The converse is also true.
  * To sample from a Dirichlet Distribution, Dir(α1 , . . . , αk), one fast way
    is to draw K independent samples y1, ... yk from gamma distributions, each
    with density: Gamma(αi) = yi^(αi-1)e^-yi/Γ(αi), then set ai = yi/∑y

# sth
* when the prior and the posterior have the same form, we say that the prior is a **conjugate prior** for the corresponding likelihood
* The parameters of the prior are called **hyper-parameters**

* MAP is MAP estimate for parameter/hypothesis, not for prediction, with respect to MLE estimate.

# Bayesian
## MAP estimate (Most probable a posteriori, posterior mode), P(𝜭|D)
* Others like **posterior mean, median** is the most appropriate choice for a real-valued quantity, and the vector of posterior marginals is the best choice for a discrete quantity. However, the **posterior mode**, aka the **MAP estimate**, is the most popular choice beacause it reduces to an **optimiztion probem**.
* Futhermore, **MAP estimation** can be interpreted in non-Baysesian terms, by thinking the log prior as a regularizer.
* For a "flat prior", the MAP estimation is equal to MLE estimation
### drawback
* no measure of uncertainty
Indeed of any other **point estimate** such as the **posterior mean or median**, does not provide any measure of uncertainty. (We can derive such confidence measures from the posterior.)
* plugging the MAP estimate can result in overfitting
Because MAP estimate don't model the **uncertainty** in parameters.
* the mode is an untypical point
* MAP estimation is not invariant to reparameterization *

## full posterior p(theta|D)
## posterior predictive density p(x|D)

## Baysian credible intervals & Frequentist confidence interval
Credible intervals are usually what people want to compute, but confidence intervals are usually what they actually compute. 

## likelihood
* **marginal likelihood(evidence)**, that's integrating all possible paramter values. While likelihood only consider one specific parameter. **Evidence** is used for bayesian model selection!
When discussing parameter inference p(theat|D, m) for a fixed model, evidence p(D|m) is ignored since it's constant for m. However, when comparing models, we need to know how to compute the marginal likelihood, p(D|m). 
In general, computing the maginal likelihood can be quite diffcult, one simple but popular approximitation is known as the **Bayesian information criterion** or **BIC**.
The **BIC** method is very closely related to the **minimum description length** or **MDL** principle,  which characterizes the score for a model in terms of how well it fits the data, minus how complex the mode is to define.
**AIC**, or **Akaike information critertion** is very similar to BIC/MDL, but with less penalty. This cause AIC to pick more complex models. However, this can result in better predictive accuracy.


# Probability
* Probability measure is a function from subsets of space X to [0, 1],
  satisfying certain properties.
