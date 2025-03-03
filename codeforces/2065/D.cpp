#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<ll> > a(n, vector<ll>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<pair<ll, int> > sums(n);
    for (int i = 0; i < n; ++i) {
        ll sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += a[i][j];
        }
        sums[i] = {sum, i};
    }

    sort(sums.rbegin(), sums.rend());

    vector<ll> one(n * m);
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        int index = sums[i].second;
        for (int j = 0; j < m; ++j) {
            one[pos++] = a[index][j];
        }
    }

    ll result = 0;
    ll prefix = 0;
    for (int i = 0; i < one.size(); ++i) {
        prefix += one[i];
        result += prefix;
    }

    cout << result << endl;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;  // раскомментируйте если нужно считать количество тестов
    while (t--) solve();
    return 0;
}

// Ctrl + Shift + B -> build & run
// Ctrl + Shift + P -> Tasks: run task -> build & run with input (for input.txt)
