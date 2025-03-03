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
        int n;
        cin >> n;
        vll a (n);
        read(a);

        um<ll, ll> cnt;
        um<ll, ll> last;
        fori(0, n)
        {
            if (cnt.count(a[i]) == 0)
                cnt[a[i]] = i;
        }
        vll dp (n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;

        last[a[0]] = 0;
        fori(2, n + 1)
        {
            dp[i] = dp[i - 1] + 1;

            if (i - 1 > cnt[a[i - 1]])
            {
                dp[i] = min(dp[i],
                            min(
                                dp[cnt[a[i - 1]]],
                                dp[last[a[i - 1]]]
                            )
                           );
            }

            last[a[i - 1]] = i - 1;
        }
        print(dp);
        cout << n - dp[n] << fendl;
    }
    return 0;
}

/*
10
9
1 2 3 2 3 1 3 2 3
13
1 2 3 2 3 1 3 2 3 2 1 3 2
8
1 2 3 2 3 1 3 2
8
1 1 2 2 3 3 4 4
9
1 2 2 3 3 4 4 5 1
8
1 2 3 4 5 6 7 8
8
1 2 1 2 1 2 1 2
7
1 2 1 2 1 2 1
6
1 2 1 2 1 2
10
2 1 2 1 3 2 3 1 2 1

9
13
7
8
9
0
8
7
6
10

1
10
2 1 2 1 3 2 3 1 2 1

*/
