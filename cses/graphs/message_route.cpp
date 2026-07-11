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
    vector<vll> g(n + 2);
    vector<bool> vis(n + 2, false);
    vll mem(n + 2);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    queue<tuple<ll, ll, ll>> q;
    q.push({1, 0, 0});
    vis[1] = 1;
    while (!q.empty()) {
        auto [u, d, v] = q.front();
        q.pop();
        mem[u] = v;
        if (u == n) {
            cout << d + 1 << '\n';
            vll ans;
            ans.pb(u);
            while (u != 1) {
                ans.pb(mem[u]);
                u = mem[u];
            }
            reverse(all(ans));
            for (auto& x : ans) cout << x << ' ';
            cout << '\n';
            return;
        }
        for (auto& c : g[u]) {
            if (!vis[c]) {
                vis[c] = 1;
                q.push({c, d + 1, u});
            }
        }
    }
    cout << "IMPOSSIBLE\n";
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
