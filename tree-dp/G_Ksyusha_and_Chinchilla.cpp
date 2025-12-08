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

vector<vector<int>> g;
vector<int> sbtree,new_sbtree;
map<pair<int, int>, int> mp;
vector<int> res;

void dfs(int u, int p) {
    sbtree[u] = 1;
    for (auto it : g[u]) {
        if (it != p) {
            dfs(it, u);
            sbtree[u] += sbtree[it];
        }
    }
}

bool dfs2(int u, int p) {
    bool ans = true;
    new_sbtree[u]=1;
    for (auto it : g[u]) {
        if (it != p) {
            ans = dfs2(it, u);
            new_sbtree[u]+=new_sbtree[it];
            if (!ans) return false;
        }
    }
    if (!ans) return false;
    if (new_sbtree[u] > 3) return false;

    if (new_sbtree[u] == 3) {
        if (p != -1) {
            res.push_back(mp[{u, p}]);
            new_sbtree[p] -= new_sbtree[u];
        }
        return true;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;

    g.assign(n + 1, {});
    sbtree.assign(n + 1, 0);
    new_sbtree.assign(n+1,0);
    mp.clear();
    res.clear();

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        mp[{a, b}] = i + 1;
        mp[{b, a}] = i + 1;
    }

    dfs(1, -1);
    bool result = dfs2(1, -1);
    if(new_sbtree[1]<3)
    {
        result=false;
    }
    if (result) {
        cout << res.size() << '\n';
    
        if(res.size())
        {
             for (int x : res) cout << x << " ";
       
        }
        cout<<endl;
       
    } else {
        cout << -1 << '\n';
    }

    g.clear();
    sbtree.clear();
    mp.clear();
    res.clear();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
