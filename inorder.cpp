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
 
   inorder(root->left, arr);
       arr.push_back(root->data);
    inorder(root->right, arr);
}
vector<int> inorder(Node* root){

    vector<int> arr;
   inorder(root, arr);
    return arr;
}