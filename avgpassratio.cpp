#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

class Solution {
private:
   
    double calculateDelta(double p, double t) {
        return (p + 1.0) / (t + 1.0) - p / t;
    }

public:
    double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents) {
        using ClassData = std::tuple<double, int, int>;
        std::priority_queue<ClassData> maxHeap;
        
        for (const auto& cls : classes) {
            int p = cls[0];
            int t = cls[1];
            double delta = calculateDelta(p, t);
            maxHeap.push({delta, p, t});
        }
        
        for (int i = 0; i < extraStudents; ++i) {
            ClassData currentClass = maxHeap.top();
            maxHeap.pop();
            
            int p = std::get<1>(currentClass);
            int t = std::get<2>(currentClass);
            
            p++;
            t++;
            
            double newDelta = calculateDelta(p, t);
            maxHeap.push({newDelta, p, t});
        }
        
        double sumOfRatios = 0.0;
        int numClasses = classes.size();
        
        while (!maxHeap.empty()) {
            ClassData finalClass = maxHeap.top();
            maxHeap.pop();
            
            double finalPass = std::get<1>(finalClass);
            double finalTotal = std::get<2>(finalClass);
            
            sumOfRatios += finalPass / finalTotal;
        }
        
        return sumOfRatios / numClasses;
    }
};

