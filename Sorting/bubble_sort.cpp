#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr;
    int n;cout<<"Enter size:";cin>>n;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        arr.push_back(k);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])
             swap(arr[j],arr[j+1]);
        }
    }
    cout<<"Sorted Array:";
    for(int i=0;i<arr.size();i++){
         cout<<arr[i]<<" ";
    }
   
    return 0;
}