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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    a[0] = min(b[0] - a[0], a[0]);
    for (int i = 1; i < a.size(); ++i) {
        int l = -1, r = b.size();
        while (r - l > 1) {
            int m = (l + r) / 2;
            int cand = b[m] - a[i];

            if (cand >= a[i - 1]) {
                r = m;
            } else {
                l = m;
            }
        }
        if (r == b.size()) {
            r--;
        }
        int b_res = b[r];
        int cand = b_res - a[i];
        if (a[i] < a[i - 1]) {
            a[i] = cand;
            continue;
        }

        int prev = a[i - 1];
        int opt1 = b_res - a[i];
        int opt2 = a[i];

        if (opt1 < opt2 && opt1 >= prev) {
            a[i] = opt1;
        } else {
            a[i] = opt2;
        }
    }
    bool isSorted = true;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] < a[i - 1]) {
            isSorted = false;
            break;
        }
    }
    cout << (isSorted ? "YES" : "NO") << endl;
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
