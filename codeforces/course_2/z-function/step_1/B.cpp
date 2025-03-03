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

    int result = 0;
    for (int i = 0; i < s.size(); ++i) {
        string prefix = s.substr(0, i);
        string suffix = s.substr(s.size() - i, i);

        if (prefix == suffix) continue;

        // cout << "prefix: " << prefix << " suffix: " << suffix << endl;
        size_t indx = 0;
        while (indx != string::npos && prefix.size() > 0) {
            indx = s.find(prefix, indx);
            if (indx != string::npos) {
                result++;
                indx++;
            }
        }

        indx = 0;
        while (indx != string::npos && suffix.size() > 0) {
            indx = s.find(suffix, indx);
            if (indx != string::npos) {
                result++;
                indx++;
            }
        }
    }
    // for (const auto& r : results) cout << r << " ";
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
