#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkHeight(vector<long long>& trees, long long mid, long long setHeight) {
    long long sum = 0;
    for (auto tree : trees) {
        if (tree > mid) sum += tree-mid;
    }

    if (sum >= setHeight) return true;
    else return false;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> trees(N);
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    long long start = 0;
    long long end = *max_element(trees.begin(), trees.end());

    long long ans = 0;
    while (start <= end) {
        long long mid = (start + end)/2;
        // cout << mid << endl;
        if (checkHeight(trees, mid, M)) { start = mid + 1; ans = mid;}
        else { end = mid - 1;}
    }

    cout << ans;

}