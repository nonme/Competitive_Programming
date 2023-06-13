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

    int n, m;
    cin >> n >> m;
    vector<int> a (n), b (m);
    forup(i, 0, n) cin >> a[i];
    forup(i, 0, m) cin >> b[i];
    vector<int> c (n + m);
    int c_i = 0, a_i = 0, b_i = 0;

   while (c_i < n + m) {
        if ((a_i == a.size() && b_i != b.size()) || a[a_i] >= b[b_i]) {
            c[c_i] = b[b_i];
            c_i++, b_i++;
        }
        else {
            c[c_i] = a[a_i];
            c_i++, a_i++;
        }
    }
    forup(i, 0, n + m) cout << c[i] << " ";
    return 0;
}
