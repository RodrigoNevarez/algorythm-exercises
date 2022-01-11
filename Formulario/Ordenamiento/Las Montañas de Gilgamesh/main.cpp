#include <bits/stdc++.h>

using namespace std;

class Montanas{
public:

    Montanas(){};
    Montanas(int alt, const char *nbre): altura(alt)
    {
        int i=0;

        for(; nbre[i] ;++i)
            nombre[i]=nbre[i];
        nombre[i]=nbre[i];
    }

    bool operator> (const Montanas &aComp) const{
        return altura>aComp.altura;
    }

    int altura;
    char nombre[12];

private:



};

void Intercambiar(Montanas arr[], int mtna1, int mtna2)
{
    Montanas aux=arr[mtna1];
    arr[mtna1] = arr[mtna2];
    arr[mtna2] = aux;


}

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int numMontanas;
    Montanas arrMontanas[100005];

    cin>>numMontanas;

    cin>>arrMontanas[0].altura>>arrMontanas[0].nombre;
    for(int i=1;i<numMontanas;++i)
    {
        cin>>arrMontanas[i].altura>>arrMontanas[i].nombre;
        for(int j=i-1; j>=0 && arrMontanas[j+1] > arrMontanas[j] ; j--)
        {
            Intercambiar(arrMontanas,j,j+1);
        }
    }

    for(int i=0;i<numMontanas;++i)
    {
        cout<<arrMontanas[i].nombre<<'\n';
    }



    return 0;
}
