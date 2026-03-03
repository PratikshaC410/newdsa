class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        unordered_map<int, int> freq;

        // Count frequencies
        for (int card : deck)
        {
            freq[card]++;
        }

        //  GCD of all frequencies
        int g = 0;
        for (auto &p : freq)
        {
            g = gcd(g, p.second);
        }

        return g >= 2;
    }
};