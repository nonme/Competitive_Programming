#include <bits/stdc++.h>

#define fendl "\n"
#define sz(x) (int) size(x)

#define ll long long
#define pll pair<long, long>
#define vl vector<long long>
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

bool comparefn(pll a, pll b) {
    if (a.first == b.first) {
        return a.second > b.second;
    } else return a.first < b.first;
}

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
        int n;
        cin >> n;
        vector<pll> lamps (n, {0, 0});
        fori (0, n) {
            cin >> lamps[i].first >> lamps[i].second;
        }
        sort(lamps.begin(), lamps.end(), comparefn);

        ll currentCount = 0;
        ll score = 0;
        fori (0, n) {
           // cout << lamps[i].first << " " << currentCount << fendl;
            if (i > 0 && lamps[i].first != lamps[i - 1].first) {
                currentCount = 0;
            }

            if (currentCount < lamps[i].first) {
                score += lamps[i].second;
                currentCount++;
            }

        }
        cout << score << fendl;
    }
    return 0;
}
