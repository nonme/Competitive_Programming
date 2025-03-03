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

/* ELSE */
map<char, int> vals;

int val(string s)
{
    reverse(s.begin(), s.end());
    char mx_cur = 'A';
    int ret = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] < mx_cur)
        {
            ret -= vals[s[i]];
        }
        else{
            ret += vals[s[i]];
            mx_cur = s[i];
        }
    }
    return ret;
}
ll else_solve(string s) {
    int T = 1;
    int ot = T;

    vals['A'] = 1;
    vals['B'] = 10;
    vals['C'] = 100;
    vals['D'] = 1000;
    vals['E'] = 10000;
    while(T--)
    {
        string rev = s;
        string nums = "ABCDE";
        int ans = val(s);
        int n = s.size();
        for(int i = 1; i < nums.size(); i++)
        {
            char cur = nums[i];
            int benifet = 0;
            int start = 0;
            for(int j = n - 1; j >= 0; j--)
            {
                if(rev[j] == cur)
                {
                    start = j;
                    break;
                }
            }
            char o_char = rev[start];
            while(rev[start] >= 'A')
            {
                ans = max(ans, val(rev));
                rev[start]--;
            }
            rev[start] = o_char;
        }
        int tot_neg = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] < 'D')
            {
                char o_char = s[i];
                s[i] = 'E';
                ans = max(ans, val(s));
                s[i] = o_char;
                tot_neg += vals[s[i]];
            }
            else if(s[i] == 'D')
            {
                char o_char = s[i];
                s[i] = 'E';
                ans = max(ans, val(s));
                s[i] = o_char;
                tot_neg += vals[s[i]];
                break;
            }
            if(tot_neg > 3000) break;
        }
        return ans;
    }
}


/* ELSE END */
int main() {
    nonme;
    //setIO("cownomics");
	srand((unsigned) time(NULL));
    freopen("c.out", "w", stdout);

    while (true) {
        int s_size = rand() % 2*1e4 + 1;
        string s(s_size, ' ');
        for (int i = 0; i < s_size; ++i) {
            int r = rand() % 5;
            char r_char = char(r + 65);
            s[i] = r_char;
        }
        ll tourist = tourist_solve(s);
        ll els = else_solve(s);
        if (tourist != els) {
                cout << s << endl;
                break;
        }
    }
    return 0;
}
