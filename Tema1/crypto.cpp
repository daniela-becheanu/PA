#include <bits/stdc++.h>
using namespace std;

/* Compare function used to sort by the first element of a pair (the power) */
bool power_comparator(pair<int, int>& e1, pair<int, int>& e2) {
    return (e1.first < e2.first);
}

int solve(vector<pair<int, int>> computers, int N, int B) {
    int add, sum = 0, min_power = computers[0].first;
    for (int i = 0; i < N - 1; ++i) {
        // Updating the sum of the upgrade costs for the first i + 1
        // computers
        sum += computers[i].second;
        if (computers[i].first < computers[i + 1].first) {
            if (B / sum == 0) {
                break;
            }

            /* Choosing how much it is possible to add */
            add = min((int) B / sum, computers[i + 1].first
                - computers[i].first);

            /* Updating the amount of money (B) and the minimum power */
            B -= sum * add;
            min_power += add;
        }
    }
    sum += computers[N - 1].second;
    add = (int) B / sum;
    min_power += add;
    return min_power;
}

int main() {
    /* Declaring variables and opening input and output files */
    vector<pair<int, int>> computers;  // contains a (power, upgrade) of each
                                       // computer
    long long int N, B, power, upgrade;
    ifstream input("crypto.in");
    ofstream output("crypto.out");

    /* Reading th variables from input and initializing the vector */
    input >> N;
    input >> B;

    for (int i = 0; i < N; ++i) {
        input >> power >> upgrade;
        computers.push_back(make_pair(power, upgrade));
    }

    input.close();

    /* Sorting the computers by their computing power */
    sort(computers.begin(), computers.end(), power_comparator);

    output << solve(computers, N, B);

    output.close();

    return 0;
}
