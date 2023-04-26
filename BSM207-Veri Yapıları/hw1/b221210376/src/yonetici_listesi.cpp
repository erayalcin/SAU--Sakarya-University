/**
* @file yonetici_listesi.cpp
* @description Çift Yönlü Bağlı Liste Kullanımı
* @course 1.Öğretim B grubu
* @assignment 1.ödev
* @date 20.11.2022
* @author Eray Alçin - eray.alcin1@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "../include/yonetici_listesi.hpp"

void YoneticiListesi::initList(SatirListesi sList)
{
    for (int i = 0; i < sList.count; i++)
    {
        float f = (sList.satList[i].getAvg());
        yonList.append(f, i);
    }
    yonList.bubbleSort();
}
