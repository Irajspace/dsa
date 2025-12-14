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
/*
    combinations questions are tough u just cant take a random shot
    here i was know the formulation still
    first of all think and write in copy
    


*/
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
int n;
vector<vector<int>>g;
vector<vector<int>>dp;
void dfs(int node, int p)
{
    int sum1=1;
    int sum2=1;
    for(auto it:g[node])
    {
        if(it!=p)
        {
         dfs(it,node);
         sum1=mul(sum1,add(dp[it][1],dp[it][0]));
        
         sum2=mul(sum2,dp[it][0]);
        }
       
    }
    if(node!=1 && g[node].size()==1)
    {
        dp[node][0]=1;
        dp[node][1]=1;
    }
    else{
        dp[node][0]=sum1;
        dp[node][1]=sum2; 

    }
}
void solve() {
    cin>>n;
    g.resize(n+1);
    for(int i=0; i<n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dp.assign(n+1,vector<int>(2,0));
    dfs(1,-1);
    cout<<add(dp[1][0],dp[1][1])<<endl;


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