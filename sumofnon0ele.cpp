class Solution {
private:
    
    bool isNoZero(int k) {
        while (k > 0) {
            if (k % 10 == 0) {
                return false; 
            }
         
            k /= 10;
        }
        return true; 
    }

public:
    
    std::vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; ++a) {
            int b = n - a;
            
            if (isNoZero(a) && isNoZero(b)) {
                return {a, b};
            }
        }
        
        return {}  ;
    }
};