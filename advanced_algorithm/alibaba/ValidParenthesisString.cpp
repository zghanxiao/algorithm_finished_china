class Solution {
public:
    /**
     * @param s: the given string
     * @return: whether this string is valid
     */
    bool checkValidString(string &s) {
        // Write your code here
        // cnt1, l: * will represent as much left parenthesis as possible. 
        // cnt2, cp: * will represnet as much right parenthesis as possible.
        int cnt1 = 0, cnt2 = 0;
        
        for (char ch: s) {
          if (ch == '(') {
            cnt1 ++;
            cnt2 ++;
          } else if (ch == ')') {
            cnt1 --;
            if (cnt1 < 0) {
              return false;
            }
            if (cnt2 > 0) {
              cnt2 --;
            }
          } else {  // ch == '*'
            cnt1 ++;  
            if (cnt2 > 0) {
              cnt2 --;
            }
          }
        }
        return cnt2 == 0;
    }
};
