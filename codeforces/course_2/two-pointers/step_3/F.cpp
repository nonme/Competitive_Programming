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
    ll n, m;
    cin >> n >> m;
    std::string s;
    cin >> s;
    std::string t;
    cin >> t;

    unordered_map<char, ll> cnt;
    unordered_map<char, ll> cntMax;
    for (auto c : t) {
        cnt[c]++;
        cntMax[c]++;
    }

    ll l = 0, result = 0;
    for (ll r = 0; r < n; ++r) {
        cnt[s[r]]--;

        while (l < r && (cnt[s[r]] < 0 || cnt[s[l]] < 0)) {
            cnt[s[l]]++;
            l++;

            // cnt[s[l]] = min(cnt[s[l]], cntMax[s[l]]);
        }

        if (cnt[s[r]] >= 0) {
            // cout << l << " " << r << endl;
            result += (r - l + 1);
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
