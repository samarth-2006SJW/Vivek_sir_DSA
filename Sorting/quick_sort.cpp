#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr,int low,int high){
    int pivot=low,l=low+1,r=high; 
    while(l<=r){
        while(l<=high && arr[pivot]>arr[l])
        {
            l++;
        }
        while(r>=low && arr[pivot]<arr[r]){
            r--;
        }
        if(l<r) swap(arr[l],arr[r]);
        else break;

    }
    swap(arr[pivot],arr[r]);return r;
}
void quick_sort(vector<int> &arr,int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
    }
}
int main(){
    vector<int> arr;int n;cout<<"ENter array size:";cin>>n;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        arr.push_back(k);
    }
    quick_sort(arr,0,n-1);
    for(auto it:arr) cout<<it<<" ";
    return 0;
}