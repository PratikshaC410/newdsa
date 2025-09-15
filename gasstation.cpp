#include <vector>
#include <numeric>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int total_gas = 0;
        int total_cost = 0;
        int current_tank = 0;
        int start_index = 0;

        for (int i = 0; i < gas.size(); ++i) {
            total_gas += gas[i];
            total_cost += cost[i];
            current_tank += gas[i] - cost[i];

            // If the current tank becomes negative, it means we can't reach the next station
            // from the current start_index. So, we reset the starting point to the next station.
            if (current_tank < 0) {
                start_index = i + 1;
                current_tank = 0;
            }
        }

        // If the total gas is less than the total cost, it's impossible to complete the circuit.
        if (total_gas < total_cost) {
            return -1;
        } else {
            return start_index;
        }
    }
};