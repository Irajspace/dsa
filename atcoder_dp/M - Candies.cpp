#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int MOD = 1000000007;
const int M = 1000000007;

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        vector<int> next_dp(k + 1, 0);
        vector<int> prefix_sum = dp;
        for (int j = 1; j <= k; j++) {
            prefix_sum[j] = add(prefix_sum[j], prefix_sum[j - 1]);
        }

        for (int j = 0; j <= k; j++) {
            int upper = j;
            int lower = j - a[i] - 1;
            int val = prefix_sum[upper];
            if (lower >= 0) {
                val = add(val, -prefix_sum[lower]);
            }
            next_dp[j] = val;
        }

        dp = next_dp;
    }

    cout << dp[k] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
    return 0;
}
