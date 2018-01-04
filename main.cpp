#include <cstdlib>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include "mmult.h"

int main()
{
    const int m = BLOCK_SIZE * 12, n = BLOCK_SIZE * 18, k = BLOCK_SIZE * 24;
    float * a, * b, * c, * c_verify;

    a = new float[m * n];
    b = new float[n * k];
    c = new float[m * k];
    c_verify = new float[m * k];

    for (int i = 0; i < m * n; ++i)
        a[i] = float(rand()) / RAND_MAX;

    for (int i = 0; i < n * k; ++i)
        b[i] = float(rand()) / RAND_MAX;

    float sTime;
    clock_t start, finish;
    
    start = clock();
    mmult(m, n, k, a, b, c);
    finish = clock();
    
    sTime = (float)(finish - start) / CLOCKS_PER_SEC;
    printf("Run time on CPU: %lf sec", sTime);

    float difference = 0;

    for (int i = 0; i < m * k; ++i)
        difference += (c[i] - c_verify[i]) * (c[i] - c_verify[i]);

    if (difference < 1e-5f)
        std::cout << "Test passed.\n";
    else
        std::cout << "Test failed (diff = " << difference << ").\n";
    
    delete [] c_verify;
    delete [] c;
    delete [] b;
    delete [] a;
}
