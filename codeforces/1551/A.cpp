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
    int n;
    cin >> n;

    if (n % 3 == 0)
        cout << n / 3 << " " << n / 3 << endl;
    else if (n % 3 == 1)
        cout << n / 3 + 1 << " " << n / 3 << endl;
    else
        cout << n / 3 << " " << n / 3 + 1 << endl;
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
