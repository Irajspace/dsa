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
    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(3,0));
    for(int i=0;i<n; i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    vector<vector<int>>dp(n,vector<int>(3,LLONG_MAX));
    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
            dp[i][0]=a[0][0];
            dp[i][1]=a[0][1];
            dp[i][2]=a[0][2];
        }
        else{
            dp[i][0]=max(dp[i-1][1]+a[i][0],dp[i-1][2]+a[i][0]);
            dp[i][1]=max(dp[i-1][0]+a[i][1],dp[i-1][2]+a[i][1]);
            dp[i][2]=max(dp[i-1][0]+a[i][2],dp[i-1][1]+a[i][2]);
        }
    }
    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});

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