class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (auto &i : nums)
            freq[i]++;

        vector<pair<int, int>> sorted_freq;
        for (auto &[num, count] : freq)
            sorted_freq.push_back({count, num});

        sort(sorted_freq.rbegin(), sorted_freq.rend());
        vector<int> result;
        for (int i = 0; i < k; i++)
            result.push_back(sorted_freq[i].second);

        return result;
    }
};
