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
    ll n, s;
    cin >> n >> s;
    vll a(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        if (s - a[i] == a[i] && mp.find(a[i]) != mp.end()) {
            cout << mp[a[i]] + 1 << ' ' << i + 1 << '\n';
            return;
        }
        if (s - a[i] != a[i] && mp.find(s - a[i]) != mp.end()) {
            cout << mp[s - a[i]] + 1 << ' ' << i + 1 << '\n';
            return;
        }
        mp[a[i]] = i;
    }
    cout << "IMPOSSIBLE\n";
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
