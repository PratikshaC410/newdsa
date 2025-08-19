class Solution {
public:
    vector<string> topNCompetitors(
        int numCompetitors, 
        int topNCompetitors, 
        vector<string>& competitors, 
        int numReviews, 
        vector<string>& reviews
    ) {
        // Convert competitors to lowercase and store in set
        unordered_set<string> competitorSet;
        for (string comp : competitors) {
            transform(comp.begin(), comp.end(), comp.begin(), ::tolower);
            competitorSet.insert(comp);
        }

        // Count how many reviews mention each competitor
        unordered_map<string,int> mentionCount;
        
        for (string review : reviews) {
            transform(review.begin(), review.end(), review.begin(), ::tolower);
            stringstream ss(review);
            string word;
            unordered_set<string> seen;  // avoid double counting in one review
            
            while (ss >> word) {
                if (competitorSet.count(word) && !seen.count(word)) {
                    mentionCount[word]++;
                    seen.insert(word);
                }
            }
        }

        // Move to vector for sorting
        vector<pair<string,int>> compList(mentionCount.begin(), mentionCount.end());

        // Sort: highest frequency first, then alphabetically
        sort(compList.begin(), compList.end(), [](auto &a, auto &b) {
            if (a.second == b.second) 
                return a.first < b.first;
            return a.second > b.second;
        });

        // Collect top N results
        vector<string> result;
        for (int i = 0; i < topNCompetitors && i < (int)compList.size(); i++) {
            result.push_back(compList[i].first);
        }

        return result;
    }
};
