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

struct lzTree {
    ll size;
    vll tree, lz;
    void build(vll& a, ll n, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            if (lx < n) tree[x] = a[lx];
            return;
        }
        ll m = (lx + rx) / 2;
        build(a, n, 2 * x + 1, lx, m);
        build(a, n, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    void build(vll& a, ll n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size * 2 + 1, 0ll);
        lz.assign(size * 2 + 1, 0ll);
        build(a, n, 0, 0, size);
    }
    void push(ll x, ll lx, ll rx) {
        if (lz[x] == 0) return;
        ll m = (lx + rx) / 2;
        lz[2 * x + 1] += lz[x];
        lz[2 * x + 2] += lz[x];
        tree[2 * x + 1] += (m - lx) * lz[x];
        tree[2 * x + 2] += (rx - m) * lz[x];
        lz[x] = 0;
    }
    void upd(ll l, ll r, ll v, ll x, ll lx, ll rx) {
        if (rx <= l || lx >= r) return;
        if (rx <= r && lx >= l) {
            tree[x] += (rx - lx) * v;
            lz[x] += v;
            return;
        }
        push(x, lx, rx);
        ll m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m);
        upd(l, r, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    void upd(ll l, ll r, ll v) {
        upd(l, r, v, 0, 0, size);
    }
    ll get(ll i, ll x, ll lx, ll rx) {
        if (rx - lx == 1) return tree[x];
        ll m = (lx + rx) / 2;
        push(x, lx, rx);
        if (i < m) return get(i, 2 * x + 1, lx, m);
        return get(i, 2 * x + 2, m, rx);
    }
    ll get(ll i) {
        return get(i, 0, 0, size);
    }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    vll a(n);
    for (auto& x : a) cin >> x;
    lzTree st;
    st.build(a, n);
    while (q--) {
        ll tp;
        cin >> tp;
        if (tp == 1) {
            ll l, r, v;
            cin >> l >> r >> v;
            st.upd(l - 1, r, v);
        } else {
            ll i;
            cin >> i;
            cout << st.get(i - 1) << '\n';
        }
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
