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
    int n, d;
    cin >> n >> d;

    cout << 1 << " ";
    if (n >= 3 || d % 3 == 0) cout << 3 << " ";

    if (d == 5) cout << 5 << " ";

    if (n >= 3 || d == 7) cout << 7 << " ";

    if (d == 9 || (n >= 3 && d % 3 == 0) || n >= 6) cout << 9 << " ";

    cout << endl;
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
