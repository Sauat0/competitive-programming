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

void solve() {
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vll> dist(n + 4, vll(n + 4, INF));
    vector<vector<pair<ll, ll>>> g(n + 4);
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = dist[u][v];
    }

    for (ll i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }

    for (ll k = 1; k <= n; ++k) {
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while (q--) {
        ll u, v;
        cin >> u >> v;
        cout << (dist[u][v] == INF ? -1 : dist[u][v]) << '\n';
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
