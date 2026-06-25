#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define pb push_back
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 1e18;
const int maxn = 1e5 + 10;
const ll MOD = 1e9 + 7;

vll g[maxn];
vll dp(maxn, 0ll);
bool vis[maxn];

void dfs(ll u) {
    vis[u] = true;
    for(auto& c : g[u]) {
        if(!vis[c]) dfs(c);
        dp[u] = max(dp[u], dp[c] + 1);
    }
}

void solve() {
    ll n, m, ans = 0;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
    }
    for (ll i = 1; i <= n; ++i) {
        if(!vis[i]) dfs(i);
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) solve();
}
