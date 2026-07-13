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

vll g[maxn];
bool vis[maxn];
vll a;

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
    if (!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vll dp(n + 5, 0ll), ans, mem(n + 5);
    dp[1] = 1;
    reverse(all(a));
    for (ll i = 0; i < sz(a); ++i) {
        for (auto& c : g[a[i]]) {
            if (dp[c] < dp[a[i]] + 1 && dp[a[i]] != 0) {
                dp[c] = dp[a[i]] + 1;
                mem[c] = a[i];
            }
        }
    }
    cout << dp[n] << '\n';
    ll u = n;
    while (u != 1) {
        ans.pb(u);
        u = mem[u];
    }
    reverse(all(ans));
    cout << "1 ";
    for (auto& x : ans) cout << x << ' ';
    cout << '\n';
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
