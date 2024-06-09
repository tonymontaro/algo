#include <bits/stdc++.h>
using namespace std;


#define ll long long

// NOTE: Use the class in Lowest_Common_Anscentor.h instead.
// https://www.youtube.com/watch?v=oib-XsjFa-M&ab_channel=ErrichtoAlgorithms
// problem: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/
class TreeAncestor {
public:
    int ansc[50001][17];
    int n;
    int mx = 16; // LOG(n)
    TreeAncestor(int nn, vector<int>& parent) {
        n = nn;
        for (int i = 0; i < n; i++) ansc[i][0] = parent[i];
        for (int i = 1; i <= mx; i++) {
            for (int node = 0; node < n; node++) {
                int p = ansc[node][i - 1];
                if (p == -1) ansc[node][i] = -1;
                else ansc[node][i] = ansc[p][i - 1];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 16; i >= 0; i--) {
            if (((1 << i) & k) != 0) node = ansc[node][i];
            if (node == -1) return -1;
        }
        return node;
    }
};