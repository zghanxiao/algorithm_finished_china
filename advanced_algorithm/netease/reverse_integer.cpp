class Solution {
public:
    /**
     * @param n: the integer to be reversed
     * @return: the reversed integer
     */
    string numToStr(int num) {
      string res;
      if (num == 0) {
        res = "0";
        return res;
      }
      
      while(num) {
        res += num % 10 + '0';
        num /= 10;
      }    
      
      reverse(res.begin(), res.end());
      return res;
    }
    
    string trail(string & str) {
      string new_str;
      bool non_zero_flag = false;
      for (int str_i = 0; str_i < str.size(); ++ str_i) {
        char ch = str[str_i];
        if (ch != '0') {
          non_zero_flag = true;
        }
        if (non_zero_flag) {
          new_str.push_back(ch);
        }
      }
      if (new_str.size() == 0) {
        new_str = "0";
      }
      return new_str;
    } 
    
    bool compareLessAndEqual(string & str1, string & str2) {
      if (str1.size() != str2.size()) {
        return str1.size() < str2.size();
      }    
      
      int size = str1.size();
      
      int str_i = 0;
      for (; str_i < size; ++ str_i) {
        if(str1[str_i] != str2[str_i]) {
          return str1[str_i] < str2[str_i];
        } 
      }
      return true;
    }
    
    int strToInt(string & str) {
      int num = 0;
      int size = str.size();
      for (int str_i = 0; str_i < str.size(); ++ str_i) {
        num *= 10;
        num += str[str_i] - '0';
      } 
      return num;
    }
    
    int reverseInteger(int n) {
      // write your code here
      string num_str = numToStr(n);
      reverse(num_str.begin(), num_str.end());
      string trail_str = trail(num_str);
      string int_max_str = numToStr(INT_MAX);
      if (!compareLessAndEqual(trail_str, int_max_str)) {
        return 0;  
      }
      //cout << "trail_str:" << trail_str << endl;
      return strToInt(trail_str);
    }
};

