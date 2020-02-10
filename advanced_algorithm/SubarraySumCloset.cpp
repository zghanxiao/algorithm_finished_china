bool cmp(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.first < p2.first || p1.first == p2.first && p1.second < p2.second;
}

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        // write your code here
        int nums_size = nums.size();
        vector<pair<long long, long long> > sums;
        int sums_size = nums_size + 1;
        sums.resize(sums_size);
        
        sums[0].first = 0;
        
        for (int iter = 0; iter < nums_size; ++ iter) {
          sums[iter + 1].first = (long long)(nums[iter]) + sums[iter].first;
        }
        
        for (int iter = 0; iter < sums_size; ++ iter) {
          sums[iter].second = iter; 
        }
        
        sort(sums.begin(), sums.end(), cmp);
        
        
        long long min_diff = LLONG_MAX;
        int min_start = -1;
        int min_end = -1;
        vector<int> res;
        for (int iter = 0; iter < sums_size - 1; ++ iter) {
            long long diff = sums[iter + 1].first - sums[iter].first;
            if (diff < min_diff) {
               min_start = sums[iter].second; 
               min_end = sums[iter + 1].second; 
               if (min_start > min_end) {
                swap(min_start, min_end);
               }
               min_end --;
               min_diff = diff;
            } 
        }
        
        res.push_back(min_start);
        res.push_back(min_end);
        return res;
    }
};
