#include <vector>
using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        auto nextIndex = [&](int i) {
            int next = ((i + nums[i]) % n + n) % n; // handle wrap-around safely
            return next;
        };

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue; // already visited

            int slow = i, fast = i;
            bool forward = nums[i] > 0; // direction we must maintain

            while (true) {
                // Move slow one step
                int nextSlow = nextIndex(slow);
                if ((nums[nextSlow] > 0) != forward || nums[nextSlow] == 0) break;

                // Move fast one step
                int nextFast = nextIndex(fast);
                if ((nums[nextFast] > 0) != forward || nums[nextFast] == 0) break;
                // Move fast another step
                nextFast = nextIndex(nextFast);
                if ((nums[nextFast] > 0) != forward || nums[nextFast] == 0) break;

                slow = nextSlow;
                fast = nextFast;

                if (slow == fast) {
                    if (slow == nextIndex(slow)) break; // single element loop not valid
                    return true;
                }
            }

            // Mark path visited as 0
            int idx = i;
            while ((nums[idx] > 0) == forward && nums[idx] != 0) {
                int next = nextIndex(idx);
                nums[idx] = 0; // mark visited
                idx = next;
            }
        }

        return false;
    }
};
