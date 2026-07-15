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
const int LOG = 30;
const int maxn = 2e5 + 10;
const ll MOD = 1e9 + 7;
const ll mod2 = 998244353;
const ull pHash = 1000003;

ll szz[maxn];
ll p[maxn];

ll find(ll u) {
    if (p[u] == u) return u;
    return p[u] = find(p[u]);
}

void unite(ll u, ll v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (szz[v] >= szz[u]) swap(u, v);
    szz[u] += szz[v];
    p[v] = u;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    ll cur = n, mx = 1;
    for (ll i = 1; i <= n; ++i) {
        p[i] = i;
        szz[i] = 1;
    }
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        if (find(u) == find(v)) {
            cout << cur << ' ' << mx << '\n';
            continue;
        }
        unite(u, v);
        cur--;
        mx = max(mx, szz[find(u)]);
        cout << cur << ' ' << mx << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
