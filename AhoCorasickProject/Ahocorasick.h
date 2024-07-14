#pragma once
#ifndef AHOCORASICK_H
#define AHOCORASICK_H

#include <vector>
#include <string>
#include <unordered_map>

class AhoCorasick {
public:
    AhoCorasick(const std::vector<std::string>& patterns);
    void build();
    std::vector<std::pair<int, int>> search(const std::string& text);

private:
    struct Node {
        std::unordered_map<char, int> next;
        int link = -1;
        std::vector<int> out;
    };

    std::vector<Node> trie;
    std::vector<std::string> patterns;
};

#endif // AHOCORASICK_H
