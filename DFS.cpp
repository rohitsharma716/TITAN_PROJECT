#include <iostream>
#include<list>
#include <queue>
using namespace std;


class Graph{
    int V ;
    list<int> *l;
 public:
    Graph(int v){
        V =v;
        l = new list<int>[V];
    }

 void addEdge(int x, int y , bool undir=true )
 {
    l[x].push_back(y);
    if(undir){
        l[y].push_back(x);
    }
     
 }
 void dfshelper(int node , bool *visited){
   visited[node] = true ;
   cout<<node<< " ," ;
   for(auto nbr : l[node]){
      if(!visited[nbr]){
         dfshelper(nbr,visited);
      }
   }
   return;
 }

void dfs(int source){

   bool *visited = new bool [V]{0};
   dfshelper(source,visited);
}


};
int  main() {
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.dfs(1);
    return 0;
    
}