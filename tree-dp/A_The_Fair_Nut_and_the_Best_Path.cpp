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
        what we found here?
       
        1) when we want to find longest path using dp
        we can use best1 and best2
        2)on returning only return a[u]+best1 and not full dp[node]
        
*/
int n;
vector<vector<pair<int,int>>>g;
vector<int>a;
vector<int>dp;
int dfs(int u, int p)
{
    int best1=0;
    int best2=0;
    dp[u]=a[u];
    for(auto it:g[u])
    {
        if(it.first!=p)
        {
            int val=dfs(it.first,u);
            if(val-it.second>=best1)
            {
                best2=best1;
                best1=val-it.second;
                dp[u]=max(dp[u],best1+best2+a[u]);
                
            }
            else if(val-it.second>=best2)
            {
             best2=val-it.second;
             dp[u]=max(dp[u],best1+best2+a[u]);
            }
        }
    }
    return (best1+a[u]);
}

void solve() {
    cin>>n;
    g.resize(n+1);
    a.resize(n+1);
    dp.assign(n+1,0);
   

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n-1; i++)
    {
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        g[a1].push_back({a2,a3});
        g[a2].push_back({a1,a3});
    }
    dfs(1,-1);
    int best=0;
    for(int i=1; i<=n; i++)
    {
       best=max(best,dp[i]);
    }
    cout<<best<<endl;

    

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