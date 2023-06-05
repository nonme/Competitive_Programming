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

#define FOR(i, start, end) for(int i = start; i < end; ++i)
#define FORd(i, start, end) for(int i = start; i >= end; --i)

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

bool isPrime(long long n) {
    if (n == 1) return false;
    for(long long i=2; i<=sqrt(n); i++)
        if(n%i==0)
            return false;
    return true;
}

int main() {
    nonme;
    //setIO("cownomics");

    int t;
    cin >> t;
    int primes = 10000;
    vector<int> prime (primes+1, true);
    prime[0] = prime[1] = false;
    for (int i=2; i<=primes; ++i)
        if (prime[i])
            if (i * 1ll * i <= primes)
                for (int j=i*i; j<=primes; j+=i)
                    prime[j] = false;
    vector<int> diffVec = {1};
    for (int i = 2; i < 10000; ++i) {
        if (!prime[i]) {
            diffVec.push_back(i);
        }
    }


    while (t--) {
        int n, m;
        cin >> n >> m;
        unordered_map<int, bool> present;
        vector<vector<int> > matrix (n,  vector<int> (m, 0));
        matrix[0][0] = 1;
        unordered_map<int, pair<int, int> > pos;

        FOR(i, 0, m) {
            matrix[0][i] = i + 1;
            present[i + 1] = true;
            pos[i + 1] = {0, i};
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int c = 0; c < diffVec.size(); ++c) {
                    int num = matrix[i - 1][j] + diffVec[c];
                    if (!present[num]) {
                        if (j == 0) {
                            matrix[i][j] = num;
                            present[num] = true;
                            pos[num] = {i, j};
                            break;
                        } else {
                            int diff = abs(matrix[i][j - 1] - num);
                            if (diff != 2 && diff != 3 && diff != 5
                                    && diff != 7 && !isPrime(diff)) {
                                matrix[i][j] = num;
                                present[num] = true;
                                pos[num] = {i, j};
                                break;
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] > n * m) {
                    int mod = matrix[i][j] % (n * m);
                    pair<int, int> temp = pos[mod];
                    int tempVal = matrix[pos[mod].first][pos[mod].second];
                    matrix[pos[mod].first][pos[mod].second] = matrix[i][j];
                    matrix[i][j] = tempVal;

                    pos[mod] = pos[matrix[i][j]];
                    pos[matrix[i][j]] = temp;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << fendl;
        }
    }
    return 0;
}
