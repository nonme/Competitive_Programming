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
    setIO("cownomics");
    int n, m;
    cin >> n >> m;
    vector<string> spotty (n);
    vector<string> plain (n);
    fori(0, n) cin >> spotty[i];
    fori(0, n) cin >> plain[i];

    vector<char> letters {'A', 'C', 'G', 'T'};
    int locations = 0;
    fori(0, m) {
        um<char, int> spotty_count;
        um<char, int> plain_count;
        forj(0, n) {
            const char s = spotty[j][i];
            spotty_count[s] = spotty_count.count(s) == 0 ? 1 : spotty_count[s] + 1;

            const char p = plain[j][i];
            plain_count[p] = plain_count.count(p) == 0 ? 1 : plain_count[p] + 1;

        }

        bool isLocation = true;
        for (const auto letter : letters) {
            if (spotty_count[letter] > 0 && plain_count[letter] > 0) {
                isLocation = false;
            }
        }
        if (isLocation) locations++;
    }
    cout << locations;
    return 0;
}
