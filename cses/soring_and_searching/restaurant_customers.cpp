#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using ull = unsigned long long;

#define pb push_back
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 2e18;
const int maxn = 1e7 + 10;
const ll MOD = 1e9 + 7;
const ll mod2 = 998244353;
const ull pHash = 1000003;

void solve() {
    ll n, ans = 0, cur = 0;
    cin >> n;
    vector<pair<ll, ll>> a;
    for (ll i = 0; i < n; ++i) {
        ll d1, d2;
        cin >> d1 >> d2;
        a.pb({d1, 1});
        a.pb({d2, -1});
    }
    sort(all(a));
    for (auto& [c, w] : a) {
        cur += w;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    while (t--) solve();
}
