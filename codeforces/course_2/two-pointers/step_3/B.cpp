#include <bits/stdc++.h>  // Includes most standard libraries
using namespace std;

// Common type definitions
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Macros for convenience
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

void solve() {
    // Your solution code goes here
    // Example input
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    FOR(i, 0, n) cin >> a[i];

    ll l = 0;
    ll result = 0;
    ll sum = 0;

    for (ll r = 0; r < n; ++r) {
        sum += a[r];
        while (sum > k && l <= r) {
            // cout << l << " " << r << " " << sum << endl;

            sum -= a[l];
            l++;
        }
        result += (r - l + 1) * (r - l + 2) / 2;
        // cout << l << " " << r << " " << result << endl;
    }

    cout << result;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // For multiple test cases
    int t = 1;
    // cin >> t; // Comment this line if single test case
    while (t--) {
        solve();
    }

    return 0;
}