#Merge sort Implementation
#Recursive Solution

void merge(vector<int> &A, vector<int> &B, int begin, int mid, int end)
{   
    #First element of left array
    int i=begin;  
    #First element of right array
    int j=mid+1;  
    #First element of temporary array
    int k=begin;  

    while (i <= mid and j <= end) {
	    if (A[i] <= A[j]) {
      // take left array element
	        B[k++] = A[i++];  
	    }
	    else {  
      // take right array element
	        B[k++] = A[j++];  
	    }
    }

    // Taking care of left-over elements on the left array.
    while (i <= mid) {
	    B[k++] = A[i++];
    }
    
    // Taking care of left-over elements on the right array.
    while (j <= end) {
	    B[k++] = A[j++];
    }

    // Copy array B to array A
    for (k=begin; k <= end; k++) {
	    A[k] = B[k];
    }
}

/* Merge sort: Break the array into two halves of equal size and sort recursively.
   Then merge two sorted arrays. */
   
void merge_sort_helper(vector<int> &A, vector<int> &B, int begin, int end) {
    // Return if the array size is trivial
    if ((end-begin) < 1)
        return;
   
    // Index to half
    int mid = begin + (end - begin) / 2;

    // Recursively sort for half arrays
    merge_sort_helper(A, B, begin, mid);
    merge_sort_helper(A, B, mid+1, end);

    // Merge two sorted arrays
    merge(A, B, begin, mid, end);
}
   
vector<int> merge_sort(vector<int> &arr) {
    // Create the aux array to avoid multiple creation
    vector<int> aux(arr.size());
    
    merge_sort_helper(arr, aux, 0, arr.size()-1);
    return arr;
}

