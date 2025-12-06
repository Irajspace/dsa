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
   /*
       
       ai+k;
       bi-k;

       a1+k
       b1-k;
 
   */
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int j=0; j<n; j++)
    {
        cin>>b[j];
    }
    vector<vector<int>>dp(n,vector<int>(2,-1e18));
    int current_max=0,current_min=0;
    for(int i=0; i<n; i++)
    {
        int val1 = current_max - a[i];
        int val2 = current_min - a[i];
        int val3 = b[i] - current_max;
        int val4 = b[i] - current_min;
        current_max = max({val1, val2, val3, val4});
        current_min = min({val1, val2, val3, val4});
    }
    cout<<current_max<<endl;

   

}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    cin >> T;
    while (T--) solve();
    return 0;
}