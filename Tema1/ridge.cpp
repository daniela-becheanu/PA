#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Declaring variables and opening input and output files */
    vector<pair<long long int, long long int>> mountains;
    long long int height, price = 0, N;
    ifstream input("ridge.in");
    ofstream output("ridge.out");

    /* Reading th variables from input and initializing the vector */
    input >> N;
    vector< vector<long long int>> dp(N, vector<long long int>(3));

    for (int i = 0; i < N; ++i) {
        input >> height >> price;
        mountains.push_back(make_pair(height, price));
    }

    input.close();

    /* Base case */
    for (int i = 0; i < 3; ++i) {
        dp[0][i] = i * mountains[0].second;
    }

    for (int i = 1; i < N; ++i) {
        switch (mountains[i - 1].first - mountains[i].first) {
            case 2:
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2])
                    + mountains[i].second;
                dp[i][2] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2])
                    + mountains[i].second * 2;
                break;

            case 1:
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][2]);
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1])
                    + mountains[i].second;
                dp[i][2] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2])
                    + mountains[i].second * 2;
                break;

            case 0:
                dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][2])
                    + mountains[i].second;
                dp[i][2] = min(dp[i - 1][0], dp[i - 1][1])
                    + mountains[i].second * 2;
                break;

            case -1:
                dp[i][0] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][2])
                    + mountains[i].second;
                dp[i][2] = min(dp[i - 1][0], dp[i - 1][2])
                    + mountains[i].second * 2;
                break;

            case -2:
                dp[i][0] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
                dp[i][1] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2])
                    + mountains[i].second;
                dp[i][2] = min(dp[i - 1][1], dp[i - 1][2])
                    + mountains[i].second * 2;
                break;

            default:
                dp[i][0] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
                dp[i][1] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2])
                    + mountains[i].second;
                dp[i][2] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2])
                    + mountains[i].second * 2;
        }
        /* Making sure not to have mountains with negative heights */
        switch (mountains[i].first) {
            case 0:
                dp[i][1] = LONG_LONG_MAX;
                dp[i][2] = LONG_LONG_MAX;
                break;
            case 1:
                dp[i][2] = LONG_LONG_MAX;
        }
    }

    output << min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);

    output.close();

    return 0;
}
