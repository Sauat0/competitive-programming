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
const int maxn = 1e5 + 10;
const ll MOD = 1e9 + 7;
const ll mod2 = 998244353;
const ull pHash = 1000003;

vll g[maxn];
bool vis[maxn];
vll comp[maxn];
ll com = 0;

void dfs(ll u) {
    vis[u] = 1;
    comp[com].pb(u);
    for (auto& c : g[u]) {
        if (!vis[c]) dfs(c);
    }
}

void solve() {
    ll n, m, last = -1;
    cin >> n >> m;
    for (ll i = 1; i <= m; ++i) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<pair<ll, ll>> ans;
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) {
            // cout << i << '\n';
            com++;
            dfs(i);
            if (last == -1) {
                last = i;
            } else {
                ans.pb({last, i});
                last = i;
            }
        }
    }
    cout << sz(ans) << '\n';
    for (auto& [u, v] : ans) cout << u << ' ' << v << '\n';
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
