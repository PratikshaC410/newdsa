// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
         int n = arr1.size();
    int i = 0, j = 0, count = 0;
    int m1 = -1, m2 = -1;

    // We need elements at index n-1 and n (0-based) in merged array
    for (count = 0; count <= n; count++) {
        if (i != n && (j == n || arr1[i] <= arr2[j])) {
            m1 = m2;
            m2 = arr1[i];
            i++;
        } else {
            m1 = m2;
            m2 = arr2[j];
            j++;
        }
    }

    return m1 + m2;// code here
        
    }
};