#include <bits/stdc++.h>
using namespace std;
string delim = " ";
#define print(x) cout << x << endl
#define print2(x, y) cout << x << delim << y << endl


#define ll long long

namespace Geometry {
    // Area of a quadrilateral:
    ll quadArea(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
        return x1*y2 - x2*y1 + x2*y3 - x3*y2 + x3*y4 - x4*y3 + x4*y1 - x1*y4;
    }

    // Complex Numbers
//    typedef complex<ll> P;
typedef complex<long double> P;
#define X real()
#define Y imag()

// Distance between two points
long double distanceBtwTwoPoints(P a, P b) {
    return abs(b - a);
}
// Angle to the x-axis in radians
long double angleToXAxis (P a) {
    return arg(a);
}

void complexExample() {
    P p = {4, 2};
    print2(p.X, p.Y);
    P v = {3, 1};
    P u = {2, 2};
    auto s = u + v;
    print2(s.X, s.Y);
    print(distanceBtwTwoPoints(u, v));
    print(distanceBtwTwoPoints({4, 2}, {3 ,-1}));


    P point = {4, 2};
    print(angleToXAxis(point));
    // polar(s, a) constructs a vector with length=s and angle=a. Rotate a vector by multiplying by l=1 and the
    // desired angle. Example: rotate point above by 1/2 radians
    point *= polar(1.0, 0.5);
    print(angleToXAxis(point)); // angle += 0.5
}

    // Cross-product: a x b tells us the following
    // +ve : b turns left
    // 0   : b does not turn
    // -ve : b turns right
    ll crossProduct(ll x1, ll y1, ll x2, ll y2) {
        return x1 * y2 - x2 * y1;
    }
    long double crossProductComplex(P a, P b) {
        // conj negates the y coordinate of vector a. => (x1, -y1) * (x2, y2) = x1y2 - x2y1.
        return (conj(a) * b).Y;
    }

    // Point location: s1 and s2 lie on the same line, is p to the left, right or same from s1 perspective?
    // vector from s1 to p => (p - s1), vector from s2 to p => (p - s2). Now take the cross-product to get the answer.
}