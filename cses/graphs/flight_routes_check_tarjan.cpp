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
const int LOG = 30;
const int maxn = 2e5 + 10;
const ll MOD = 1e9 + 7;
const ll mod2 = 998244353;
const ull pHash = 1000003;

vll g[maxn];
vll comp[maxn];
vll tin(maxn, 0ll);
vll low(maxn, 0ll);
ll cur = 0, timer = 0;
bool in[maxn];
vll st;

void dfs(ll u) {
    tin[u] = low[u] = ++timer;
    st.pb(u);
    in[u] = 1;
    for (auto& to : g[u]) {
        if (tin[to] == 0) {
            dfs(to);
            low[u] = min(low[u], low[to]);
        } else if (in[to]) {
            low[u] = min(low[u], tin[to]);
        }
    }
    if (low[u] == tin[u]) {
        cur++;
        while (!st.empty()) {
            ll v = st.back();
            st.pop_back();
            comp[cur].pb(v);
            in[v] = false;
            if (u == v) break;
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
    }
    for (ll i = 1; i <= n; ++i) {
        if (tin[i] == 0) dfs(i);
    }
    if (cur == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        cout << comp[1][0] << ' ' << comp[2][0] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
