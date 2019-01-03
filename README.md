The goal is to estimate the probability density function of a random variable. Let vector X=(x1,x2,…,xn) be a sample drawn from some univariate distribution with an unknown density function f. We can estimate f, as: ^fh(x)=1n⋅hn∑i=1K(x−xih), where h is bandwidth (think smoothing factor), and K is a kernel function. In the specific case of Gaussian kernel density estimate, K is defined as follows: K(x)=1√2πexp(−x22). Given an input vector X=(x1,x2,…,xn), and some predefined bandwidth h, we can estimate density over X, as Y=(y1,y2,…,yn), where yi=^fh(xi). Hence, your task is to compute Y given X and h

. To solve the problem you may assume the following:

    Input vector X

and output vector Y
are single precision.
The size n
of X (and Y

    ) is such that it exceeds capacity of a single CUDA thread block, but is small enough to be processed by a single kernel invocation (e.g. with multiple blocks).


