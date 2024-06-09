#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<ll, ll>
#define tpp tuple<ll, ll, ll>

class TrieNode {
public:
    vector<TrieNode*> kids;
    bool wordEnd = false;
    TrieNode() {
        kids.resize(28, nullptr);
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {root = new TrieNode();}
    void add(string &s) {
        TrieNode *node = root;
        for (ll i = 0; i < s.size(); i++) {
            ll c = s[i]-'a';
            if (!node->kids[c])
                node->kids[c] = new TrieNode();
            node = node->kids[c];
        }
        node->wordEnd = true;
    }
    bool contains(string &s) {
        TrieNode *node = root;
        for (ll i = 0; i < s.size(); i++) {
            ll c = s[i]-'a';
            if (!node->kids[c])
                return false;
            node = node->kids[c];
        }
        return node->wordEnd;
    }
};
