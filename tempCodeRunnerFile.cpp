#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        v = V;
        l = new list<int>[V];
    }

    void addEdge(int i, int j)
    {
        l[i].push_back(j);
    }
    void Tepology_shorting()
    {
        vector<int> indegre(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto nbr : l[i])
            {
                indegre[nbr]++;
            }
        }

     queue<int> q;
     for(int  i = 0 ;i < V ;i++){
        if(indegre[i]==0){
            q.push(i);
        }
     }
     while(!q.empty()){
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        for(auto nbr : l[node] ){
            indegre[nbr]--;
            if(indegre[nbr] == 0){
                q.push(nbr);
            }
        }

     }

    }
};
int main(){