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
 
 
vector<vll> dp(1e6+5, vll(2, 0ll));
 
void solve() {
    ll n;
    cin >> n;
    dp[n][0] = dp[n][1] = 1;
    for (ll i = n - 1; i >= 0; --i) {
        dp[i][0] = (2ll * dp[i + 1][0] + dp[i + 1][1]) % MOD;
        dp[i][1] = (4ll * dp[i + 1][1] + dp[i + 1][0]) % MOD;
    }
    cout << (dp[1][1] + dp[1][0]) % MOD << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t = 1;
    cin >> t;
    while (t--) solve();
}
