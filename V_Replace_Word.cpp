#include<iostream>
#include <string> 
using namespace std;

int main() {
    string name;
    getline (cin, name);
    while(name.find("EGYPT") != -1){
        name.replace(name.find("EGYPT"),5," ");
    }
    cout<<name;
    return 0;
}
