//#pragma GCC optimize("O3","unroll-loops")
//#pragma GCC target ("avx2")

#include <bits/stdc++.h>

#define fendl "\n"
#define sz(x) (int) size(x)
#define all(v) v.begin(), v.end()

#define ll long long
#define pll pair<long, long>
#define vll vector<long long>
#define vpll vector<pair<long long, long long> >

#define um unordered_map

#define debug(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

#define forup(i, start, end) for(int i = start; i < end; ++i)
#define ford(i, start, end) for(int i = start; i >= end; --i)

#define fori(start, end) for(int i = start; i < end; ++i)
#define forj(start, end) for(int j = start; j < end; ++i)
#define forc(start, end) for(int c = start; c < end; ++c)

#define tests int TEST_COUNT_; cin >> TEST_COUNT_; while(TEST_COUNT_--)

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

// sorts to (1, 3) -> (1, 4) -> (2, 5) -> (2, 6)
bool defpcomp(pll a, pll b) {
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}
// ----------- ACTUAL PROGRAM START -----------

int main() {
    nonme;
    //setIO("cownomics");
    tests {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        int l_dif = 0, r_dif = 0;

        fori (0, n) {
            if (a[i] != b[i]) l_dif++;
            if (a[i] != b[n - i - 1]) r_dif++;
        }

        int answer = min(
            2 * l_dif - (l_dif % 2),
            2 * r_dif - (1 - r_dif % 2));

        if (l_dif == r_dif && l_dif == 0) cout << "0" << fendl;
        else if (r_dif == 0) {
            cout << "2" << fendl;
        } else cout << answer << fendl;
    }
    return 0;
}
