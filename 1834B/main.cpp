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
        string l, r;
        cin >> l >> r;

        int lSize = l.size();
        int rSize = r.size();

        ll answer = 0;
        int l_i = 0;
        int r_i = 0;
        bool lead = false;

        if (lSize > rSize) {
            r.insert(0, string(lSize - rSize, '0'));
        } else if (rSize > lSize) {
            l.insert(0, string(rSize - lSize, '0'));
        }

        while (l[l_i] == r[r_i]) {
            l_i++;
            r_i++;
        }
        if (l_i < lSize && r_i < rSize) {
            answer += abs(l[l_i] - r[r_i]);
            l_i++;
            r_i++;
        }
        while (l_i < lSize || r_i < rSize) {
            answer += 9;
            l_i++;
            r_i++;
        }
        cout << answer << fendl;
    }
    return 0;
}
