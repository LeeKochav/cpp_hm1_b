#pragma once

#include <iostream>
#include <string> 
#include <vector>

using namespace std ; 

namespace phonetic
{
    string find(string text,string word);
};

size_t split(const string &txt, vector<string> &strs, char ch);
string to_lower(string str);
bool isAMatch(string text_word, string word);