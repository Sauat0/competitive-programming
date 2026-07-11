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
    vector<vector<char>> g(n + 2, vector<char>(m + 2, '#'));
    vector<vector<bool>> vis(n + 2, vector<bool>(m + 2, false));
    vector<vector<char>> mem(n + 2, vector<char>(m + 2, '-'));
    queue<tuple<ll, ll, ll, char>> q;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 'A') q.push({i, j, 0, '-'});
        }
    }
    while (!q.empty()) {
        auto [i, j, d, dir] = q.front();
        q.pop();
        mem[i][j] = dir;
        if (g[i][j] == 'B') {
            cout << "YES\n"
                 << d << '\n';
            string ans;
            while (g[i][j] != 'A') {
                ans.pb(mem[i][j]);
                if (mem[i][j] == 'R')
                    j--;
                else if (mem[i][j] == 'L')
                    j++;
                else if (mem[i][j] == 'U')
                    i++;
                else
                    i--;
            }
            reverse(all(ans));
            cout << ans << '\n';
            return;
        }
        for (ll k = 0; k < 4; ++k) {
            ll x = i + dx[k];
            ll y = j + dy[k];
            if (g[x][y] == '#' || vis[x][y]) continue;
            vis[x][y] = 1;
            char nxt;
            if (k == 0) nxt = 'U';
            if (k == 1) nxt = 'D';
            if (k == 2) nxt = 'L';
            if (k == 3) nxt = 'R';
            q.push({x, y, d + 1, nxt});
        }
    }
    cout << "NO\n";
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
