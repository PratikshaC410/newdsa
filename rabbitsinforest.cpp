class Solution {
public:
    int numRabbits(std::vector<int>& answers) {
        if (answers.empty()) {
            return 0;
        }
        std::unordered_map<int, int> answer_counts;
        for (int k : answers) {
            answer_counts[k]++;
        }

        int total_rabbits = 0;
        for (auto const& [k, F_k] : answer_counts) {
            
            // Group Size (G) is k + 1
            int group_size = k + 1;
            
            // Calculate the minimum number of groups needed to cover F_k observations.
            // We use integer arithmetic for the ceiling function: ceil(a/b) = (a + b - 1) / b
            
            // Number of groups (N_groups) = ceil(F_k / group_size)
            int N_groups = (F_k + group_size - 1) / group_size;
            
            // Minimum rabbits of this color = N_groups * group_size
            int rabbits_of_color = N_groups * group_size;
            
            total_rabbits += rabbits_of_color;
        }

        return total_rabbits;
    }
};