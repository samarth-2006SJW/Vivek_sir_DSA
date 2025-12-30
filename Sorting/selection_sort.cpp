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
        int min=i;
        int j=0;
        for( j=i+1;j<n;j++){
            if(arr[j]<arr[min])
             min=j;
            
        }
        swap(arr[i],arr[min]);
    }
    cout<<"Sorted Array:";
    for(int i=0;i<arr.size();i++){
         cout<<arr[i]<<" ";
    }
   
    return 0;
}