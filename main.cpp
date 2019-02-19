#include <iostream>
#include <thread>
#include <array>
#include <chrono>
using namespace std;

int bitesXchar(char evaluando)
{
    int cont = 0;
    for(int shift = 0; shift < sizeof(evaluando)* 8; shift++)
        if ( evaluando & (1 << shift) )
            /*
             * shift dicta cuantos espacios se hara el left shift en 0 0 0 0 0 0 0 1, basicamente compara bit por bit
             * */
            cont++;
    /*cout << "The char : *" << evaluando
         << "* has : " << cont << " active bits\n";*/
    return cont;
}

int main() {


    //Se declaran las variables
    int tamano = 10000;
    int cantBits =0;
    char  byte_array[tamano];

    //se llena el array de manera rand, esto es por el momento ya que el profe nos asignara el array
    for (char &i : byte_array)
        i = ' '+ rand()%95; //Agarra un numero random entre 32 y 126, estos caracteres son leidos sin problemas

    auto start = chrono::steady_clock::now();
    for (int x=0; x<9999; x++)
        cantBits+= bitesXchar(byte_array[x]);

    auto finish = chrono::steady_clock::now();
    cout << "Cant of active bits : "
         << cantBits
         << " bits " << endl;
    cout << "Elapsed time in nanoseconds : "
         << chrono::duration_cast<chrono::nanoseconds>(finish - start).count()
         << " ns" << endl;


    return 0;
}
