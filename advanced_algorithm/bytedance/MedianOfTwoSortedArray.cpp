class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<vector<int> > matrix(2);
      matrix.push_back(nums1);
      matrix.push_back(nums2);
      
      priority_queue<pair<int, pair<int, int> >,
                     vector<pair<int, pair<int, int> > >,
                     greater<pair<int, pair<int,int> > > > min_heap;
      
      int tot_num = 0;
      if (nums1.size() > 0) {
        min_heap.push(matrix[0][0], make_pair(0, 0));
        tot_num += nums1.size();
      }
      
      if (nums2.size() > 0) {
        min_heap.push(matrix[1][0], make_pair(1, 0));
        tot_num += nums2.size();
      }
      
      int cnt = 0;
      unordered_set<int> median_cnt;
      vector<int> values;
      int max_i = 0;
      if (tot_sum %2 == 0) {
        median_cnt.insert(tot_sum / 2);  
        median_cnt.insert(tot_sum / 2 + 1);
        max_i = tot_sum / 2 + 1;
      } else {
        median_cnt.insert((tot_sum + 1) / 2);
        max_i = (tot_sum + 1) / 2;
      }
      
      while(min_heap.size()) {
        ++ cnt;
        pair<int, pair<int, int> > top = min_heap.top();
        int val = top.first;
        int g_r_i = top.second.first;
        int g_c_i = top.second.second;
        top.pop();
        
        if (cnt > max_i) {
           break;
        }
        
        if (median_cnt.find(cnt) != median_cnt.end()) {
          values.push_back(val);    
        }
        
        int g_r_i_size = matrix[g_r_i].size();
        if (g_c_i + 1 < g_r_i_size) {
          min_heap.push(matrix[g_r_i][g_c_i + 1], make_pair(g_r_i, g_c_i + 1));
        }
      }
      
      double median = 0;
      if (values.size() == 1) {
        median = values[0]; 
      } else {
        median = (values[0] + values[1]) / 2.0; 
      }
      return median; 
    }
};
