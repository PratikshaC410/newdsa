#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void max_heap(vector<int>&H,int n,int k)
{
     int i;
    for(i=n/2;i>=1;i--)
    {
        k=i;
    int v=H[k];
    bool heap=false;
    int j;
    while(!heap && 2*k<=n)
    {
        j=2*k;
        if(j<n && H[j+1])
            j=j+1;
        if(v>=H[j])
            heap=true;
        else{
            H[k]=H[j];
            k=j;
        }
    }
    H[k]=v;
}
}


int main() { 
   int N;
    cin>>N;
   if(N<=0)
       return 0;
    vector<int> H(N+1);
    for(int i=1;i<=N;++i)
    {
        cin>>H[i];
    }
    max_heap(H,N,1);
    for(int i=1;i<=N;++i)
    {
        cout<<H[i]<<(i==N ? "":" ");
    }
    cout<<endl;
    
    return 0;
}