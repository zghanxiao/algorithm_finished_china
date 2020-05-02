class Solution {
public:
    /**
     * @param strs: a list of string
     * @return: return a string
     */
    string find(char max_ch, int iter, vector<string> & strs) {
      int size = strs.size();
      string outside = "";
      for (int cur_iter = (iter + 1) % size ;  cur_iter != iter;) {    
          
        string str = strs[cur_iter]; 
        string rev_str = str;
        reverse(rev_str.begin(), rev_str.end());
        if (str > rev_str) {
          outside += str;        
        } else {
          outside += rev_str;
        }
        cur_iter = (cur_iter + 1) % size;
      }
      
      string to_split_str = strs[iter];
      int to_split_str_size = to_split_str.size();
      string rev_to_split_str = to_split_str;
      reverse(rev_to_split_str.begin(), rev_to_split_str.end());
      vector<string> split_strs;
      split_strs.push_back(to_split_str);
      split_strs.push_back(rev_to_split_str);
      string max_str;
      bool ini = true;
      for (string split_str: split_strs) {
        for (int str_i = 0; str_i < to_split_str_size ; ++ str_i) {
          if (max_ch == split_str[str_i]) {
             string front_str = split_str.substr(0, str_i);    
             string tail_str = split_str.substr(str_i, to_split_str_size - 1 - str_i + 1); 
          
             string whole_str = tail_str + outside + front_str; 
             if (ini || whole_str > max_str){
               max_str = whole_str;
             }
             ini = false;
          }
        }
      }
      
      return max_str;
    }
    
    string splitLoopedString(vector<string> &strs) {
      // write your code here
      int size = strs.size();
      char max_ch = 0;
      vector<int> hiCharStrs;
      for (int iter = 0; iter < size; ++ iter) {
        string str = strs[iter];    
        for (char ch: str) {
          if (ch > max_ch ) {
            hiCharStrs.clear();
            hiCharStrs.push_back(iter);
            max_ch = ch;
          } else if (ch == max_ch) {
            hiCharStrs.push_back(iter);
          }
        }
      }
      
      
      string max_str;
      bool ini = true;
      for (int iter: hiCharStrs) {
        //cout << "iter max_ch " << iter << " " << max_ch << endl;
        string res = find(max_ch, iter, strs);
        if (ini || res > max_str){
          max_str = res;
        }
        ini = false;
      }
      return max_str;
    }
};
