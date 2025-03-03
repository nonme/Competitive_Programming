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


vll tree_;
int treeSize_;

void __bst__(const int node, const int l, const int r, const vll& v) {
    if (l == r)
        tree_[node] = v[l];
    else {
        int mid = (l + r) / 2;
        __bst__(2 * node, l, mid, v);
        __bst__(2 * node + 1, mid + 1, r, v);

        tree_[node] = tree_[2 * node] + tree_[2 * node + 1];
    }
}

void __ust__(const int node, const int l, const int r, const int index, const ll val) {
    if (l == r)
        tree_[node] = val;
    else {
        int mid = (l + r) / 2;
        if (index <= mid)
            __ust__(2 * node, l, mid, index, val);
        else
            __ust__(2 * node + 1, mid + 1, r, index, val);

        tree_[node] = tree_[2 * node] + tree_[2 * node + 1];
    }
}

ll __gst__(const int node, const int l, const int r, const int tl, const int tr) {
    //cout << node << " " << l << " " << r << " " << tl << " " << tr << fendl;
    if (tl > r || tr < l) return 0;

    if (tl >= l && tr <= r)
        return tree_[node];
    else {
        int mid = (tl + tr) / 2;

        ll left = __gst__(2 * node, l, r, tl, mid);
        ll right = __gst__(2 * node + 1, l, r, mid + 1, tr);

        return left + right;
    }
}

void bst(const vll& v) {
    treeSize_ = v.size();
    tree_.assign(4 * treeSize_, 0);

    __bst__(1, 0, treeSize_, v);
}

void ust(const int i, const ll val) {
    __ust__(1, 0, treeSize_, i, val);
}

ll gst(const int l, const int r) {
    return __gst__(1, l, r, 0, treeSize_);
}

int main() {
    nonme;
    //setIO("cownomics");

    int n, m;
    cin >> n >> m;
    vll a (n);
    read(a);
    //print(a);

    bst(a);
    //print(tree_);

    fori(0, m) {
        int t, f, s;
        cin >> t >> f >> s;
        if (t == 1) ust(f - 1, s);
        else cout << gst(f - 1, s - 1) << fendl;
    }
    return 0;
}
