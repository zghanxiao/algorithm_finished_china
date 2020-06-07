class Solution {
public:
   int getIncLeft(vector<int> & paths, int sel_i) {
     if(paths.size() == 0) {
       return sel_i;
     } else {
       return sel_i - paths[paths.size() - 1] - 1;  
     }    
   }
   
   string formStr(vector<int> paths, int total_num) {
     string str;
     for (int str_i = 0; str_i < total_num; ++ str_i) {
       str += '(';
     }
     
     for (int path: paths) {
       str[path] = ')';
     }
     return str;
   }
   
   void combination(int total_num, int tot_sel_num, int index, vector<int> & paths, int left_cnt, vector<string> & str_vec) {
      if (tot_sel_num == paths.size()) {
        str_vec.push_back(formStr(paths, total_num));
        return;
      }
      for (int sel_i = index; sel_i < total_num - (tot_sel_num - paths.size() - 1); ++ sel_i) {
        int inc_left = getIncLeft(paths, sel_i);
        if (inc_left + left_cnt < paths.size() + 1 ) {
          continue;
        }
        paths.push_back(sel_i);       
        combination(total_num, tot_sel_num, sel_i + 1, paths, left_cnt + inc_left, str_vec);
        paths.pop_back();
      }  
   }
   vector<string> generateParenthesis(int n) {
     vector<int> paths;
     vector<string> str_vec;
     combination(2 * n, n, 0, paths, 0, str_vec);
     return str_vec;
   }
};
