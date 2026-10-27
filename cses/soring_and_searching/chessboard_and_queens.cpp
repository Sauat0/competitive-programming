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

const ll INF = 1e18;
const int LOG = 24;
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll mod2 = 998244353;
const ull pHash = 1000003;

int ans = 0;
char a[8][8];
bool col[8], d1[20], d2[20];

void get(int r) {
    if (r == 8) {
        ans++;
        return;
    }
    for (int c = 0; c < 8; ++c) {
        if (col[c] || d1[r + c] || d2[r - c + 10] || a[r][c] == '*') continue;
        col[c] = d1[r + c] = d2[r - c + 10] = true;
        get(r + 1);
        col[c] = d1[r + c] = d2[r - c + 10] = false;
    }
}

void solve() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) cin >> a[i][j];
    }
    get(0);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // compute();

    ll tt = 1;
    // cin >> tt;
    while (tt--) solve();
}
