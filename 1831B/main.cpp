#include <bits/stdc++.h>

#define fendl "\n"
#define sz(x) (int)(x).size()

#define f first
#define s second
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

unordered_map<ll, ll> find_long_sec(const vector<ll>& vec) {
    unordered_map<ll, ll> res;
    ll sec_len = 1;
    res[vec[0]] = sec_len;
    for (int i = 1; i < int(vec.size()); ++i) {
        if (vec[i] == vec[i - 1]) {
            sec_len++;
        } else {
            res[vec[i - 1]] = res.count(vec[i - 1]) == 0 ? sec_len : max(res[vec[i - 1]], sec_len);
            sec_len = 1;
        }
    }
    int length = int(vec.size());
    if (res.count(vec[length - 1]) == 0)
        res[vec[length - 1]] = sec_len;
    else
        res[vec[length - 1]] = max(res[vec[length - 1]], sec_len);
    return res;
}

int main() {
    nonme;
    // setIO("filename");
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a (n, 0);
        vector<ll> b (n, 0);
        forn(0, n) {
            cin >> a[i];
        }
        forn(0, n) {
            cin >> b[i];
        }

        unordered_map<ll, ll> long_sec_a = find_long_sec(a);
        unordered_map<ll, ll> long_sec_b = find_long_sec(b);

        ll result = 0;
        for (const auto &a_entry : long_sec_a) {
            ll value = a_entry.second + (long_sec_b.count(a_entry.first) != 0 ? long_sec_b[a_entry.first] : 0);
            result = max(value, result);
        }
        for (const auto &b_entry : long_sec_b) {
            ll value = b_entry.second + (long_sec_a.count(b_entry.first) != 0 ? long_sec_a[b_entry.first] : 0);
            result = max(value, result);
        }
        cout << result << fendl;

    }
    return 0;
}
