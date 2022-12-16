#include <bits/stdc++.h>
using namespace std;

#define ll long long

void rotate(vector<vector<ll>>& matrix) {
    ll row = matrix.size(), col = matrix[0].size();
    vector<vector<ll>> ans(col, vector<ll>(row));
    for (ll r = 0; r < row; r++) {
        for (ll c = 0; c < col; c++) {
            ll cc = row - 1 - r;
            ll rr = c;
            ans[rr][cc] = matrix[r][c];
        }
    }
    swap(matrix, ans);
}