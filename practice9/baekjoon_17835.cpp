#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<pair<int, int>>> adj(N+1); // u | {v, cost}... 
    for (int i = 0; i < M; i++) {
        int city1, city2, distBetween;
        cin >> city1 >> city2 >> distBetween;

        adj[city2].push_back({city1, distBetween});
    }

    vector<int> interviewPlaces;
    for(int i = 0; i < K; i++) {
        int place;
        cin >> place;
        interviewPlaces.push_back(place);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // cost, u
    vector<int> dist(N+1, INT_MAX);

    for (auto place : interviewPlaces) {
        dist[place] = 0;
        pq.push({0, place});
    }

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (dist[u] < cost) continue;

        for (auto [v, weight] : adj[u]) {
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    int ans_i = -1;
    int max_dist = -1;
    for (int i = N; i > 0; i--) {
        if (dist[i] == INT_MAX) continue;
        if (max_dist >= dist[i]) { ans_i = i; max_dist = dist[i]; }
    }
    cout << ans_i << endl;
    cout << max_dist << endl;

    return 0;
} 