#include <iostream>

const int LIM_SUP = 1000000;
using namespace std;

/** \brief Inicia los valores de la criba, tambien inicia la sumatoria
 * \param criba El arreglo dondé se guardan los resultados
 */
void IniciarCriba(bool criba[]);

/** \brief Calcula la cantidad de primos en el intervalo [incio,fin]
 *
 * \param inicio El limite inferior del intervalo
 * \param fin El limite superior del intervalo
 * \return La cantidad de primos en el intervalo
 *
 */
unsigned ContarPrimos(int inicio, int fin);


/** \brief Incrementa el valor del ABI
 *
 * \param i el valor del indice a aumentar
 * \param val el valor por el cual se va a imcrementar
 *
 */
void IncSuma(int i,int val);


/** \brief Obtiene el valor de la sumatoria desde 0 hasta i en el ABI
 *
 * \param i El indice de la sumatoria a consguir
 * \return El valor de la sumatoria hasta i
 *
 */
unsigned GetSuma(int i);


// 'sumatoria' es un Arbol Binario Indexado (ABI), es una estructura para guardar sumatorias
int sumatoria[LIM_SUP +2];

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
        cout << ContarPrimos(i,j) << '\n';
    }
    return 0;
}

void IniciarCriba(bool criba[])
{
    for(int i = 0; i <= LIM_SUP; ++i) criba[i] = true;

    for(int i = 2; i <= LIM_SUP; ++i){
        if(criba[i]){
            IncSuma(i,1);
            for(int j = i*2; j <= LIM_SUP; j+=i)
                criba[j] = false;
        }
    }
}



unsigned ContarPrimos(int inicio, int fin)
{
    //Anteriormente, está funcion tenia tiempo de O(fin - inicio),
    //  ahora tiene O(Log(inicio) )+ O(Log(fin)), segun Wikipedia GetSuma tiene tiempo
    //       O(log(n)) (O() es una funcipón, pero ni idea de que es ,pero mientras más
    //           grande sea el valor adentro más tiempo tarda en ejecutar el programa)
    return GetSuma(fin) - GetSuma(inicio-1);
}


// Un ABI guarda la suma descomponiendo el número en bits,  ejemplo, para aumentar el 5 (101)
//          tines que incrementar el (101) despues el (1101), despues el (11101)... hasta el LIM_SUP
void IncSuma(int i,int val)
{
    while(i <= LIM_SUP)
    {
        sumatoria[i]+=val;
        i+=( i & -i); // Está operacion es para pasar del (101) al (1101)
    }
}

// para obtener una suma, con la construccion anterior, hace falta "sumar todos los '1' "
// Por ejemplo, para el 11(1011) tenemos que sumar el (1011) + (1010) + (1000)
unsigned GetSuma(int i)
{
    unsigned s = 0;
    while(i > 0)
    {
        s += sumatoria[i];
        i-=( i & -i);
    }
    return s;
}

