class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
         if (x == y) return 0;
        
        unordered_set<int> visited;
        queue<pair<int, int>> q; 
        q.push({x, 0});
        visited.insert(x);
        
        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();
            
            if (curr == y) return steps;
            
            vector<int> next_vals;
           
            if (curr % 11 == 0) next_vals.push_back(curr / 11);
            
            if (curr % 5 == 0) next_vals.push_back(curr / 5);
          
            next_vals.push_back(curr - 1);
           
            next_vals.push_back(curr + 1);
            
            for (int nxt : next_vals) {
                if (nxt > 0 && visited.find(nxt) == visited.end()) {
                    visited.insert(nxt);
                    q.push({nxt, steps + 1});
                }
            }
        }
        
        return -1; 
    }
};