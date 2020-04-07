class Node{
public:
  int v;
  int pre;
  int dist;
  Node(int v, int pre, int dist) {
    this->v = v;
    this->pre = pre;
    this->dist = dist;
  }
};

class Solution {
public:
    /**
     * @param n: The number of nodes
     * @param starts: One point of the edge
     * @param ends: Another point of the edge
     * @param lens: The length of the edge
     * @return: Return the length of longest path on the tree.
     */
    Solution() {
      heads.resize(200002);
      distance.resize(200002);
      edges.resize(200002);
      edge_num = 0;  
    }
    
    // store current node's edge_num, heads[u] node u has an edge of heads[u];
    // edges[heads[u]] is this edge.
    vector<int> heads;
    vector<Node*> edges;
    vector<int> distance;
    int edge_num;
    
    void add(int u, int v, int dist) {
      edges[edge_num] = new Node(v, heads[u], dist);
      heads[u] = edge_num++;
    }
    
    pair<int, int> bfs(int start_node) {
       fill(distance.begin(), distance.end(), 0);
       vector<bool> visited(200002, false);
       
       queue<int> q; 
       q.push(start_node);
       visited[start_node] = true;
       
       int max_i = start_node;
       int max_dist = 0;
       
       while(!q.empty()) {
         int top = q.front();
         q.pop();
         
         for (int iter = heads[top]; iter != -1; iter = edges[iter]->pre) {
           int v = edges[iter]->v;
           int dist = edges[iter]->dist;
           if (!visited[v]) {
             visited[v] = true;
             distance[v] = max(distance[top] + dist, distance[v]);
             if (max_dist < distance[v]) {
               max_dist = distance[v];
               max_i = v;
             }
             q.push(v); 
           }
         }
       }
       
       return make_pair(max_i, max_dist);
    }
    
    int longestPath(int n, vector<int> &starts, vector<int> &ends, vector<int> &lens) {
      // Write your code here
      if (n <= 1) {
        return 0;
      }
      
      fill(heads.begin(), heads.end(), -1);
      edges.resize(0);
      for (int iter = 0; iter < n - 1; ++ iter) {
        add(starts[iter], ends[iter], lens[iter]);  
        add(ends[iter], starts[iter], lens[iter]);
      }
      
      pair<int, int> first_pair = bfs(starts[0]);
      int first_i = first_pair.first;
      pair<int, int> second_pair = bfs(first_i);
      return second_pair.second;
    }
};
