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

const ll INF = 1e18;
const int LOG = 24;
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll mod2 = 998244353;
const ull pHash = 1000003;

void solve() {
    ll n, s = 0, sum = 0, s1 = 0;
    cin >> n;
    vll a(n);
    for (auto& x : a) cin >> x;
    sort(all(a));
    for (ll i = 0; i < n; ++i) {
        s += abs(a[n / 2] - a[i]);
        if ((n + 1) / 2 != n) s1 += abs(a[(n + 1) / 2] - a[i]);
    }
    cout << min(s1, s) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // compute();

    ll tt = 1;
    // cin >> tt;
    while (tt--) solve();
}
