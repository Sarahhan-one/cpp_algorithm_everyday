#include <iostream>
#include <vector>
using namespace std; 

void printArr(int dig, int arr[]) {
    for (int i = 1; i < dig; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n");
}


void dp(int dig, int N, int M, int cnt, bool vis[], int arr[]) {
    if (dig > M) {
        cnt++; 
        printArr(dig, arr);
        return; 
    }

    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        arr[dig] = i + 1; 
        vis[i] = true; 
        dp(dig+1, N, M, cnt, vis, arr); 
        vis[i] = false;
    }
}

int main() {
    int T; 
    cin >> T; 
    vector<pair<int, int>> bridges(T); // <N, M> 
    for (int i = 0; i < T; i++) {
        cin >> bridges[i].first >> bridges[i].second;
    }

    for (auto& bridge : bridges) {
        int N = bridge.first, M = bridge.second;
        bool vis[N] = {false}; 
        int arr[M] = {0};
        int ans = 0; 

        dp(0, N, M, ans, vis, arr); 
        cout << ans;
    }

}

//Not the right appraoch : each positions are not indepedent to each other
// -> combination C(M, N)

// int main() {
//     int T;
//     cin >> T; 
//     vector<pair<int,int>> bridges(T);
//     for (int i = 0; i < T; i++) {
//         cin >> bridges[i].first >> bridges[i].second;
//     }

//     for (auto& bridge : bridges) {
//         if (bridge.first == 1) {
//             cout << bridge.second << endl; 
//             continue;
//         }
//         if (bridge.first == bridge.second) {
//             cout << 1 << endl; 
//             continue;
//         }

//         long long ans = 1; 
//         int addOn = bridge.second % 2 ? 1 : 0;
//         int size = bridge.second;
//         vector<int> cases(size+1);
//         for (int i = 1; i <= (size/2 + addOn); i++) {
//             int j;
//             if (i > bridge.first) {
//                 j = bridge.first;
//             } else {
//                 j = i; 
//             }
//             cases[i] = cases[size - i + 1] = j; 
//         }


//         for (int i = 1; i < cases.size(); i++) {
//             ans *= cases[i];
//             cout <<cases[i] << " ";

//         }

//         cout << ans << endl;
//     }
    
// }