#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long


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
        here implementation is the key 
        learn it the way if to choose first is the way how to choose it 
        

*/

const int MAXN = 200005;
int dp[MAXN][6];   

bool rec(int idx, int last, const vector<int> &a) {
    if (idx == (int)a.size()) return true;

    int &memo = dp[idx][last];
    if (memo != -1) return memo;

    for (int x = 1; x <= 5; x++) {
        if (idx == 0 ||
            (a[idx] > a[idx - 1] && x > last) ||
            (a[idx] < a[idx - 1] && x < last) ||
            (a[idx] == a[idx - 1] && x != last)) {
            if (rec(idx + 1, x, a)) {
                return memo = 1;
            }
        }
    }
    return memo = 0;
}

void build(int idx, int last, const vector<int> &a, vector<int> &res) {
    if (idx == (int)a.size()) return;

    for (int x = 1; x <= 5; x++) {
        if (idx == 0 ||
            (a[idx] > a[idx - 1] && x > last) ||
            (a[idx] < a[idx - 1] && x < last) ||
            (a[idx] == a[idx - 1] && x != last)) {
            if (rec(idx + 1, x, a)) {
                res[idx] = x;
                build(idx + 1, x, a, res);
                return;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    memset(dp, -1, sizeof(dp));

    if (!rec(0, 0, a)) {
        cout << -1 << '\n';
        return;
    }

    vector<int> res(n);
    build(0, 0, a, res);

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
