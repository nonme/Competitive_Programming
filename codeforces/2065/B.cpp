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

    bool isSame = false;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            isSame = true;
        }
    }
    if (isSame)
        cout << "1" << endl;
    else
        cout << s.size() << endl;
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
