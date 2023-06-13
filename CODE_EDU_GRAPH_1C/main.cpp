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
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a (k);
        forup(i, 0, k) cin >> a[i];

        um<int, um<int, bool> > paths;

        bool isValid = true;
        forup(i, 0, m) {
            int u, v;
            cin >> u >> v;

            if (u > n || v > n) isValid = false;

            paths[u][v] = true;
            paths[v][u] = true;
        }

        if (k == 1) isValid = false;
        forup(i, 1, k) {
            if (!paths[a[i - 1]][a[i]]) isValid = false;
        }
        if (!isValid) {
            cout << "none" << fendl;
            continue;
        }

        if (a.front() == a.back()) {
            // cycle
            um<int, bool> seen;
            bool isSimple = true;

            forup (i, 0, k - 1) {
                if (seen[a[i]]) isSimple = false;
                seen[a[i]] = true;
            }
            cout << (isSimple ? "simple cycle" : "cycle") << fendl;
        } else {
            um<int, bool> seen;
            bool isSimple = true;

            forup (i, 0, k) {
                if (seen[a[i]]) isSimple = false;
                seen[a[i]] = true;
            }
            cout << (isSimple ? "simple path" : "path") << fendl;
        }
    }
    return 0;
}
