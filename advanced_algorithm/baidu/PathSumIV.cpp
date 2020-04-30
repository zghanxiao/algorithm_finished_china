class Node{
public:
  Node * left;
  Node * right;
  int _val;
  Node(int val) {
    left = nullptr;  
    right = nullptr;
    _val = val;
  }
};
class Solution {
public:
    /**
     * @param nums: the list
     * @return: the sum of all paths from the root towards the leaves
     */
    int getHundred(int num) {
      return num / 100;
    }
    
    int getTen(int num) {
      return (num % 100) / 10;    
    }
    
    int getDigit(int num) {
      return (num % 10);
    }
    
    int getHunTen(int num) {
      return num/10;  
    }
    
    int parentNum(int num) {
      int hundred = getHundred(num);   
      int new_hundred = hundred - 1;
      int ten = getTen(num);
      int new_ten = (ten + 2 - 1) / 2;
      int new_val = new_hundred * 10 + new_ten;
      return new_val;
    }
    
    Node * createTree(vector<int> & nums) {
      int size = nums.size();
      if (size == 0) {
        return nullptr;
      }
      unordered_map<int, Node *> map;
      Node * root = nullptr;
      for (int iter = 0; iter < size; ++ iter) {
        int num = nums[iter];
        Node * new_node = new Node(getDigit(num));
        if (getHundred(num) == 1) {
          root = new_node; 
        } else {
          Node * parent = map[parentNum(num)];
          if(getTen(num) % 2 == 1) {
            parent->left = new_node;
          } else {
            parent->right = new_node;
          }
        }
        map[getHunTen(num)] = new_node;
      }
      return root;  
    }
    
    void dfs(Node * root, int curr_sum, int & tot_sum) {
      if (root == nullptr) {
        return;
      }
      
      curr_sum += root->_val;
      
      if (root->left != nullptr) {
        dfs(root->left, curr_sum, tot_sum);  
      } 
      
      if (root->right != nullptr) {
        dfs(root->right, curr_sum, tot_sum);  
      }
      
      if (root->left == nullptr && root->right == nullptr) {
        tot_sum += curr_sum;
      }
    }
    
    int pathSumIV(vector<int> &nums) {
      // Write your code here.
      sort(nums.begin(), nums.end());
      Node * root = createTree(nums);
      int curr_sum = 0;
      int tot_sum = 0;
      dfs(root, curr_sum, tot_sum);
      return tot_sum;
    }
};
