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
    ll n;
    cin >> n;
    vector<vector<char>> a(n + 2, vector<char>(n + 2, 'Z'));
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) cin >> a[i][j];
    }
    string s;
    s.pb(a[1][1]);
    queue<pair<ll, ll>> q;
    q.push({1, 1});
    while (sz(s) != 2 * n - 1) {
        char mn = 'Z';
        vector<pair<ll, ll>> v;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x + 1 <= n) v.pb({x + 1, y});
            if (y + 1 <= n) v.pb({x, y + 1});
        }
        sort(all(v));
        v.erase(unique(all(v)), v.end());
        for (auto& [x, y] : v) mn = min(mn, a[x][y]);
        s.pb(mn);
        for (auto& [x, y] : v) {
            if (a[x][y] == mn) q.push({x, y});
        }
    }
    cout << s << '\n';
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
