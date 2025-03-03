#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1e9 + 7;
const int INF = 1e18;

// !!!: auto& primes = getPrimes();
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

// !!!: auto& isSimple = getIsSimple();
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

// Half / semi primes, up to MAX_N numbers that have only two prime factors
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

// MinMaxStack to get min/max in O(1)
// See: codeforces/course_2/two-pointers/step_2/F2_stacks.cpp
struct MinMaxStack {
    stack<ll> s;
    stack<ll> minStack;
    stack<ll> maxStack;

    void push(ll x) {
        s.push(x);

        minStack.push(minStack.empty() || x < minStack.top() ? x
                                                             : minStack.top());
        maxStack.push(maxStack.empty() || x > maxStack.top() ? x
                                                             : maxStack.top());
    }
    ll pop() {
        ll x = s.top();

        s.pop();
        minStack.pop();
        maxStack.pop();

        return x;
    }
    ll getMin() { return minStack.top(); }
    ll getMax() { return maxStack.top(); }

    size_t size() { return s.size(); }

    static ll get_min(MinMaxStack& s1, MinMaxStack& s2) {
        if (s1.size() == 0) return s2.getMin();
        if (s2.size() == 0) return s1.getMin();
        return min(s1.getMin(), s2.getMin());
    }

    static ll get_max(MinMaxStack& s1, MinMaxStack& s2) {
        if (s1.size() == 0) return s2.getMax();
        if (s2.size() == 0) return s1.getMax();
        return max(s1.getMax(), s2.getMax());
    }
};

// GCD Segment Tree
// see: codeforces/course_2/two-pointers/step_2/G.cpp
struct SegTreeGCD {
    vector<ll> t;
    int n;

    SegTreeGCD(int n) : n(n) { t.resize(4 * n); }

    void build(vector<ll>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = gcd(t[v * 2], t[v * 2 + 1]);
        }
    }

    ll query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return t[v];
        int tm = (tl + tr) / 2;
        return gcd(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int binpow(int a, int n, int m = MOD) {
    int res = 1;
    while (n) {
        if (n & 1) res = (res * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    return res;
}