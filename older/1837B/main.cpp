#include <bits/stdc++.h>

#define fendl "\n"
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
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define forn(k,n) for(int i = k; i < n; ++i)
#define non ios::sync_with_stdio(false);
#define me cin.tie(0); cout.tie(0);

using namespace std;

int main()
{
    non me;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int maxval = 0;
        int current = 1;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                current++;
            } else current = 1;

            maxval = max(maxval, current);
        }
        cout << max(2, maxval + 1) << fendl;
    }
    return 0;
}
