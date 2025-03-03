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
ll make_1(int len) {
    ll num = 1;
    int i = 1;
    while (i < len) {
        num *= 10;
        i++;
    }
    return num;
}
ll make_9(int len) {
    ll num = 9;
    int i = 1;
    while (i < len) {
        num = 10 * num + 9;
        i++;
    }
    return num;
}

int main() {
    nonme;
    //setIO("cownomics");
    tests {
        ll a, b, c, k;
        cin >> a >> b >> c >> k;

        if (c < max(a, b) || c > max(a, b) + 1) cout << "-1" << fendl;
        else {
            ll min_a = make_1(a);
            ll max_a = make_9(a);

            ll min_b = make_1(b);
            ll max_b = make_9(b);

            ll min_c = make_1(c);
            ll max_c = make_9(c);

            ll counter = 0;
            for (int i = min_a; i <= max_a; ++i) {
                for (int j = min_b; j <= max_b; ++j) {
                    ll sum = i + j;
                    if (sum > max_c || sum < min_c) continue;

                    counter++;
                    cout << counter << ": " << i << " + " << j << " = " << sum << fendl;
                }
            }
        }
    }
    return 0;
}
