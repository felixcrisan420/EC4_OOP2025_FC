//
// Created by felix on 5/22/2025.
//

#pragma once

#include <vector>
#include <string>
#include <QString>
#include <QSet>
#include "WordLadderGraph.h"
#include "utils.h"
using namespace std;
class GameEngine {
public:
    GameEngine(int wordLength);

    vector<string> getAllWords() const;
    vector<string> getPath(const string& start, const string& target);
    string getHint(const string& current, const string& target);
    bool isValidWord(const string& word) const;

private:
    int wordLength;
    vector<string> dictionary;
    Graph<string> graph;
    QSet<QString> dictionarySet;

    void loadAndBuild();
};

