class Solution {
public:
  
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> cnt;
    int str_i = 0;
    int pre_i = 0;
    int longest = 0;
    int size = s.size();
    int break_flag = false;
    for(; str_i < size ; ++ str_i ) {
        
      char ch = s[str_i];    
      if (cnt.find(ch) != cnt.end()) {
        int dup_i = cnt[ch];
        if (dup_i >= pre_i) {
          longest = max(longest, str_i - pre_i);  
          pre_i = dup_i + 1;   
        }
      }
      cnt[ch] = str_i;
    }
      
    longest = max(longest, str_i - pre_i);  
    return longest;
  }
};
