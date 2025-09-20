class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        
        for (auto& op : operations) {
            if (op == "C") {
                // Invalidate previous score
                record.pop_back();
            } 
            else if (op == "D") {
                // Double previous score
                record.push_back(2 * record.back());
            } 
            else if (op == "+") {
                // Sum of previous two scores
                int n = record.size();
                record.push_back(record[n - 1] + record[n - 2]);
            } 
            else {
                // Integer score
                record.push_back(stoi(op));
            }
        }
        
        int total = 0;
        for (int score : record) {
            total += score;
        }
        return total;
    }
};