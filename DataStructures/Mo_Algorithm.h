#include <bits/stdc++.h>
using namespace std;


// Understand concept: https://www.youtube.com/watch?v=RENzmNgIZ4A
// Great vid: https://www.youtube.com/watch?v=BJhzd_VG61k
// Helpful article: https://cp-algorithms.com/data_structures/sqrt_decomposition.html#mos-algorithm
// Example Problem: https://atcoder.jp/contests/abc242/tasks/abc242_g
// Submission: https://atcoder.jp/contests/abc242/submissions/32488965

#define ll long long
ll block_size; // TODO: set block_size as sqrt(n)
struct Query {
    ll l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};
class MoAlgorithm {
public:
    void remove(ll idx);  // TODO: remove value at idx from data structure
    void add(ll idx);     // TODO: add value at idx from data structure
    ll get_answer();  // TODO: extract the current answer of the data structure

    vector<ll> mo_s_algorithm(vector<Query> queries) {
        vector<ll> answers(queries.size());
        sort(queries.begin(), queries.end());

        // TODO: initialize data structure

        ll cur_l = 0;
        ll cur_r = -1;
        // invariant: data structure will always reflect the range [cur_l, cur_r]
        for (Query q : queries) {
            while (cur_l > q.l) {
                cur_l--;
                add(cur_l);
            }
            while (cur_r < q.r) {
                cur_r++;
                add(cur_r);
            }
            while (cur_l < q.l) {
                remove(cur_l);
                cur_l++;
            }
            while (cur_r > q.r) {
                remove(cur_r);
                cur_r--;
            }
            answers[q.idx] = get_answer();
        }
        return answers;
    }
};