# BST or not

bool isBSTHelper(TreeNode *root, int &prev){
    // NULL node check
    if(root == NULL){
        return true;
    }

    // checking if left subtree is bst or not
    bool isLeftSubtreeBST = isBSTHelper(root->left_ptr, prev);

    // Checking if current node value is greater or equal to the max value of left subtree nodes
    if(root->val < prev){
        return false;
    }

    // Updating the prev variable by current node value as each value of right subtree must be greater or equal to the current root value
    prev = root->val;
    
    // true when both left and right subtrees are valid BST
    bool isRightSubtreeBST = isBSTHelper(root->right_ptr, prev);

    // Bitwise AND operation to return true only when both subtree is BST, otherwise false
    return (isLeftSubtreeBST && isRightSubtreeBST);
}

bool isBST(TreeNode* root){
    // empty or null tree check
    if(root==NULL){
        return true;
    }
    int min = INT_MIN;
    return isBSTHelper(root, min);
}
