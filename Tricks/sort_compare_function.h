#include<bits/stdc++.h>
using namespace std;


// Should a appear before b
// use: sort(arr.begin(), arr.end(), compare);
bool compare(string &a, string &b) {
    return a.size() < b.size();
}