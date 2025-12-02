class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        // Left pass
        int balls = 0;      // number of balls to the left
        int moves = 0;      // total moves needed so far
        for (int i = 0; i < n; i++) {
            answer[i] += moves;
            if (boxes[i] == '1') balls++;
            moves += balls;  // every ball moves 1 step to the right
        }

        // Right pass
        balls = 0;
        moves = 0;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] += moves;
            if (boxes[i] == '1') balls++;
            moves += balls;  // every ball moves 1 step to the left
        }

        return answer;
    }
};
