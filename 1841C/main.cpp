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

        ll sum = 0;
        ll maxN = 0;

        ll minN = INF;
        ll minPos = 0;

        ford(i, n - 1, 0) {
            ll curN = pow(10, int(s[i]) - 65);
            if (curN < maxN) curN *= -1;

            if (curN <= minN) {
                minN = curN;
                minPos = i;
            }

            sum += curN;

            maxN = max(curN, maxN);
        }
        cout << minN << " " << minPos << endl;
        s[minPos] = 'E';
        sum = 0;
        maxN = 0;

        ford(i, n - 1, 0) {
            ll curN = pow(10, int(s[i]) - 65);
            if (curN < maxN) curN *= -1;

            sum += curN;

            maxN = max(curN, maxN);
        }

        cout << sum << fendl;
    }
    return 0;
}
