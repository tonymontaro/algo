#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<ll, ll>
#define tpp tuple<ll, ll, ll>


struct Trie {
    Trie* kids[26];
    bool wordEnd = false;
    Trie() {
        for (auto &x: kids) x = nullptr;
    }
};
class TrieManager {
    // supports lowercase OR uppercase alphabets
public:
    void add(string &s) {
        Trie *node = root;
        for (ll i = 0; i < s.size(); i++) {
            ll c = s[i]-'a';
            if (!node->kids[c])
                node->kids[c] = new Trie();
            node = node->kids[c];
        }
        node->wordEnd = true;
    }
    bool contains(string &s) {
        Trie *node = root;
        for (ll i = 0; i < s.size(); i++) {
            ll c = s[i];
            if (!node->kids[c])
                return false;
            node = node->kids[c];
        }
        return node->wordEnd;
    }
private:
    Trie* root = new Trie;
};


//class Trie {
//public:
//    struct Trie* c[27];
//    vector<string> suggestions;
//    Trie() {
//        for (auto & i : c) i = nullptr;
//    }
//};

int main() {
    // usage
    vector<string> words = {"word1", "word2", "..."};
    for (auto &word: words) {
        Trie* node = new Trie();
        for (char c: word) {
            if (!node->c[c - 'a']) node->c[c - 'a'] = new Trie();
            node = node->c[c - 'a'];
            if (node->suggestions.size() < 3) node->suggestions.push_back(word);
        }
        node->c[26] = new Trie();
    }
    return 0;
}