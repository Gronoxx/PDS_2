#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    int count;
    string frase;
    cin>>count;
    int pont[count]={};
    string falsos;
    getline(cin>>ws,falsos);
    getline(cin>>ws,frase);
    int count2=0;
    while(frase[count2])
    {
        int j=0;
    for(int i=0; i<(count+count-1);i=i+2){
        if(frase[count2]==falsos[i])
        {
        pont[j]++;
        frase[count2]='#';
        }
        j++;
        }
    count2++;    
    }
    cout<<frase<<endl;
    int j=0;
    for(int i=0;i<count;i++)
    {
    cout<<falsos[j];
    cout<<" ";
    cout<<pont[i]<<endl;    
    j=j+2;
    }
}
