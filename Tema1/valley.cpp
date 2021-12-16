#include <bits/stdc++.h>
using namespace std;

long long int solve(long long int N, long long int last_min_pos,
    vector<long long int> heights) {
    long long int last_max, hours = 0;

    /* Edge cases where the mountain with the minimum height is on the first
     * or last position, where it is needed to excavate the mountain
     * after/before it */
    if (last_min_pos == 0) {
        last_min_pos = 1;
        hours = hours + heights[1] - heights[0];
        heights[1] = heights[0];
    }

    if (last_min_pos == N - 1) {
        hours = hours + heights[N - 2] - heights[N - 1];
        heights[N - 2] = heights[N - 1];
    }

    last_max = heights[0];

    for (int i = 0; i < last_min_pos; ++i) {
        /* If there is a mountain with the minimum height found before the
         * position last_min_pos, then all the mountains between them must have
         * the mininum height */
        if (heights[i] == heights[last_min_pos]) {
            for (int j = i + 1; j < last_min_pos; ++j) {
                hours += heights[j] - heights[last_min_pos];
            }
            break;
        }

        /* Updating hours or last_max, if needed */
        if (heights[i] > last_max) {
            hours = hours + (heights[i] - last_max);
        } else {
            last_max = heights[i];
        }
    }

    last_max = heights[N - 1];

    /* Updating hours or last_max, if needed */
    for (int i = N - 1; i > last_min_pos; --i) {
        if (heights[i] > last_max) {
            hours = hours + (heights[i] - last_max);
        } else {
            last_max = heights[i];
        }
    }

    return hours;
}

int main() {
    /* Declaring variables and opening input and output files */
    vector<long long int> heights;
    long long int last_min_pos = 0, last_max, valley, N, hours = 0;
    ifstream input("valley.in");
    ofstream output("valley.out");

    /* Reading th variables from input and initializing the vector */
    input >> N;

    for (int i = 0; i < N; ++i) {
        input >> valley;
        heights.push_back(valley);
        if (valley <= heights[last_min_pos]) {
            last_min_pos = i;
        }
    }

    input.close();

    output << solve(N, last_min_pos, heights) << endl;

    output.close();

    return 0;
}
