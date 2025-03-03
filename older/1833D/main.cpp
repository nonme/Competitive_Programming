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

/*
9
5     1
2 3 1 5 4
9      2
4 1 6 7 2 8 5 3 9
4      3
4 3 2 1
2      4
2 1
6      5
3 2 4 1 5 6
7       6
3 2 1 5 7 6 4
10       7
10 2 5 6 1 9 3 8 4 7
4       8
4 2 1 3
1         9
1
*/
int main() {
    nonme;
    //setIO("cownomics");

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int maxNum = 0;
        int pos = -1;
        bool skip = true;
        FOR(i, 0, n) {
            cin >> a[i];
            if (a[i] != n - i) {
                skip = false;
            }
            if (!skip) {
                if (a[i] > maxNum) {
                    maxNum = a[i];
                    pos = i;
                }
            }
        }
        if (skip || pos == -1) {
            cout << a[n - 1] << " ";
            FOR(i, 1, n) cout << a[i] << " ";
            cout << fendl;
        } else {
            int r = pos - 1;
            int l = r;
            while (l - 1 >= 0 && a[l - 1] <= a[l]) {
                l--;
            }
            FOR (i, r + 1, n) cout << a[i] << " ";
            cout << "    ";
            FORd (i, r, l) cout << a[i] << " ";
            cout << "    ";
            FOR (i, 0, l) cout << a[i] << " ";
            cout << fendl;
        }
    }
    return 0;
}
