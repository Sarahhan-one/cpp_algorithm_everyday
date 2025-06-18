#include <iostream> 
#include <vector> 
#include <map>
#include <algorithm>
using namespace std;

struct Shortcut {
    int start, end, dist;
};

int main() {
    int N, D;
    cin >> N >> D; 
    
    map<pair<int, int>, int> shortcutMap;
    
    for (int i = 0; i < N; i++) {
        int pairFirst, pairSecond, dist; 
        cin >> pairFirst >> pairSecond >> dist;
        
        pair<int, int> key = {pairFirst, pairSecond};
        
        // If the pair doesn't exist or current distance is smaller, update it
        if (shortcutMap.find(key) == shortcutMap.end() || shortcutMap[key] > dist) {
            shortcutMap[key] = dist;
        }
    }
    
    // Convert map back to vector
    vector<Shortcut> shortcuts;
    for (auto& p : shortcutMap) {
        shortcuts.push_back({p.first.first, p.first.second, p.second});
    }
    
    //but.. we might find better shorcuts later that could improve earlier positions
    sort(shortcuts.begin(), shortcuts.end(), [](const Shortcut& a, const Shortcut& b) {
        return a.start < b.start;});


    vector<int> dp(shortcuts.size());
    
    // Base case
    dp[0] = shortcuts[0].start + min(shortcuts[0].end - shortcuts[0].start, shortcuts[0].dist);
    
    for (int i = 1; i < shortcuts.size(); i++) {
        int start = shortcuts[i].start;
        int end = shortcuts[i].end;
        int dist = shortcuts[i].dist;
        
        //1: Don't use any previous shortcuts
        dp[i] = start + min(end - start, dist);
        
        //2: Use previous shortcut
        for (int j = 0; j < i; j++) {
            if (shortcuts[j].end <= start) {
                int distPrev = dp[j] + (start - shortcuts[j].end) + min(end - start, dist);
                dp[i] = min(dp[i], distPrev);
            }
        }
    }
    
    // at destination
    int result = D;  
    
    for (int i = 0; i < shortcuts.size(); i++) {
        if (shortcuts[i].end <= D) {
            result = min(result, dp[i] + (D - shortcuts[i].end));
        }
    }
    
    cout << result;
    
    return 0;
}