#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using ull = unsigned long long;
using i128 = __int128;

#define pb push_back
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const ll INF = 2e18;
const int LOG = 25;
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll mod2 = 998244353;
const ull pHash = 1000003;

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<vector<char>> a(n, vector<char>(n));
    vector<vll> p(n + 1, vll(n + 1, 0ll));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) cin >> a[i][j];
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            p[i][j] = (a[i - 1][j - 1] == '*') + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }
    while (q--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1] + p[x1 - 1][y1 - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll tt = 1;
    // cin >> tt;
    while (tt--) solve();
}
