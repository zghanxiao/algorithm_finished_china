class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
      
      int tot_sum = 0;
      priority_queue<int, vector<int>> pq1;
      priority_queue<int, vector<int>> pq2;
      for (auto num: nums) {
        tot_sum += num;  
        if (num % 3 == 1) {
          pq1.push(num);
          while(pq1.size() > 2) {
            pq1.pop();
          }
        } else if (num % 3 == 2) {
          pq2.push(num);
          while(pq2.size() > 2) {
            pq2.pop();
          }
        }
      }
      
      int min_val = INT_MAX;
      if (tot_sum % 3 == 1) {
        if (pq1.size() >= 1) {
          while(pq1.size() > 1) {
            pq1.pop();
          }
          min_val = min(min_val, pq1.top()); 
        }
        if (pq2.size() == 2) {
          int val1 = pq2.top();
          pq2.pop();
          int val2 = pq2.top();
          min_val = min(min_val, val1 + val2);
        }
        return tot_sum - min_val;
      } else if (tot_sum % 3 == 2) {
        if (pq2.size() >= 1) {
          while(pq2.size() > 1) {
            pq2.pop();
          }
          min_val = min(min_val, pq2.top()); 
        }
        if (pq1.size() == 2) {
          int val1 = pq1.top();
          pq1.pop();
          int val2 = pq1.top();
          min_val = min(min_val, val1 + val2);
        }
        return tot_sum - min_val;
      } else {
        return tot_sum;
      }
    }
};
