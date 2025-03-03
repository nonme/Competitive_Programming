#include <bits/stdc++.h>
using namespace std;

#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const vector<int>& getPrimes() {
    static const vector<int> primes = []() {
        const int MAX_N = 2e5 + 1;

        vector<int> temp;
        vector<bool> isPrime(MAX_N + 1, true);

        for (int i = 2; i * i <= MAX_N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= MAX_N; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= MAX_N; i++) {
            if (isPrime[i]) temp.push_back(i);
        }
        return temp;
    }();
    return primes;
}

const vector<pair<int, int>>& getHalfPrimes() {
    static const vector<pair<int, int>> halfPrimes = []() {
        const vector<int>& primes = getPrimes();
        const int MAX_N = 2e5 + 1;
        vector<pair<int, int>> temp(MAX_N + 1, {0, 0});

        for (int i = 0; i < primes.size(); ++i) {
            for (int j = i; j < primes.size(); ++j) {
                if ((long long)primes[i] * primes[j] <= MAX_N) {
                    temp[primes[i] * primes[j]] = {primes[i], primes[j]};
                } else {
                    break;
                }
            }
        }
        return temp;
    }();
    return halfPrimes;
}

const vector<ll>& getIsSimple() {
    static const vector<ll> isSimple = []() {
        const vector<int>& primes = getPrimes();
        vector<ll> temp(2e5 + 1);
        for (ll i : primes) {
            temp[i] = 1;
        }
        return temp;
    }();
    return isSimple;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto& isSimple = getIsSimple();

    auto& halfPrimes = getHalfPrimes();
    sort(a.begin(), a.end());

    vector<int> prevNumbers(n + 1, 0);

    ll simpleCount = 0;
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        if (isSimple[a[i]]) {
            prevNumbers[a[i]]++;
            simpleCount++;

            result = result + (simpleCount - prevNumbers[a[i]]);
        } else if (halfPrimes[a[i]].first) {
            prevNumbers[a[i]]++;

            auto [p1, p2] = halfPrimes[a[i]];
            // cout << "p1 p2 " << p1 << " " << p2 << endl;
            if (p1 != p2)
                result = result + prevNumbers[p1] + prevNumbers[p2] +
                         prevNumbers[a[i]];
            else
                result += prevNumbers[p1] + prevNumbers[a[i]];
        }
        // cout << i << ": " << result << endl;
    }

    cout << result << endl;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;  // раскомментируйте если нужно считать количество тестов
    while (t--) solve();
    return 0;
}

// Ctrl + Shift + B -> build & run
// Ctrl + Shift + P -> Tasks: run task -> build & run with input (for
// input.txt)
