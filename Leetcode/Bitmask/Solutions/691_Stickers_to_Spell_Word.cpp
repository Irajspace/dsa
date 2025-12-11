#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = (int)target.size();
        if (n == 0) return 0;

        const int INF = INT_MAX / 4;     
        int FULL = (1 << n) - 1;
        vector<int> dp(1 << n, INF);
        dp[0] = 0;

        for (int mask = 0; mask <= FULL; ++mask) {
            if (dp[mask] == INF) continue;
            for (const string &p : stickers) {      
                int new_mask = mask;
                for (char ch : p) {
                    for (int k = 0; k < n; ++k) {
                        if (ch == target[k] && ((new_mask & (1 << k)) == 0)) {
                            new_mask |= (1 << k);
                            break;
                        }
                    }
                }
                dp[new_mask] = min(dp[new_mask], dp[mask] + 1);
            }
        }

        return dp[FULL] == INF ? -1 : dp[FULL];
    }
};
