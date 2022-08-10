#include <bits/stdc++.h>
using namespace std;
#define ll long long

class UnionFind {
    /*
    UnionFind or DisjollSet data-structure with Path compression. Zero indexed.
    Initialize:
            UnionFind(n)
            Methods:
    unify(p, q)        # unify p and q
    connected(p, q)    # is p connected to q (return bool)
    find(p)            # find the parent of q
    getSize(p)         # return the group size of p
    */
private:
    ll size = 0;
    ll* sizes;
    ll* parents;
public:
    ll groups;
    UnionFind(ll n) {
        size = n;
        groups = n;
        sizes = new ll[size];
        parents = new ll[size];
        for(ll i=0; i < size; i++) {
            parents[i] = i;
            sizes[i] = 1;
        }
    }
    ~UnionFind() {
        delete [] sizes;
        delete [] parents;
    }

    ll find(ll p) {
        assert(p >= 0 && p < size);
        ll root = p;
        while (root != parents[root])
            root = parents[root];

        // path compression
        while (p != root) {
            ll tmp = parents[p];
            parents[p] = root;
            p = tmp;
        }
        return root;
    }
    ll getSize(ll p) {
        return sizes[find(p)];
    }

    bool connected(ll p, ll q){
        return find(p) == find(q);
    }
    bool unify(ll p, ll q) {
        assert(p >= 0 && p < size);
        assert(q >= 0 && q < size);
        ll root1 = find(p);
        ll root2 = find(q);
        if (root1 == root2) return false;
        if (sizes[root1] < sizes[root2]){
            parents[root1] = root2;
            sizes[root2] += sizes[root1];
        } else {
            parents[root2] = root1;
            sizes[root1] += sizes[root2];
        }
        groups -= 1;
        return true;
    }
};