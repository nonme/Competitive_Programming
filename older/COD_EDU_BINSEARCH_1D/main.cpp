//#pragma GCC optimize("O3","unroll-loops")
//#pragma GCC target ("avx2")

#include <bits/stdc++.h>

#define fendl "\n"
#define sz(x) (int) size(x)
#define all(v) v.begin(), v.end()

#define ll long long
#define pll pair<long, long>
#define vll vector<long long>

#define um unordered_map

#define debug(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

#define foru(i, start, end) for(int i = start; i < end; ++i)
#define ford(i, start, end) for(int i = start; i >= end; --i)

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

// ----------- ACTUAL PROGRAM START -----------

template <typename T>
T binSearch(const vector<T>& v, T val, bool leftSearch = true) {
    T l = -1, r = v.size();
    while (r - l > 1) {
        T mid = (r + l) / 2;

        if (leftSearch) {
            if (v[mid] >= val) r = mid;
            else l = mid;
        } else {
            if (v[mid] > val) r = mid;
            else l = mid;
        }
    }

    return l;
}

int main() {
    nonme;
    //setIO("cownomics");
    int n;
    cin >> n;
    vll a (n);
    foru(i, 0, n) cin >> a[i];
    sort(all(a));
    int k;
    cin >> k;
    while (k--) {
        int f, t;
        cin >> f >> t;
        ll l = binSearch<ll>(a, f);
        ll r = binSearch<ll>(a, t, false);

        cout << (r == l ? 0 : r - l  )<< " ";
    }
    return 0;
}
