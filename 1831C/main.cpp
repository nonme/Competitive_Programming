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
    C:\Program Files\CodeBlocks\share\CodeBlocks\templates\wizard\console\cpp\main.cpp <- to change this code

*/

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

// ----------- ACTUAL PROGRAM START -----------

vector<int> visited;
vector<vector<pii> > d;

int dfs (int v, int pos, int order) {
    //cout << v + 1 << " " << pos << " " << order << fendl;
    visited[v] = order;
    int max_order = order;
    for (int i = 0; i < d[v].size(); ++i) {
        int u = d[v][i].first;
        int pos_u = d[v][i].second;
        if (visited[u] < 0) {
            if (pos_u < pos || pos == -1) {
                max_order = max(max_order, dfs(u, pos_u, order + 1));
            } else {
                max_order = max(max_order, dfs(u, pos_u, order));
            }
        }
    }
    return max_order;
}

int main() {
    nonme;
    // setIO("filename");
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        d.assign(n, vector<pii> (0));
        visited.assign(n, -1);
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            d[a - 1].push_back({b - 1, i});
            d[b - 1].push_back({a - 1, i});
        }
        int max_order = dfs(0, -1, 0);
        cout << max_order << fendl;
    }
    return 0;
}
