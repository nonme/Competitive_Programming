#include <bits/stdc++.h>

#define fendl "\n"
#define sz(x) (int) size(x)

#define ll long long
#define vl vector<long long>
#define um unordered_map

#define debug(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define fori(start, end) for(int i = start; i < end; ++i)
#define forj(start, end) for(int j = start; j < end; ++j)

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

        vector<int> a (n, 0);
        fori(0, n) {
            cin >> a[i];
        }
        if (a[n - 1] == 1) {
            cout << "NO" << fendl;
            continue;
        }

        vector<int> steps (n, 0);
        int si = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] != a[i - 1]) {
                steps[si] = i;
                si++;
            }
        }
        cout << "YES" << fendl;
        fori (0, n - si ) cout << "0 ";
        for (int i = 0; i < si; ++i) {
            cout << steps[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
