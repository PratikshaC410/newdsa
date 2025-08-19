#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_map<string, vector<string>> favoriteGenres(
    unordered_map<string, vector<string>>& userSongs,
    unordered_map<string, vector<string>>& songGenres) {
    
    unordered_map<string, vector<string>> result;

    // Step 1: Build song-to-genre map
    unordered_map<string, string> songToGenre;
    for (const auto& genrePair : songGenres) {
        string genre = genrePair.first;
        for (const string& song : genrePair.second) {
            songToGenre[song] = genre;
        }
    }

    // Step 2: For each user, count genres
    for (const auto& userPair : userSongs) {
        string user = userPair.first;
        const vector<string>& songs = userPair.second;

        unordered_map<string, int> genreCount;
        int maxCount = 0;

        for (const string& song : songs) {
            if (songToGenre.count(song)) {
                string genre = songToGenre[song];
                genreCount[genre]++;
                maxCount = max(maxCount, genreCount[genre]);
            }
        }

        // Step 3: Find all genres with max count
        vector<string> favorites;
        for (const auto& pair : genreCount) {
            if (pair.second == maxCount) {
                favorites.push_back(pair.first);
            }
        }

        result[user] = favorites;
    }

    return result;
}
