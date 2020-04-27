#include <iostream>
#include <vector>

using namespace std;

using std::vector;
using std::pair;

void depth(vector<vector<int> > &adj ,vector<bool> &visited , int curr_node){
	visited[curr_node] = true;
	for(int i = 0; i < adj[curr_node].size() ; i++){
		int v = adj[curr_node][i];
		if(!visited[v])
			depth(adj,visited,v);
	}
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  //write your code here
  vector<bool> visited(adj.size(),false);
  for(int i = 0 ; i < adj.size() ; i++){
  	if(!visited[i]){
  		depth(adj,visited,i);
  		res++;
	}
  }
  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
