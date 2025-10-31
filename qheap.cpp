#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int arr[1000005];
int sizee = 0;

void heapup(int k) {
    int v = arr[k];
    while (k > 1 && arr[k / 2] > v) {
        arr[k] = arr[k / 2];
        k = k / 2;
    }
    arr[k] = v;
}

void heapdown(int k) {
    int v = arr[k];
    while (2 * k <= sizee) {
        int j = 2 * k;
        if (j < sizee && arr[j + 1] < arr[j]) {
            j++;
        }
        if (v <= arr[j]) break;
        arr[k] = arr[j];
        k = j;
    }
    arr[k] = v;
}

void insertt(int v) {
    sizee++;
    arr[sizee] = v;
    heapup(sizee);
}

void delett(int v) {
    int k = -1;
    for (int i = 1; i <= sizee; i++) {
        if (arr[i] == v) {
            k = i;
            break;
        }
    }
    if (k == -1) return;

    arr[k] = arr[sizee];
    sizee--;

    if (k <= sizee) {
        if (k > 1 && arr[k] < arr[k / 2])
            heapup(k);
        else
            heapdown(k);
    }
}

int main() {


    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int v;cin >> v;
            insertt(v);
        } else if (type == 2) {
            int v;cin >> v;
            delett(v);
        } else if (type == 3) {
            if (sizee > 0)
                cout << arr[1] << "\n";
        }
    }
    return 0;
}