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

ll indexOfMin(const vector<ll>& v) {
    int result = 0;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] < v[result]) {
            result = i;
        }
    }
    return result;
}

ll min(const vector<ll>& v) { return v[indexOfMin(v)]; }

ll indexOfMax(const vector<ll>& v) {
    int result = 0;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > v[result]) {
            result = i;
        }
    }
    return result;
}

ll max(const vector<ll>& v) { return v[indexOfMax(v)]; }

void solve() {
    ll n1, n2, n3, n4;
    cin >> n1;
    vector<ll> a(n1);
    for (auto& ai : a) cin >> ai;
    cin >> n2;
    vector<ll> b(n2);
    for (auto& bi : b) cin >> bi;
    cin >> n3;
    vector<ll> c(n3);
    for (auto& ci : c) cin >> ci;
    cin >> n4;
    vector<ll> d(n4);
    for (auto& di : d) cin >> di;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());

    vector<ll> l(4, 0);
    vector<ll> results(4, 0);
    ll minDif = LLONG_MAX;

    while (l[0] < n1 && l[1] < n2 && l[2] < n3 && l[3] < n4) {
        ll currentMin = min({a[l[0]], b[l[1]], c[l[2]], d[l[3]]});
        ll currentMax = max({a[l[0]], b[l[1]], c[l[2]], d[l[3]]});
        ll currentDif = currentMax - currentMin;
        if (currentDif < minDif) {
            minDif = currentDif;
            results = {a[l[0]], b[l[1]], c[l[2]], d[l[3]]};
        }
        ll indexOfCurrentMin = indexOfMin({a[l[0]], b[l[1]], c[l[2]], d[l[3]]});
        l[indexOfCurrentMin]++;
    }

    for (auto result : results) {
        cout << result << " ";
    }
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
