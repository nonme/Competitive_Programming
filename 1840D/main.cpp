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
        int a_size = a.size();

        int l_bound = 0;
        int l_min = 99999999;

        for (int i = 1; i <= a[a_size - 1]; ++i) {
            int res = 0;
            for (int j = 0; j < n; ++j) {
                res += abs(a[j] - i);
            }
            debug(i);
            debug(res);
            if (res < l_min) {
                l_bound = i;
                l_min = res;
            }
        }
        int f_value = (l_bound + a[0]) / 2;
        debug(f_value);

        int r_bound = 0;
        int r_min = 99999999;
        for (int i = 1; i <= a[a_size - 1]; ++i) {
            int res = 0;
            for (int j = 0; j < n; ++j) {
                res += min(abs(a[j] - f_value), abs(a[j] - i));
            }
            if (res < r_min) {
                r_bound = i;
                r_min = res;
            }
        }
        int s_value = (r_bound + a[a_size - 1]) / 2;

        int f_index = 0, s_index = 0;
        FOR(i, 0, n) {
            if (a[i] == f_value) {
                f_index = i;
            }
            if (a[i] == s_value) {
                s_index = i;
                break;
            }
        }
        int answer = 0;
        FOR(i, 0, f_index + 1) {
            answer = max(answer, abs(f_value - a[i]));
        }
        int m_value = (a[f_index + 1] + a[s_index - 1]) / 2;
        FOR(i, 0, f_index + 1) {
            answer = max(answer, abs(m_value - a[i]));
        }
        FOR(i, s_index, n) {
            answer = max(answer, abs(s_value - a[i]));
        }
        cout << answer << fendl;
    }
    return 0;
}
//9 14 19 37 59 1 4 4 98 73
