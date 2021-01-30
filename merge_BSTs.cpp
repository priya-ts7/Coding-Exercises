# Merge 2 BSTs

# Question: Merge two Binary Search Trees (each may contain duplicates) into one height balanced BST.

// Function to reate a vector of inorder traversal all the nodes of Tree1 and Tree2
void inorderTraversal(Node* root, vector<Node*> &list) {
    if (root == nullptr)
        return;
    
    inorderTraversal(root->left, list);
    list.push_back(root);
    inorderTraversal(root->right, list);
}

void printList(const vector<Node*> &list) {
    for(auto node : list) {
        cout << node->key << " ";
    }
    cout << endl;
}

// Function to merge both in to an array
void mergeList(const vector<Node*> &list1, const vector<Node*> &list2, vector<Node*> &masterList) {
    int n1 = list1.size();
    int n2 = list2.size();
    
    int startList1 = 0, startList2 = 0;
    
    int index1 = startList1, index2 = startList2;
    
    while ( (index1 < n1) && (index2 < n2) ) {
        if (list1[index1]->key < list2[index2]->key)
            masterList.push_back(list1[index1++]);
        else
            masterList.push_back(list2[index2++]);
    }
    
    while (index1 < n1)
        masterList.push_back(list1[index1++]);
        
    while (index2 < n2)
        masterList.push_back(list2[index2++]);
}

Node* createBalancedTree(const vector<Node*> &masterList, int start, int end) {
    if (end < start)
        return nullptr;
        
    int mid = start + (end-start) / 2;
    
    // cout << masterList[mid]->key << endl;
    
    // Traversing to left of the array and create=ing left sub-tree
    masterList[mid]->left = createBalancedTree(masterList, start, mid-1);
    
    // Traversing to right of the array and creating right sub-tree
    masterList[mid]->right = createBalancedTree(masterList, mid+1, end);
    
    return masterList[mid];
}

Node* mergeTwoBSTs(Node* root1, Node* root2){
   vector<Node*> list1 = { };
   vector<Node*> list2 = { };
   vector<Node*> masterList = { };
   
   inorderTraversal(root1, list1);
   inorderTraversal(root2, list2);
   
   mergeList(list1, list2, masterList);
   
   Node* root = createBalancedTree(masterList, 0, masterList.size()-1);
   
   return root;
}
