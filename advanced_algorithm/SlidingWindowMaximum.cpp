class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @param k: An integer
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
      // write your code hee
      int nums_size = nums.size();
      deque<int> deque;
      vector<int> res;
      for(int iter = 0; iter < nums_size; ++iter) {
        int item = nums[iter];    
        for (;!deque.empty() && item > *deque.rbegin();) {
          deque.pop_back();
        }
        
        deque.push_back(item);
        
        if (iter >= k - 1) {
          res.push_back(*deque.begin());
          if (!deque.empty() && *deque.begin() == nums[iter - k + 1]) {
            deque.pop_front();  
          }
        }
      }
      return res;
    }
};
