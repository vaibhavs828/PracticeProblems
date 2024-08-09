//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solveEqualPartition(int n,int arr[],int W,int t[][1001]){
        //Base condition
        if (W==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(t[n][W]!=-1){
            return t[n][W];
        }
        
        
        if(arr[n-1]>W){
            return t[n][W] = solveEqualPartition(n-1,arr,W,t);
        }
        return t[n][W] = solveEqualPartition(n-1,arr,W-arr[n-1],t) || solveEqualPartition(n-1,arr,W,t);
        
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){//Is odd
            return 0;
        }
        int t[1001][1001];
        memset(t,-1,sizeof(t));
        return solveEqualPartition(N,arr,sum/2,t);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends