# n Queen Problem

/* Question: Given an integer n, find all the possible ways to position n queens on an n×n chessboard so that no two queens attack each other.
A queen in chess can move horizontally, vertically, or diagonally. */

const char queen = 'q';
const char no_queen = '-';

// Function to check if a queen can be placed at position candidate[row][col].
bool is_safe(vector<bool> &slash_diagonal_occupied, vector<bool> &col_occupied,
    vector<bool> &backslash_diagonal_occupied, int row, int col, int n)
{
    // Checking top-left to bottom-right diagonal.
    if (slash_diagonal_occupied[row + col])
    {
        return false;
    }
    
    // Checking column.
    if (col_occupied[col])
    {
        return false;
    }
    
    // Checking top-right to bottom-left diagonal.
    if (backslash_diagonal_occupied[row - col + n - 1])
    {
        return false;
    }
    return true;
}

void find_all_arrangements_util(vector<vector<int>> &solutions, vector<int> &candidate,
    vector<bool> &slash_diagonal_occupied, vector<bool> &col_occupied, vector<bool> &backslash_diagonal_occupied, int n, int row)
{
    // Checking if all queens are placed.
    if (row == n)
    {
        // push_back() makes a deep copy
        solutions.push_back(candidate);
        return;
    }
    
    // For current row, trying to place queen at candidate[row][0 <= col < n].
    for (int col = 0; col < n; col++)
    {
        // A a queen can only be placed if it does not clash with already placed queens.
        if (is_safe(slash_diagonal_occupied, col_occupied, backslash_diagonal_occupied, row,
            col, n))
        {
            candidate[row] = col;
            
            // Marking appropriate diagonals and column as occupied.
            slash_diagonal_occupied[row + col] = true;
            col_occupied[col] = true;
            backslash_diagonal_occupied[row - col + n - 1] = true;
        
            // After having placed queens in rows from 0 to row, without any clash. Try to place queen in next row
            find_all_arrangements_util(solutions, candidate, slash_diagonal_occupied, col_occupied, backslash_diagonal_occupied, n, row + 1);
            
            // Marking appropriate diagonals and column as unoccupied.
            slash_diagonal_occupied[row + col] = false;
            col_occupied[col] = false;
            backslash_diagonal_occupied[row - col + n - 1] = false;
        }
    }
}

// Function to convert the solutions from vector<int> into vector<string>.
vector<vector<string>> generate_output(vector<vector<int>> &solutions, int n)
{
    vector<vector<string>> output;
    string chessboard_empty_row(n, no_queen); // zero queens in a row.
    vector<string> empty_chesspoard(n, chessboard_empty_row); // zero queens on a board.

    int len = solutions.size();
    // Iterating over the solutions.
    for (int i = 0; i < len; i++)
    {
        output.push_back(empty_chesspoard); // push_back conveniently makes a deep copy of empty_chesspoard.

        // Iterating over the positions of the queens and place queens in 2D arrangement.
        for (int row = 0; row < n; row++)
        {
            int col = solutions[i][row]; // column where a queen is in row-th row in i-th solution.
            output[i][row][col] = queen;
        }
    }
    return output;
}

vector<vector<string>> find_all_arrangements(int n)
{
   
    // vector solutions is for collecting the valid solutions.
    vector<vector<int>> solutions;

    // Candidate solution that the recursive function will be modifying.
    vector<int> candidate(n);

    // Initializing all three occupied vectors with false
    vector<bool> slash_diagonal_occupied (n + n - 1, false);
    vector<bool> col_occupied (n, false);
    vector<bool> backslash_diagonal_occupied (n + n - 1, false);

    // Starting with an empty board from the 0th row:
    find_all_arrangements_util(solutions, candidate, slash_diagonal_occupied, col_occupied, backslash_diagonal_occupied, n, 0);

    return generate_output(solutions, n);
}
