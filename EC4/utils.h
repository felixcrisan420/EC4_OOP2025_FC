//
// Created by felix on 5/22/2025.
//


#pragma once

#include <string>
#include <vector>
#include "WordLadderGraph.h"

using namespace std;

bool oneLetterDiff(const string& a, const string& b);
void buildGraphFromDictionary(const vector<string>& words, Graph<string>& graph);
vector<string> readFromFile(const string& filename, int wordLength);
