#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

multiset<int> orig;
vector<pii> ans;

bool check(multiset<int>& copy, int mx, int n) {
    while (!copy.empty()) {
        int sum = mx;
        auto maxit = copy.rbegin();
        mx = *maxit;
        copy.erase(copy.find(mx));
        if (copy.find(sum - mx) == copy.end()) break;
        ans.pb({mx, sum - mx});
        copy.erase(copy.find(sum - mx));
    }
    if (sz(ans) == n / 2) {
        cout << "YES\n";
        cout << ans.front().first + ans.front().second << '\n';
        for (auto it : ans) cout << it.first << ' ' << it.second << '\n';
        return true;
    }
    return false;
}

void runcase() {
    int n;
    cin >> n;
    orig.clear();
    ans.clear();
    n *= 2;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        orig.insert(v[i]);
    }
    sort(all(v));
    for (int i = 0; i < n - 1; i++) {
        ans.pb({v[i], v[n - 1]});
        multiset<int> copy = orig;
        copy.erase(copy.find(v[i]));
        copy.erase(copy.find(v[n - 1]));
        if (check(copy, v[n - 1], n)) return;
        ans.clear();
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcases = 1;
    cin >> testcases;

    while (testcases--) runcase();

    return 0;
}
