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
    Observations
    1) when i was thinking of test samples i was thinking how to calculate this whole in dp
    2) so sometimes writing code help you very much 
    3) so start with something you will eventually get it
    



*/

void solve() {
    int N;
    cin>>N;
    vector<double>a(N+1);
    for(int i=1; i<=N; i++)
    {
        double p;
        cin>>p;
        a[i]=p;
    }
    vector<vector<double>>dp(N+1,vector<double>(N+1,0));
    dp[0][0]=0;
    dp[1][1]=a[1];
    dp[1][0]=1-a[1];
    for(int i=2;i<=N; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j==0)
            {
                dp[i][0]=(1-a[i])*dp[i-1][0];
            }
            else{
                dp[i][j]=(a[i]*dp[i-1][j-1]);
                dp[i][j]=(dp[i][j]+dp[i-1][j]*(1-a[i]));
            }
        }
    }
    double tot=0;
    
        for(int j=(N+1)/2; j<=N; j++)
        {
            tot+=dp[N][j];
        }
    
    cout<<fixed<<setprecision(12)<<tot<<endl;


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