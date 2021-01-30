# Palindromic Decomposition of a string

/* Question: Find all palindromic decompositions of a given string s.
A palindromic decomposition of string is a decomposition of the string into substrings, such that all those substrings are valid palindromes. */


void find_is_palindrome_for_all_substrings(vector<vector<bool>> &is_palindrome, int n, string &s)
{
	for (int len = 1; len <= n; len++)
	{
		for (int start = 0; start < n; start++)
		{
			int stop = start + len - 1;
      
			// Finding if s[start, stop] is a palindrome or not.
			if (stop >= n)
			{
				break;
			}
			is_palindrome[start][stop] = false;
			if (len <= 2)
			{
				is_palindrome[start][stop] = (s[start] == s[stop]);
			}
			else if (s[start] == s[stop])
			{
				# When first and last characters are same then whether string is a palindrome or not, depends on the inner string.
				is_palindrome[start][stop] = is_palindrome[start + 1][stop - 1];
			}
		}
	}
}

vector<string> generate_palindromic_decompositions(string s)
{
	int n = s.length();

	# Pre-calculating if palindrome or not, for all substrings of s, we will pre-calculate if it is a palindrome or not.
	vector<vector<bool>> is_palindrome (n, vector<bool> (n, false));
	find_is_palindrome_for_all_substrings(is_palindrome, n, s);
  
	
	# decompositions_container[i] will contain all possible palindromic decompositions of s[0, i]. 
	vector<vector<string>> decompositions_container(n, vector<string>(0));

	#Loop to find decompositions_container[i] (i.e. all possible palindromic decompositions of 
	for (int i = 0; i < n; i++)
	{
		// If s[0, i] is a palindrome then add it.
		if (is_palindrome[0][i])
		{
			decompositions_container[i].push_back(s.substr(0, i + 1));
		}
		
		# Loop to find other palindromic decompositions of s[0, i] using already calculated palindromic decompositions of s[0, 0], ..., s[0, n - 1].
		for (int j = 0; j < i; j++)
		{
			if (is_palindrome[j + 1][i])
			{
				string cur_sub_str = '|' + s.substr(j + 1, i - j);
				int len = decompositions_container[j].size();
				for (int k = 0; k < len; k++)
				{
					decompositions_container[i].push_back(decompositions_container[j][k] + 
						cur_sub_str);
				}
			}
		}
	}
	return decompositions_container[n - 1];
}
