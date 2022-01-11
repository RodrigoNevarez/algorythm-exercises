#include <bits/stdc++.h>

using namespace std;

unsigned long long BusquedaBinaria(unsigned long long aBuscar,unsigned long long tamArr,unsigned long long arr[])
{
    unsigned long long inf(1),sup(tamArr),mit;
    while(sup >= inf)
    {
        mit = (inf + sup)/2; //<- inf + (sup-inf)/2 Evita Overflow

        if(arr[mit] == aBuscar) return mit;
        else
        {
            if(arr[mit] > aBuscar) sup = mit-1;
            else inf = mit+1;
        }

    }
    return inf;
}

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    unsigned long long nAutos,numPreg,preg,sumAut[100001],autosAt;

    cin>>numPreg>>nAutos;
    sumAut[0]=0;
    cin>>sumAut[1];

    for(unsigned long long i=2;i<=nAutos;++i)
    {
        cin>>sumAut[i];
        sumAut[i]+=sumAut[i-1];
    }

    for(unsigned long long i=0;i<numPreg;++i)
    {
        cin>>preg;
        autosAt=BusquedaBinaria(preg,nAutos,sumAut);

        while(autosAt >nAutos || sumAut[autosAt] > preg) --autosAt;
        while(autosAt < nAutos && sumAut[autosAt+1] < preg) ++autosAt;

        cout<<autosAt<<" "<<preg-sumAut[autosAt]<<'\n';
    }

    return 0;

}
