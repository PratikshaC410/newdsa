class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;

    // Count frequencies
    for (int x : nums) {
        freq[x]++;
    }

    // Find maximum frequency
    int maxFreq = 0;
    for (auto& p : freq) {
        maxFreq = max(maxFreq, p.second);
    }

    // Sum all frequencies equal to maxFreq
    int total = 0;
    for (auto& p : freq) {
        if (p.second == maxFreq) {
            total += p.second;
        }
    }

    return total;   
    }
};