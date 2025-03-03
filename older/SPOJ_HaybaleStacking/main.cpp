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

    int n, k;
    cin >> n >> k;

    vll a (n + 1, 0);
    vll b (n + 1, 0);
    while (k--) {
        int l, r;
        cin >> l >> r;
        a[l - 1]++;
        b[r]++;
    }
    int current = 0;

    vll c (n, 0);
    fori(0, n) {
        if (a[i] > 0) {
            current += a[i];
        }
        if (b[i] > 0) {
            current -= b[i];
        }
        c[i] = current;
    }
    int mid = n / 2;
    nth_element(c.begin(), c.begin() + mid,  c.end());
    std::cout << c[mid];
    return 0;
}
