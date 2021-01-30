# Generate all subsets of a set

# Question: Generate ALL possible subsets of a given set. The set is given in the form of a string s containing distinct lowercase characters 'a' - 'z'.
#Iterative Solution

vector<string> generate_all_subsets(string s)
{
	int n = s.length();
	vector<string> all_subsets;
	// Base case when n = 0 i.e. s = "".
	all_subsets.push_back("");

	for (int i = 1; i <= n; i++)
	{
		int old_len = all_subsets.size();
		for (int j = 0; j < old_len; j++)
		{
			#Adding values to the end of the array
			all_subsets.push_back(all_subsets[j] + s[i - 1]);
		}
	}
	return all_subsets;
}
