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
    ll n;
    cin >> n;
    vll dp(n + 2, INF);
    dp[0] = 0;
    for (ll i = 1; i <= n; ++i) {
        ll x = i;
        while (x > 0) {
            dp[i] = min(dp[i], dp[i - (x % 10)] + 1);
            x /= 10;
        }
    }
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) solve();
}
