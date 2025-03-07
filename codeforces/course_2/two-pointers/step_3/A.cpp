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
    ll pos = 0, result = -1;
    ll sum = 0;

    vector<ll> prefix_sum(n);
    prefix_sum[0] = a[0];
    FOR(i, 1, n) { prefix_sum[i] = a[i] + prefix_sum[i - 1]; }

    ll loops = k / prefix_sum[n - 1];
    k = k % prefix_sum[n - 1];
    if (k != 0) {
        for (ll R = 0; R < 2 * n; ++R) {
            ll r = R % n;
            l = l % n;
            sum += a[r];
            while (sum >= k && l <= R) {
                // cout << l << " " << r << " " << R << " " << sum << endl;
                if (result == -1 || abs(R - l + 1) < result) {
                    result = abs(R - l + 1);
                    pos = l;
                }
                sum -= a[l];
                l++;
                l %= n;
            }
        }
    } else
        result = 0;
    cout << pos + 1 << " " << result + n * loops;
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