class Vector2D {
public:
    int row_i; 
    vector<vector<int>::iterator> curr_vec; 
    vector<vector<int>::iterator> end_vec; 

    Vector2D(vector<vector<int>>& vec2d) {
      // Initialize your data structure here
      int row_size = vec2d.size(); 
      
      curr_vec.resize(row_size);
      end_vec.resize(row_size);
      
      for (int iter = 0; iter < row_size ; ++ iter) {
        curr_vec[iter] = vec2d[iter].begin();
        end_vec[iter] = vec2d[iter].end();
      }
      row_i = -1;
    }

    int next() {
      // Write your code here
      row_i = peek_row_i;
      curr_vec[row_i] = peek_iter;
      return *peek_iter;
    }

    int peek_row_i;
    vector<int>:: iterator peek_iter;

    bool hasNext() {
      // Write your code here
      int curr_vec_size = curr_vec.size();
      if (curr_vec_size == 0) {
        return false;
      }

      if (row_i == -1) {
        // first element
        peek_row_i = 0;
        for(; peek_row_i < curr_vec_size; peek_row_i ++ ) {
          peek_iter = curr_vec[peek_row_i];
          if (peek_iter != end_vec[peek_row_i]) {
            break;
          }
        }

      } else {
        // has one valid element std::and looking for the next
        peek_row_i = row_i;
        peek_iter = curr_vec[peek_row_i];
        peek_iter = std::next(peek_iter, 1);
        if (peek_iter == end_vec[peek_row_i]) {
          while(true) {
            ++ peek_row_i;
            if (peek_row_i >= curr_vec_size){
              break;
            }
            peek_iter = curr_vec[peek_row_i];
            if (peek_iter != end_vec[peek_row_i]) {
              break;
            }
          }
        }
      }
      return peek_row_i != curr_vec_size;
    }
};
