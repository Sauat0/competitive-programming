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
    struct node {
        ll val, id;
    };
    node merge(node& a, node& b) {
        if (a.val > b.val) return a;
        if (b.val > a.val) return b;
        if (a.id < b.id) return a;
        return b;
    }
    vector<node> tree;
    void build(vll& a, ll n, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            if (lx < n) tree[x] = {a[lx], lx + 1};
            return;
        }
        ll m = (lx + rx) / 2;
        build(a, n, 2 * x + 1, lx, m);
        build(a, n, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void build(vll& a, ll n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size * 2 + 1, {0, 0});
        build(a, n, 0, 0, size);
    }
    void upd(ll i, ll v, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            tree[x].val = v;
            return;
        }
        ll m = (lx + rx) / 2;
        if (i < m)
            upd(i, v, 2 * x + 1, lx, m);
        else
            upd(i, v, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void upd(ll i, ll v) {
        upd(i, v, 0, 0, size);
    }
    pair<ll, ll> get(ll v, ll x, ll lx, ll rx) {
        if (rx - lx == 1) return {tree[x].val, tree[x].id};
        ll m = (lx + rx) / 2;
        if (tree[2 * x + 1].val >= v) return get(v, 2 * x + 1, lx, m);
        return get(v, 2 * x + 2, m, rx);
    }
    pair<ll, ll> get(ll v) {
        if (tree[0].val < v) return {0, 0};
        return get(v, 0, 0, size);
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
        ll v;
        cin >> v;
        pair<ll, ll> i = st.get(v);
        cout << i.second << ' ';
        if (i.second != 0) st.upd(i.second - 1, i.first - v);
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
