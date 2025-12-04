#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool started = false;

        for (int i = 0; i < num.size(); i++) {
            int d = num[i] - '0';

            if (!started) {
                if (change[d] > d) {
                    started = true;
                    num[i] = char(change[d] + '0');
                }
            } else {
                if (change[d] >= d) {
                    num[i] = char(change[d] + '0');
                } else {
                    break;
                }
            }
        }
        return num;
    }
};
