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
    vll dp(s + 1, 0), cc(n);
    dp[0] = 1;
    for (auto& x : cc) cin >> x;
    for (auto& c : cc) {
        for (ll x = c; x <= s; ++x) dp[x] = (dp[x] + dp[x - c]) % MOD;
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
