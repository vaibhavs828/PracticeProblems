//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
  
    bool subsetSumSolve(vector<int>arr, int sum, int t[][10001],int n){
        if(sum==0){
            return true;
        }//writing this first ensures that t[0][0] is true
        
        if(n==0){//Nothing to take from array
            return false;
        }
        
        if(t[n][sum]!=-1){
            return t[n][sum]==1;
        }
         bool flag;
        if(arr[n-1]<=sum){
            flag =  subsetSumSolve(arr,sum-arr[n-1],t,n-1) || subsetSumSolve(arr,sum,t,n-1);
            t[n][sum] = flag ? 1 : 0;
            return flag;
        }
        
        else{
            flag =  subsetSumSolve(arr,sum,t,n-1);
            t[n][sum] = flag ? 1 : 0;
            return flag;
        }
        t[n][sum] = flag ? 1 : 0;
        return flag;
        
    }
  
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        //initializing matrix
        int t[101][10001];
        int n = arr.size();
         for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
             
                t[i][j]=-1;
            }
        }
    return subsetSumSolve(arr,sum,t,n);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends