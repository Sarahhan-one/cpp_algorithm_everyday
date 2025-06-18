#include <iostream>
#include <vector>
using namespace std; 

//compare with other papers and find overlap paper size 
// int main() {
//     int num; 
//     cin >> num; 
//     vector<pair<int, int>> papers(num);
//     int sum = 0;
//     for (int i = 0; i < num; i++) {
//         cin >> papers[i].first >> papers[i].second;

//         sum += 100;
//         for (int j = 0; j < i; j ++) {
//             int x1 = papers[i].first, y1 = papers[i].second; 
//             int x2 = papers[j].first, y2 = papers[j].second;
//             if ((x2 + x1 < 10)||(y2 + y1 < 10) ) { //when it overlaps
//                 sum -= (x2+10 - x1) * (y1+10 - y2); 
//             }
//             break;
//         }
//         cout << sum << '\n';
//     }
//     cout << sum;
// }

int main() {
    int num, sum = 0;
    cin >> num;
    int x, y; 

    bool canvas[100][100] = {};
    for (int i = 0; i < num; i++) {
        cin >> x >> y;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (canvas[i][j])
                canvas[x + j][y + k] = true;
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (canvas[i][j]) sum++;
        }
    }

    cout << sum;   
}