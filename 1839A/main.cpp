//#pragma GCC optimize("O3","unroll-loops")
//#pragma GCC target ("avx2")

#include <bits/stdc++.h>

#define fendl "\n"
#define sz(x) (int) size(x)

#define ll long long
#define vll vector<long long>
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
        int n, k;
        cin >> n >> k;

        int result = 0;
        int last_index = 0;
        for (int i = 0; i < n; i+=k) {
            result++;
            last_index = i;
        }
        if ((n - 1) - last_index > 0) result++;
        cout << result << fendl;
    }
    return 0;
}
