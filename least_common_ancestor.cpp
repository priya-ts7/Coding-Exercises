#Least Common Ancestor of Binary Tree

/* Find the lowest common ancestor (LCA) of two nodes in a binary tree of n nodes. 
Given references to the root node and nodes a and b of the tree, return the value from the LCA node of a and b.
The LCA of nodes a and b in a tree is defined as the shared ancestor node of a and b that is located farthest from the root. */

// Function to precompute parents
void dfs(Node * head, int parent , int * par)  
{
    if(head==NULL)
        return ;
    par[ head->data ] = parent ;
    dfs( head -> left , head->data ,par) ;
    dfs( head -> right , head->data,par ) ;
}

// Function to get the path from root 
vector< int >get_path( int *par ,int node )   
{
    vector< int >path ;     
    while( par[node]!=-1 )
    { 
        path.push_back( node ) ;  
        node = par[node];
    }
    // Adding root left explicitly    
    path.push_back(node) ;        
    return path ;
}

int lca( Node * head , Node * a, Node * b )
{
    int par[100020],i;
    int aa = a -> data , bb = b->data ;
    
    // storing parents
    dfs(head , -1 , par ) ; 
    vector< int > path_of_a = get_path( par, aa ) ; 
    vector< int > path_of_b = get_path( par, bb ) ;
    
    // Reversing the obtained path
    reverse(path_of_a.begin(),path_of_a.end()) ; 
    reverse(path_of_b.begin(),path_of_b.end()) ;
    for(i=0;i<path_of_a.size() && i < path_of_b.size();i++)
    {
        if( path_of_a[i] != path_of_b[i] )      
            return path_of_a[i-1];
    }
    // Returning the last match
    return path_of_a[i-1];   
}
