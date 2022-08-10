#include <bits/stdc++.h>
using namespace std;

namespace Z_Algorithm {
    vector<int> buildTheZTable(const string & word) {
        int n = word.size();
        vector<int> zTable = vector<int>(n);
        int x = 0, y = 0;
        for (int i = 1; i < n; i++) {
            zTable[i] = max(0,min(zTable[i-x],y-i+1));
            while (i+zTable[i] < n && word[zTable[i]] == word[i+zTable[i]]) {
                x = i; y = i+zTable[i]; zTable[i]++;
            }
        }
        return zTable;
    }
}
// problem: https://cses.fi/problemset/task/2107