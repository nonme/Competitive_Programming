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
    vector<int> a(n);
    vector<int> b(m);
    for (auto& ai : a) cin >> ai;
    for (auto& bi : b) cin >> bi;

    ll result = 0;
    ll cnt = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        if (i > 0 && a[i] == a[i - 1])
            result += cnt;
        else
            cnt = 0;

        while (j < m && b[j] <= a[i]) {
            if (a[i] == b[j]) {
                result++;
                cnt++;
            }
            j++;
        }
    }
    cout << result;
}

int main() {
    fast_io;
    int t = 1;
    // cin >> t;  // раскомментируйте если нужно считать количество тестов
    while (t--) solve();
    return 0;
}

// Ctrl + Shift + B -> build & run
// Ctrl + Shift + P -> Tasks: run task -> build & run with input (for input.txt)
