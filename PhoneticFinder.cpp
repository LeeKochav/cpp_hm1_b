#include "PhoneticFinder.hpp"

#include <stdexcept>

size_t split(const string &txt, vector<string> &strs, char ch)
{
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    strs.clear();

    while (pos != string::npos)
    {
        strs.push_back(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;

        pos = txt.find(ch, initialPos);
    }

    // Add the last one
    strs.push_back(txt.substr(initialPos, min(pos, txt.size()) - initialPos + 1));

    return strs.size();
}

string to_lower(string str)
{
    string ans = str;
    for(int i = 0 ; i < str.size(); i++)
    {
        ans[i] = tolower(str[i]);
    }
    return ans;
}

bool isAMatch(string text_word, string word)
{
    if(text_word.size()!=word.size())
    {
        return false;
    }
    for(int i=0; i<word.size(); i++)
    {
        if(word[i]==text_word[i]) continue;

        else
        {
            switch (word[i])
            {
            case 'v':
                if(text_word[i]!='w') return false;
                break;

            case 'w':
                if(text_word[i]!='v') return false;
                break;

            case 'b':
                if(text_word[i]!='f' && text_word[i]!='p') return false;
                break;

            case 'f':
                if(text_word[i]!='b'&& text_word[i]!='p') return false;
                break;
            
             case 'p':
                if(text_word[i]!='b' && text_word[i]!='f') return false;
                break;

            case 'g':
                if(text_word[i]!='j') return false;
                break;

            case 'j':
                if(text_word[i]!='g') return false;
                break;

            case 'c':
                if(text_word[i]!='k'&& text_word[i]!='q') return false;
                break;
            
            case 'k':
                if(text_word[i]!='c'&& text_word[i]!='q') return false;
                break;

             case 'q':
                if(text_word[i]!='c'&&text_word[i]!='k') return false;
                break;
            
            case 's':
                if(text_word[i]!='z') return false;
                break;
            
            case 'z':
                if(text_word[i]!='s') return false;
                break;
            
            case 'd':
                if(text_word[i]!='t') return false;
                break;
            
            case 't':
                if(text_word[i]!='d') return false;
                break;

            case 'o':
                if(text_word[i]!='u') return false;
                break;

            case 'u':
                if(text_word[i]!='o') return false;
                break;

             case 'i':
                if(text_word[i]!='y') return false;
                break;

            case 'y':
                if(text_word[i]!='i') return false;
                break;

            default:
            return false;
            break;
            }
        }
        
    }
    return true;
}

string phonetic::find(string text,string word)
{
    if(word.size()==0)
    {
        throw exception();
    }
    else if(word.find(" ")!=string::npos)
    {
        throw exception();
    }

    bool isInText = false;
    string word_lower=to_lower(word);
    vector<string> text_split;
    split(text, text_split, ' ');

    for (string text_word : text_split)
    {
        string text_word_lower=to_lower(text_word);
        if(isAMatch(text_word_lower,word_lower))
        {
            return text_word;
        }
    }
     throw exception();
}


