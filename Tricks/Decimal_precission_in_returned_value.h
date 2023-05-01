#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

#define ll long long
#define lb long double
#define pi pair<ll, ll>
#define tpp tuple<ll, ll, ll>

// Use stringstream
// Example question: https://leetcode.com/problems/apply-discount-to-prices/
class Solution {
public:
    lb percent;
    string discountPrices(string sentence, int discount) {
        percent = (lb)discount / 100.0;
        stringstream ss(sentence);
        string word;
        string res;
        while (ss >> word) {
            res += solve(word);
            res += " ";
        }
        res.pop_back();
        return res;
    }
    string solve(string &word) {
        if (word.size() == 1 || word[0] != '$') return word;
        lb val = 0;
        for (ll i = 1; i < word.size(); i++) {
            if (!isdigit(word[i])) return word;
            val = (val * 10) + (word[i] - '0');
        }
        val = val - (percent * val);
        stringstream ss;
        ss << "$";
        ss << fixed << setprecision(2) << val;
        return ss.str();
    }
};