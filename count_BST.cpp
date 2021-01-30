#Possible binary search trees

# Question: Write a function that returns the number of distinct binary search trees that can be constructed with n nodes.
# Recursive Solution (with memoization)

vector<long long int> memorized_BSTs(16 + 1, -1);

long long int how_many_BSTs(int n)
{
    // If base case.
    if (n == 0)
    {
        return 1LL;
    }
    
    // If already calculated the value then return it.
    if (memorized_BSTs[n] != -1LL)
    {
        return memorized_BSTs[n];
    }
    
    long long int BSTs = 0LL;
    
    // Trying all possibilities by taking number of nodes in left subBST from 0 to n - 1.
    for (int number_of_nodes_in_left_subBST = 0; number_of_nodes_in_left_subBST < n;
        number_of_nodes_in_left_subBST++)
    {
        int number_of_nodes_in_right_subBST = n - 1 - number_of_nodes_in_left_subBST;
        BSTs += how_many_BSTs(number_of_nodes_in_left_subBST) *
            how_many_BSTs(number_of_nodes_in_right_subBST);
    }
    
    // Storing the calculated result.
    memorized_BSTs[n] = BSTs;
    return BSTs;
}
