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
    ll n, m;
    cin >> n >> m;
    vector<vll> dp(n + 1, vll(m + 1, 0ll));
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) cin >> a[i][j];
    }
    dp[1][1] = (a[1][1] == '.');
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            if (a[i][j] == '#' || (i == 1 && j == 1)) continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[n][m] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) solve();
}
