#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<string> result(T, "NO");

    for (int t = 0; t < T; t++) {
        int N, M, W;
        cin >> N >> M >> W;

        vector<vector<int>> graph(N + 1, vector<int>(N + 1, INT_MAX / 2));
        for (int i = 1; i <= N; i++) {
            graph[i][i] = 0;
        }

        for (int i = 0; i < M; i++) {
            int s, e, cost;
            cin >> s >> e >> cost;
            graph[s][e] = min(graph[s][e], cost);
            graph[e][s] = min(graph[e][s], cost);
        }

        for (int i = 0; i < W; i++) {
            int s, e, cost;
            cin >> s >> e >> cost;
            graph[s][e] = min(graph[s][e], -cost);
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            if (graph[i][i] < 0) {
                result[t] = "YES";
                break;
            }
        }
    }

    for (const string &res : result) {
        cout << res << "\n";
    }

    return 0;
}