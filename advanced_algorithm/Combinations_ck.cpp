class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
     
    void combineHelper(int n, int curr_index, int tot_sel, vector<int> & path, vector<vector<int> > & res) {
      if (path.size() == tot_sel) {
        res.push_back(path);    
        return;
      }
      
      for (int iter = curr_index; iter < n - (tot_sel - path.size() - 1); ++ iter) {
        path.push_back(iter + 1);
        combineHelper(n, iter + 1, tot_sel, path, res);
        path.erase(path.end() - 1);
      }
    }
    vector<vector<int>> combine(int n, int k) {
      // write your code here
      vector<int> path;
      vector<vector<int> > res;
      combineHelper(n, 0, k, path, res);
      return res;
    }
};
