# Sampling
* Simple MC(Monte Carlo) like `rejection sampling` and `importance sampling` do not work well in high dimensional spaces.

## Gibbs Sampling
* Label switching
  * paramters of the model and the indicator function are unidentifiable
  * instead of asking for the probability that data point i belongs to cluster k, ask for the probability that data points i and j belong to the same cluster.
  
### Collapsed Gibbs Sampling
* Rao-Blackwellisation theorem guarantees that the variance of the estimate created by analytically integrating out theta will always be lower (or rather, will never be higher) than the variance of a direct MC estimate. **Integrate out theta**.
### Blocked Gibbs Sampling



