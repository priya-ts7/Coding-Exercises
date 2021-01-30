#Dutch National Flag Problem

#Question : Given some balls of three colors arranged in a line, rearrange them such that all the red balls go first, then green and then blue ones.

void dutch_flag_sort(vector<char>& balls)
{
	int n = balls.size();

	// When any red ball is encountered,swapping it with character present at this index.
	int swap_red_here = 0;

  //The current position we are at
	int current_idx = 0;

	// When any blue ball is encountered,swapping it with character present at this index.
	int swap_blue_here = n - 1;

	// Continuing till all the balls are sorted.
	while (current_idx <= swap_blue_here)
	{
    /*
				Two cases possible:

				Swapping with left most 'G' if available or swapping with 
				itself. Both cases will maintain the required structure!
       
    */
    
		if (balls[current_idx] == 'R')
		{
			swap(balls[current_idx++], balls[swap_red_here++]);
		}
		else if (balls[current_idx] == 'G')
		{
			// Skip the current character.
			current_idx++;
		}
		else
		{
			swap(balls[current_idx], balls[swap_blue_here--]);
		}
	}
}
