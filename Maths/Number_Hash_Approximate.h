#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
 Example problem: https://atcoder.jp/contests/abc250/tasks/abc250_e
 Solution: https://atcoder.jp/contests/abc250/submissions/31627462
 */
ll hashNum(ll a) {
    return a * (a + 1346) * (a + 9185);
}
