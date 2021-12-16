#include <bits/stdc++.h>
using namespace std;

#define KMAX 4
#define MOD 1000000007

void multiply_matrix(unsigned long long A[KMAX][KMAX],
    unsigned long long B[KMAX][KMAX], unsigned long long C[KMAX][KMAX]) {
    unsigned long long tmp[KMAX][KMAX];

    for (unsigned long long i = 0; i < KMAX; ++i) {
        for (unsigned long long j = 0; j < KMAX; ++j) {
            unsigned long long sum = 0;

            for (unsigned long long k = 0; k < KMAX; ++k) {
                sum += (1LL * (A[i][k] % MOD) * (B[k][j] % MOD)) % MOD;
            }

            tmp[i][j] = sum % MOD;
        }
    }

    memcpy(C, tmp, sizeof(tmp));
}

void power_matrix(unsigned long long C[KMAX][KMAX], unsigned long long p,
    unsigned long long R[KMAX][KMAX]) {
    unsigned long long tmp[KMAX][KMAX];
    for (unsigned long long i = 0; i < KMAX; ++i) {
        for (unsigned long long j = 0; j < KMAX; ++j) {
            tmp[i][j] = (i == j) ? 1 : 0;
        }
    }

    while (p != 1) {
        if  (p % 2 == 1) {
            multiply_matrix(tmp, C, tmp);
            --p;
        } else {
            multiply_matrix(C, C, C);
            p /= 2;
        }
    }

    multiply_matrix(C, tmp, R);
}

unsigned long long solve(unsigned long long N) {
    /* Base cases */
    if (N <= 1) {
        return N;
    }

    if (N == 2) {
        return 3;
    }

    /* C = matrix of constant coefficients */
    unsigned long long C[KMAX][KMAX] = {{1, 0, 1, 1},
                                        {1, 0, 0, 0},
                                        {0, 1, 0, 0},
                                        {0, 0, 0, 1}};

    power_matrix(C, N - 2, C);

    /* The solution is on the first column */
    unsigned long long sol = (((3 * C[0][0]) % MOD) + ((1 * C[0][1]) % MOD)
        + ((0 * C[0][2]) % MOD)  + ((3 * C[0][3]) % MOD)) % MOD;

    return sol % MOD;
}

int main() {
    /* Declaring variables and opening input and output files */
    unsigned long long N;
    ifstream input("trigigel.in");
    ofstream output("trigigel.out");

    input >> N;

    input.close();

    output << solve(N) << endl;

    output.close();

    return 0;
}
