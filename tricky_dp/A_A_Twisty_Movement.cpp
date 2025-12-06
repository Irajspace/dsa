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
        small observations->

        a1 a2 a3 .... an
        we can reverse any part of array 
        to get maximum non decreasing subsequence

        if we dont reverse it
        we can do it o(n2)

        we know what is maximum till l
        we can also get what is in suffix of r

        1 2 .....l r r-1 .....l+1 r+1 ....n
        for any l what is maximum for r+1 + its left part
        
        what if a[l]=2
        then reversing the array

        what if a[l]=1
        
        1 2 2 3 3 4 4-prefix of 1
        0 1 2 3 4 5 5-pefix of 2

        if(suffixes of 1 is less than 2 
         suffix[j] if i choose 2
         but if i choose 1
        max over all j -best of (prefix of j+suffix of j+1)
        if i reverse
        then
        
                                        
    
    */
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++)cin>>a[i];
    
    int dp1=0,dp2=0,dp3=0,dp4=0;

    for(int i=0; i<n; i++)
    {
        if(a[i]==1)
        {
            dp1=dp1+1;
            dp3=max(dp3,dp2)+1;
        }
        else
        {
            dp2=max(dp2+1,dp1+1);
            dp4=max(dp4+1,dp3+1);
        }
    }
    cout<<max({dp1,dp2,dp3,dp4})<<endl;

    


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