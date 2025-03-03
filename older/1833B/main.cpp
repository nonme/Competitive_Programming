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

bool comp(pll a, pll b) {
    if (a.first == b.first) {
        return a.first < b.first;
    }
    return a.first < b.first;
}

int main() {
    nonme;
    //setIO("cownomics");
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pll> a (n);
        vector<pll> b (n);
        FOR(i, 0, n) {
            cin >> a[i].first;
            a[i].second = i;
        }
        FOR(i, 0, n) {
            cin >> b[i].first;
            b[i].second = i;
        }
        sort (a.begin(), a.end(), comp);
        sort (b.begin(), b.end(), comp);

        vector<ll> answer (n);
        FOR(i, 0, n) {
            answer[a[i].second] = b[i].first;
        }
        FOR (i, 0, n) {
            cout << answer[i] << " ";
        }
        cout << fendl;
    }
    return 0;
}
