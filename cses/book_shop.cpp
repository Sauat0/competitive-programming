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
    ll n, s;
    cin >> n >> s;
    vll c(n + 1), w(n + 1), dp(s + 1, 0ll);
    for (ll i = 1; i <= n; ++i) cin >> c[i];
    for (ll i = 1; i <= n; ++i) cin >> w[i];
    for (ll i = 1; i <= n; ++i) {
        for (ll x = s; x >= c[i]; --x) {
            dp[x] = max(dp[x], dp[x - c[i]] + w[i]);
        }
    }

    cout << dp[s] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) solve();
}
