#include<bits/stdc++.h>
#define MOD 1000000007
#define init_arr(arr,val) memset(arr,val,sizeof(arr))
#define ll long long
using namespace std;

class TreeNode{
  public:
  int val;
  TreeNode *left, *right;
  
  
  TreeNode(int val){
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};

TreeNode *root = NULL;

TreeNode* add(TreeNode* root, int val){
  if(root == NULL){
    root = new TreeNode(val);
    return root;
  }

  if(val > root->val)
    root->right = add(root->right, val);
  else
    root->left = add(root->left, val);

  return root;
}

void pre(TreeNode* node){
  if(node == NULL) return;

  cout << ' ' << node->val;

  pre(node->left);
  pre(node->right);
}

void in(TreeNode* node){
  if(node == NULL) return;

  in(node->left);
  
  cout << ' ' << node->val;

  in(node->right);
}

void post(TreeNode* node){
  if(node == NULL) return;

  post(node->left);
  post(node->right);
  
  cout << ' ' << node->val;
}

void erase(TreeNode *root){
  if(root != NULL){
    erase(root->left);
    erase(root->right);
    delete root;
    root=NULL;
  }
}

int main(){
  int c;

  cin>>c;

  for(int i=0; i<c; i++){
    int n;
    cin>>n;

    root = NULL;

    while(n--){
      int v;
      cin>>v;

      root = add(root,v);
    }
    
    cout << "Case " << i+1 << ":" << endl;

    cout << "Pre.:";
    pre(root);
    cout << endl;

    cout << "In..:";
    in(root);
    cout << endl;

    cout << "Post:";
    post(root);
    cout << endl;

    cout << endl;

    erase(root);
  }
  
  return 0;
}