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
ll tourist_solve(string s) {
    int len = (int) s.size();
    const vector<int> p10 = {1, 10, 100, 1000, 10000};

    const int inf = (int) 2.01e9;
    vector<vector<int>> f(5, vector<int>(2, -inf));
    f[0][0] = 0;
    for (int pos = len - 1; pos >= 0; pos--) {
      vector<vector<int>> new_f(5, vector<int>(2, -inf));
      int me = (int) (s[pos] - 'A');
      for (int mx = 0; mx < 5; mx++) {
        for (int have = 0; have < 2; have++) {
          for (int dig = 0; dig < 5; dig++) {
            int new_mx = max(mx, dig);
            int new_have = have + (dig != me);
            int new_value = f[mx][have] + (dig < mx ? -1 : 1) * p10[dig];
            if (new_have <= 1) {
              new_f[new_mx][new_have] = max(new_f[new_mx][new_have], new_value);
            }
          }
        }
      }
      swap(f, new_f);
    }
    int ans = -inf;
    for (int mx = 0; mx < 5; mx++) {
      for (int have = 0; have < 2; have++) {
        ans = max(ans, f[mx][have]);
      }
    }
    return ans;
}
int main() {
    nonme;
    //setIO("cownomics");
    string s = "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDEE";
    cout << tourist_solve(s);
    return 0;
}
