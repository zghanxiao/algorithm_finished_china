class Solution {
public:
    /**
     * @param A: An array of integers
     * @return: A long integer
     */
    long long fact[100];
    long long perm_num(int num) {
      fact[1] = 1;
      for (int iter = 2; iter <= num; ++ iter) {
        fact[iter] = (long long)(iter) * fact[iter - 1];
      }
      return fact[num];
    }
    
    bool check(vector<int> & sorted, int index, int target) {
      return sorted[index] >= target; 
    }
    
    int bfsMin(vector<int> & sorted, int ori_left, int ori_right, int target){
      int left = ori_left;
      int right = ori_right;
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(sorted, mid, target)) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      return left == right && check(sorted, right, target)? right: right + 1;
    }
    
    long long permutationIndex(vector<int> &A) {
      vector<int> sorted = A;  
      sort(sorted.begin(), sorted.end());
      long long sum = 1;
      int size = A.size();
      for (int iter = 0; iter < size; ++ iter) {
        int val = A[iter];    
        int s_i = bfsMin(sorted, 0, size - 1, val);
        long long mul =  s_i * perm_num(sorted.size() - 1);
        sorted.erase(sorted.begin() + s_i);
        sum += mul;
      }
      return sum;
    }
};
