class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
      // write your code here
      int size = nums.size();
      bool up_flag = false;
      int pre_val;
      for (int iter = 0; iter < size; ++ iter) {
        int num_val = nums[iter];
        
        bool pre_up_flag = up_flag;
        
        if (iter >= 1) {
          up_flag = pre_val <= num_val;
        } 
       
        
        if (iter == 1 && up_flag == false || iter >= 2 && up_flag == pre_up_flag) {
          swap(nums[iter - 1], nums[iter]);
          up_flag = ! up_flag;
        } 
        
        pre_val = nums[iter];
      }
      return;
    }
};
