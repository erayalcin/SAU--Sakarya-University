/**
* @file yonetici_listesi.hpp
* @description yönetici listesi
* @course 1.Öğretim B grubu
* @assignment 1.ödev
* @date 20.11.2022
* @author Eray Alçin - eray.alcin1@ogr.sakarya.edu.tr
*/
#ifndef YONLIST_H
#define YONLIST_H

#include <iostream>
#include "../include/satir_listesi.hpp"

class YoneticiListesi
{
public:
    LinkedList yonList;
    void initList(SatirListesi sList);
};

#endif
