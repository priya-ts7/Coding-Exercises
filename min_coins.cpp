// Minimum Coins

/* Question: Given a variety of coin types defining a currency system, find the minimum number of coins required to express a given amount of money.
Assume infinite supply of coins of every type.  */


const int MAX_VALUE=100005;

int minimum_coins(vector<int> coins, int value) 
{
    // Dp array of size (value+1) and pre filled value MAX_VALUE
    vector<int> dp(value+1, MAX_VALUE);
    // As number of coins required to make 0 value is 0
    dp[0]=0;
    // Following nested loop calculates the minimum number of coins required to make the value i and stored in dp table
    int n=coins.size();
    for(int i=1; i <= value; i++) {
        for(int j=0; j < n; j++) {
            if (i >= coins[j] and 1+dp[i-coins[j]] < dp[i]) {
                // Condition that we have found a better minimal solution
                dp[i]=1+dp[i-coins[j]];
            }
        }
    }
    // Recursive function that calculates the distinct combinations of minimal size that has the sum given to the input value
    return dp[value];
}
