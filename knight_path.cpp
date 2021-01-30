# Knight path on chess board

/* Question: You are given a rows * cols chessboard and a knight that moves like in normal chess.
Currently knight is at starting position denoted by start_row th row and start_col th col, and want to reach at ending position
denoted by end_row th row and end_col th col.  The goal is to calculate the minimum number of moves that the knight needs to take 
to get from starting position to ending position.
start_row, start_col, end_row and end_col are 0-indexed.  */

const int no_of_possible_moves = 8;
// 8 possible moves of knight.
const int add_row[] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int add_col[] = {-1, 1, 2, 2, 1, -1, -2, -2};


// Function to check if position described by new_row th row and new_col th col, is inside the chess board or not.
bool is_valid_position(int rows, int cols, int new_row, int new_col)
{
	return ((0 <= new_row) && (new_row < rows) && (0 <= new_col) && (new_col < cols));
} 

int find_minimum_number_of_moves(int rows, int cols, int start_row, int start_col, int end_row, int end_col) 
{
	// Checking if starting and ending positions are same.
	if (start_row == end_row && start_col == end_col)
	{
		return 0;
	}
	
	vector<vector<int>> dist(rows, vector<int>(cols, -1));
  
	// Starting position can be reached from starting position in 0 moves.
	dist[start_row][start_col] = 0;
	queue<pair<int, int>> bfs_q;
  
	// Adding starting position. 
	bfs_q.push({start_row, start_col});
	while(bfs_q.empty() == false)
	{
		// Removing first element from queue. 
		int cur_row = bfs_q.front().first;
		int cur_col = bfs_q.front().second;
		bfs_q.pop();
    
		// Updating neighbours that are not visited till now. 
		for (int i = 0; i < no_of_possible_moves; i++)
		{
			// Neighbour's position. 
			int new_row = cur_row + add_row[i];
			int new_col = cur_col + add_col[i];
			if (is_valid_position(rows, cols, new_row, new_col))
			{
      
				// Checking if neihbour is not visited till now.
				if (dist[new_row][new_col] == -1)
				{

					dist[new_row][new_col] = dist[cur_row][cur_col] + 1;
					// Checking if found the ending position. 
					if (new_row == end_row && new_col == end_col)
					{
						return dist[end_row][end_col];
					}
          
					// Adding the neighbour in queue. 
					bfs_q.push({new_row, new_col});
				}
			}
		}
	}
	// If ending position can not be reached from starting position.
	return -1;
}
