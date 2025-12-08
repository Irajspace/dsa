#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int MOD = 1000000007;
const int M = 1000000007;

// int MOD;
// int M;

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

void solve() {
    int H,W;
    cin>>H>>W;
    vector<vector<char>>grid(H+1,vector<char>(W+1));
    for(int i=1; i<=H; i++)
    {
        for(int j=1; j<=W; j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>dp(H+1,vector<int>(W+1,0));
    dp[1][1]=1;
    for(int i=1; i<=H; i++)
    {
        for(int j=1; j<=W; j++)
        {
            if(grid[i][j]=='.')
            {
                if(grid[i-1][j]=='.')
                {
                    dp[i][j]=add(dp[i][j],dp[i-1][j]);
                }
                if(grid[i][j-1]=='.')
                {
                    dp[i][j]=add(dp[i][j],dp[i][j-1]);
                }
            }
        }
    }
    cout<<dp[H][W]<<endl;
    
    
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