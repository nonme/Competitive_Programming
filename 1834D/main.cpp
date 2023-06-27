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

int main() {
    nonme;
    //setIO("cownomics");
    tests {
        int n, m;
        cin >> n >> m;
        vector<pll> h (n);

        int smallest = 1e9+7;
        int smallest_index = -1;
        fori(0, n) {
            cin >> h[i].first >> h[i].second;


        }
        //sort(h.begin(), h.end(), defpcomp);
        fori(0, n) {
            if (h[i].second - h[i].first < smallest) {
                smallest = h[i].second - h[i].first;
                smallest_index = i;
            }
        }
        int answer = 0;

        cout << smallest << " " << smallest_index << fendl;
        fori (0, n) {
            if (i == smallest_index) continue;

            int pos_answer = h[i].second - h[i].first + 1;
            if (h[i].first >= h[smallest_index].first && h[i].second <= h[smallest_index].second) {
                // Impossible case, wasting time
            } else if (h[i].first <= h[smallest_index].second && h[i].second >= h[smallest_index].second) {
                // intersects in right part
                pos_answer -= abs(h[smallest_index].second - h[i].first);
            } else if (h[i].second >= h[smallest_index].first && h[i].first <= h[smallest_index].first) {
                pos_answer -= abs(h[smallest_index].first - h[i].second);

            }
            answer = max(answer, pos_answer);
        }

        cout << answer + (h[smallest_index].second - h[smallest_index].first + 1) << fendl;
    }
    return 0;
}
