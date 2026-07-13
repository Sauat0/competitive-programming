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

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> g[i][0];
    for (int k = 1; k < LOG; ++k) {
        for (int i = 1; i <= n; ++i) {
            g[i][k] = g[g[i][k - 1]][k - 1];
        }
    }
    while (q--) {
        int u, k;
        cin >> u >> k;
        for (int b = LOG - 1; b >= 0; b--) {
            if ((k >> b) & 1) u = g[u][b];
        }
        cout << u << '\n';
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
