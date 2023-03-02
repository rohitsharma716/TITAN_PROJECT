#include <iostream>
using namespace std;

int febo(int n){
    if(n==0 or n==1){
        return n;
    }
    return febo(n-1) + febo(n-2);
 }

int  main(){
  
 cout<< febo(10);

    
}