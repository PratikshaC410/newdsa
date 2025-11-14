pair<string, long long> remove_pairs(const string& s, const string& target_pair, int points) {
    long long total_points = 0;
    string result_stack; // Acts as a stack to build the remaining string

    for (char c : s) {
        result_stack.push_back(c);

        // Check if the last two characters form the target pair
        if (result_stack.size() >= 2) {
            char last = result_stack.back();
            char second_last = result_stack[result_stack.size() - 2];

            if (second_last == target_pair[0] && last == target_pair[1]) {
                // Found the target pair, remove it (pop twice)
                result_stack.pop_back();
                result_stack.pop_back();
                total_points += points;
            }
        }
    }

    return {result_stack, total_points};
}

class Solution {
public:
    long long maximumGain(string s, int x, int y) {
        long long max_points = 0;
        string s_remaining;
        long long p1 = 0;
        long long p2 = 0;

        // --- Step 1: Determine the order and perform the first greedy removal ---

        if (x >= y) {
            // Prioritize "ab" (x points)
            
            // First pass: Remove "ab"
            auto result1 = remove_pairs(s, "ab", x);
            s_remaining = result1.first;
            p1 = result1.second;

            // Second pass: Remove "ba" from the remaining string
            auto result2 = remove_pairs(s_remaining, "ba", y);
            p2 = result2.second;
        } else {
            // Prioritize "ba" (y points)
            
            // First pass: Remove "ba"
            auto result1 = remove_pairs(s, "ba", y);
            s_remaining = result1.first;
            p1 = result1.second;

            // Second pass: Remove "ab" from the remaining string
            auto result2 = remove_pairs(s_remaining, "ab", x);
            p2 = result2.second;
        }

        // --- Step 2: Calculate the total maximum points ---
        max_points = p1 + p2;
        return max_points;
    }
};