// Count ways to reach the Nth stair

/* There are n stairs, a person standing at the bottom wants to reach the top. 
He can climb a certain number of steps at once. For instance, the person can climb either 1 stair or 2 stairs at a time. 
Count the number of ways, the person can reach the top.
Solve the problem for the general case i.e. for n stairs, and different kinds of steps that can be taken 
(e.g. instead of only 1 or 2 steps, it could be 2, 3 and 5 steps at a time). */

long long int countWaysToClimb(vector<int> steps, int n) {

    sort(steps.begin(),steps.end());
    
    vector<long long int> dp(n+1,0);
    if(n<steps[0])
    return 0;
     
    int s = 0;
    while(s<steps[0]){
            dp[s] = 0;
            s++;
    }
   
    dp[steps[0]] = 1;

    for(int i=steps[0]+1; i<n+1; i++){
        long long int temp = 0;
        for(auto x:steps){
            if((i-x)>=0){
                temp = temp + dp[i-x];
            }
            
            if((i-x)==0)
                temp = temp + 1;
        }
        
        dp[i] = temp;
    }
    
