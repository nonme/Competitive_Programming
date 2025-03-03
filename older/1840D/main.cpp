//#pragma GCC optimize("O3","unroll-loops")
//#pragma GCC target ("avx2")

#include <bits/stdc++.h>

#define fendl "\n"
#define sz(x) (int) size(x)

#define ll long long
#define pll pair<long, long>
#define vll vector<long long>

#define um unordered_map

#define debug(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

#define FOR(i, start, end) for(int i = start; i < end; ++i)
#define FORd(i, start, end) for(int i = start; i >= end; --i)

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

int main() {
    nonme;
    //setIO("cownomics");
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a (n);
        FOR(i, 0, n) cin >> a[i];
        sort (a.begin(), a.end());

        int l = 0, r = a.back();
        while (r - l > 1) {
            int m = (r + l) / 2;
            //debug(m);
            int prefix_score = 0;
            int suffix_score = 0;
            int mid_score = 0;

            int i = 0;
            while (i < n && prefix_score < m) {
                prefix_score = abs((a[i] - a[0] + 1) / 2);
                if (prefix_score < m) i++;
            }
            //debug(i);
            //debug(prefix_score);
            if (i == n) {
                r = m;
                continue;
            }
            int j = n - 1;
            while (j > i && suffix_score < m) {
                suffix_score = abs((a[n - 1] - a[j] + 1) / 2);
                if (suffix_score < m) j--;
            }
            //debug(j);
            //debug(suffix_score);
            if (j == i) {
                r = m;
                continue;
            }
            for (int c = i; c <= j; ++c) {
                mid_score = max(mid_score, abs((a[j] - a[c] + 1) / 2));
            }
            //debug(mid_score);
            if (mid_score >= m) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << l << fendl;
    }
    return 0;
}
// 9 14 19 37 59 1 4 4 98 73
// 11 17 19 12 12 3 9 17 12 4 14 3
