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
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a (n);
        FOR(i, 0, n) cin >> a[i];
        ll answer = 0;
        int curLen = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] <= q) {
                curLen++;
            } else {
                if (curLen >= k) {
                    double len = curLen - k + 1;
                    double sum = double(1 + len) / 2.0 * len;
                    answer += sum;
                }
                curLen = 0;
            }
        }
        if (curLen >= k) {
            double len = curLen - k + 1;
            double sum = double(1 + len) / 2.0 * len;
            answer += sum;
        }
        cout << answer << fendl;
    }
    return 0;
}
