#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr;
    int n;cout<<"Enter size:";cin>>n;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        arr.push_back(k);
    }
    for(int i=1;i<n;i++){
        int j=i-1;
        int key=arr[i];
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        
    }
    cout<<"Sorted Array:";
    for(int i=0;i<arr.size();i++){
         cout<<arr[i]<<" ";
    }
   
    return 0;
}