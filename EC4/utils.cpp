//
// Created by felix on 5/22/2025.
//

#include "utils.h"
#include <map>
#include <fstream>
using namespace std;

bool oneLetterDiff(const string& a, const string& b) {
    // Theta(a.size())
    int diff = 0;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] != b[i] && ++diff > 1)
            return false;
    return diff == 1;
}

void buildGraphFromDictionary(const vector<string>& words, Graph<string>& graph) {
    // WC = O(n*k^2),
    // BC = Theta(n*k^2)
    // TC = O(n*k^2)
    // n = number of words, k = word length
    map<string, vector<string>> wildcardMap;

    for (const auto& word : words) {
        for (int i = 0; i < word.length(); ++i) {
            string pattern = word;
            pattern[i] = '*';
            wildcardMap[pattern].push_back(word);
        }
    }

    for (const auto& [pattern, group] : wildcardMap) {
        for (const auto& w1 : group)
            for (const auto& w2 : group)
                if (w1 != w2)
                    graph.addEdge(w1, w2);
    }
}

vector<string> readFromFile(const string& filename, int wordLength) {
    ifstream in(filename);
    vector<string> words;
    string word;
    while (in >> word)
        if (word.length() == wordLength)
            words.push_back(word);
    return words;
}

