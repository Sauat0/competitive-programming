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

vll color(maxn, 0ll);
vll g[maxn];
vll par(maxn, -1);
vll ans;
ll s = -1, e = -1;

bool dfs(ll u, ll p) {
    color[u] = 1;
    par[u] = p;
    for (auto& c : g[u]) {
        if (c == p) continue;
        if (color[c] == 0) {
            bool can = dfs(c, u);
            if (can) {
                return true;
            }
        }
        if (color[c] == 1) {
            s = c;
            e = u;
            return true;
        }
    }
    color[u] = 2;
    return false;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (ll i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            if (dfs(i, -1)) {
                ans.pb(s);
                while (e != s) {
                    ans.pb(e);
                    e = par[e];
                }
                ans.pb(s);
                cout << sz(ans) << '\n';
                for (auto& x : ans) cout << x << ' ';
                cout << '\n';
                return;
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
