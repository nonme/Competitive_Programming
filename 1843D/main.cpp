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

vector<ll> dp;
vector<vector<int> > g;
vector<bool> visited;

ll dfs(int v) {
    visited[v] = true;
    if (dp[v]) return dp[v];

    bool isChild = true;
    ll sum = 0;
    for (const auto& u : g[v]) {
        if (!visited[u]) {
            isChild = false;
            sum += dfs(u);
        }
    }
    if (isChild) return dp[v] = 1;
    else dp[v] = sum;
}

int main() {
    nonme;
    //setIO("cownomics");

    tests {
        int n;
        cin >> n;
        g.assign(n, vector<int> ());
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u - 1].push_back(v - 1);
            g[v - 1].push_back(u - 1);
        }
        dp.assign(n, 0);
        visited.assign(n, false);

        dfs(0);

        int q;
        cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;

            const ll uSum = dp[u - 1];
            const ll vSum = dp[v - 1];
            const ll sum = uSum * vSum;
            cout << sum << fendl;

        }
    }
    return 0;
}
