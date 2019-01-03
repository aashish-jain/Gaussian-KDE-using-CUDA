This code is used to estimate the probability density function of a random variable. 

If <img src="/tex/c371a73a64c8bc918099b2cdee140718.svg?invert_in_darkmode&sanitize=true" align=middle width=145.32900195pt height=24.65753399999998pt/> is a vector that is a sample drawn from some univariate distribution with an unknown density function f,  f can be estimated using 

<img src="/tex/326347a59923f9940326c8c41e469747.svg?invert_in_darkmode&sanitize=true" align=middle width=184.92213629999998pt height=33.20539859999999pt/>

where h is bandwidth, and K is a kernel function defined as

<img src="/tex/0f112e14927d4cc039d09a790ebc8396.svg?invert_in_darkmode&sanitize=true" align=middle width=147.85341449999999pt height=33.45973289999998pt/>. So, for a given input vector X and some predefined bandwidth h, we can estimate density over X, as <img src="/tex/3460173881692fcf1792c5968bca39bd.svg?invert_in_darkmode&sanitize=true" align=middle width=139.61004419999998pt height=24.65753399999998pt/>, where <img src="/tex/1eed8e31acde72ccdc18f378f53049f2.svg?invert_in_darkmode&sanitize=true" align=middle width=81.43843124999998pt height=31.50689519999998pt/>. 

In this project it is assumed that the input vector X are single precision and X is such that it exceeds capacity of a single CUDA thread block, but is small enough to be processed by a single kernel invocation(e.g. with multiple blocks).
