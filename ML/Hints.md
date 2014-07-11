
It's natural to want to compute the **full posterior** over the parameters, p(w|D). This can be useful for any suituation where we want to associate **confidence intervals** with our predictions.

# implementation hints
* sigmoid function
  // to prevent e^x overflow, nice!
  if (x < 0) return e^x/(1+e^x)
  else return 1/(1+e^(-x))
  
