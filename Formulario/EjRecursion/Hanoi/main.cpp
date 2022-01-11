#include <iostream>


using namespace std;

bool RespRec(char *palabra, int inicio, int fin)
{
    if(inicio >= fin ) return true;

    if(palabra[inicio] != palabra[fin]) return false;
    return RespRec(palabra, inicio+1,fin-1);
}

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    char palabra[1002];
    int t=0;

    cin>>palabra;
    while(palabra[t] != '\0')
        ++t;

    if( RespRec(palabra, 0,t-1))
        cout<< "Si";
    else
        cout<<"No";

    return 0;
}
