// les05_16

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Entry
{
    string word;
    int count;
};

vector<Entry> getDictionary(string text);
vector<string> getWords(string text);

int main()
{
    string text
    { R"(
If you can keep your head when all about you
Are losing theirsand blaming it on you;
If you can trust yourself when all men doubt you,
But make allowance for their doubting too :
If you can wait and not be tired by waiting,
Or, being lied about, don't deal in lies,
Or being hated don't give way to hating,
And yet don't look too good, nor talk too wise;
    )" };

    cout << "From text" << endl;
    cout << text << endl;

    cout << "Create dictionary" << endl;
    cout << endl;

    vector<Entry> dictionary = getDictionary(text);
    for (auto entry : dictionary)
    {
        cout << setw(12) << entry.word << setw(4) << entry.count << endl;
    }
    cout << endl;

    _getch();
    return 0;
}

bool sortByWords(const string& word1, const string& word2)
{
    return word1 < word2;
}

vector<Entry> getDictionary(string text)
{
    vector<Entry> entries;
    vector<string> words = getWords(text);
    sort(words.begin(), words.begin() + words.size(), sortByWords);
    int i = 0;
    while (i < words.size())
    {
        Entry entry{ words[i], 0 };
        while (i < words.size() && words[i] == entry.word)
        {
            entry.count++;
            i++;
        }
        entries.push_back(entry);
    }
    return entries;
}

vector<string> getWords(string text)
{
    vector<string> words;
    int pos = 0;
    while (pos < text.size())
    {
        while (pos < text.size() && !isalpha(text[pos]))
        {
            pos++;
        }
        if (pos == text.size())
        {
            break;
        }
        int wordStart = pos;
        while (pos < text.size() && isalpha(text[pos]))
        {
            pos++;
        }
        int wordLen = pos - wordStart;
        words.push_back(text.substr(wordStart, wordLen));
    }
    return words;
}


