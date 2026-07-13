vll g[maxn];
bool vis[maxn];
vll a, dp(maxn, 0ll);

void dfs(ll u) {
    vis[u] = 1;
    for (auto& c : g[u]) {
        if (!vis[c]) dfs(c);
    }
    a.pb(u);
}

void solve() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
    }

    dfs(1);
    dp[1] = 1;
    reverse(all(a));
    for (ll i = 0; i < sz(a); ++i) {
        for (auto& c : g[a[i]]) {
            dp[c] = (dp[c] + dp[a[i]]) % MOD;
        }
    }
    cout << dp[n] << '\n';
}
