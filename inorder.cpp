struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
void inorder(Node* root, vector<int> &arr){
   
    if(root == nullptr){
        return;
    }
    arr.push_back(root->left->data);
   
    preorder(root, arr);
    
    preorder(root->right, arr);
}
vector<int> inoreder(Node* root){

    vector<int> arr;
   inorder(root, arr);
    return arr;
}