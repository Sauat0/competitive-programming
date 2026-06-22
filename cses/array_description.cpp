#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define pb push_back
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;
const int maxn = 1e5 + 10;
const ll MOD = 1e9 + 7;

void solve() {
    ll n, m, x, ans = 0;
    cin >> n >> m >> x;
    vector<vll> dp(n + 1, vll(m + 3, 0ll));

    if (x == 0) {
        for (ll i = 1; i <= m; ++i) dp[1][i] = 1;
    } else
        dp[1][x] = 1;

    for (ll i = 2; i <= n; ++i) {
        cin >> x;
        if (x != 0) {
            dp[i][x] = (dp[i - 1][x] + dp[i - 1][x - 1] + dp[i - 1][x + 1]) % MOD;
        } else {
            for (ll j = 1; j <= m; ++j) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    for (ll i = 1; i <= m; ++i) ans = (dp[n][i] + ans) % MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) solve();
}
