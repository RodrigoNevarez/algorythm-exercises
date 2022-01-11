#include <bits/stdc++.h>

using namespace std;
int n,tAux,ortcion,contI,contD,numI,numD,res;
int esperaIzq[10000],esperaDer[10000];
int espA; //<- 0 si la cinta está detenida, 1 si va izq->der, 2 si va der->izq

int Empieza()
{
    if(contI == numI) return 2;
    if(contD == numD) return 1;

    if(esperaIzq[contI] < esperaDer[contD])
        return 1;
    return 2;
}

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>tAux>>ortcion;
        if(ortcion == 0) esperaIzq[numI++]=tAux;
        else esperaDer[numD++]=tAux;
    }

    espA = Empieza();
    if(espA == 1) res = esperaIzq[0];
    else res = esperaDer[0];

    for(int i=0;i<n;)
    {
        espA = Empieza();

        if(espA == 1)
        {
            tAux=esperaIzq[contI];
            while( contI+1 < numI && esperaIzq[contI]+ 10 >= esperaIzq[contI+1] )
            {
                ++contI;
                ++i;
            }
            res += esperaIzq[contI]+10 -tAux;
            ++contI;
            ++i;
        }
        else
        {
            tAux=esperaDer[contD];
            while( contD+1 < numD && esperaDer[contD]+ 10 >= esperaDer[contD+1] )
            {
                ++contD;
                ++i;
            }
            res += esperaDer[contD]+10 -tAux;
            ++contD;
            ++i;
        }
    }
    cout<<res;
    return 0;
}
