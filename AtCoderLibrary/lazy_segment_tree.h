/* Atcoder Lib Start */

#ifndef ATCODER_INTERNAL_BITOP_HPP
#define ATCODER_INTERNAL_BITOP_HPP 1

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

    namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
        int ceil_pow2(int n) {
            int x = 0;
            while ((1U << x) < (unsigned int)(n)) x++;
            return x;
        }

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
        constexpr int bsf_constexpr(unsigned int n) {
            int x = 0;
            while (!(n & (1 << x))) x++;
            return x;
        }

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
        int bsf(unsigned int n) {
#ifdef _MSC_VER
            unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
            return __builtin_ctz(n);
#endif
        }

    }  // namespace internal

}  // namespace atcoder

#endif  // ATCODER_INTERNAL_BITOP_HPP


#ifndef ATCODER_LAZYSEGTREE_HPP
#define ATCODER_LAZYSEGTREE_HPP 1

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

namespace atcoder {

    template <class S,
            S (*op)(S, S),
            S (*e)(),
            class F,
            S (*mapping)(F, S),
            F (*composition)(F, F),
            F (*id)()>
    struct lazy_segtree {
    public:
        lazy_segtree() : lazy_segtree(0) {}
        explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
        explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
            log = internal::ceil_pow2(_n);
            size = 1 << log;
            d = std::vector<S>(2 * size, e());
            lz = std::vector<F>(size, id());
            for (int i = 0; i < _n; i++) d[size + i] = v[i];
            for (int i = size - 1; i >= 1; i--) {
                update(i);
            }
        }

        void set(int p, S x) {
            assert(0 <= p && p < _n);
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            d[p] = x;
            for (int i = 1; i <= log; i++) update(p >> i);
        }

        S get(int p) {
            assert(0 <= p && p < _n);
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            return d[p];
        }

        S prod(int l, int r) {
            assert(0 <= l && l <= r && r <= _n);
            if (l == r) return e();

            l += size;
            r += size;

            for (int i = log; i >= 1; i--) {
                if (((l >> i) << i) != l) push(l >> i);
                if (((r >> i) << i) != r) push((r - 1) >> i);
            }

            S sml = e(), smr = e();
            while (l < r) {
                if (l & 1) sml = op(sml, d[l++]);
                if (r & 1) smr = op(d[--r], smr);
                l >>= 1;
                r >>= 1;
            }

            return op(sml, smr);
        }

        S all_prod() { return d[1]; }

        void apply(int p, F f) {
            assert(0 <= p && p < _n);
            p += size;
            for (int i = log; i >= 1; i--) push(p >> i);
            d[p] = mapping(f, d[p]);
            for (int i = 1; i <= log; i++) update(p >> i);
        }
        void apply(int l, int r, F f) {
            assert(0 <= l && l <= r && r <= _n);
            if (l == r) return;

            l += size;
            r += size;

            for (int i = log; i >= 1; i--) {
                if (((l >> i) << i) != l) push(l >> i);
                if (((r >> i) << i) != r) push((r - 1) >> i);
            }

            {
                int l2 = l, r2 = r;
                while (l < r) {
                    if (l & 1) all_apply(l++, f);
                    if (r & 1) all_apply(--r, f);
                    l >>= 1;
                    r >>= 1;
                }
                l = l2;
                r = r2;
            }

            for (int i = 1; i <= log; i++) {
                if (((l >> i) << i) != l) update(l >> i);
                if (((r >> i) << i) != r) update((r - 1) >> i);
            }
        }

        template <bool (*g)(S)> int max_right(int l) {
            return max_right(l, [](S x) { return g(x); });
        }
        template <class G> int max_right(int l, G g) {
            assert(0 <= l && l <= _n);
            assert(g(e()));
            if (l == _n) return _n;
            l += size;
            for (int i = log; i >= 1; i--) push(l >> i);
            S sm = e();
            do {
                while (l % 2 == 0) l >>= 1;
                if (!g(op(sm, d[l]))) {
                    while (l < size) {
                        push(l);
                        l = (2 * l);
                        if (g(op(sm, d[l]))) {
                            sm = op(sm, d[l]);
                            l++;
                        }
                    }
                    return l - size;
                }
                sm = op(sm, d[l]);
                l++;
            } while ((l & -l) != l);
            return _n;
        }

