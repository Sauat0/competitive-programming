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
    ll n, m, k, cnt = 0;
    cin >> n >> m >> k;
    vll a(n), b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    sort(all(a));
    sort(all(b));
    ll i = 0, j = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= k) {
            cnt++;
            i++;
            j++;
        } else if (a[i] > b[j]) {
            j++;
        } else
            i++;
    }
    cout << cnt << '\n';
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
