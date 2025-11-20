class Solution {
public:
    int intersectionSizeTwo(std::vector<std::vector<int>>& intervals) {
        // 1. Sort the intervals
        // Sort by end time (ascending). If end times are equal, sort by start time (descending).
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1]; // Primary sort: end time ascending
            }
            return a[0] > b[0]; // Secondary sort: start time descending
        });

        int min_set_size = 0;
        // The two largest points chosen so far that satisfy the most recently processed interval.
        // Initialize to impossible values. point1 < point2 is always maintained.
        int point1 = -1; 
        int point2 = -1;

        // 2. Iterate and Choose Points
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            // Case 1: Fully Satisfied (point1 and point2 are both >= start)
            if (point1 >= start) {
                // Since point1 < point2, if point1 is inside [start, end], point2 must be too.
                // Already covered by the two largest chosen points. Do nothing.
                continue;
            } 
            
            // Case 2: Partially Satisfied (Only point2 is >= start)
            else if (point2 >= start) {
                // The interval is covered by one point (point2), but needs one more.
                // We add one new point: the largest possible point, which is 'end'.
                
                // Update the two largest points:
                // The new largest points are point2 and end.
                point1 = point2;
                point2 = end;
                min_set_size++;
            } 
            
            // Case 3: Not Satisfied (point2 < start)
            else {
                // The interval is not covered by any existing point. It needs two new points.
                // We must add two new points: the two largest possible points, 'end - 1' and 'end'.

                // Update the two largest points:
                point1 = end - 1;
                point2 = end;
                min_set_size += 2;
            }
        }

        return min_set_size;
    }
};