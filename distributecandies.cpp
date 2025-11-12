#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
    sort(candyType.begin(), candyType.end()); // sort to group same types
    int uniqueTypes = 1; // first candy type counts

    // count how many unique types
    for (int i = 1; i < n; i++) {
        if (candyType[i] != candyType[i - 1]) {
            uniqueTypes++;
        }
    }

    // she can only eat n/2 candies
    int maxAllowed = n / 2;

    // return the smaller of the two
    if (uniqueTypes < maxAllowed)
        return uniqueTypes;
    else
        return maxAllowed;
    }
};
