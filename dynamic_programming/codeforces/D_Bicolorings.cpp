#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int MOD = 998244353;
const int M = 998244353;

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
    for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
    invFact[N - 1] = inv(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--) invFact[i] = mul(invFact[i + 1], i + 1);
}
/*
        what we have to learn
        1) this was easy case for transitions
        2) thinking what can be the cases
        B-B W-W W-B B-W
        here ek chiz yaad rkhna sometimes it is given two i's
        we can consider simultaneously 

*/

void solve() {
    int n, k;
    cin >> n >> k;
    int dp[n + 1][k + 1][4] = {};

    if (k >= 1) {
        dp[1][1][0] = 1;
        dp[1][1][1] = 1;
    }
    if (k >= 2) {
        dp[1][2][2] = 1;
        dp[1][2][3] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= min(k, 2 * n); j++) {
            dp[i][j][0] = add(dp[i][j][0], dp[i - 1][j][0]);
            if (j > 0) dp[i][j][0] = add(dp[i][j][0], dp[i - 1][j - 1][1]);
            dp[i][j][0] = add(dp[i][j][0], dp[i - 1][j][2]);
            dp[i][j][0] = add(dp[i][j][0], dp[i - 1][j][3]);

            dp[i][j][1] = add(dp[i][j][1], dp[i - 1][j][1]);
            if (j > 0) dp[i][j][1] = add(dp[i][j][1], dp[i - 1][j - 1][0]);
            dp[i][j][1] = add(dp[i][j][1], dp[i - 1][j][2]);
            dp[i][j][1] = add(dp[i][j][1], dp[i - 1][j][3]);

            if (j > 0) dp[i][j][2] = add(dp[i][j][2], dp[i - 1][j - 1][0]);
            if (j > 0) dp[i][j][2] = add(dp[i][j][2], dp[i - 1][j - 1][1]);
            dp[i][j][2] = add(dp[i][j][2], dp[i - 1][j][2]);
            if (j > 1) dp[i][j][2] = add(dp[i][j][2], dp[i - 1][j - 2][3]);

            if (j > 0) dp[i][j][3] = add(dp[i][j][3], dp[i - 1][j - 1][0]);
            if (j > 0) dp[i][j][3] = add(dp[i][j][3], dp[i - 1][j - 1][1]);
            dp[i][j][3] = add(dp[i][j][3], dp[i - 1][j][3]);
            if (j > 1) dp[i][j][3] = add(dp[i][j][3], dp[i - 1][j - 2][2]);
        }
    }

    int val = add(dp[n][k][0], dp[n][k][1]);
    val = add(val, dp[n][k][2]);
    val = add(val, dp[n][k][3]);
    cout << val << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
    return 0;
}
