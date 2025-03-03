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

int solve(const string& s, const string& t) {
    int result = 0;
    int i = 0;
    int j = 0;
    int currentSubstrLength = 0;
    while (i < s.size()) {
        cout << i << " " << s[i] << " " << j << " " << t[j] << endl;
        if (s[i] != t[j]) {
            i -= j;
            currentSubstrLength -= j;
            j = 0;
        }

        if (s[i] == t[j]) j++;

        if (j < t.size()) currentSubstrLength++;

        if (j == t.size()) {
            j = 0;

            result += (currentSubstrLength * currentSubstrLength +
                       currentSubstrLength) /
                      2;

            if (t.size() > 2) {
                int tmp = t.size() - 2;
                result -= (tmp * tmp + tmp) / 2;
            }

            cout << i << " " << j << " " << currentSubstrLength << " " << result
                 << endl;

            currentSubstrLength = 0;
            i = i - t.size() + 1;
        }
        i++;
    }
    result +=
        (currentSubstrLength * currentSubstrLength + currentSubstrLength) / 2;

    return result;
}

int solve2(const string& s, const string& t) {
    int result = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 1; j < s.size() - i + 1; ++j) {
            size_t searchResult = s.find(t, i);
            if (j < t.size() || searchResult == string::npos ||
                searchResult + t.size() > i + j) {
                // cout << i << " " << j << " " << s.substr(i, j) << endl;
                result++;
            }
        }
    }
    return result;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;  // раскомментируйте если нужно считать количество тестов
    int cnt = 0;
    while (t--) {
        string s, t;
        cin >> s >> t;
        int result1 = solve(s, t);
        int result2 = solve2(s, t);

        if (result1 != result2) {
            cout << result1 << " " << result2 << endl;
            cout << s << " " << t << endl;
            cnt++;
        }
    }
    if (cnt == 0) cout << "OK" << endl;
    return 0;
}

// Ctrl + Shift + B -> build & run
// Ctrl + Shift + P -> Tasks: run task -> build & run with input (for input.txt)
