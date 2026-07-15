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
 
int g[maxn][LOG];
vll gv[maxn];
int cyc[maxn];
vll cycnum(maxn, -1);
int szcyc[maxn];
int d[maxn];
bool vis[maxn];
int cur = 0;
 
void dfs(ll u, ll dd) {
    cyc[u] = cur;
    d[u] = dd;
    for (auto& c : gv[u]) {
        if (!vis[c] && cycnum[c] == -1) {
            dfs(c, dd + 1);
        }
    }
}
 
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> g[i][0];
        gv[g[i][0]].pb(i);
    }
    for (int k = 1; k < LOG; ++k) {
        for (int i = 1; i <= n; ++i) {
            g[i][k] = g[g[i][k - 1]][k - 1];
        }
    }
 
    for (int i = 1; i <= n; ++i) {
        ll u = i;
        for (int k = 0; k < LOG; ++k) {
            if (n & (1 << k)) u = g[u][k];
        }
        if (cycnum[u] == -1) {
            ll a = g[u][0], b = g[u][1], cnt = 0;
            cur++;
            while (a != b) {
                a = g[a][0];
                b = g[b][1];
            }
            cycnum[a] = 0;
            b = g[a][0];
            while (a != b) {
                cycnum[b] = ++cnt;
                b = g[b][0];
            }
            b = g[a][0];
            while (a != b) {
                // cout << a << ' ' << b << '\n';
                dfs(b, 0);
                b = g[b][0];
            }
            szcyc[cur] = ++cnt;
            dfs(a, 0);
        }
    }
 
    // cout << g[3][0] << '\n';
    for (ll i = 1; i <= n; ++i) {
        cout << d[i] + szcyc[cyc[i]] << ' ';
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
