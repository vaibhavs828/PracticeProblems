//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public: 
    int solveCountPartitions(int n,int W, vector<int> &wt, vector<vector<int>> &t){
        if(W==0 && n==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(t[n][W]!=-1){
            return t[n][W];
        }
        if(wt[n-1]>W){
            t[n][W] = solveCountPartitions(n-1,W,wt,t);
        }
        else{
            t[n][W] = solveCountPartitions(n-1,W,wt,t) + solveCountPartitions(n-1,W-wt[n-1],wt,t);
        }
        return t[n][W];
    }
  
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int sumArray = 0;
        for(int i=0;i<arr.size();i++){
            sumArray+=arr[i];
        }
        // Check if it's possible to split the array
        if ((sumArray + d) % 2 != 0 || sumArray < d) {
            return 0;
        }
        int targetSum=(sumArray+d)/2;
        vector<vector<int>> t(arr.size()+1,vector<int>(targetSum+1,-1));
        return solveCountPartitions(arr.size(),targetSum,arr,t);
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends