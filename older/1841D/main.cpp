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

template<typename X, typename Y>
ostream& operator<<(ostream& os, const pair<X, Y>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    bool printIndex = true;
    for (int i = 0; i < v.size(); ++i) {
        os << (printIndex ? (to_string(i) + ": ") : "" ) << v[i] << (i < v.size() - 1 ? fendl : "");
    }
    return os;
}

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

// sorts to (1, 3) -> (1, 4) -> (2, 5) -> (2, 6)
bool defpcomp(pll a, pll b) {
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}

// ----------- ACTUAL PROGRAM START -----------

bool intersect(pll a, pll b) {
    return a.second >= b.first;
}

int main() {
    nonme;
    //setIO("cownomics");
    tests {
        int n;
        cin >> n;
        vpll a (n);
        fori(0, n) {
            cin >> a[i].first >> a[i].second;
        }
        sort(all(a), defpcomp);
        vll dp (n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;
        fori(2, n + 1) {
            if (intersect(a[i - 2], a[i - 1])) {
                dp[i] = max(
                            dp[i - 1],
                            dp[i - 2] + 1);
            } else {
                dp[i] = dp[i - 1];
            }
        }
        cout << dp << fendl;
        cout << dp[n] << fendl;
    }
    return 0;
}
