class Solution {
public:
  
    bool qEmpty(pair<vector<int>, int> &q) {
      return q.first.size() == q.second;
    }
  
    int qSize(pair<vector<int>, int> &q) {
      return q.first.size() - q.second;
    }
  
    int qTop(pair<vector<int>, int> &q) {
      return q.first[q.second];  
    }
  
    bool qPopLen(pair<vector<int>, int> &q, int len, int & k) {
      if(q.second + len > q.first.size()){
        return false; 
      }   
      q.second += len;
      k -= len;
      return true;
    }
  
    int qIndex(pair<vector<int>, int> &q, int new_i) {
      return q.first[q.second + new_i];  
    }
  
    int findkth(pair<vector<int>, int> &q1, pair<vector<int>, int> &q2,  int k) {
      while(k <= qSize(q1) + qSize(q2)) {
        
        if(qSize(q1)> qSize(q2)) {
          swap(q1, q2);
        }
        
        if (qEmpty(q1)) {  
          return qIndex(q2, k - 1);
        } else if (k == 1) {
          return min(qTop(q1), qTop(q2));
        } 
        
        int cut_len1 = min(qSize(q1), k/2) , cut_len2 = k - cut_len1;
        if (qIndex(q1, cut_len1 - 1) < qIndex(q2, cut_len2 - 1)) {
          qPopLen(q1, cut_len1, k); 
        } else {
          qPopLen(q2, cut_len2, k);
        }
      }
      return -1;
    }
  
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int tot_size = nums1.size() + nums2.size();
      double res = 0.0;
      pair<vector<int>, int> q1= make_pair(nums1, 0);
      pair<vector<int>, int> q2= make_pair(nums2, 0);
      if (tot_size % 2 == 0) {
        int res1 = findkth(q1, q2, tot_size/2); 
        q1.second = q2.second = 0;
        int res2 = findkth(q1, q2, tot_size/2 + 1); 
        res = ((double)(res1) + (double)(res2))/2.0;
      } else if (tot_size % 2 == 1) {
        res = (double)(findkth(q1, q2, (tot_size + 1) /2)); 
      }
      return res;
    }
};
