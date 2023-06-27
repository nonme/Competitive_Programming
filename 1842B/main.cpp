//#pragma GCC optimize("O3","unroll-loops")
//#pragma GCC target ("avx2")

#include <bits/stdc++.h>

#define fendl "\n"
#define sz(x) (int) size(x)
#define all(v) v.begin(), v.end()

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpll vector<pair<ll, ll> >

#define um unordered_map

#define debug(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

#define forup(i, start, end) for(int i = start; i < end; ++i)
#define ford(i, start, end) for(int i = start; i >= end; --i)

#define fori(start, end) for(int i = start; i < end; ++i)
#define forj(start, end) for(int j = start; j < end; ++i)
#define forc(start, end) for(int c = start; c < end; ++c)

#define read(ARRAY) fori(0, ARRAY.size()) cin >> ARRAY[i];
#define print(ARRAY) fori(0, ARRAY.size()) cout << ARRAY[i] << " "; cout << fendl;

#define tests int TEST_COUNT_; cin >> TEST_COUNT_; while(TEST_COUNT_--)

#define nonme ios::sync_with_stdio(false); cin.tie(nullptr);

/*
    Useful links
    https://codeforces.com/blog/entry/15547 Compiler options
    -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -Wduplicated-cond -Wlogical-op
    C:\Program Files\CodeBlocks\share\CodeBlocks\templates\wizard\console\cpp\main.cpp <- to change this code

*/

using namespace std;

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

// sorts to (1, 3) -> (1, 4) -> (2, 5) -> (2, 6)
bool defpcomp(pll a, pll b)
{
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}
// ----------- ACTUAL PROGRAM START -----------

int main()
{
    nonme;
    //setIO("cownomics");

    tests
    {
        int n, x;
        cin >> n >> x;
        vll a(n), b (n), c(n);
        read(a);
        read(b);
        read(c);

        ll start = 0;
        int i = 0, j = 0, k = 0;
        bool changed = false;
        do
        {
            changed = false;
            if (i < n && (a[i] | x) <= x)
            {
                start = start | a[i];
                i++;
                changed = true;
            }
            if (j < n && (b[j] | x) <= x)
            {
                start = start | b[j];
                j++;
                changed = true;
            }
            if (k < n && (c[k] | x) <= x)
            {
                start = start | c[k];
                k++;
                changed = true;
            }
        }
        while (changed);

        if (start == x) cout << "Yes" << fendl;
        else cout << "No" << fendl;
    }
    return 0;
}
