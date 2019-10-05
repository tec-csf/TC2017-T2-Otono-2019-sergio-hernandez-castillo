/*
Sergio Hernandez Castillo, A01025210

02/10/2019

Descripción: Este programa determina cuales hombres estarían mejor con cuales mujeres para formar una pareja estable, basandose en las preferencias de todos los hombres y mujeres

Complejidad y técnica de diseño: Este algoritmo/programa tiene una complejidad O(n^2) por solo operar con un ciclo while y dos ciclos for separados dentro del while. Este algoritmo/programa es un algoritmo que utiliza programación dinámica.

El codigo fue basado de https://www.geeksforgeeks.org/stable-marriage-problem/
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

//Number of Men or Women
#define N  4

bool wPrefersM1OverM(int prefer[2*N][N], int w, int m, int m1)
{
    for (int i = 0; i < N; i++)
    {
        if (prefer[w][i] == m1)
            return true;

        if (prefer[w][i] == m)
           return false;
    }
}

void stableMarriage(int prefer[2*N][N])
{
    int wPartner[N];
    bool mFree[N];

    // Initialize all men and women as free
    memset(wPartner, -1, sizeof(wPartner));
    memset(mFree, false, sizeof(mFree));
    int freeCount = N;

    while (freeCount > 0)
    {
        int m;
        for (m = 0; m < N; m++)
            if (mFree[m] == false)
                break;

        for (int i = 0; i < N && mFree[m] == false; i++)
        {
            int w = prefer[m][i];

            if (wPartner[w-N] == -1)
            {
                wPartner[w-N] = m;
                mFree[m] = true;
                freeCount--;
            }

            else
            {
                int m1 = wPartner[w-N];

                if (wPrefersM1OverM(prefer, w, m, m1) == false)
                {
                    wPartner[w-N] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            } // End of Else
        }
    } // End of main while loop

    cout << "Woman   Man" << endl;
    for (int i = 0; i < N; i++)
       cout << " " << i+N << "\t" << wPartner[i] << endl;
}

int main()
{
  //The men go first in the array, with 4 rows dedicated to each one and that man's preferences for the women. 
    int prefer[2*N][N] = { {7, 5, 6, 4},
        {5, 4, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };
    stableMarriage(prefer);

    return 0;
}
