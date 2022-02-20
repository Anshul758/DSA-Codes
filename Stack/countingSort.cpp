#include "bits/stdc++.h"
using namespace std;
 
void countsort(int arr[], int n)
{   
    int k = arr[0];
    for(int i=0;i<n;i++)
        k=max(k,arr[i]);
    
    int count[10]={0};
    for(int i=0;i<n;i++)
       count[arr[i]]++;
    
    for(int i=1;i<=k;i++)
       count[i] += count[i-1];
 
    int ob[n];
    for(int i=n-1;i>=0;i--)
       ob[--count[arr[i]]] = arr[i];
   cout<<"sorted array:"<<" ";
   for(int i=0;i<n;i++)
      cout<<ob[i]<<" ";        
}
 
int main()
{ 
   cout<<"Anshul Sharma"<<endl<<"19SCSE1010376"<<endl;
   
   int arr[]={6,5,6,4,4,2,7,1,1,0};
   countsort(arr,10);
   return 0;
}
