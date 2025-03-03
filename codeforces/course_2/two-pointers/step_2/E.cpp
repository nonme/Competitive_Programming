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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& ai : a) cin >> ai;

    unordered_map<ll, ll> s;
    ll l = 0;
    ll result = 0;
    for (ll r = 0; r < n; ++r) {
        if (s.count(a[r]) == 0) {
            s[a[r]] = 0;
        }
        s[a[r]]++;
        while (s.size() > k) {
            if (s[a[l]] == 1) {
                s.erase(a[l]);
            } else {
                s[a[l]]--;
            }
            l++;
        }
        result += r - l + 1;
    }
    cout << result << endl;
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
