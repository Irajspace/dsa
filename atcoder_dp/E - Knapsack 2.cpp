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

void solve() {
    int N,W;
    cin>>N>>W;
    vector<int>w(N),v(N);
    int cost=0;
    for(int i=0; i<N; i++)
    {
        cin>>w[i]>>v[i];
        cost+=v[i];
    }
    vector<vector<int>>dp(N,vector<int>(cost+1,1e12));
    dp[0][0]=0;
    dp[0][v[0]]=w[0];
    for(int i=1; i<N; i++)
    {
        for(int j=0; j<=cost; j++)
        {
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
            if(j-v[i]>=0)
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j-v[i]]+w[i]);
            }
        }
    }
    for(int i=cost; i>=0; i--)
    {
        if(dp[N-1][i]<=W)
        {
            cout<<i<<endl;
            return;
        }
    }

    
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