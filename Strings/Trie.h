#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    struct Trie* c[27];
    vector<string> suggestions;
    Trie() {
        for (auto & i : c) i = nullptr;
    }
};

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