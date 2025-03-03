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

vector<ll> dp;

int main() {
    nonme;
    //setIO("cownomics");
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        int powers = 0;

        int num = n;
        while (num != 1) {
            num /= 2;
            powers++;
        }
        if (k > powers) {
            cout << n + 1 << fendl;
        } else {
            int ans = 0;
            for (int i = 0; i < k; ++i) {
                ans += pow(2, i);
            }
            cout << ans + 1 << fendl;
        }
    }
    return 0;
}
