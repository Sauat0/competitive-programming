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
    ll n, m;
    cin >> n >> m;
    vll dist(n + 4, INF);
    vector<vector<pair<ll, ll>>> g(n + 4);
    vector<bool> vis(n + 4, false);
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }
    priority_queue<pair<ll, ll>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto& [c, w] : g[u]) {
            if (dist[u] + w < dist[c]) {
                dist[c] = dist[u] + w;
                pq.push({-dist[c], c});
            }
        }
    }

    for (ll i = 1; i <= n; ++i) cout << dist[i] << ' ';
    cout << '\n';
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
