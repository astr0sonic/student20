#include "bits/stdc++.h"
#include "volume.h"
using namespace std;

int getMaxVolume(int a, int b, int c, int n, int* arr) {
    int mx=0,ans=0;
    for(int i=0;i+a<n;i++){
        if(min(arr[i],arr[a+i])>ans&&min(arr[i],arr[a+i])<=c){
            ans=min(arr[i],arr[a+i]);
            mx=i;
        }
    }
    int l=mx,r=l+min(a,n-1);
    ans*=a;
    while(r>l){
        if(min(arr[l],arr[r])<=c){
            ans=max(ans,(r-l)*min(arr[l],arr[r]));
        }
        if(arr[l]>arr[r]){
            r--;
        }
        else{
            l++;
        }
    }
    return ans*b;
}