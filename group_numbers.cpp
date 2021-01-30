#Grouping numbers

/* Question: You are given an integer array arr of size n. Group and rearrange them (in-place) into evens and odds 
in such a way that group of all even integers appears on the left side and group of all odd integers appears on the right side. */

vector <int> solve(vector <int> arr) {
    int even=0;
    int odd =0;
    int len = arr.size();
    int result[len];
    if(arr.size() <=1)
    {
        return arr;
    }
    for (int i=0,even=0,odd=arr.size()-1;i<arr.size();i++)
    {
        if(arr[i] % 2 ==0){
            result[even] =arr[i];
            even++;
        }
        else{
            result[odd] = arr[i];
            odd--;
        }
    }
    
    for(int i=0;i<len;i++)
    {
        arr[i]=result[i];
    }
    return arr;
}
