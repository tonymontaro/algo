#include <bits/stdc++.h>
using namespace std;
void fastInputOutput(){
    cin.tie(nullptr)->sync_with_stdio(false);
}

#define useFile() ifstream cin("../test_input.txt"); ofstream cout("../out.txt")
string delim = " ";
#define print(x) cout << x << endl
#define print2(x, y) cout << x << delim << y << endl
#define print3(x, y, z) cout << x << delim << y << delim << z << endl


template <typename T>
void printArr(T &arr) {
    for (auto x: arr) cout << x << " ";
    cout << endl;
}

#define ll long long
#define lb long double
const int INF = (int)2e9;
const ll LINF = (ll)4e18;
ll mpow(ll x, ll y, ll p) {
    ll res = 1;
    if (y == 0) return 1; x = x % p;  if (x == 0) return 0; // In case x is divisible by p;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
// same as count = __builtin_popcount((unsigned int) num);
ll popcount(ll num) {
    ll res = 0;
    while (num > 0) { res += (1 & num); num >>= 1; }
    return res;
}
ll MOD = 1e9 + 7;

ll hashNum(ll a) {
    return a * (a + 1346) * (a + 9185);
}
#define tp tuple<ll, ll, ll, ll>

#define ll long long
class FenwickTree {
    // One indexed Binary Indexed Tree.
public:
    int n;
    vector<ll> tree;
    FenwickTree(int num){
        n = num;
        tree = vector<ll>(n + 1);
    }
    void update(int index, ll value){
        for (int i = index; i <= n; i += (i & -i))
            tree[i] += value;
    }
    ll query(int index){
        ll total = 0;
        for (int i = index; i > 0; i -= (i & -i))
            total += tree[i];
        return total;
    }
};

// dynamic segment tree
struct SegTreeNode {
    ll value = 0;
    SegTreeNode *left = nullptr, *right = nullptr;
};
class DynamicSegmentTree {
public:
    DynamicSegmentTree(ll start, ll end): START(start), END(end){}

    void modify(ll index, ll val) {
        modifyHelper(root, index, START, END, val);
    }
    ll query(ll queryStart, ll queryEnd, ll k) {
        return queryHelper(root, queryStart, queryEnd, START, END, k);
    }

private:
    struct SegTreeNode* root = new SegTreeNode;
    ll START, END;
    ll queryHelper(struct SegTreeNode* node, ll queryStart, ll queryEnd, ll start, ll end, ll k) {
        if (node == nullptr || start > queryEnd || end < queryStart || node->value < k) return -1;
        if (start == end) return start;
//        if (start >= queryStart && end <= queryEnd) return node->value;
        ll mid = start + (end - start) / 2;
        ll l = queryHelper(node->left, queryStart, queryEnd, start, mid, k);
        if (l != -1) return l;
        return queryHelper(node->right, queryStart, queryEnd, mid + 1, end, k);
    }
    void setChildren(struct SegTreeNode* node) {
        if (node->left == nullptr) node->left = new SegTreeNode;
        if (node->right == nullptr) node->right = new SegTreeNode;
    }
    void modifyHelper(struct SegTreeNode* node, ll index, ll start, ll end, ll val) {
        if (start > index || end < index) return;
        if (start == end && start == index) {
            node->value = val;
            return;
        }
        setChildren(node);
        ll mid = start + (end - start) / 2;
        modifyHelper(node->left, index, start, mid, val);
        modifyHelper(node->right, index, mid + 1, end, val);

        node->value = max(node->left->value, node->right->value);
    }
};

/*
 * Question: https://leetcode.com/problems/booking-concert-tickets-in-groups/
 * Contest: https://leetcode.com/contest/biweekly-contest-79/
 */
class BookMyShow {
public:
    ll n, m;
    ll left = 1;
    vector<ll> rows;
    FenwickTree* fw;
    DynamicSegmentTree* sg;
    BookMyShow(int n_, int m_) {
        n = n_; m = m_;
        fw = new FenwickTree(n_);
        sg = new DynamicSegmentTree(0, n + 1);
        rows.resize(n + 1);
        for (ll i = 1; i <= n_; i++) {
            fw->update(i, m);
            sg->modify(i, m);
            rows[i] = m;
        }
    }

    vector<int> gather(int k, int maxRow) {
        maxRow++;
        int r = sg->query(0, maxRow, k);
        if (r == -1) return {};

        fw->update(r, -k);
        vector<int> ans = {r - 1, ((int)(m - rows[r]))};
        rows[r] -= k;
        sg->modify(r, rows[r]);
        return ans;
    }

    bool scatter(int k_, int maxRow) {
        ll k = k_;
        maxRow++;
        if (fw->query(maxRow) < k) return false;
        while (k > 0) {
            ll diff = min(k, rows[left]);
            k -= diff;
            fw->update((int)left, -diff);
            rows[left] -= diff;
            sg->modify((int) left, rows[left]);
            if (rows[left] == 0)
                left++;
        }
        return true;
    }
};

int main() {
    fastInputOutput();

//    Solution solver;
    vector<ll> arr;
    printArr(arr);

    return 0;
}
/*
["BookMyShow","scatter","scatter","gather","gather","gather"]
[[5,10],[9,1],[1,3],[3,4],[1,1],[10,4]]


[null,true,true,[1,0],[1,3],[2,0]]
 */