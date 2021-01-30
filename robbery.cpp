// Robbery 

/* Question: There are n houses built in a line, each of which contains some value in it. 
A thief is going to steal the maximal value in these houses, but he cannot steal in two adjacent houses because the owner of a stolen house will 
tell his two neighbors on the left and right side. What is the maximal stolen value?
For example, if there are four houses with values [6, 1, 2, 7], the maximal stolen value is 13, when the first and fourth houses are stolen. */

int max(int a, int b)
{
    return a > b ? a : b;    
}

int maxStolenValue(vector<int> values) 
{

    int size = (int) values.size();
    if (size < 1)
        return values[0];
        
    int* dp  = new int[size+1];
    dp[0] = 0;
    dp[1] = values[0];
    int result;
    
    for (int i = 1; i < size; i++) 
        dp[i+1] = max (dp[i], dp[i-1] + values[i]);
    
    result = dp[size];
    
    delete dp;
    return result;

}
