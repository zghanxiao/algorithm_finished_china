class Solution {
public:
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
      // write your code here
      unordered_set<ParentTreeNode*> set;
      ParentTreeNode * iter = A;
      for (; iter != nullptr ;iter = iter->parent) {
        set.insert(iter);   
        if (iter == root) {
          break;
        }
      }
      
      iter = B;
      for (; iter != nullptr ; iter = iter->parent) {
        if (set.find(iter) != set.end()) {
          return iter; 
        }   
      }
      return nullptr;
    }
};
