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
    ll n, m, lst = -1;
    cin >> n >> m;
    vector<tuple<ll, ll, ll>> g(m);
    vll dist(n + 5, 0), ans, p(n + 5);
    for (auto& [u, v, w] : g) cin >> u >> v >> w;
    for (ll i = 1; i <= n; ++i) {
        lst = -1;
        for (auto& [u, v, w] : g) {
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                lst = v;
                p[v] = u;
            }
        }
    }
    if (lst == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        ll cur = lst;
        for (ll i = 0; i < n; ++i) cur = p[cur];
        for (ll v = cur;; v = p[v]) {
            ans.pb(v);
            if (v == cur && sz(ans) > 1) break;
        }
        for (ll i = sz(ans) - 1; i >= 0; --i) cout << ans[i] << ' ';
        cout << '\n';
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
