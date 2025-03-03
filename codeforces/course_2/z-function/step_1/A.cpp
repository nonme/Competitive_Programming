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
    string s;
    cin >> s;

    for (int i = s.size() - 1; i >= 1; i--) {
        int j = 0;
        int c = i;
        while (s[c] == s[j] && j <= c) {
            j++;
            c--;
        }
        if (j > c) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << 1 << endl;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;  // раскомментируйте если нужно считать количество тестов
    while (t--) solve();
    return 0;
}

// Ctrl + Shift + B -> build & run
// Ctrl + Shift + P -> Tasks: run task -> build & run with input (for
// input.txt)
