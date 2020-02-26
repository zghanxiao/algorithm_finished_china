class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    
    int partition(vector<int> &nums, int left, int right) {
      if (left > right ) {
        return -1;
      } else if (left == right) {
        return 0;
      }
      
      int pivot = nums[left];
      int left_iter = left + 1;  
      int right_iter = right; 
      
      for(;left_iter <= right_iter && left_iter <= right 
        && right_iter >= left + 1;)  {
        while(left_iter <= right && nums[left_iter] < pivot) {
          ++ left_iter;
        }        
        while(right_iter >= left + 1 && nums[left_iter] >= pivot) {
          -- right_iter;
        }
        
        if (left_iter <= right_iter) {
          swap(nums[left_iter], nums[right_iter]);
        }
      }
      swap(nums[left], nums[left_iter - 1]);
      return left_iter - 1;
    }
    
    int kthSmallest(vector<int> &nums, int k) {
    }
    
    int median() {
    }
    
    void wiggleSort(vector<int> &nums) {
      // write your code here
      int res = median(nums);
        
    }
};
