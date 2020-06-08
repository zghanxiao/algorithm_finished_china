class Solution {
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    void increase(unordered_map<int, int> & cnt, char ch, int & minus_num) {
      if (cnt.find(ch) == cnt.end()) {
        cnt[ch] = 0;  
      }
      cnt[ch] ++;
      if (cnt[ch] == 0) {
        minus_num --;
      }
    }
    
    void decrease(unordered_map<int, int> & cnt, char ch, int & minus_num) {
      if (cnt.find(ch) == cnt.end()) {
        cnt[ch] = 0;
      }
      cnt[ch] --;
      if (cnt[ch] == -1) {
        minus_num ++;
      }
    }
    
    string minWindow(string &source , string &target) {
      // write your code here
      unordered_map<int, int> cnt;
      unordered_map<int, int> target_cnt;
      
      int minus_num = 0;
      for (char ch: target) {
        decrease(cnt, ch, minus_num);  
      }
      
      int s_size = source.size();
      // r is the current char
      // l points to the next to be removed char.
      int l = 0, r = 0; 
      int min_len = INT_MAX, min_l = -1, min_r = -1;
      while(r < s_size) {
        char r_ch = source[r];
        increase(cnt, r_ch, minus_num);
        if (minus_num == 0) {
          while(l <= r) {
            char l_ch = source[l];
            decrease(cnt, l_ch, minus_num);
            l++;
            if (minus_num > 0) {
              if (r - l + 2 < min_len) {
                min_len = r - l + 2;
                min_l = l - 1;
                min_r = r;
              }
              break;
            } 
          } 
        }
        r++;
      }
      string res = min_len == INT_MAX? "" : source.substr(min_l, min_r - min_l + 1);
      return res;
    }
};
