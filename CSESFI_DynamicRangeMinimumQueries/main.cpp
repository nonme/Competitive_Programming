//#pragma GCC optimize("O3","unroll-loops")
//#pragma GCC target ("avx2")

#include <bits/stdc++.h>

typedef long long ll;

constexpr ll mod = 998244353;
const int mod17 = 1000000007;
const ll INF = mod * mod;

#define fendl "\n"
#define sz(x) (int) size(x)
#define all(v) v.begin(), v.end()

#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vector<long long> >
#define vvvll vector<vector<vector<ll> > >
#define vpll vector<pair<ll, ll> >

#define um unordered_map

#define debug(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

#define forup(i, start, end) for(int i = start; i < end; ++i)
#define ford(i, start, end) for(int i = start; i >= end; --i)

#define fori(start, end) for(int i = start; i < end; ++i)
#define forj(start, end) for(int j = start; j < end; ++j)
#define forc(start, end) for(int c = start; c < end; ++c)

#define fordi(start, end) for(int i = end - 1; i >= 0; --i)
#define fordj(start, end) for(int j = end - 1; j >= 0; --j)
#define fordc(start, end) for(int c = end - 1; c >= 0; --c)

#define read(ARRAY) for(int i__ = 0; i__ < ARRAY.size(); ++i__) cin >> ARRAY[i__];
#define print(ARRAY) for(int i__ = 0; i__ < ARRAY.size(); ++i__) cout << ARRAY[i__] << " "; cout << fendl;

#define tests int TEST_COUNT_; cin >> TEST_COUNT_; while(TEST_COUNT_--)

#define nonme ios::sync_with_stdio(false); cin.tie(nullptr);

/*
    Useful links
    https://codeforces.com/blog/entry/15547 Compiler options
    -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -Wduplicated-cond -Wlogical-op
    C:\Program Files\CodeBlocks\share\CodeBlocks\templates\wizard\console\cpp\main.cpp <- to change this code

*/

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

// sorts to (1, 3) -> (1, 4) -> (2, 5) -> (2, 6)
bool defpcomp(pll a, pll b) {
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}
// ----------- ACTUAL PROGRAM START -----------

vector<ll> tree;
void bst(int node, int l, int r, const vll& a) {
    if (l == r)
        tree[node] = a[l];
    else {
        int m = (r + l) / 2;
        bst(2 * node, l, m, a);
        bst(2 * node + 1, m + 1, r, a);

        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}
void bst(const vll& a) {
    tree.assign(4 * a.size(), INF);
    bst(1, 0, a.size(), a);
}

void update(int node, int l, int r, int index, ll value) {
    if (l == r)
        tree[node] = value;
    else {
        int m = (r + l) / 2;
        if (index <= m) update(2 * node, l, m, index, value);
        else update(2 * node + 1, m + 1, r, index, value);

        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}

ll get(int node, int l, int r, int tl, int tr) {
    if (tl > r || tr < l) return INF;
    if (l <= tl && tr <= r) return tree[node];

    int m = (tl + tr) / 2;

    ll left_val = get(2 * node, l, r, tl, m);
    ll right_val = get(2 * node + 1, l, r, m + 1, tr);

    return min(left_val, right_val);
}

int main() {
    nonme;
    //setIO("cownomics");

    int n, q;
    cin >> n >> q;
    vector<ll> a (n);
    read(a);
    bst(a);

    while(q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
            update(1, 0, n, l - 1, r);
        else cout << get(1, l - 1, r - 1, 0, n) << fendl;
    }
    return 0;
}
