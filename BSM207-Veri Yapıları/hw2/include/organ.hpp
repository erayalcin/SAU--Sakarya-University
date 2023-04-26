/**
* @file organ.hpp
* @description Organ
* @course 1.Öğretim B grubu
* @assignment 2
* @date 14.12.2022
* @author eray.alcin1@ogr.sakarya.edu.tr
*/
#ifndef ORGAN_H
#define ORGAN_H

#include <iostream>
using namespace std;

class Organ
{
private:
    int count;

public:
    Organ();
    int *dna_value;
    int get_Doku_count();
    void set_Doku_count(int cnt);
};

#endif