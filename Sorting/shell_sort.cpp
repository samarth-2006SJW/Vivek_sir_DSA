#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr;
    int n;cout<<"Enter size:";cin>>n;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        arr.push_back(k);
    }
    for(int gap=n/2;gap>0;gap/=2)
    {
        for(int i=gap;i<n;i++){
        int j=i;
        int key=arr[i];
        while(j>=gap && arr[j-gap]>key){
            arr[j]=arr[j-gap];
            j-=gap;
        }
        arr[j]=key;
        }

    }
    
    cout<<"Sorted Array:";
    for(int i=0;i<arr.size();i++){
         cout<<arr[i]<<" ";
    }
   
    return 0;
}