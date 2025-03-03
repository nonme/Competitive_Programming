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

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

struct SegTreeGCD {
    vector<ll> t;
    int n;

    SegTreeGCD(int n) : n(n) { t.resize(4 * n); }

    void build(vector<ll>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = gcd(t[v * 2], t[v * 2 + 1]);
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return t[v];
        int tm = (tl + tr) / 2;
        return gcd(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ai : a) cin >> ai;

    ll l = 0;
    ll result = -1;
    ll g = 0;

    SegTreeGCD st(n);
    st.build(a, 1, 0, n - 1);

    for (ll r = 0; r < n; ++r) {
        g = gcd(a[r], g);
        // cout << l << " " << r << " g: " << g << endl;
        while (l <= r && g == 1) {
            result = result == -1 ? r - l + 1 : min(result, r - l + 1);

            l++;
            g = st.query(l, r);
        }
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
