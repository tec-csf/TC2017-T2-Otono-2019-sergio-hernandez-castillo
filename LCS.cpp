/*
Sergio Hernandez Castillo, A01025210

02/10/2019

Descripción: Este programa determina la longitud de una subsecuencia tomada de una secuencia X y Y.

Complejidad y técnica de diseño: Este algoritmo/programa tiene una complejidad O(nm), donde n y m son las longitudes de las secuencias X y Y, respectivamente. Este algoritmo/programa es un algoritmo que utiliza programación dinámica.

El codigo fue basado de https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
*/

#include<bits/stdc++.h>
using namespace std;

int max(int a, int b);

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
        if (i == 0 || j == 0)
            L[i][j] = 0;

        else if (X[i - 1] == Y[j - 1])
            L[i][j] = L[i - 1][j - 1] + 1;

        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    /* L[m][n] contains length of LCS
    for X[0..n-1] and Y[0..m-1] */
    return L[m][n];
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

int main()
{
    char X[] = "010001";
    char Y[] = "000011";

    int m = strlen(X);
    int n = strlen(Y);

    cout << "Length of LCS is "
         << lcs( X, Y, m, n );

    return 0;
}
