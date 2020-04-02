class Solution {
public:
    /**
     * @param S: a String consists of a and b
     * @return: the longest of the longest string that meets the condition
     */
    int getAns(string &S) {
      int size = S.size();
      int ABdiff = 0;
      unordered_map<int, int> map;
      // empty string iter = -1
      map[0] = -1;
      int max_length = 0;
      for (int iter = 0; iter < size; iter ++) {
        char ch = S[iter];    
        if (ch == 'A') {
          ABdiff ++;
        } else {
          ABdiff --;  
        }
        if (map.find(ABdiff) == map.end()) {
          map[ABdiff] = iter;
        } else {
          max_length = max(max_length, iter - map[ABdiff]);
        } 
      }
      return max_length;
    }
};
