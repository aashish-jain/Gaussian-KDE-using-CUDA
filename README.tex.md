This code is used to estimate the probability density function of a random variable. 

If $X=(x_1,x_2,…,x_n)$ is a vector that is a sample drawn from some univariate distribution with an unknown density function f,  f can be estimated using 

$ \^{f}_h(x)=\frac{1}{nh} \sum_{i=1}^{n} K\frac{(x-x_i)}{h}$

where h is bandwidth, and K is a kernel function defined as

$K(x)=\frac{1}{\sqrt{2\pi}}\exp{-\frac{x^2}{2}}$. So, for a given input vector X and some predefined bandwidth h, we can estimate density over X, as $Y=(y_1,y_2,…,y_n)$, where $y_i=\^{f}_h(x_i)$. 

In this project it is assumed that the input vector X are single precision and X is such that it exceeds capacity of a single CUDA thread block, but is small enough to be processed by a single kernel invocation(e.g. with multiple blocks).
