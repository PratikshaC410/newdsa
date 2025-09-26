 
 struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
void postorder(Node* root, vector<int> &arr){
   
    if(root == nullptr){
        return;
    }
    postorder(root->left, arr);
   
    postorder(root->right, arr);
   
    arr.push_back(root->data);
   }
   
vector<int> postorder(Node* root){

    vector<int> arr;
   postorder(root, arr);
    return arr;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 