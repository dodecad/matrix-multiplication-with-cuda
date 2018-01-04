#ifndef MMULT_H
#define MMULT_H

#define BLOCK_SIZE 16

// Matrix multiplication function
// c = a * b
// a: m x n
// b: n x k
// c: m x k
void mmult(int m, int n, int k, const float * a, const float * b, float * c);

#endif
