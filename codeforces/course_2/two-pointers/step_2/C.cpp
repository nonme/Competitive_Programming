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

    ll cnt = 0;
    ll sum = 0;
    ll l = 0;
    for (ll r = 0; r < n; ++r) {
        sum += a[r];
        while (l <= r && sum > s) {
            sum -= a[l];
            l++;
        }
        if (sum <= s) cnt += (r - l + 1);
    }
    cout << cnt << endl;
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
