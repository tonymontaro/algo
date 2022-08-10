#include <bits/stdc++.h>
using namespace std;

namespace KMP {
    vector<int> computeTable(const string &s) {
        int sz = s.size();
        vector<int> table = vector<int>(sz);
        int left = 0;
        int idx = 1;
        while (idx < sz) {
            if (s[idx] == s[left]) {
                table[idx] = left + 1;
                left++; idx++;
            } else if (left > 0) {
                left = table[left - 1];
            } else
                idx++;
        }
        return table;
    }
}
// problem: https://cses.fi/problemset/task/2107