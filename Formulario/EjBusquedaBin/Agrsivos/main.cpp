#include <bits/stdc++.h>

using namespace std;

bool SiSePuede(const int &espacioReq , const int &personas ,const int cubiculos[], const int &nc)
{
    int ultCubOcupado=0;
    int CubNum=1;

    for(int i=1; CubNum<nc ;++CubNum)
    {
       if(cubiculos[CubNum]-cubiculos[ultCubOcupado] >= espacioReq)
       {
           ultCubOcupado=CubNum;
           if(++i == personas) return true;
       }
    }
    return false;
}

void PuntoMedio(int &RInf, int &RSup, const int &personas , const int cubiculos[], const int &nc)
{
    int mit;
    while(RSup > (RInf + 1) )
    {
        mit = RInf + (RSup-RInf)/2; //<- RInf + (RSup-inf)/2 Evita Overflow

        if(SiSePuede(mit, personas,cubiculos,nc) < 1 ) RSup = mit;
        else RInf = mit;

    }
    return ; //Regresa un rango de valores (Un par)
}


int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int cubiculos,personas,posCubiculo[100005];

    cin>>cubiculos>>personas;
    for(int i=0; i<cubiculos ; ++i) cin>>posCubiculo[i];
    sort(posCubiculo,posCubiculo+cubiculos);

    int sup(posCubiculo[cubiculos-1]) ,inf(1);
    PuntoMedio(inf,sup,personas,posCubiculo,cubiculos);
    if(SiSePuede(sup,personas,posCubiculo,cubiculos)) cout<<sup;
    else cout<<inf;

    return 0;
}
