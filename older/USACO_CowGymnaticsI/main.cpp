#include <bits/stdc++.h>

#define fendl "\n"
#define sz(x) (int)(x).size()

#define f first
#define s second
#define ull unsigned long long
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vc vector<char>
#define vpii vector<pair<int,int> >
#define vll vector<long long>
#define vull vector<unsigned long long>
#define vvii vector<vector<int> >
#define vvll vector<vector<long long> >
#define vvull vector<vector<unsigned long long> >

#define debug(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define forn(k,n) for(int i = k; i < n; ++i)

#define nonme ios::sync_with_stdio(false); cin.tie(nullptr);

/*
    Useful links
    https://codeforces.com/blog/entry/15547 Compiler options
    -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -Wduplicated-cond -Wlogical-op

*/

using namespace std;

void setIo(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

// ----------- ACTUAL PROGRAM START -----------

int main() {
    nonme;
    setIo("gymnastics");

    int k, n;
    cin >> k >> n;
    vector<vector<int>> cows (n, vi (k, 0));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            int cow;
            cin >> cow;
            cows[cow - 1][i] = j;
        }
    }
    int nPairs = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            bool isConsisent = true;
            bool isBigger = cows[i][0] > cows[j][0];
            for (int c = 1; c < k; ++c) {
                if (isBigger != (cows[i][c] > cows[j][c])) {
                    //cout << i + 1 << " " << j + 1 << " " << c << " " << cows[i][c] << " " << cows[j][c] << fendl;
                    isConsisent = false;
                    break;
                }
            }
            if (isConsisent) {
                //cout << i + 1 << " " << j + 1 << "\n";
                nPairs++;
            }
        }
    }
    cout << nPairs;
    return 0;
}
