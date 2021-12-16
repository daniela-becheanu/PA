#include <bits/stdc++.h>
using namespace std;

class stock {
 public:
    int curr_val;
    int min_val;
    int max_val;
};

int main() {
    /* Declaring variables and opening input and output files */
    int N, B, L;
    ifstream input("stocks.in");
    ofstream output("stocks.out");
    vector<stock> stocks;
    stock st;

    /* Reading th variables from input and initializing the vector */
    input >> N >> B >> L;

    vector<vector<vector<int>>> dp(N + 1,
        vector<vector<int>>(B + 1, vector<int>(L + 1, 0)));

    for (int i = 0; i < N; ++i) {
        input >> st.curr_val >> st.min_val >> st.max_val;
        stocks.push_back(st);
    }

    input.close();

    for (int i = 1; i < N + 1; ++i) {
        for (int j = 1; j < B + 1; ++j) {
            for (int k = 1; k < L + 1; ++k) {
                if (j < stocks[i - 1].curr_val
                    || k < stocks[i - 1].curr_val - stocks[i - 1].min_val) {
                    dp[i][j][k] = dp[i - 1][j][k];
                } else {
                    dp[i][j][k] = max(dp[i - 1][j - stocks[i - 1].curr_val]
                        [k + stocks[i - 1].min_val - stocks[i - 1].curr_val]
                        - stocks[i - 1].curr_val + stocks[i - 1].max_val,
                        dp[i - 1][j][k]);
                }
            }
        }
    }

    output << dp[N][B][L];

    output.close();

    return 0;
}
