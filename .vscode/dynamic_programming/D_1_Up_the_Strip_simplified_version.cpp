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
        what we have learned here?

        whenever there is need for summation for
        x/z for all 1 to n
        1) we can do it o(N*(root(N)))
        2) we can also do o(N log N)
            we have to think for which values it is giving i
            z*i<=k<=z*(i+1)-1
            for all thos values ans will be z only
            



*/



void solve() {
   /*
        x se kahan ja skta hai
        x/2 
        ()
 
   */
    int n, m;
    cin >> n >> m;
    M = m;
    MOD = m;
    vector<int> dp(n + 1, 0);
    int sum = 0;
    dp[n] = 1;
    vector<int>suffix(n+2,0);
    suffix[n]=1;
    suffix[n+1]=0;
    for (int i = n-1; i >= 1; i--) {
        dp[i]=add(dp[i],suffix[i+1]);
        
        for(int z=2; z*i<=n; z++)
        {
             int l=z*i;
             int r=min(n,z*(i+1)-1);
             int range=(suffix[l]-suffix[r+1]+M)%M;
             dp[i]=add(dp[i],range);
        }
        suffix[i]=add(dp[i],suffix[i+1]);
    }
    cout << dp[1] << endl;


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