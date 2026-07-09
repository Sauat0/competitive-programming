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

vector<pair<ll, ll>> g[maxn];
vll dist(maxn, INF);
bool vis[maxn];

void solve() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].pb({w, v});
        g[v].pb({w, u});
    }
    priority_queue<pair<ll, ll>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto& [w, v] : g[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
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
