#include <bits/stdc++.h>

#include <atcoder/all>
using namespace atcoder;
using namespace std;

#define ll long long

// example question: https://atcoder.jp/contests/abc339/tasks/abc339_g
// solution: https://atcoder.jp/contests/abc339/submissions/50087475
// help in understanding the solution: https://youtu.be/riozIXbU3BQ
// help in understanding persistent segment tree: https://www.youtube.com/watch?v=m3uEG4NgJx8
struct SegTreeNode {
    ll value = 0;
    SegTreeNode *left = nullptr, *right = nullptr;
};
class PersistentSegmentTree {
public:
    PersistentSegmentTree(ll start, ll end): START(start), END(end){}

    SegTreeNode* modify(SegTreeNode *node, ll index, ll val) {
        return modifyHelper(node, index, START, END, val);
    }
    ll query(SegTreeNode *node, ll queryStart, ll queryEnd) {
        return queryHelper(node, queryStart, queryEnd, START, END);
    }

private:
    struct SegTreeNode* root = new SegTreeNode;
    ll START, END;
    ll queryHelper(struct SegTreeNode* node, ll queryStart, ll queryEnd, ll start, ll end) {
        if (node == nullptr || start > queryEnd || end < queryStart) return 0;
        if (start >= queryStart && end <= queryEnd) return node->value;
        ll mid = start + (end - start) / 2;
        return queryHelper(node->left, queryStart, queryEnd, start, mid)
               + queryHelper(node->right, queryStart, queryEnd, mid + 1, end);
    }
    void setChildren(struct SegTreeNode* node) {
        if (node->left == nullptr) node->left = new SegTreeNode;
        if (node->right == nullptr) node->right = new SegTreeNode;
    }
    SegTreeNode* modifyHelper(struct SegTreeNode* node, ll index, ll start, ll end, ll val) {
        if (start > index || end < index) return node;
        SegTreeNode* nd = new SegTreeNode;
        if (start == end && start == index) {
            nd->value = node->value;
            return nd;
        }
        setChildren(node);
        ll mid = start + (end - start) / 2;
        nd->left = modifyHelper(node->left, index, start, mid, val);
        nd->right = modifyHelper(node->right, index, mid + 1, end, val);

        nd->value = nd->left->value + nd->right->value;
        return nd;
    }
};
