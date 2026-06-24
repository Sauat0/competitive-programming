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
    ll n, s, ans = 0;
    cin >> n >> s;
    vll c(n + 1), v(n + 1);
    vector<vll> dp(n + 1, vll(maxn + 2, INF));
    for (ll i = 1; i <= n; ++i) cin >> c[i] >> v[i];
    dp[0][0] = dp[1][0] = 0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 0; j <= maxn; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i]) dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + c[i]);
        }
    }
    for (ll i = maxn; i >= 0; --i) {
        if (dp[n][i] <= s) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) solve();
}
