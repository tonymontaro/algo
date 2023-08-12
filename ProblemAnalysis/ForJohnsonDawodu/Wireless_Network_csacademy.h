#include <bits/stdc++.h>
using namespace std;

void fastInputOutput() { cin.tie(nullptr)->sync_with_stdio(false); }

#define ll long long
#define pi pair<ll, ll>
#define tpp tuple<ll, ll, ll>

class UnionFind {
    /*
    UnionFind or DisjointSet data-structure with Path compression. Zero indexed.
    Initialize:
            UnionFind(n)
            Methods:
    unify(p, q)        # unify p and q
    connected(p, q)    # is p connected to q (return bool)
    find(p)            # find the parent of q
    getSize(p)         # return the group size of p
    groups             # total disjoint groups
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

class Solution{
public:
    ll COST_TO_UPGRADE = 10000;
    void run() {
        vector<tuple<ll, ll, ll, ll>> edges;
        set<ll> upgradeNodesSet;
        ll t; cin >> t;
        for (ll i = 0; i < t; i++) {
            string s1, s2;
            ll cost, upgrade;
            cin >> s1 >> s2 >> cost >> upgrade;
            ll a = getIdx(s1);
            ll b = getIdx(s2);
            edges.push_back({cost, a, b, upgrade});
            if (upgrade) {
                upgradeNodesSet.insert(a);
                upgradeNodesSet.insert(b);
            }
        }
        vector<ll> upgradeNodes(upgradeNodesSet.begin(), upgradeNodesSet.end());
        ll answer = LONG_LONG_MAX;
        ll n = upgradeNodes.size();
        for (ll mask = 0; mask < (1ll << n); mask++) {
            set<ll> selected;
            ll upgradeCost = 0;
            for (ll i = 0; i < n; i++) {
                if (((1ll << i) & mask) == 0) continue;
                selected.insert(upgradeNodes[i]);
                upgradeCost += COST_TO_UPGRADE;
            }
            vector<tpp> edgesToProcess;
            ll cost, a, b, upgrade;
            for (auto &edge: edges) {
                tie(cost, a, b, upgrade) = edge;
                if (upgrade && selected.find(a) == selected.end() && selected.find(b) == selected.end())
                    continue;
                edgesToProcess.push_back({cost, a, b});
            }
            ll res = computeCost(edgesToProcess, upgradeCost);
            if (res == -1) continue;
            answer = min(answer, res);
        }
        cout << answer << endl;
    }
    map<string, ll> mp;
    ll totalNodes = 0;
    ll getIdx(string &s) {
        if (mp.find(s) == mp.end())
            mp[s] = totalNodes++;
        return mp[s];
    }
    ll computeCost(vector<tpp> edges, ll upgradeCost) {
        sort(edges.begin(), edges.end());  // tpp -> cost, edgeA, edgeB
        UnionFind uf(totalNodes);
        ll totalCost = 0;
        ll cost, a, b;
        for (ll i = 0; i < edges.size(); i++) {
            tie(cost, a, b) = edges[i];
            if (uf.connected(a, b)) continue;
            totalCost += cost;
            uf.unify(a, b);
        }
        if (uf.groups > 1) return -1;
        return totalCost + upgradeCost;
    }
};

int main(){
    fastInputOutput();

    Solution sol;
    sol.run();

    return 0;
}