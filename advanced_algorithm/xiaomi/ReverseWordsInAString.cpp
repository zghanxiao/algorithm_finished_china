class Solution {
public:
    /*
     * @param s: A string
     * @return: A string
     */
    string reverseWords(string &s) {
      // write your code here
      int size = s.size();
      int pre_i = 0;
      int new_i = 0;
      for (int str_i = 1; str_i <= size; ++ str_i) {
        if (str_i != size  && !isspace(s[str_i])  && isspace(s[str_i - 1]) )  {
          pre_i = str_i;
          if (new_i) {
            s[new_i ++] = s[str_i - 1];
          }
        } else if (!isspace(s[str_i - 1]) &&(str_i == size || isspace(s[str_i])))  {
          reverse(s.begin() + pre_i, s.begin() + str_i); 
          for (int iter = pre_i; iter < str_i; ++ iter) {
            s[new_i++] = s[iter];      
          }
        }
      }
      s.resize(new_i);
      reverse(s.begin(), s.end());
      return s;
    }
};
