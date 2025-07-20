// C++ Program to find the nth tribonacci number

#include <bits/stdc++.h>
using namespace std;

// Function to multiply two 3x3 matrices
void multiply(vector<vector<long long> >& A,
              vector<vector<long long> >& B)
{
    // Matrix to store the result
    vector<vector<long long> > C(3, vector<long long>(3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                C[i][j]
                    = (C[i][j] + ((A[i][k]) * (B[k][j])));
            }
        }
    }

    // Copy the result back to the first matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A[i][j] = C[i][j];
        }
    }
}

// Function to calculate (Matrix M) ^ expo
vector<vector<long long> >
power(vector<vector<long long> > M, int expo)
{
    // Initialize result with identity matrix
    vector<vector<long long> > ans
        = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };

    // Fast Exponentiation
    while (expo) {
        if (expo & 1)
            multiply(ans, M);
        multiply(M, M);
        expo >>= 1;
    }

    return ans;
}

// function to return the Nth tribonacci number
long long tribonacci(int n)
{

    // base condition
    if (n == 0 || n == 1)
        return n;

    // Matrix M to generate the next tribonacci number
    vector<vector<long long> > M
        = { { 1, 1, 1 }, { 1, 0, 0 }, { 0, 1, 0 } };

    // Since first 3 number of tribonacci series are:
    // trib(0) = 0
    // trib(1) = 1
    // trib(2) = 1
    // F = {{trib(2), 0, 0}, {trib(1), 0, 0}, {trib(0), 0,
    // 0}}
    vector<vector<long long> > F
        = { { 1, 0, 0 }, { 1, 0, 0 }, { 0, 0, 0 } };

    vector<vector<long long> > res = power(M, n - 2);
    multiply(res, F);

    return res[0][0];
}

int main()
{

    // Sample Input
    int n = 4;
    // Function call
    cout << tribonacci(n);

    return 0;
}