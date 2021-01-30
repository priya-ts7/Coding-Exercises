# Merge one sorted array into another

/* Question : Given two arrays:
1) arr1 of size n, which contains n positive integers sorted in the ascending order.
2) arr2 of size (2*n) (twice the size of first), which contains n positive integers sorted in the ascending order in its first half. 
Second half of this array arr2 is empty. (Empty elements are marked by 0).
Write a function that takes these two arrays, and merges the first one into second one, resulting in an increasingly sorted array of (2*n) positive integers. */

void merger_first_into_second(vector<int>& arr1, vector<int>& arr2) {   
    int n = arr1.size();
    
	// Start merging from the end. 
	int last1 = n - 1;
	int last2 = n - 1;
	int last = n + n - 1;
  
	//While at least one array element is reamining. 
	while (last >= 0)
	{
		// If no elements remaining in arr1.
		if (last1 < 0)
		{
            // Considering the case when arr1 = [4, 5, 6] arr2 = [1, 2, 3, 0, 0, 0].
            // Once last1 = -1, arr2 will be [1, 2, 3, 4, 5, 6]. Hence, break.
            break;
		}
    
		// If no elements remaining in arr2.
		else if (last2 < 0)
		{
			arr2[last--] = arr1[last1--];
		}
    
		// Priority to larger element, as we are merging from the end. 
		else if (arr1[last1] <= arr2[last2])
		{
			arr2[last--] = arr2[last2--];
		}
    
		else
		{
			arr2[last--] = arr1[last1--];
		}
	}
}
