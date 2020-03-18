class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @param k: An integer
     * @return: The maximum number inside the window at each moving.
     */
        
    void enque(deque<int> & deque, int item) {
      for (;!deque.empty() && item > *deque.rbegin();) {
        deque.pop_back();
      }
    }
    
    void outque(deque<int> & deque, int item) {
      if (!deque.empty() && *deque.begin() == item) {
        deque.pop_front();  
      }
    }
    
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
      // write your code hee
      int nums_size = nums.size();
      deque<int> deque;
      vector<int> res;
      for(int iter = 0; iter < nums_size; ++iter) {
        int item = nums[iter];    
        enque(deque, item);     
        
        deque.push_back(item);
        
        if (iter >= k - 1) {
          res.push_back(*deque.begin());
          outque(deque, nums[iter- k + 1]);
        }
      }
      return res;
    }
};
