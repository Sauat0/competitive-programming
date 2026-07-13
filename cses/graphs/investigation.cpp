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
 
vector<pair<ll, ll>> g[maxn];
bool vis[maxn];
vector<vll> dp(maxn, vll(4));
 
void solve() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }
    for (ll i = 2; i <= n + 5; ++i) dp[i] = {INF, 0, INF, -INF};
    dp[1] = {0, 1, 0, 0};
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        d = -d;
        if (d > dp[u][0] || vis[u]) continue;
        vis[u] = 1;
        for (auto& [c, w] : g[u]) {
            if (dp[c][0] > dp[u][0] + w) {
                dp[c] = dp[u];
                dp[c][0] += w;
                dp[c][2]++;
                dp[c][3]++;
                pq.push({-dp[c][0], c});
            } else if (dp[c][0] == dp[u][0] + w) {
                dp[c][1] = (dp[c][1] + dp[u][1]) % MOD;
                dp[c][2] = min(dp[c][2], dp[u][2] + 1);
                dp[c][3] = max(dp[c][3], dp[u][3] + 1);
            }
        }
    }
 
    for (auto& x : dp[n]) cout << x << ' ';
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
