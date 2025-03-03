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
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for (auto& ai : a) cin >> ai;

    ll l = 0, r = 0;
    ll sum = 0;
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        while (sum > s) {
            sum -= a[l];
            l++;
        }
        result = max(result, i - l + 1);
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
