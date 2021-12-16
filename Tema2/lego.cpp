#include<bits/stdc++.h>
using namespace std;

/* Function to count the number of consecutive elements equal to 1 */
int consec(vector<int> v, ofstream &output) {
    int max_num = 0, curr_num = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 1) {
            curr_num++;
        } else {
            if (max_num < curr_num) {
                max_num = curr_num;
            }
            curr_num = 0;
        }
    }
    return max(max_num, curr_num);
}

/* Function that generates the all the combinations possible with the elements
 * int the vector v and stores them in the comb matrix */
void comb_generetor(vector<int> v, vector<int> data, int start, int end,
                    int index, int N, vector<vector<int>> &comb) {
    if (index == N) {
        comb.push_back(data);
        return;
    }

    for (int i = start; i <= end; i++) {
        if (N - index - 1 <= end - i) {
            data[index] = v[i];

            if (data[0] != 1) {
                return;
            }

            comb_generetor(v, data, i + 1, end, index + 1, N, comb);
        }
    }
}

int main() {
    /* Declare variables */
    int K, N, T, maxim = 0, curr_max, max_sum;
    vector<int> v;
    vector<vector<int>> comb;

    /* Open input and output files */
    ifstream input("lego.in");
    ofstream output("lego.out");

    input >> K >> N >> T;

    for (int i = 1; i <= K; ++i) {
        v.push_back(i);
    }

    /* Close input file */
    input.close();

    vector<int> data(N), max_comb(N);

    /* Generate the combiantions */
    comb_generetor(v, data, 0, K - 1, 0, N, comb);

    for (auto &v : comb) {
        max_sum = v[N - 1] * T;
        vector<vector<int>> dp(T + 1, vector<int>(max_sum + 1, 0));

        /* Base cases for dynamic programming */
        for (int j = 1; j < T + 1; ++j) {
            for (int k = 0; k < N; ++k) {
                dp[j][v[k] * j] = 1;
            }
        }

        /* Complete the cases for knapsack problem matrix */
        for (int i = 1; i <= T; ++i) {
            for (int j = 1; j <= max_sum; ++j) {
                for (int k = 0; k < N; ++k) {
                    if (dp[i - 1][j] == 1 || (j >= v[k]
                        && dp[i - 1][j - v[k]] == 1)) {
                        dp[i][j] = 1;
                    }
                }
            }
        }

        curr_max = consec(dp[T], output);

        /* Store the maximum number and the correpsonding combination */
        if (maxim < curr_max) {
            maxim = curr_max;
            max_comb = v;
        }
    }

    /* Write output in the output file and close it */
    output << maxim << endl;
    for (int i = 0; i < N; ++i) {
        output << max_comb[i] << " ";
    }
    output << endl;

    /* Close the output file */
    output.close();
}
