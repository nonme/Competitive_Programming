//#pragma GCC optimize("O3","unroll-loops")
//#pragma GCC target ("avx2")

#include <bits/stdc++.h>

#define fendl endl
#define sz(x) (int) size(x)
#define all(v) v.begin(), v.end()

#define ll long long
#define pll pair<long long, long long>
#define vll vector<long long>
#define vpll vector<pair<long long, long long> >

#define um unordered_map

#define debug(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

#define forup(i, start, end) for(int i = start; i < end; ++i)
#define ford(i, start, end) for(int i = start; i >= end; --i)

#define fori(start, end) for(int i = start; i < end; ++i)
#define forj(start, end) for(int j = start; j < end; ++i)
#define forc(start, end) for(int c = start; c < end; ++c)

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

const ll INF = 1e9+7;

// ----------- ACTUAL PROGRAM START -----------

vector<pll> tree;

void update(int node, int s, int e, int index, ll q_n) {
    //cout << node << " " << s << " " << e << " " << index << " " << q_n << fendl;
    if (s == e) {
        tree[node].first++;
        if (tree[node].first > (e - s) / 2) {
            tree[node].second = min(tree[node].second, q_n);
        }
    } else {
        int mid = (s + e) / 2;
        int value = 0;
        if (index <= mid) {
            update(2 * node, s, mid, index, q_n);
        } else
            update(2 * node + 1, mid + 1, e, index, q_n);
        tree[node].first = tree[2 * node].first + tree[2 * node + 1].first;

        if (tree[node].first > (e - s) / 2)
            tree[node].second = min(tree[node].second, q_n);
    }
}

pll get(int node, int s, int e, int l, int r) {
    cout << node << " " << s << " " << e << " " << l << " " << r << endl;
    if (node == 0) return {0, INF};
    if (s > r || e < l) return {0, INF};
    if (s == l && e == r) return tree[node];

    int mid = (s + e) / 2;
    pll left = get(2 * node, s, mid, l, r);
    pll right = get(2 * node + 1, mid + 1, e, l, r);

    return {left.first + right.first, max(left.second, right.second) };
}

long long query(int node, int s, int e, int l, int r) {
    cout << node << " " << s << " " << e << " " << l << " " << r << endl;
    if (s > r || e < l) return INF;
    if (s == l && e == r) return tree[node].second;

    int mid = (s + e) / 2;
    pll left = get(2 * node, s, mid, l, r);
    pll right = get(2 * node + 1, mid + 1, e, l, r);

    ll sum = left.first + right.first;
    if (sum > (e - s) / 2) {
        return max(left.second, right.second);
    }
    return INF;
}

int main() {
    nonme;
    //setIO("cownomics");

    tests {
        int n, m;
        cin >> n >> m;

        tree.assign(4 * n, {0, INF});

        vector<pll> a(m);
        fori(0, m) cin >> a[i].first >> a[i].second;

        int q, cur = 1;
        cin >> q;
        int q_n = 0;
        while (q--) {
            int t;
            cin >> t;
            q_n++;
            update(1, 0, n, t - 1, q_n);
        }
        //fori(0, 4 * n) cout << tree[i].second << " ";

        ll minQ = INF;
        fori (0, m) {
            ll res = query(1, 0, n, a[i].first - 1, a[i].second - 1);
            minQ = min(res, minQ);
        }
        if (minQ == INF) cout << "-1" << fendl;
        else cout << minQ << fendl;
    }
    return 0;
}
