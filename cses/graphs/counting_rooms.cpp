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

ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};

void solve() {
    ll n, m, cnt = 0;
    cin >> n >> m;
    vector<vector<char>> g(n+2, vector<char>(m + 2, '#'));
    vector<vector<bool>> vis(n+2, vector<bool>(m+2, false));
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) {
            cin >> g[i][j];
        }
    }
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) {
            if(g[i][j] == '#' || vis[i][j]) continue;
            queue<pair<ll, ll>> q;
            q.push({i, j});
            vis[i][j] = 1;
            cnt++;
            while(!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                for(ll i = 0; i < 4; ++i) {
                    ll x = r + dx[i];
                    ll y = c + dy[i];
                    if(g[x][y] == '#' || vis[x][y]) continue;
                    vis[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
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
