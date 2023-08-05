#include <bits/stdc++.h>
using namespace std;

void fastInputOutput() { cin.tie(nullptr)->sync_with_stdio(false); }
#define print(x) cout << x << endl
#define ll long long
#define pi pair<ll, ll>

// Question: https://csacademy.com/ieeextreme-practice/task/robot-versus-fan/statement/

class Solution {
public:
    ll n;
    vector<string> grid;
    map<pi, ll> circle; // {r,c} -> distance
    map<pi, ll> dist; // {r, c} -> distance
    map<ll, ll> circleStartTimes;
    ll k;
    void run() {
        cin >> n;
        grid.resize(n);
        for (ll i = 0; i < n; i++) {
            cin >> grid[i];
        }
        cin >> k;
        computeDist();
        ll idx = 0;
        ll ans = -1;
        for (ll i = 0; i < k; i++) {
            pi tmp;
            cin >> tmp.first >> tmp.second;
            ll res = check(tmp, idx++);
            if (res == -1) continue;
            if (ans == -1 || ans > res) ans = res;
        }
        print((ans == -1 ? "never" : to_string(ans)));
    }
    ll check(pi cord, ll d) {
        // normal check
        if (dist.find(cord) == dist.end()) return -1;
        ll dd = dist[cord];
        if (dd % k == d) return dd;

        // check in the cycle
        if (circle.find(cord) == circle.end()) return -1;
        ll sz = circle[cord];
        ll mult = (sz / k) + 2;
        ll start = (d - sz + (k * mult)) % k;
        if (circleStartTimes.find(start) == circleStartTimes.end()) return -1;
        return circleStartTimes[start] + sz;
    }
    void computeDist() {
        ll r = 0, c = 0;
        ll d  = 0;
        vector<pi> arr;
        while (true) {
            if (dist.find({r, c}) != dist.end()) {
                // we are in a cycle, handle it.
                pi tmp = {r, c};
                for (ll i = 0; i < arr.size(); i++) {
                    if (arr[i] != tmp) continue;
                    ll sz = arr.size() - i;
                    ll startTime = d - sz;
                    computeCycleDistances(i, sz, startTime, arr);
                    break;
                }
                break;
            }
            arr.push_back({r, c});
            dist[{r, c}] = d++;
            if (grid[r][c] == '>') c++;
            else if (grid[r][c] == '<') c--;
            else if (grid[r][c] == 'v') r++;
            else if (grid[r][c] == '^') r--;
        }
    }
    void computeCycleDistances(ll startIdx, ll sz, ll startTime, vector<pi> &arr) {
        ll idx = startTime % k;
        while (circleStartTimes.find(idx) == circleStartTimes.end()) {
            circleStartTimes[idx] = startTime;
            idx = (idx + sz) % k;
            startTime += sz;
        }
        idx = 0;
        for (ll j = startIdx; j < arr.size(); j++) {
            circle[arr[j]] = idx++;
        }
    }
};

int main(){
    fastInputOutput();
//    usefile();

    int cases;
    cin >> cases;
    for (int case_id = 1; case_id < cases + 1; case_id++) {
        Solution sol;
        sol.run();
    }

    return 0;
}
