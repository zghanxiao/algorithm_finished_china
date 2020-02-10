class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        // write your code here
        
        int size = nums.size();
        vector<int> sums;
        sums.resize(size + 1); 
        for (int iter = 0; iter < size ; ++ iter ) {
          sums[iter + 1] = nums[iter] + sums[iter];
        }
        
        unordered_map<int, int> map;
        vector<int> result;
        
        for (int iter = 0; iter <= size; ++iter) {
          int sum = sums[iter];
          if (map.find(sum) == map.end()) {
            map[sum] = iter;
          } else {
            result.push_back(map[sum]);
            result.push_back(iter - 1);
          }
        }
        return result;
    }
};
