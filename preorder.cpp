struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
void preorder(Node* root, vector<int> &arr){
   
    if(root == nullptr){
        return;
    }
    arr.push_back(root->data);
   
    preorder(root->left, arr);
    
    preorder(root->right, arr);
}
vector<int> preOrder(Node* root){

    vector<int> arr;
    preorder(root, arr);
    return arr;
}