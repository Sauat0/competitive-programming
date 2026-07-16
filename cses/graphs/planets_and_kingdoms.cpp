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
vll low(maxn, 0ll);
vll tin(maxn, 0ll);
vll comp(maxn);
bool is[maxn];
vll st;
ll cur = 0, timer = 0;

void dfs(ll v) {
    st.pb(v);
    is[v] = true;
    tin[v] = low[v] = ++timer;
    for (auto& to : g[v]) {
        if (tin[to] == 0) {
            dfs(to);
            low[v] = min(low[v], low[to]);
        } else if (is[to]) {
            low[v] = min(low[v], tin[to]);
        }
    }
    if (low[v] == tin[v]) {
        cur++;
        while (!st.empty()) {
            ll u = st.back();
            st.pop_back();
            is[u] = false;
            comp[u] = cur;
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
        if (tin[i] == 0) {
            dfs(i);
        }
    }
    cout << cur << '\n';
    for (ll i = 1; i <= n; ++i) cout << comp[i] << ' ';
    cout << '\n';
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
