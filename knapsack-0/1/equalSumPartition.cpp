//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool solveEqualPartition(int W, int n, vector<int> &wt, vector<vector<int>> &t){
        if(W==0){
            return true;
        }
        if(n==0){
            return false;
        }
        //Check if value is already computed
        if(t[n][W]!=-1){
            return t[n][W];
        }
        if(wt[n-1]>W){//since greater => can't take
            return t[n][W]=solveEqualPartition(W,n-1,wt,t);
        }
        //otherwise check what is better
        return t[n][W]=solveEqualPartition(W-wt[n-1],n-1,wt,t) || solveEqualPartition(W,n-1,wt,t);
    }
  
    bool equalPartition(vector<int>& arr) {
        // code here
        int n=arr.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return false;
        }
        int W=sum/2;
        vector<vector<int>> t(n+1,vector<int> (W+1,-1));
        return solveEqualPartition(W,n,arr,t);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends