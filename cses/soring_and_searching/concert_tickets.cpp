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
    ll n, m;
    cin >> n >> m;
    multiset<ll> st;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        st.insert(x);
    }
    for (ll i = 0; i < m; ++i) {
        ll x;
        cin >> x;
        if (st.empty()) {
            cout << "-1\n";
            continue;
        }
        auto it = st.upper_bound(x);
        if (it == st.begin()) {
            cout << "-1\n";
            continue;
        }
        it = prev(it);
        if (it != st.end()) {
            cout << *it << '\n';
            st.erase(it);
        } else
            cout << "-1\n";
    }
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
