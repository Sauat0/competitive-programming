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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<ll, ll>>> g(n + 5);
    vector<priority_queue<ll>> dist(n + 5);
    vector<bool> vis(n + 5, false);
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        d = -d;
        if (!dist[u].empty() && d > dist[u].top()) continue;
        for (auto& [c, w] : g[u]) {
            if (sz(dist[c]) < k || w + d < dist[c].top()) {
                dist[c].push({w + d});
                if (sz(dist[c]) > k) dist[c].pop();
                pq.push({-(w + d), c});
            }
        }
    }

    while (sz(dist[n]) > k) dist[n].pop();
    vll ans;
    while (!dist[n].empty()) {
        ans.pb(dist[n].top());
        dist[n].pop();
    }
    for (ll i = sz(ans) - 1; i >= 0; --i) cout << ans[i] << ' ';
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
