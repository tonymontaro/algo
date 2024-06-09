#include <bits/stdc++.h>
using namespace std;

string delim = " ";
#define print(x) cout << setprecision(16) << fixed << x << endl
template <typename T>
void printArr(T &arr) {
    for (auto x : arr) cout << x << " ";
    cout << endl;
}

#define ll long long

// Best explanation video: https://www.youtube.com/watch?v=ru7mWZJlRQg
// Great Practice question: https://atcoder.jp/contests/abc286/tasks/abc286_f (Solution: https://atcoder.jp/contests/abc286/submissions/50998735)

class Solution {
public:
    ll n, m, q;
    vector<ll> nums = {4, 5, 7, 9, 11, 13, 17, 19 ,23 };
//    vector<ll> nums = {2, 3};
    vector<ll> starts;
    void run() {
        ll sm = 0;
        vector<ll> arr;
        ll idx = 0;
        for (ll i = 0; i < nums.size(); i++) {
            sm += nums[i];
            ll jdx = 2;
            for (ll j = 0; j < nums[i]; j++) {
                if (jdx > nums[i]) jdx = 1;
                arr.push_back(jdx + idx);
                jdx++;
            }
            starts.push_back(idx);
            idx += nums[i];
        }
//        printArr(starts);

        print(sm);
        printArr(arr);
        vector<ll> inp(sm);
        for (ll i = 0; i < sm; i++) cin >> inp[i];

        vector<ll> hold;
        for (ll i = 0; i < nums.size(); i++) {
            ll res = inp[starts[i]] - starts[i] - 1;

            hold.push_back(res);
        }
        print(solve(hold));
    }
    ll solve(vector<ll> &hold) {
        ll prd = 1;
        for (auto x: nums) prd *= x;
        ll ans = 0;
        for (ll i = 0; i < hold.size(); i++) {
            ll p = nums[i];
            ll rem = hold[i];
            ll res = prd / p;
            for (ll j = 1; j < p; j++) {
                if ((j * res) % p == rem) {
                    ans += j * res;
                    ans %= prd;
                    break;
                }
            }
        }
        return ans;
    }
    bool done = false;
    void find_valid_nums(ll num, ll prod, ll sm, vector<ll> &arr) {
        if (done) return;
        if (num + sm > 110) return;
        // skip
        find_valid_nums(num + 1, prod, sm, arr);

        for (auto x: arr) if (gcd(x, num) != 1) return;
        arr.push_back(num);
        prod *= num;
        if (prod > (ll)1e9) {
            printArr(arr);
            done = true;
            return;
        }
        sm += num;
        find_valid_nums(num + 1, prod, sm, arr);
        arr.pop_back();
    }
};


int main() {
//    usefile();

    Solution sol;
    sol.run();

    return 0;
}
