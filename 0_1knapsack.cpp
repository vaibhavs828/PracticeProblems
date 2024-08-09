//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int knapSackSolve(int W, int wt[], int val[], int n, int t[][1001])
    {
        // Check if result is already computed
        if (t[n][W] != -1)
            return t[n][W];

        // Base condition
        if (n == 0 || W == 0)
            return 0;

        // If weight of the nth item is more than knapsack capacity W
        if (wt[n - 1] > W)
            return t[n][W] = knapSackSolve(W, wt, val, n - 1, t);

        // Take the maximum of including the nth item or excluding it
        return t[n][W] = max(val[n - 1] + knapSackSolve(W - wt[n - 1], wt, val, n - 1, t),
                             knapSackSolve(W, wt, val, n - 1, t));
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        //Initialize dp array
        int t[1001][1001];
        memset(t,-1,sizeof(t));
       // Your code here
       
    
      return knapSackSolve(W,wt,val,n,t);
    
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends