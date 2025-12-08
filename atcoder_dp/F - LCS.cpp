#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

// const int MOD = 1000000007;
// const int M = 1000000007;

int MOD;
int M;

static int fact[1000005];
static int invFact[1000005];

long long mod(long long x) { return ((x % M + M) % M); }
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }

ll modPow(ll a, ll b) {
    if (b == 0) return 1LL;
    if (b == 1) return a % M;
    ll res = 1;
    while (b) {
        if (b % 2 == 1) res = mul(res, a);
        a = mul(a, a);
        b = b / 2;
    }
    return res;
}

ll inv(ll x) { return modPow(x, M - 2); }

const int N = 1000005;

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = mul(fact[i - 1], i);
    }

    invFact[N - 1] = inv(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        invFact[i] = mul(invFact[i + 1], i + 1);
    }
}
/*

    Imp thing learn:->
    1) To print iterative just go to last i=n && j=m;
    then
    The Logic (Backtracking)
Start at i = n and j = m.

Match: If s[i-1] == t[j-1], this character is part of the LCS. Add it to your result and move diagonally up-left (i--, j--).

No Match: If they don't match, look at the cell's neighbors (Top dp[i-1][j] vs Left dp[i][j-1]). Move towards the neighbor that holds the larger value (this tells you where the current max length came from)

*/

void solve() {
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
            }
            else{
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
    }
   // cout<<dp[n][m]<<endl;

    string ans="";
    int i=n,j=m;
    while(i>=1 && j>=1)
    {
        if(s[i-1]==t[j-1])
        {
            ans.push_back(s[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;

        }
        else{
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;


}

signed main() {
// #ifndef ONLINE_JUDGE
//     freopen("inputf.txt", "r", stdin);
//     freopen("outputf.txt", "w", stdout);
//     freopen("error.txt", "w", stderr);
// #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    //cin >> T;
    while (T--) solve();
    return 0;
}