#include <iostream>
using namespace std;

void TOH(int n,char peg1, char peg2, char peg3){
    if (n==1){
    cout<<"Move top disk from "<<peg1<<"to "<<peg2<<endl;
    return;
    }
    TOH(n-1, peg1, peg3,peg2);
    cout<<"Move top disk from "<<peg1<<"to "<<peg2<<endl;
    TOH(n-1, peg3, peg2, peg1);
}

int main(){
    
    TOH(4,'P','S','T');
    return 0;
}
