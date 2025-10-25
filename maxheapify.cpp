#include <iostream>
#include <vector>
#include <algorithm>
void max_heapify(std::vector<int>& H, int n, int k) {
    int v = H[k];
    bool hoop = false;
    int j;            
    while (!hoop && 2 * k <= n) {
        j = 2 * k; 
        if (j < n && H[j] < H[j + 1]) {
            j = j + 1; 
        }

        if (v >= H[j]) {
            hoop = true;
        } else {
            H[k] = H[j];

            k = j;
        }
    }

    H[k] = v;
}
void build_max_heap(std::vector<int>& H, int n) {
    for (int i = n / 2; i >= 1; --i) {
        max_heapify(H, n, i);
    }
}




