class Solution {
public:
  int inc_map(unordered_map<int, int>& cnt, int key) {
    if (cnt.find(key) == cnt.end()) {
      cnt[key] = 0;
    }
    cnt[key] ++;
    return cnt[key];
  }
  
  int dec_map(unordered_map<int, int>& cnt, int key) {
    if (cnt.find(key) == cnt.end()) {
      return -1;
    }  
    int ret_val = -- cnt[key]; 
    if (!ret_val) {
      cnt.erase(key);
    }
    return ret_val;
  }
  
  bool repeat(int str_i, int pre_i, int map_size) {
    return str_i - pre_i + 1 > map_size;
  }
  
  int lengthOfLongestSubstring(string s) {
    unordered_map<int, int> cnt;
    int str_i = 0;
    int pre_i = 0;
    int longest = 0;
    int size = s.size();
    while(true) {
      for(;str_i < size; ++ str_i) {
        cout << " str_i " << str_i << " ";
        char ch = s[str_i];    
        if(inc_map(cnt, ch) > 1) {
          break;  
        }
      }
      
      longest = max(longest, str_i - pre_i);  
      if(str_i == size){
        break;
      }
      
      for(;repeat(str_i, pre_i, cnt.size()); ++ pre_i) {
        cout << " pre_i " << pre_i << " ";
        char ch = s[pre_i];    
        dec_map(cnt, ch);
      }
      str_i ++;
    }
    return longest;
  }
};
