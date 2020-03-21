class Solution {
public:
    /*
     * @param num: An integer
     * @return: An integer
     */
    int countOnes(int num) {
      // write your code here
      
      int cnt = 0;
      for (;num; ++ cnt) {
        num &= (num - 1);  
      }
      return cnt;
    }
};
