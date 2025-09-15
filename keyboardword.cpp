#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        using namespace std;

        vector<string> result;
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        unordered_map<char, int> keyboardMap;
        for (char c : row1) keyboardMap[c] = 1;
        for (char c : row2) keyboardMap[c] = 2;
        for (char c : row3) keyboardMap[c] = 3;

        for (const string& word : words) {
            if (word.empty()) continue;

            int row = keyboardMap[tolower(word[0])];
            bool sameRow = true;

            for (char c : word) {
                if (keyboardMap[tolower(c)] != row) {
                    sameRow = false;
                    break;
                }
            }

            if (sameRow) {
                result.push_back(word);
            }
        }
        return result;
    }
};