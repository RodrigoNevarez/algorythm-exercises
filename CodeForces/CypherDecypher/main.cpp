#include <iostream>

const int LIM_SUP = 1000000;
using namespace std;

void IniciarCriba(bool criba[]);
bool EsPrimoCriba(int num, bool criba[]);
unsigned ContarPrimos(int inicio, int fin, const bool criba[]);

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    bool primos[LIM_SUP + 2];
    IniciarCriba(primos);
    int t,i,j;
    cin >> t;
    for(int c=1; c <= t; ++c){
        cin >> i >> j;
        cout << ContarPrimos(i,j,primos) << '\n';
    }
    return 0;
}

void IniciarCriba(bool criba[])
{
    for(int i = 0; i <= LIM_SUP; ++i) criba[i] = true;
    for(int i = 2; i <= LIM_SUP; ++i){
        if(criba[i]){
            for(int j = i*2; j <= LIM_SUP; j+=i)
                criba[j] = false;
        }
    }
}

bool EsPrimoCriba(int num, const bool criba[])
{
    return criba[num];
}

unsigned ContarPrimos(int inicio, int fin, const bool criba[])
{
    unsigned numPrim = 0;
    for(int i = inicio; i <= fin; ++i){
        if(EsPrimoCriba(i, criba)) ++numPrim;
    }
    return numPrim;
}
