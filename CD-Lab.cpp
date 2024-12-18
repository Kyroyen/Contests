#include <bits/stdc++.h>
using namespace std;
typedef struct{
    string name;
    int value;
} Symbol;

Symbol symbolTable[100];

int SymbolCount = 0;

void addSymbol(string name, int value){
    symbolTable[SymbolCount].name = name;
    symbolTable[SymbolCount].value = value;
    SymbolCount++;
}

int main(){
    int n = 0, value;
    cin>>n;
    string name;
    for(int i = 0; i<n; i++){
        cin>>name>>value;
        addSymbol(name, value);
    }
    cout<<"name\tvalue"<<endl;
    for(int i=0; i<SymbolCount; i++){
        cout<<symbolTable[i].name<<"\t"<<symbolTable[i].value<<endl;
    }
    return 0; 
}