/*  AASHISH
 *  JAIN
 *  ajain28
 */

#ifndef A3_HPP
#define A3_HPP

/* Added */
#include <cuda_runtime_api.h>
#include <iostream>
#include <math.h>

#define PI 3.141592653589
#define BLOCK_SIZE 1024

__device__ float K(float val){
    return expf(-val*val/2)/sqrtf(2*PI);
}

__global__ void compute_gaussian_kde(int n, float h, float *x, float *y)
{
    int gidx = threadIdx.x + blockIdx.x * BLOCK_SIZE;
    float x_val = x[gidx], sum=0;
    __syncthreads();
    if (gidx < n){
        for (int i = 0; i < n; i++)
            sum += K((x_val - x[i])/h);
        y[gidx] = sum/(n*h);
    }
}



void gaussian_kde(int n, float h, const std::vector<float>& x, std::vector<float>& y) {
    float *input, *output;

    long size = x.size() * sizeof(float);
    long block_num = (n + BLOCK_SIZE - 1) / BLOCK_SIZE;

    cudaMalloc((void **)&input, size);
    cudaMalloc((void **)&output, size);

    cudaMemcpy(input, x.data(), size, cudaMemcpyHostToDevice);

    std::cout << BLOCK_SIZE << ' ' << block_num << std::endl;
    for (int i = 0; i < x.size(); i++)
         std::cout << x[i] << ' ';
     std::cout << std::endl
               << "Done" << std::endl;

    /*Call kernel here*/
    compute_gaussian_kde<<<block_num, BLOCK_SIZE>>>(n, h, input, output);

    /*Retrieve the values*/
    cudaMemcpy(y.data(), output, size, cudaMemcpyDeviceToHost);

    for (int i = 0; i < y.size(); i++)
         std::cout << y[i] << ' ';
     std::cout << std::endl;

    //Check
    int flag=true;
    for (int i = 0; i < n; i++)
    {
        float sum = 0, val;
        for (int j = 0; j < n; j++)
        {
            val = (x[i] - x[j]) / h;
            sum += exp(-val * val / 2) / sqrt(2 * PI);
        }
        float z=sum / (n * h);
        if(y[i] - z > 0.0001){
            std::cout<<"Expected "<<y[i]<<" Got "<<z<<std::endl;
            flag = false;
            break;
        }
    }
    if(!flag){
        std::cout<<"Problem detected\n";
    }
    else
        std::cout<<"Passed\n";

    /*Clean up memory */
    cudaFree(input);
    cudaFree(output);
} // gaussian_kde


#endif // A3_HPP
