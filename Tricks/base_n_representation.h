#include<bits/stdc++.h>
using namespace std;
#define ll long long


string base_repr(ll num, ll base) {
    if (num == 0) return "0";
    string res;
    while (num > 0) {
        res += char('0' + (num % base));
        num /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}
