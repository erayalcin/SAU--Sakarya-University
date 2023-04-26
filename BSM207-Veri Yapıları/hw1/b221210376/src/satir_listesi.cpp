/**
* @file satir_listesi.cpp
* @description satır listesini oluşturma
* @course 1.Öğretim B grubu
* @assignment 1.ödev
* @date 20.11.2022
* @author Eray Alçin - eray.alcin1@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "../include/satir_listesi.hpp"

using namespace std;

void SatirListesi::initList()
{
    VeriOku vo;
    vo.fileName = "veriler.txt";
    vo.getHowManyLines();
    vo.getEachLine();
    satList = new LinkedList[vo.count];
    for (int line = 0; line < vo.count; line++)
    {
        vo.isolateNumbersOf(line);
        for (int i = 0; i < vo.size; i++)
        {
            satList[line].append(vo.arrx[i], line);
        }
    }
    count = vo.count;
}

void SatirListesi::delAt(int pos)
{
    for (int i = pos + 1; i < count; i++)
    {
        satList[i - 1] = satList[i];
    }
    count -= 1;
}