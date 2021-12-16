#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Declare variables */
    int N, M, X, Y, min = 0, x, y, size;
    queue<pair<int, int>> q;
    pair<int, int> front;

    /* Open input and output files */
    ifstream input("poduri.in");
    ofstream output("poduri.out");

    input >> N >> M >> X >> Y;

    vector<vector<char>> m(N, vector<char>(M, '.'));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    /* Matrix correspinding to the input file */
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            input >> m[i][j];
        }
    }

    /* Close the input file */
    input.close();

    /* Inserting the sorce node in order to do a BFS */
    q.push({X - 1, Y - 1});

    while (!q.empty()) {
        size = q.size();

        while (size--) {
            front = q.front();
            x = front.first;
            y = front.second;

            q.pop();

            if (visited[x][y]) {
                continue;
            }

            visited[x][y] = true;

            /* If we get to the side of the matrix and are able to get out of
             * it */
            if (((x == 0 || x == N - 1) && (m[x][y] == 'D' || m[x][y] == 'V'))
                || ((y == 0 || y == M - 1) &&
                (m[x][y] == 'O' || m[x][y] == 'D'))) {
                output << (min + 1);
                output.close();
                return 0;
            }

            /* Insert in tge queue the nighbours of the current node */
            if (m[x][y] == 'V' || m[x][y] == 'D') {
                q.push({x - 1, y});
                q.push({x + 1, y});
            }

            if (m[x][y] == 'O' || m[x][y] == 'D') {
                q.push({x, y - 1});
                q.push({x, y + 1});
            }
        }
        /* Incrementing the level (which is the number of movements needed to
         * be done) */
        min++;
    }

    /* If the minimum number was not found, print -1, then close the output
     * file */
    output << "-1";
    output.close();
    return 0;
}
