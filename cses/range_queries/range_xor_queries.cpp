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

struct segTree {
    ll size;
    vll tree;
    void build(vll& a, ll n, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            if (lx < n) tree[x] = a[lx];
            return;
        }
        ll m = (lx + rx) / 2;
        build(a, n, 2 * x + 1, lx, m);
        build(a, n, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] ^ tree[2 * x + 2];
    }
    void build(vll& a, ll n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size * 2 + 1, 0ll);
        build(a, n, 0, 0, size);
    }
    void upd(ll i, ll v, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        ll m = (lx + rx) / 2;
        if (i < m)
            upd(i, v, 2 * x + 1, lx, m);
        else
            upd(i, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] ^ tree[2 * x + 2];
    }
    void upd(ll i, ll v) {
        upd(i, v, 0, 0, size);
    }
    ll get(ll l, ll r, ll x, ll lx, ll rx) {
        if (rx <= l || lx >= r) return 0ll;
        if (rx <= r && lx >= l) return tree[x];
        ll m = (lx + rx) / 2;
        return (get(l, r, 2 * x + 1, lx, m) ^ get(l, r, 2 * x + 2, m, rx));
    }
    ll get(ll l, ll r) {
        return get(l, r, 0, 0, size);
    }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    vll a(n);
    for (auto& x : a) cin >> x;
    segTree st;
    st.build(a, n);
    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << st.get(l - 1, r) << '\n';
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