        template <bool (*g)(S)> int min_left(int r) {
            return min_left(r, [](S x) { return g(x); });
        }
        template <class G> int min_left(int r, G g) {
            assert(0 <= r && r <= _n);
            assert(g(e()));
            if (r == 0) return 0;
            r += size;
            for (int i = log; i >= 1; i--) push((r - 1) >> i);
            S sm = e();
            do {
                r--;
                while (r > 1 && (r % 2)) r >>= 1;
                if (!g(op(d[r], sm))) {
                    while (r < size) {
                        push(r);
                        r = (2 * r + 1);
                        if (g(op(d[r], sm))) {
                            sm = op(d[r], sm);
                            r--;
                        }
                    }
                    return r + 1 - size;
                }
                sm = op(d[r], sm);
            } while ((r & -r) != r);
            return 0;
        }

    private:
        int _n, size, log;
        std::vector<S> d;
        std::vector<F> lz;

        void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
        void all_apply(int k, F f) {
            d[k] = mapping(f, d[k]);
            if (k < size) lz[k] = composition(f, lz[k]);
        }
        void push(int k) {
            all_apply(2 * k, lz[k]);
            all_apply(2 * k + 1, lz[k]);
            lz[k] = id();
        }
    };

}  // namespace atcoder

#endif  // ATCODER_LAZYSEGTREE_HPP

/* Atcoder Lib End */


/*
// Example: https://codeforces.com/contest/52/problem/C
// Using the description in this editorial as a guide: https://atcoder.jp/contests/practice2/editorial/100
using namespace atcoder;
ll MAX = 1e13;
struct S {
    ll val; // represents a set of values stored in the seg tree (in this case it's just longlong)
};
struct F {
    ll incr; // represents the variable attributes of the modifier function. Here we will use this to increment vals.
};
S op(S a, S b) {
    return S{min(a.val, b.val)}; // The seg tree operation. i.e. min of a given range
}
S e() {return S{(MAX)};} // the seg tree identity function. min(e(), val) = min(val, e()) = val
S mapping(F f, S x) {
    return S{(f.incr + x.val)}; // represents what the modifier function does to vals. Here, we just increment by incr.
}
F composition(F f, F g) {
    return F{(f.incr + g.incr)}; // represents what happens when two modifier functions with different constants are used.
}
F id() { return F{0}; }  // identity modifier function. Using it should simply return the original val. i.e. id(val) = val + 0 = val since the incr is 0.
vector<pi> getRanges(ll a, ll b, ll n) {
    vector<pi> res;
    if (a <= b) res.push_back({a, b+1});
    else {
        res.push_back({a, n});
        res.push_back({0, b + 1});
    }
    return res;
}
int main(){
    fastInputOutput();
    ll n; cin >> n;
    vector<S> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i].val;
    lazy_segtree<S, op, e, F, mapping, composition, id> lazySegtree(arr);

    ll q; cin >> q;
    string line;
    std::getline(std::cin, line);
    for (ll i = 0; i < q; i++){
        std::getline(std::cin, line);
        auto values = splitWord(line);
        ll l = stoll(values[0]), r = stoll(values[1]);
        if (values.size() == 2) {
            ll res = MAX + 10;
            auto ranges = getRanges(l, r, n);
            for (auto &range: ranges) {
                res = min(res, lazySegtree.prod(range.first, range.second).val);
            }
            print(res);
        } else {
            ll val = stoll(values[2]);
            auto ranges = getRanges(l, r, n);
            for (auto &range: ranges) {
                lazySegtree.apply(range.first, range.second, F{val});
            }
        }
    }

    return 0;
}

 */

/*
 Advanced Example : https://atcoder.jp/contests/practice2/tasks/practice2_k
 // Using the description in this editorial as a guide: https://atcoder.jp/contests/practice2/editorial/100
using namespace atcoder;
using lm = ::atcoder::modint998244353;

struct S {
    lm total;
    lm size;
};
struct F {
    lm mult;
    lm add;
};
S op(S a, S b) {
    return S{(a.total + b.total), (a.size + b.size)};
}
S e() {return S{0, 0};}
S mapping(F f, S x) {
    return S{(f.mult * x.total + f.add * x.size), (x.size)};
}
F composition(F last, F first) {
    return F{(first.mult * last.mult), (last.mult * first.add + last.add)};
}
F id() { return F{1, 0}; }
class Solution {
public:
    void run() {
        ll n, q; cin >> n >> q;
        vector<S> arr(n);
        for (ll i = 0; i < n; i++) {
            ll a; cin >> a;
            arr[i] = S{a, 1};
        }
        lazy_segtree<S, op, e, F, mapping, composition, id> lazySegtree(arr);

        for (ll i = 0; i < q; i++) {
            ll typ; cin >> typ;
            if (typ == 1) {
                ll l, r; cin >> l >> r;
                print(lazySegtree.prod(l, r).total.val());
            } else {
                ll l, r, b, c; cin >> l >> r >> b >> c;
                F f{b, c};
                lazySegtree.apply(l, r, f);
            }
        }
    }
};

 */