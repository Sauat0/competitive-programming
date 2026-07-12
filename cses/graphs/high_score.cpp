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
    vector<tuple<ll, ll, ll>> g(m);
    vll dist(n + 4, -INF);
    for (auto& [u, v, w] : g) cin >> u >> v >> w;
    dist[1] = 0;
    for (ll i = 1; i <= 2 * n; ++i) {
        for (auto& [u, v, w] : g) {
            if (dist[u] == -INF) continue;
            if (dist[v] < dist[u] + w) {
                if (i >= n)
                    dist[v] = INF;
                else
                    dist[v] = dist[u] + w;
            }
        }
    }

    cout << (dist[n] == INF ? -1 : dist[n]) << '\n';
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
