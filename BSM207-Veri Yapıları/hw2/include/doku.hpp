/**
* @file doku.hpp
* @description Doku
* @course 1.Öğretim B grubu
* @assignment 2
* @date 14.12.2022
* @author eray.alcin1@ogr.sakarya.edu.tr
*/
#ifndef DOKU_H
#define DOKU_H

#include <iostream>
using namespace std;

class Doku
{
private:
    int count;

public:
    Doku();
    int *dna_cells;
    int get_DNA_count();
    void set_DNA_count(int cnt);
};

#endif