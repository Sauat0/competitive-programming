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
const int maxn = 1e7 + 10;
const ll MOD = 1e9 + 7;
const ll mod2 = 998244353;
const ull pHash = 1000003;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n + 5);
    vector<vector<bool>> vis(n + 4, vector<bool>(2, false));
    vector<vll> dist(n + 4, vll(2, INF));
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }
    priority_queue<tuple<ll, ll, ll>> pq;
    dist[1][0] = 0;
    pq.push({0, 1, 0});
    while (!pq.empty()) {
        auto [d, u, state] = pq.top();
        d = -d;
        pq.pop();
        if (d > dist[u][state]) continue;
        if (vis[u][state]) continue;
        vis[u][state] = 1;
        for (auto& [c, w] : g[u]) {
            if (state == 0) {
                if (dist[c][0] > dist[u][0] + w) {
                    dist[c][0] = dist[u][0] + w;
                    pq.push({-dist[c][0], c, 0});
                }
                if (dist[c][1] > dist[u][0] + w / 2) {
                    dist[c][1] = dist[u][0] + w / 2;
                    pq.push({-dist[c][1], c, 1});
                }
            } else {
                if (dist[c][1] > dist[u][1] + w) {
                    dist[c][1] = dist[u][1] + w;
                    pq.push({-dist[c][1], c, 1});
                }
            }
        }
    }
    cout << min(dist[n][0], dist[n][1]);
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
