//
// Created by felix on 5/28/2025.
//

#include "engine.h"
#include <algorithm>
#include <random>
#include <QDebug>
using namespace std;

GameEngine::GameEngine(int wordLength) : wordLength(wordLength) {
        loadAndBuild();
}

void GameEngine::loadAndBuild() {
    qDebug() << "Loading...\n";
    dictionary = readFromFile("C:/Programming/Uni/OOP_A1S2/Extra Credit/ExtraCredit4_Qt/EC4/words.txt", wordLength);

    qDebug() << "Words loaded:" << dictionary.size();

    for (const auto& word : dictionary)
        dictionarySet.insert(QString::fromStdString(word));

    buildGraphFromDictionary(dictionary, graph);
}

vector<string> GameEngine::getAllWords() const {
    return dictionary;
}

vector<string> GameEngine::getPath(const string& start, const string& target) {
    return graph.bfs(start, target);
}

bool GameEngine::isValidWord(const string& word) const {
    return dictionarySet.contains(QString::fromStdString(word));
}

string GameEngine::getHint(const string& current, const string& target) {
    for (int i = 0; i < current.size(); ++i) {
        if (current[i] != target[i]) {
            string hint = current;
            hint[i] = target[i];
            if (isValidWord(hint))
                return hint;
        }
    }
    return "";
}

