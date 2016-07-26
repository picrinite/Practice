#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main() {
    char c;
    vector<string> vecWords;
    string word;
    while (cin.get(c)) {
        if (c == ' ' || c == '\n' || c == ',' || c == '.') {
            if (word.length()) {
                vecWords.push_back(word);
                word = "";
            }
            if (c != ' ')
                vecWords.push_back(string{c});
            continue;
        }
        if (c >= 'A' && c <= 'Z')
            c += 32;
        word += c;
    }
    bool foundPeriod = true;
    for (unsigned i = 0; i < vecWords.size(); ++i) {
        string & word = vecWords[i];
        if (word[0] >= 'a' && word[0] <= 'z') {
            if (foundPeriod) {
                word[0] -= 32;
                if (i && vecWords[i - 1] == ".")
                    cout << " ";
            }
            else
                cout << " ";
            foundPeriod = false;
        }
        cout << word;
        if (word == ".")    foundPeriod = true;
    }
    return 0;
}