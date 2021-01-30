# Print all paths in a tree


void getAllPaths(TreeNode *root, vector<int> &currentPathValues, vector<vector<int> > &allPaths){
    
    // If leaf node is reached
    if(root->left_ptr == NULL && root->right_ptr == NULL){
       currentPathValues.push_back(root->val);
       allPaths.push_back(currentPathValues);
       currentPathValues.pop_back();
       return;
    }
    
    // Pushing current node's value in current path
    currentPathValues.push_back(root->val);

    // Recursive call for left subtree
    if(root->left_ptr != NULL){
        getAllPaths(root->left_ptr, currentPathValues, allPaths);
    }

    // Recusrive call for right subtree
    if(root->right_ptr != NULL){
        getAllPaths(root->right_ptr, currentPathValues, allPaths);
    }

    // Poping current node's value
    currentPathValues.pop_back();
}

vector<vector<int> > allPathsOfABinaryTree(TreeNode* root){
    vector<vector<int> > allPaths;
    
    // empty or null tree check
    if(root == NULL) {
        return allPaths;
    }
    vector<int> currentPathValue;
    getAllPaths(root, currentPathValue, allPaths);
    return allPaths;
}
