class Solution {
public:
  bool canConstruct(std::string ransomNote, std::string magazine) {
        int counts[26] = {0}; 
        for (char c : magazine) {
            // Convert character 'c' to its corresponding index (0-25)
            counts[c - 'a']++;
        }
        
        // 3. Check if there are enough characters for the ransomNote.
        for (char c : ransomNote) {
            int index = c - 'a';
            
            // Decrement the count for the required character.
            counts[index]--;
            
            // If the count drops below zero, it means the magazine 
            // has run out of this character.
            if (counts[index] < 0) {
                return false;
            }
        }
        
        // 4. If the entire ransomNote is processed without returning false, 
        // it means all required letters were available.
        return true;
    }
};