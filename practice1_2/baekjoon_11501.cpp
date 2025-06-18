#include <iostream>
#include <vector>
using namespace std;

//FAIL : it doesn't handle local max

//use vector<pair<int,int>> - index and price
//buy stocks before the abs.max. of price(maxVal), count how many bought and total cost
//sell all of them at maxVal, update the profit - abs.max. * cnt - sum
//erase them, start the new tracking


int main() {
    int N, num; 
    cin >> N; 

    while (N--) {
        cin >> num; 
        vector<pair<int, int>> stocks; 
        for (int i = 0; i < num; i++) {
            int price; 
            cin >> price; 
            stocks.push_back({i, price});
        }

        int ans = 0;
        while (!stocks.empty()) {
            int maxVal = 0, maxKey = -1; 
            for (auto& stock : stocks) { //find maxVal and maxKey
                if (stock.second > maxVal) {
                    maxVal = stock.second; 
                    maxKey = stock.first; 
                }
            }

            int cnt = 0, sum = 0;
            vector<pair<int, int>> newStocks; 
            for (auto& stock : stocks) { //buy everything before maxKey
                if (stock.first < maxKey) {
                    cnt++; 
                    sum += stock.second;
                } 
                else if (stock.first > maxKey) {
                    newStocks.push_back(stock);
                }
            }

            ans += maxVal * cnt - sum;
            stocks = newStocks;
        }
        cout << ans << '\n';
    }
}