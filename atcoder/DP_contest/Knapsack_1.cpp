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

void solve() {
    ll n, s;
    cin >> n >> s;
    vll c(n+1), v(n+1);
    for(ll i = 1; i <= n; ++i) cin >> c[i] >> v[i];
    vector<vll> dp(n+1, vll(s+1, 0ll));
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= s; ++j) {
            dp[i][j] = dp[i-1][j];
            if(j - c[i] >= 0) dp[i][j] = max(dp[i-1][j-c[i]] + v[i], dp[i][j]);
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= n; ++i) ans = max(ans, dp[i][s]);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) solve();
}
