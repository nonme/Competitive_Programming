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
    int m, a, b, c;
    cin >> m >> a >> b >> c;

    int result = 0;
    if (a <= m) {
        result += a;

        int diff = m - a;
        if (c >= diff) {
            result = m;
            c -= diff;
        } else {
            result += c;
            c = 0;
        }
    } else
        result = m;

    if (b <= m) {
        result += b;

        int diff = m - b;
        if (c >= diff) {
            result += m - b;
            c -= diff;
        } else {
            result += c;
            c = 0;
        }
    } else
        result += m;

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
