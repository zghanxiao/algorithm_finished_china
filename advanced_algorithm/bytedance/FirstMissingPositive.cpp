class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      int size = nums.size();
      
      bool one_exists = false;
      for (int & num: nums) {
        if (num == 1) {
          one_exists = true;
        } else if (num <= 0) {
          num = 1;
        }
      }    
      
      if (!one_exists) {
        return 1;
      }
      
      int iter = 0;
      for (;iter < size; ++ iter) {
        int num = abs(nums[iter]);
        if (num >= 1 && num <= size) {
          int index = num - 1;
          nums[index]  = 0 - abs(nums[index]);
        }  
      }
      
      for (iter = 0; iter < size; ++ iter) {
        if (nums[iter] >= 1) {
          break;  
        }
      }
      return iter + 1;
    }
};
