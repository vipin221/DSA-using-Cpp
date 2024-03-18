#include<iostream>
#include<vector>
using namespace std;
int solveRecursion(int weight[], int value[], int capacity, int index){
     // base case
    if(index == 0){
        if(weight[0] <= capacity) return value[0];
        else return 0;
    }
    // include  and exclude pattern 
    int include = INT_MIN;
    if(weight[index] <= capacity)
    include = value[index] + solveRecursion(weight, value, capacity - weight[index], index -1);
    int exclude =  0 + solveRecursion(weight , value, capacity, index-1);
    int ans   = max(include, exclude);
    return ans;

}
int solveUsingMem(int weight[], int value[], int capacity, int index, vector<vector<int>>&dp){
     // base case
    if(index == 0){
        if(weight[0] <= capacity) return value[0];
        else return 0;
    }
    if(dp[index][capacity] != -1) return dp[index][capacity];
     // include  and exclude pattern 
     int include = 0;
    if(weight[index] <= capacity)
    include = value[index] + solveUsingMem(weight, value, capacity - weight[index], index -1,dp);
    int exclude =  0 + solveUsingMem(weight , value, capacity, index-1,dp);
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];

}

int solveUsingTabular(int weight[], int value[], int n, int capacity){
    vector<vector<int>>dp(n+1, vector<int>(capacity+1, 0));

    for(int w = weight[0]; w<=capacity; w++){
        if(w <= capacity){
            dp[0][w] = weight[0];
        
        }
        else{
            dp[0][w] = 0;
        }
    }

    for(int index = 1; index<=n; index++){
        for(int wt = 0; wt<=capacity; wt++){
            int include = 0;
            if(weight[index] <= wt)
            include = value[index] + dp[index-1][wt - weight[index]];
            int exclude = dp[index-1][wt];
            dp[index][wt] = max(include, exclude);
           

        }
    }
     return dp[n][capacity];
}
int solveUsingTabularSO(int weight[], int value[], int n, int capacity){
    // vector<vector<int>>dp(n+1, vector<int>(capacity+1, 0));
    vector<int>prev(capacity+1, 0);
    vector<int>curr(capacity+1, 0);

    for(int w = weight[0]; w<=capacity; w++){
        if(w <= capacity){
            prev[w] = weight[0];
        
        }
        else{
            prev[w] = 0;
        }
    }

    for(int index = 1; index<=n; index++){
        for(int wt = 0; wt<=capacity; wt++){
            int include = 0;
            if(weight[index] <= wt)
            include = value[index] + prev[wt - weight[index]];
            int exclude = prev[wt];
            curr[wt] = max(include, exclude);

            

        }
        //shift
            prev = curr;
    }
     return prev[capacity];
}
int solveUsingTabularSO2(int weight[], int value[], int n, int capacity){
    // vector<vector<int>>dp(n+1, vector<int>(capacity+1, 0));
    // vector<int>prev(capacity+1, 0);
    vector<int>curr(capacity+1, 0);

    for(int w = weight[0]; w<=capacity; w++){
        if(w <= capacity){
            curr[w] = weight[0];
        
        }
        else{
            curr[w] = 0;
        }
    }

    for(int index = 1; index<=n; index++){
        for(int wt = capacity; wt>=0; wt--){
            int include = 0;
            if(weight[index] <= wt)
            include = value[index] + curr[wt - weight[index]];
            int exclude = curr[wt];
            curr[wt] = max(include, exclude);

            

        }
        
    }
     return curr[capacity];
}


int main(){
    int weight[] ={3,5,2};
    int value[]= {3,2,5};
    int capacity = 5;
     int n = 3;

    // int ans = solveRecursion(weight, value, capacity, 2); 
    // since two parameter ischagning so it is a 2d dp problem 
    // vector<vector<int>> dp(n, vector<int>(capacity+1 , -1));
    // int ans  =  solveUsingMem(weight, value , capacity, n-1, dp );
    // int ans  =  solveUsingTabular(weight, value , n, capacity);
    // int ans  =  solveUsingTabularSO(weight, value , n, capacity);
    int ans  =  solveUsingTabularSO2(weight, value , n, capacity);
    cout << "ans "<< ans<<endl; 
return 0;
}