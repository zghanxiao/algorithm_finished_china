class Solution {
public:
   int getIncLeft(vector<int> & paths) {
     if (paths.size() < 1) {
       return 0;
     } else if (paths.size() == 1) {
       return paths[0];
     } else {
       return paths[paths.size() - 1] - paths[paths.size() - 2] - 1;  
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
   
   void combination(int total_num, int to_select, int index, vector<int> & paths, int left_cnt, vector<string> & str_vec) {
      if (to_select == 0) {
        str_vec.push_back(formStr(paths, total_num));
        return;
      }
      for (int sel_i = index; sel_i < total_num; ++ sel_i) {
        paths.push_back(sel_i);       
        int inc_left = getIncLeft(paths);
        if (paths.size() <= left_cnt + inc_left) {
          combination(total_num, to_select - 1, sel_i + 1, paths, left_cnt + inc_left, str_vec);
        }
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
