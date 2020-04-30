class Solution {
public:
    /**
     * @param n: a positive integer 
     * @return: the minimum number of replacements
     */
    unordered_map<int, int> map;
    Solution() {
      map.clear();  
      map[1] = 0;
      map[2] = 1;
      map[3] = 2;
      map[4] = 2;
    }
    
    int integerReplacementHelper(int n) {
      if (n <= 4) {
        return map[n];
      }
      
      if (map.find(n) != map.end()) {
        return map[n];  
      }
      
      if (n % 2 == 0) {
        return integerReplacement(n/2) + 1;
      } else {
        return min(integerReplacement(n+1), integerReplacement(n-1)) + 1; 
      }
    }
    int integerReplacement(int n) {
      return integerReplacementHelper(n);
    }
};
