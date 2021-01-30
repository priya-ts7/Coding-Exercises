// Upside down of Binary Tree

/* Question : Given a binary tree where every node has either 0 or 2 children and every right node is a leaf node, 
flip it upside down turning it into a binary tree where all left nodes are leafs. */

//Iterative solution

TreeNode* flipUpsideDown(TreeNode* root){
    if(root == NULL){
        return root;
    }
    
    // In upside down tree, for current root, these should be the left and right children.
    TreeNode* assign_me_as_left_of_root = NULL;
    TreeNode* assign_me_as_right_of_root = NULL;
    
    while(root) {
        // Before updating root->left_ptr, storing its value for future use.
        TreeNode* next_root = root->left_ptr;

        // In upside down tree, for next_root, these will be the left and right children.
        TreeNode* next_assign_me_as_left_of_root = root->right_ptr;
        TreeNode* next_assign_me_as_right_of_root = root;
        
        // Making changes for current root. Updating left and right children.
        root->left_ptr = assign_me_as_left_of_root;
        root->right_ptr = assign_me_as_right_of_root;

        if (next_root) {
            // Operating on the next root.
            root = next_root;
            assign_me_as_left_of_root = next_assign_me_as_left_of_root;
            assign_me_as_right_of_root = next_assign_me_as_right_of_root;
        } 
        else {
            return root;
        }
    }
    // Should never reach here.
    assert(false);
    return NULL;
}
