#include <vector>
#include <algorithm>
#include <cstdlib> // Required for std::rand and std::srand
#include <ctime>   // Required for std::time

class Solution {
private:
    /**
     * Swaps the pivot element at a random index with the element at the 'high' index.
     */
    void chooseRandomPivot(std::vector<int>& nums, int low, int high) {
        // Seed the random number generator only once (better done outside the function/class)
        // For simplicity in a single class method, we can use it here, 
        // but typically srand is called once at program start.
        // std::srand(std::time(0)); 
        
        // Generate a random index between low and high (inclusive)
        int random_index = low + (std::rand() % (high - low + 1));
        
        // Swap the random element with the element at the high index
        std::swap(nums[random_index], nums[high]);
    }

    /**
     * Revised Partition function using a Random Pivot.
     */
    int partition(std::vector<int>& nums, int low, int high) {
        // STEP 1: Choose a random pivot and move it to the 'high' position
        chooseRandomPivot(nums, low, high);
        
        // The rest is the standard Lomuto partition scheme with the new pivot
        int pivot = nums[high]; 
        int i = (low - 1); 

        for (int j = low; j <= high - 1; j++) {
            if (nums[j] <= pivot) {
                i++;
                std::swap(nums[i], nums[j]);
            }
        }
        
        // Place the pivot element in its correct sorted position
        std::swap(nums[i + 1], nums[high]);
        return (i + 1);
    }
    
    // ... (quickSort function remains the same)

    void quickSort(std::vector<int>& nums, int low, int high) {
        if (low < high) {
            int pi = partition(nums, low, high);
            quickSort(nums, low, pi - 1);
            quickSort(nums, pi + 1, high);
        }
    }

public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        if (nums.empty()) {
            return nums;
        }
        
        // IMPORTANT: Seed the random number generator before using rand()
        std::srand(std::time(0)); 
        
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};