# Generate All Possible Expressions That Evaluate To The Given Target Value

/* Given a string s that consists of digits (“0”..”9”) and target, a non-negative integer, find all expressions that can be built from string s
that evaluate to the target. When building expressions, you have to insert one of the following operators between each pair of consecutive characters in s: 
“join” or “*” or “+”. For example, by inserting different operators between the two characters of string “12” we can get either 12 (1 joined with 2)
or 2 (1*2) or 3 (1+2).
Other operators such as “-” or “÷” are NOT supported.
Expressions that evaluate to the target but only utilize a part of s do not count: entire s has to be consumed.
Precedence of the operators is conventional: “join” has the highest precedence, “*” – medium and “+” has the lowest precedence. 
For example, 1+2*34=(1+(2*(34)))=1+68=69.
You have to return ALL expressions that can be built from string s and evaluate to the target. */

int n;

// Function to convert string to long long int, e.g. "123" -> 123.
long long int str_to_ll(string &str)
{
    long long int val = 0;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        val = val * 10LL + (str[i] - '0');
    }
    return val;
}


//Function to generate all valid expressions that evaluate to the given target value.
void generate_all_expressions_util(vector<string> &all_expressions_container, string cur_expr, string &s, long long int target,
    int pos, long long int cur_expr_val, long long int cur_expr_val_after_rightmost_addition_sign)
{
    // If processed the whole string.
    if (pos == n)
    {
        // Checking if generated expression evaluates to the target value or not.

        if (cur_expr_val == target)
        {
            // If generated expression evaluates to the target value,storing it.
            all_expressions_container.push_back(cur_expr);
        }
        return;
    }
    /*
   Building "cur_expr" as follows:
       Stage 1: 1
       Stage 2: 1+2 
       Stage 3: 1+2*3...
    */
    for (int i = pos; i < n; i++)
    {
        // Get the string s[pos, i] (both inclusive).
        string number_to_add_as_str = s.substr(pos, i - pos + 1);
        
        // Converting it to number.
        long long int number_to_add = str_to_ll(number_to_add_as_str);
        
        // If just started, then first adding the number without an operator.
        if (pos == 0)
        {
            generate_all_expressions_util(all_expressions_container, number_to_add_as_str, s, target,
                i + 1, number_to_add, number_to_add);
        }
        else
        {
           
           // Adding the number with '+' operator before it.

            
            generate_all_expressions_util(all_expressions_container, cur_expr + '+' + 
                      number_to_add_as_str, s, target, i + 1, cur_expr_val + number_to_add, number_to_add);
           
           // Add the number with '*' operator before it.

            generate_all_expressions_util( all_expressions_container, cur_expr + '*' + number_to_add_as_str, s, target, i + 1,
                cur_expr_val - cur_expr_val_after_rightmost_addition_sign + (cur_expr_val_after_rightmost_addition_sign * number_to_add),
                cur_expr_val_after_rightmost_addition_sign * number_to_add);
        }
    }
}

vector<string> generate_all_expressions(string s, long long int target)
{
    // Storing length of given string in a global variable.
    n = s.length();

    // This vector will store the answer.
    vector<string> all_expressions_container;
    generate_all_expressions_util(all_expressions_container, "", s, target, 0, 0LL, 0LL);
    return all_expressions_container;
}
