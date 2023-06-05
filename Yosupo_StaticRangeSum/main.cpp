#include <bits/stdc++.h>

#define fendl "\n"
#define sz(x) (int)(x).size()

#define ll long long
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
    int n, q;
    cin >> n >> q;
    vector<ll> a (n);
    vector<ll> sums (n, 0);
    fori(0, n) cin >> a[i];
    fori(0, n) {
        if (i == 0) sums[i] = a[i];
        else sums[i] = sums[i - 1] + a[i];
    }
    while(q--) {
        int l, r;
        cin >> l >> r;

        const ll left = (l != 0 ? sums[l - 1] : 0);
        const ll right = (r != 0 ? sums[r - 1] : 0);
        cout << right - left << fendl;
    }
    return 0;
}
