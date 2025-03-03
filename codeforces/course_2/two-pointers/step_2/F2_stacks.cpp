#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);

    for (auto& ai : a) cin >> ai;

    MinMaxStack s1;
    MinMaxStack s2;

    ll l = 0;
    ll result = 0;
    for (ll r = 0; r < n; ++r) {
        s2.push(a[r]);
        ll maxVal = MinMaxStack::get_max(s1, s2);
        ll minVal = MinMaxStack::get_min(s1, s2);

        while (maxVal - minVal > k) {
            if (s1.size() == 0) {
                while (s2.size() > 0) {
                    s1.push(s2.pop());
                }
            }
            s1.pop();
            l++;

            maxVal = MinMaxStack::get_max(s1, s2);
            minVal = MinMaxStack::get_min(s1, s2);
        }
        result += r - l + 1;
    }

    cout << result << endl;
}

int main() {
    int t = 1;
    // cin >> t;  // раскомментируйте если нужно считать количество тестов
    while (t--) solve();
    return 0;
}

// Ctrl + Shift + B -> build & run
// Ctrl + Shift + P -> Tasks: run task -> build & run with input (for input.txt)
