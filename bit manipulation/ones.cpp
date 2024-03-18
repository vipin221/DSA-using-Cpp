#include<iostream>
#include<cstdint>
using namespace std;

int main(){
      uint32_t t = 11;
      int c  = 0;
   while(t!=0){

    t = t & (t-1);
    cout<<t<<endl;
    c++;


   }
   cout<<c <<endl;
      
    

 
return 0;
}