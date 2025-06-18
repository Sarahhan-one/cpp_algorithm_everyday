#include <iostream>
#include <vector>
using namespace std; 

//count the 1s that close to 0
int main() {
    int num; 
    cin >> num; 
    vector<vector<int>> canvas(100, vector<int> (100, 0)); 

    int x, y;
    for (int i = 0; i < num; i++) {
        cin >> x >> y;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                canvas[x + j][y + k]++;
            }
        }
    }

    int ans = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (canvas[i][j] == 1) {
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni < 0 || nj < 0 || ni >= 100 || nj >= 100 || canvas[ni][nj] == 0) {
                        ans++;
                        // break;
                    }
                }
            }
        }
    }
    cout << ans;
}

//FAIL : it can't pass the some test cases 
// //compare with other papers and find overlap paper size 
// int main() {
//     int num; 
//     cin >> num; 
//     vector<pair<int, int>> papers(num);

//     for (int i = 0; i < num; i++) {
//         cin >> papers[i].first >> papers[i].second;
//     }

//     int sum = 40 * num;
//     for (int i = 0; i < num; i++) {
//         for (int j = i+1; j < num; j++) { //compare with remaining papers
//             int x1 = papers[i].first, y1 = papers[i].second; 
//             int x2 = papers[j].first, y2 = papers[j].second;
//             int x_overlap = min(x1+10, x2+10) - max(x1, x2);
//             int y_overlap = min(y1+10, y2+10) - max(y1, y2);

//             //need to consider the side-to-side interference
//             if (x_overlap >= 0 && y_overlap >= 0) { //when it overlaps
//                 sum -= 2*(x_overlap + y_overlap);
//             }
//         }
//     }
//     cout << sum;
// }