#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using ull = unsigned long long;

#define pb push_back
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 2e18;
const int maxn = 2e5 + 10;
const ll MOD = 1e9 + 7;
const ll mod2 = 998244353;
const ull pHash = 1000003;

vll g[maxn];
vll d(maxn);
ll up[maxn][20];

void dfs(ll u, ll p, ll dd) {
    d[u] = dd;
    for (auto& c : g[u]) {
        if (c != p) {
            dfs(c, u, dd + 1);
            up[c][0] = u;
        }
    }
}

ll lca(ll u, ll v) {
    if (d[v] > d[u]) swap(u, v);
    ll diff = abs(d[u] - d[v]);
    for (ll k = 0; k < 20; ++k) {
        if (diff & (1ll << k)) u = up[u][k];
    }
    if (u == v) return u;
    for (ll k = 19; k >= 0; --k) {
        if (up[u][k] != up[v][k]) {
            u = up[u][k];
            v = up[v][k];
        }
    }
    return up[u][0];
}

void solve() {
    ll n, q;
    cin >> n >> q;
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    up[1][0] = 1;
    dfs(1, 0, 0);
    for (ll j = 1; j < 20; ++j) {
        for (ll i = 1; i <= n; ++i) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        ll u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    ll t = 1;
    // cin >> t;
    while (t--) solve();
}
