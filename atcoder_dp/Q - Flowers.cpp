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
vector<int>t;
void update(int id, int lo, int hi, int idx, int val)
{
    if(lo==hi)
    {
        t[id]=val;
        return;
    }
    int mid=(hi+lo)/2;
    if(idx<=mid)
    {
        update(2*id+1,lo,mid,idx,val);
    }
    else
    {
        update(2*id+2,mid+1,hi,idx,val);
    }
    t[id]=max(t[2*id+1],t[2*id+2]);
}
int query(int id, int lo, int hi, int l, int r)
{
    if(l<=lo && r>=hi)
    {
        return t[id];
    }
    if(lo>r || hi<l)
    {
        return 0;
    }
    int mid=(hi+lo)/2;
    return max(query(2*id+1,lo,mid,l,r),query(2*id+2,mid+1,hi,l,r));
}
void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    t.resize(4*n+8);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int j=0; j<n; j++)
    {
        cin>>b[j];
    }
    
    for(int i=0; i<n; i++)
    {
        int maxi=0;
        maxi=max(maxi,b[i]);
        if(a[i]>1)
        {
            int val=query(0,0,n,1,a[i]-1);
            maxi=max(maxi,val+b[i]);
        }
        update(0,0,n,a[i],maxi);


    }
    cout<<query(0,0,n,1,n)<<endl;


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