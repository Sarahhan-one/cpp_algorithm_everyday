#include <iostream>
#include <vector>
#include <numeric>
using namespace std; 

int N, K; 
vector<int> bagWeight;
vector<int> bagValue;
vector<vector<int>> list; 
int ans = 0;

void print(vector<int> vis) {
    for (auto& v : vis) {
        cout << v << " ";
    }
    cout << "\n";
}

void dfs(int digit, vector<int>& vis) {
    if (digit == N) {
        int totalWeight = inner_product(vis.begin(), vis.end(), bagWeight.begin(), 0);
        if (totalWeight <= K) {
            int totalValue = inner_product(vis.begin(), vis.end(), bagValue.begin(), 0);
            ans = max(ans, totalValue); 
        }
        return; 
    }

    vis[digit] = 0;
    dfs(digit+1, vis);

    vis[digit] = 1;
    dfs(digit+1, vis);
}

//using dfs, creates bitmaps
//leave the bitmaps that their dot product of bagWeight are under K
//dot product the vis with bagValue, keep the highest one in ans
int main() {
    cin >> N >> K; 
    bagWeight.resize(N);
    bagValue.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> bagWeight[i] >> bagValue[i]; 
    }

    vector<int> vis(N, 0);
    dfs(0, vis);

    cout << ans;
}