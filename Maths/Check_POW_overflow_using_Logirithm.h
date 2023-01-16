#include <bits/stdc++.h>
using namespace std;

#define ll long long

// From: https://stackoverflow.com/questions/18609085/how-can-i-check-if-stdpow-will-overflow-double
// num^power <= MAX
// log(num^power) <= log(MAX)
// power * log(num) <= log(MAX)
// power <= log(MAX) / log(num)
bool isOverflow(ll num, ll power, ll MAX) {
    if (power * std::log(num) <= std::log(MAX)) {
//        ll c = std::pow(num, power);
//        std::cout << c << '\n';
        return false;
    }
    else
        return true;
}