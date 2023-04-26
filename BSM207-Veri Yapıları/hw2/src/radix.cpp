/**
* @file radix.cpp
* @description Radix
* @course 1.Öğretim B grubu
* @assignment 2
* @date 14.12.2022
* @author eray.alcin1@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "radix.hpp"
#include "kontrol.hpp"

using namespace std;


int Radix::maksimumOlsun(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void Radix::saymaSiralamasi(int arr[], int n, int exp)
{
    int cikti[MAS]; // çıkış dizisi
    int i, say[10] = {0};

    for (i = 0; i < n; i++)
        say[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        say[i] += say[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        cikti[say[(arr[i] / exp) % 10] - 1] = arr[i];
        say[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = cikti[i];
}

void Radix::radixSiralamasi(int arr[], int n)
{
    int m = maksimumOlsun(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        saymaSiralamasi(arr, n, exp);
}

void Radix::yazdir(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
