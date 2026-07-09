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
const int maxn = 2e5 + 10;
const ll MOD = 1e9 + 7;
const ll mod2 = 998244353;
const ull pHash = 1000003;

ll p[maxn];
ll szz[maxn];
vll g[maxn];

ll find(ll u) {
    if (p[u] == u) return u;
    return p[u] = find(p[u]);
}

void unite(ll u, ll v) {
    ll f1 = find(u), f2 = find(v);
    if (f1 == f2) return;
    if (szz[f1] > szz[f2]) {
        szz[f1] += szz[f2];
        p[f2] = f1;
    } else {
        szz[f2] += szz[f1];
        p[f1] = f2;
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) {
        p[i] = i;
        szz[i] = 1;
    }
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    vector<pair<ll, ll>> ans;
    for (ll i = 1; i <= m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        pq.push({w, u, v});
    }
    while (sz(ans) < n - 1) {
        auto [w, u, v] = pq.top();
        pq.pop();
        if (find(u) != find(v)) {
            ans.pb({u, v});
            unite(u, v);
        }
    }

    for (auto& [u, v] : ans) cout << u << ' ' << v << '\n';
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
