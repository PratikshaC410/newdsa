#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;  
        string token;

        for (char c : path) {
            if (c == '/') {
                if (!token.empty()) {
                    if (token == "..") {
                        if (!stack.empty()) stack.pop_back();
                    } else if (token != ".") {
                        stack.push_back(token);
                    }
                    token.clear();
                }
            } else {
                token.push_back(c);
            }
        }
        if (!token.empty()) {
            if (token == "..") {
                if (!stack.empty()) stack.pop_back();
            } else if (token != ".") {
                stack.push_back(token);
            }
        }

        string result = "/";
        for (int i = 0; i < stack.size(); i++) {
            result += stack[i];
            if (i < stack.size() - 1) result += "/";
        }
        return result;
    }
};
