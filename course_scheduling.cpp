// Course Schedule

/* Question: There are n courses to take, they are referred to by numbers from 0 to n-1. Some of them have prerequisites, 
e.g. courses A and B must be completed before course C can be taken (in other words, course C depends on A and B).
Find and return an ordering in which all the given courses can be taken while satisfying all the prerequisites. 
If there exists more than one such ordering, any one of them would be a correct answer. If no such ordering exists, return a special value: [-1]. */

// Storing a list of outgoing edges for every graph node.
vector<vector<int>> edges;

const int NEVER_VISITED = 0, VISITED = 1, FINISHED = 2;

// Storing those states for all nodes.
vector<int> visited;

// This will store the ordering of nodes to be returned.
vector<int> answer;

// Running DFS from current_node. Returns false if a cycle is detected.
bool dfs(int current_node){
    visited[current_node] = VISITED;

    for(int connected_node: edges[current_node])
    {
        if(visited[connected_node] == VISITED)
            // Cycle detected.
            return false;

        if(visited[connected_node] == NEVER_VISITED)
        {
            if(!dfs(connected_node))
                // Cycle detected while exploring connected_node's children.
                return false; 
        }
    }

    visited[current_node] = FINISHED;
    answer.push_back(current_node);

    return true; 
}

vector<int> course_schedule(int n, vector<vector<int> > prerequisites)
{
    answer.clear();

    // Initializing the graph.
    edges.clear();
    visited.clear();

    for(int i = 0; i < n; i++)
    {
        // Initial state: no edges.
        edges.push_back(vector<int>()); 
        visited.push_back(0); 
    }

    // Populating edges from the input data.
    for(vector<int> prereq: prerequisites)
    {
        edges[prereq[1]].push_back(prereq[0]);
    }

    // Calling DFS on each unvisited node in the graph.
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == NEVER_VISITED)
        {
            if(!dfs(i))
                return {-1};
        }
    }

    reverse(answer.begin(), answer.end());
    return answer;
}
