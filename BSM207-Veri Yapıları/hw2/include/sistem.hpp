/**
* @file sistem.hpp
* @description Sistem
* @course 1.Öğretim B grubu
* @assignment 2
* @date 14.12.2022
* @author eray.alcin1@ogr.sakarya.edu.tr
*/
#ifndef SISTEM_H
#define SISTEM_H

#include <iostream>
using namespace std;

class Sistem
{
private:
    int count;

public:
    Sistem();
    int *nSistem;
    int *mSistem;
    int get_Organ_count();
    void set_Organ_count(int cnt);
};

#endif