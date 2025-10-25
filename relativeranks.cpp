#include <vector>
#include <string>
#include <algorithm>
#include <map>

class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        int n = score.size();
        std::vector<std::pair<int, int>> indexed_scores(n);
        for (int i = 0; i < n; ++i) {
            indexed_scores[i] = {score[i], i};
        }

        std::sort(indexed_scores.begin(), indexed_scores.end(), 
                  [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                      return a.first > b.first; 
                  });
        std::vector<std::string> result(n);

        for (int i = 0; i < n; ++i) {
            int original_index = indexed_scores[i].second;
            int rank = i + 1; 

            if (rank == 1) {
                result[original_index] = "Gold Medal";
            } else if (rank == 2) {
                result[original_index] = "Silver Medal";
            } else if (rank == 3) {
                result[original_index] = "Bronze Medal";
            } else {
                result[original_index] = std::to_string(rank);
            }
        }

        return result;
    }
};