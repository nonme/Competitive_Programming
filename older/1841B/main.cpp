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

#define forup(i, start, end) for(int i = start; i < end; ++i)
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

int main() {
    nonme;
    //setIO("cownomics");
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        int f = 0;
        int s = 0;
        bool isSecond = false;
        int fLast = 0;
        int sLast = 0;
        for (int i = 0; i < q; ++i) {
            int n;
            cin >> n;

            if (i == 0) {
                f = n;
                fLast = n;
                cout << "1";
            } else {
                if (isSecond) {
                    if (n >= sLast && n <= f) {
                        cout << "1";
                        sLast = n;
                    } else cout << "0";
                } else {
                    if (n >= fLast) {
                        cout << "1";
                        fLast = n;
                    } else if (n <= f && !isSecond) {
                        s = n;
                        sLast = n;
                        isSecond = true;
                        cout << "1";
                    } else cout << "0";
                }
            }
        }
        cout << fendl;
    }
    return 0;
}
