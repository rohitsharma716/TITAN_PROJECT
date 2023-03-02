#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class Node{
 public:
    string name;
    list<string> nbrs;

 Node(string name){
    this->name = name;
 }

};
class Graph {
    unordered_map<string,Node*> m;

 public:
    Graph(vector<string> cities){
         for(auto city : cities){
            m[city] = new Node(city);
         }
    }
    void addEdge(string x, string y ,bool undir = false){
        m[x]->nbrs.push_back(y);
        if(undir){ 
            m[y]->nbrs.push_back(x);
        }
    }
    void printADJList(){
        for(auto cityPair : m){        
            auto city = cityPair.first;
            Node *node = cityPair.second;
            cout<<city<<"-->";
            for(auto nbr : node->nbrs){
                cout<<nbr<<" ,";
            }
            cout<<endl;
        }
    }
};
int main(){
   vector<string> cities ={"delhi","london","paris","New york"};
   Graph g(cities);
   g.addEdge("delhi","london");
   g.addEdge("New york","london");
   g.addEdge("delhi","paris");
   g.addEdge("paris","new york");

g.printADJList();
    return 0;
}