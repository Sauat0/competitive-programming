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
    ll n, k;
    cin >> n >> k;
    vll h(n), dp(n);
    for(ll i = 0; i < n; ++i) {
        cin >> h[i];
    }
    dp[0] = 0;
    for(ll i = 1; i < n; ++i) {
        dp[i] = INF;
        for(ll j = i - 1; j >= max(0ll, i - k); --j) dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
    }
    cout << dp[n-1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) solve();
}
