/**
* @file bagli_liste.hpp
* @description satir listesini oluşturma
* @course 1.Öğretim B grubu
* @assignment 1.ödev
* @date 20.11.2022
* @author Eray Alçin - eray.alcin1@ogr.sakarya.edu.tr
*/
#ifndef SATLIST_H
#define SATLIST_H

#include <iostream>
#include "../include/bagli_liste.hpp"
#include "../include/verioku.hpp"

class SatirListesi
{
public:
    LinkedList *satList = new LinkedList();
    int count = 0;
    void initList();
    void delAt(int pos);
};

#endif
