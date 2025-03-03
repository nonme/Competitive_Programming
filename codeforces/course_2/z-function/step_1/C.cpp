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
    string t, p;
    cin >> t >> p;

    list<int> indexes;
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] == p[0] || p[0] == '?') {
            bool found = true;
            for (int j = 0; j < p.size(); ++j) {
                if (i + j >= t.size() || (t[i + j] != p[j] && p[j] != '?')) {
                    found = false;
                    break;
                }
            }
            if (found) {
                indexes.push_back(i);
            }
        }
    }
    cout << indexes.size() << endl;
    for (const auto& i : indexes) cout << i << " ";
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
