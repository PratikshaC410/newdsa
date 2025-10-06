#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

// Comparator for sorting pairs
bool compareCompetitors(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second != b.second) {
        return a.second > b.second; // Sort by frequency in descending order
    }
    return a.first < b.first; // For ties, sort alphabetically
}

string toLower(const string& str) {
    string lower_str = str;
    transform(lower_str.begin(), lower_str.end(), lower_str.begin(),
                   [](unsigned char c){ return tolower(c); });
    return lower_str;
}

vector<string> getTopNCompetitors(int numCompetitors, int topNCompetitors,
                                            const vector<string>& competitors,
                                            int numReviews, const vector<string>& reviews) {
    
    map<string, int> competitorCounts;
    map<string, string> lowerToOriginalName;
    
    for (const auto& comp : competitors) {
        string lowerComp = toLower(comp);
        lowerToOriginalName[lowerComp] = comp;
        competitorCounts[lowerComp] = 0;
    }

    for (const auto& review : reviews) {
        stringstream ss(review);
        string word;
        while (ss >> word) {
            string lowerWord = toLower(word);
            // Remove punctuation from the end of the word
            if (!lowerWord.empty() && ispunct(lowerWord.back())) {
                lowerWord.pop_back();
            }
            if (competitorCounts.count(lowerWord)) {
                competitorCounts[lowerWord]++;
            }
        }
    }
    
    vector<pair<string, int>> sortedCompetitors;
    for (const auto& pair : competitorCounts) {
        if (pair.second > 0) {
            sortedCompetitors.push_back(pair);
        }
    }
    
    sort(sortedCompetitors.begin(), sortedCompetitors.end(), compareCompetitors);

    vector<string> result;
    int n = min((size_t)topNCompetitors, sortedCompetitors.size());
    for (int i = 0; i < n; ++i) {
        result.push_back(lowerToOriginalName[sortedCompetitors[i].first]);
    }
    
    return result;
}

int main() {
    int numCompetitors = 6;
    int topNCompetitors = 2;
    vector<string> competitors = {"newshop", "shopnow", "mymarket", "bargain", "discount", "deal"};
    int numReviews = 6;
    vector<string> reviews = {
        "newshop is a good site for deal. newshop also has discount",
        "i love the deal on mymarket",
        "mymarket is better than newshop",
        "shopnow is so cheap",
        "bargain is a great site",
        "deal, deal, deal, mymarket, mymarket"
    };
    
    vector<string> top_competitors = getTopNCompetitors(numCompetitors, topNCompetitors, competitors, numReviews, reviews);

    cout << "Top " << topNCompetitors << " competitors:" << endl;
    for (const auto& comp : top_competitors) {
        cout << comp << endl;
    }
    
    return 0;
}