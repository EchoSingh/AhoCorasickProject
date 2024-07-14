#include "AhoCorasick.h"
#include <queue>

AhoCorasick::AhoCorasick(const std::vector<std::string>& patterns) : patterns(patterns) {
    trie.emplace_back();
    for (const auto& pattern : patterns) {
        int node = 0;
        for (char c : pattern) {
            if (trie[node].next.find(c) == trie[node].next.end()) {
                trie[node].next[c] = trie.size();
                trie.emplace_back();
            }
            node = trie[node].next[c];
        }
        trie[node].out.push_back(&pattern - &patterns[0]);
    }
}

void AhoCorasick::build() {
    std::queue<int> q;
    for (const auto& p : trie[0].next) {
        q.push(p.second);
        trie[p.second].link = 0;
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (const auto& p : trie[node].next) {
            char c = p.first;
            int nextNode = p.second;
            int fail = trie[node].link;

            while (fail != -1 && trie[fail].next.find(c) == trie[fail].next.end()) {
                fail = trie[fail].link;
            }

            if (fail != -1) {
                trie[nextNode].link = trie[fail].next[c];
            }
            else {
                trie[nextNode].link = 0;
            }

            for (int outPattern : trie[trie[nextNode].link].out) {
                trie[nextNode].out.push_back(outPattern);
            }

            q.push(nextNode);
        }
    }
}

std::vector<std::pair<int, int>> AhoCorasick::search(const std::string& text) {
    std::vector<std::pair<int, int>> results;
    int node = 0;
    for (int i = 0; i < text.size(); ++i) {
        char c = text[i];
        while (node != -1 && trie[node].next.find(c) == trie[node].next.end()) {
            node = trie[node].link;
        }
        if (node == -1) {
            node = 0;
            continue;
        }
        node = trie[node].next[c];
        for (int patternIndex : trie[node].out) {
            results.emplace_back(i - patterns[patternIndex].size() + 1, patternIndex);
        }
    }
    return results;
}
