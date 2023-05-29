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

    int t, x, k;
    cin >> t;
    while (t--) {
        cin >> x >> k;

        if (x % k != 0) {
            cout << "1" << fendl << x << "\n";
        } else {
            cout << "2" << "\n" << x - k - 1 << " " << k + 1 << "\n";
        }
    }
    return 0;
}
