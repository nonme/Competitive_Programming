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
    vector<ll> w(n);
    for (auto& wi : w) cin >> wi;
    vector<ll> c(n);
    for (auto& ci : c) cin >> ci;

    ll l = 0, maxCost = 0, currentCost = 0, currentWeight = 0;
    for (ll r = 0; r < n; ++r) {
        currentCost += c[r];
        currentWeight += w[r];
        while (currentWeight > s) {
            currentCost -= c[l];
            currentWeight -= w[l];
            l++;
        }
        maxCost = max(maxCost, currentCost);
    }
    cout << maxCost;
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
