/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> _stack;
  
    BSTIterator(TreeNode* root) {
      while(!_stack.empty()) {
        _stack.pop();
      }
      findLeftMost(root); 
    }
  
    void findLeftMost(TreeNode * node) {
       while(node != nullptr) {
         _stack.push(node);
         node= node->left;
       }
    }
    
    /** @return the next smallest number */
    int next() {
      TreeNode * top = _stack.top();
      _stack.pop();
      if (top->right != nullptr) {
        findLeftMost(top->right);        
      } 
      return top->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
      return !_stack.empty(); 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
