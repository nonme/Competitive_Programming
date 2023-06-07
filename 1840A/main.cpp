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
        string s;
        cin >> s;
        string res {s[0]};
        char curLet = s[0];
        bool addNext = false;
        for (int i = 1; i < s.size(); ++i) {
            if (addNext) {
                res += s[i];
                addNext = false;
                curLet = s[i];
            }
            else if (s[i] == curLet) {
                addNext = true;
            }
        }
        cout << res << fendl;
    }
    return 0;
}
