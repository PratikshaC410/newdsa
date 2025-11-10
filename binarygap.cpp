#include <iostream>
#include <string>
#include <algorithm>

class Solution {
private:
    std::string toBinary(int n) {
        if (n == 0) return "0";
        std::string s = "";
        while (n > 0) {
            s = (n % 2 == 0 ? "0" : "1") + s;
            n /= 2;
        }
        return s;
    }

public:
    int longestBinaryGap(int n) {
        std::string binary = toBinary(n);
        
        int maxGap = 0;
        // p1 tracks the index of the last '1' encountered
        int p1 = -1;
        
        // p2 is the current index being examined
        for (int p2 = 0; p2 < binary.length(); ++p2) {
            if (binary[p2] == '1') {
                
                if (p1 != -1) {
                    maxGap = std::max(maxGap, p2 - p1);
                }
                
                p1 = p2;
            }
        }
        
        return maxGap;
    }
};