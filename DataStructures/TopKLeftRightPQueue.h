#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pi pair<ll, ll>

// Example question: https://atcoder.jp/contests/abc306/tasks/abc306_e (solution: https://atcoder.jp/contests/abc306/submissions/50315216)
class TopKQueue {
    // Right holds top K values, while Left holds the rest of the values.
public:
    priority_queue< ll> left;
    priority_queue<ll, vector<ll>, greater<>> right;
    map<ll,ll> rm;
    ll total = 0;
    ll sz = 0;
    ll k;
    TopKQueue(ll k_) {
        k = k_;
    }
    ll add(ll num) {
        if (sz < k) {
            right.push(num);
            total += num;
            sz++;
            return total;
        }
        left.push(num);
        if (left.top() > right.top()) {
            total += (left.top() - right.top());
            right.push(left.top());
            left.pop();
            left.push(right.top());
            right.pop();
            fix();
        }
        return total;
    }
    void remove(ll num) {
        rm[num]++;
        if (!left.empty() && num <= left.top()) {
            fix(); return;
        }
        sz--;
        total -= num;
        if (!left.empty()) {
            sz++;
            total += left.top();
            right.push(left.top());
            left.pop();
        }
        fix();
    }
    void fix() {
        while (!left.empty() && rm[left.top()] > 0) {
            rm[left.top()]--;
            left.pop();
        }
        while (!right.empty() && rm[right.top()] > 0) {
            rm[right.top()]--;
            right.pop();
        }
    }
};
