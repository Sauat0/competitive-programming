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
const int LOG = 30;
const int maxn = 2e5 + 10;
const ll MOD = 1e9 + 7;
const ll mod2 = 998244353;
const ull pHash = 1000003;

vll g[maxn];
vll gv[maxn];
vll comp[maxn];
vll eul;
ll cur = 0;
vector<bool> vis(maxn, false);

void dfs(ll u) {
    vis[u] = 1;
    for (auto& c : g[u]) {
        if (!vis[c]) dfs(c);
    }
    eul.pb(u);
}

void dfs2(ll u) {
    vis[u] = 1;
    comp[cur].pb(u);
    for (auto& c : gv[u]) {
        if (!vis[c]) dfs2(c);
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        gv[v].pb(u);
    }
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i);
    }
    vis.assign(n + 5, false);
    for (ll i = sz(eul) - 1; i >= 0; --i) {
        // cout << eul[i] << ' ';
        if (!vis[eul[i]]) {
            cur++;
            dfs2(eul[i]);
        }
    }
    if (cur == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        for (ll i = 0; i < sz(g[comp[2][0]]); ++i) {
            if (g[comp[2][0]][i] == comp[1][0]) {
                cout << comp[1][0] << ' ' << comp[2][0] << '\n';
                return;
            }
        }
        cout << comp[2][0] << ' ' << comp[1][0] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
