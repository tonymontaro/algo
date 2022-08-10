#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
    ll query(ll queryStart, ll queryEnd) {
        return queryHelper(root, queryStart, queryEnd, START, END);
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

        node->value = node->left->value + node->right->value;
    }
};

// simple segment tree
class SegmentTree {
public:
    const int N = 2e5 + 4;  // limit for array size
    int n;  // array size
    ll t[400008];
    void build() {
        // build the tree
        for (int i = n - 1; i > 0; --i) {
            t[i] = t[2 * i] + t[2 * i + 1];
        }
    }
    void modify(int i, ll value) {
        // update value at position i
        i += n;
        t[i] = value;
        while (i > 1) {
            i /= 2;
            t[i] = t[2 * i] + t[2 * i + 1];
        }
    }
    ll query(int left, int right) {
        // query on interval [l, r] both inclusive and zero indexed.
        ll res = 0;
        left += n;
        right += n;
        while (left <= right) {
            if (left % 2 == 1) res = res + t[left++];
            if (right % 2 == 0) res = res + t[right--];
            left /= 2; right /= 2;
        }
        return res;
    }
    SegmentTree(vector<ll> &arr) {
        n = arr.size();
        for (int i = 0; i < n; ++i)
            t[n + i] = arr[i];
        build();
    }
};


// lazy segment tree (https://cses.fi/problemset/task/1735/)
struct LazySegNode {
    ll value = 0;
    ll set = 0;
    ll add = 0;
    LazySegNode *left = nullptr, *right = nullptr;
};
class DynamicLazySegmentTree {
public:
    DynamicLazySegmentTree(ll start, ll end): START(start), END(end){}

    void set(ll queryStart, ll queryEnd, ll val) {
        setHelper(root, queryStart, queryEnd, START, END, val);
    }
    void add(ll queryStart, ll queryEnd, ll val) {
        addHelper(root, queryStart, queryEnd, START, END, val);
    }
    ll query(ll queryStart, ll queryEnd) {
        return queryHelper(root, queryStart, queryEnd, START, END);
    }

private:
    struct LazySegNode* root = new LazySegNode;
    ll START, END;

    void pushDown(struct LazySegNode* node, ll start, ll end) {
        if (start == end) return;
        ll mid = start + (end - start) / 2;
        if (node->left == nullptr) node->left = new LazySegNode;
        if (node->right == nullptr) node->right = new LazySegNode;
        auto left = node->left; auto right = node->right;
        if (node->set) {
            left->add = right->add = 0;
            left->set = right->set = node->set;
            left->value = (mid - start + 1) * node->set;
            right->value = (end - mid) * node->set;
            node->set = 0;
        } else if (node->add) {
            if (left->set) left->set += node->add;
            else left->add += node->add;
            if (right->set) right->set += node->add;
            else right->add += node->add;
            left->value += (mid - start + 1) * node->add;
            right->value += (end - mid) * node->add;
            node->add = 0;
        }
    }
    ll queryHelper(struct LazySegNode* node, ll queryStart, ll queryEnd, ll start, ll end) {
        if (start > queryEnd || end < queryStart || node == nullptr) return 0;
        if (start >= queryStart && end <= queryEnd)
            return node->value;
        ll mid = start + (end - start) / 2;
        pushDown(node, start, end);
        return queryHelper(node->left, queryStart, queryEnd, start, mid) + queryHelper(node->right, queryStart, queryEnd, mid + 1, end);
    }
    void setHelper(struct LazySegNode* node, ll queryStart, ll queryEnd, ll start, ll end, ll val) {
        if (start > queryEnd || end < queryStart) return;
        if (start >= queryStart && end <= queryEnd) {
            node->value = (end - start + 1) * val;
            node->set = val;
            node->add = 0;
            return;
        }
        ll mid = start + (end - start) / 2;
        pushDown(node, start, end);
        setHelper(node->left, queryStart, queryEnd, start, mid, val);
        setHelper(node->right, queryStart, queryEnd, mid + 1, end, val);
        node->value = node->left->value + node->right->value;
    }
    void addHelper(struct LazySegNode* node, ll queryStart, ll queryEnd, ll start, ll end, ll val){
        if (start > queryEnd || end < queryStart) return;
        if (start >= queryStart && end <= queryEnd) {
            node->value += (end - start + 1) * val;
            if (node->set) node->set += val;
            else node->add += val;
            return;
        }
        ll mid = start + (end - start) / 2;
        pushDown(node, start, end);
        addHelper(node->left, queryStart, queryEnd, start, mid, val);
        addHelper(node->right, queryStart, queryEnd, mid + 1, end, val);
        node->value = node->left->value + node->right->value;
    };
};

