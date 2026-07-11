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
bool ok = true;

void dfs(ll u) {
    for (auto& c : g[u]) {
        if (color[c] == color[u]) {
            ok = false;
            break;
        } else if (color[c] == 0) {
            color[c] = (color[u] == 1 ? 2 : 1);
            dfs(c);
        }
    }
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
            color[i] = 1;
            dfs(i);
        }
    }
    if (!ok)
        cout << "IMPOSSIBLE\n";
    else {
        for (ll i = 0; i < n; ++i) cout << color[i + 1] << ' ';
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
