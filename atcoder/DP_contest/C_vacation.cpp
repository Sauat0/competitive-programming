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
    ll n;
    cin >> n;
    vector<vll> dp(n+1, vll(3, 0ll)), a(n+1, vll(3));
    for(ll i = 1; i <= n; ++i) cin >> a[i][0] >> a[i][1] >> a[i][2];
    dp[1][0] = a[1][0];
    dp[1][1] = a[1][1];
    dp[1][2] = a[1][2]; 
    for(ll i = 2; i <= n; ++i) {
        dp[i][0] = max(dp[i-1][1] + a[i][0], dp[i-1][2] + a[i][0]);
        dp[i][1] = max(dp[i-1][0] + a[i][1], dp[i-1][2] + a[i][1]);
        dp[i][2] = max(dp[i-1][1] + a[i][2], dp[i-1][0] + a[i][2]);
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) solve();
}
