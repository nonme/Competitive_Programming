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
#define INF 1e9;

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
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = int(s.size());

        vector<ll> suf (n + 1, 0);
        vector<vector<ll> > sum (n + 1, vector<ll> (5, 0));
        vector<int> curMaxN (n, 0);

        ll maxN = 0;
        ford(i, n - 1, 0) {
            curMaxN[i] = maxN;

            ll p = int(s[i]) - 65;
            ll curN = pow(10, p);

            if (p >= maxN) suf[i] = suf[i + 1] + curN;
            else suf[i] = suf[i + 1] - curN;

            if (p > maxN) {
                maxN = p;
            }


        }
        forup(i, 0, n) {
            forup(j, 0, 5) {
                ll p = int(s[i]) - 65;
                ll curN = pow(10, p);

                if (p >= j) {
                    sum[i + 1][p] = sum[i][p] + curN;
                } else {
                    sum[i + 1][j] = sum[i][j] - curN;
                }
            }
        }
        ll maxSum = 0;
        forup(i, 0, n) {
            forup(j, 0, 5) {
                ll curN = pow(10, j);
                ll curSum = 0;
                if (j < curMaxN[i]) {
                    curSum -= curN;
                } else curSum += curN;

                int maxP = max(j, curMaxN[i]);
                curSum += (sum[i][maxP] + suf[i + 1]);

                maxSum = max(curSum, maxSum);
            }
        }
        cout << maxSum << fendl;
    }
    return 0;
}
/*
        ll maxSum = 0;
        forup(i, 1, n + 1) {

        }

*/
