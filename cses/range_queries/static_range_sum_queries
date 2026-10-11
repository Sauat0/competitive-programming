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
const int LOG = 20;
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll mod2 = 998244353;
const ull pHash = 1000003;

void solve() {
    ll n, q;
    cin >> n >> q;
    vll a(n), p(n + 1, 0ll);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        p[i + 1] = p[i] + a[i];
    }
    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << p[r] - p[l - 1] << '\n';
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
