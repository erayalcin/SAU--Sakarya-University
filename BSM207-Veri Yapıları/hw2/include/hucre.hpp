/**
* @file doku.hpp
* @description Hücre
* @course 1.Öğretim B grubu
* @assignment 2
* @date 14.12.2022
* @author eray.alcin1@ogr.sakarya.edu.tr
*/
#ifndef HUCRE_H
#define HUCRE_H

#include <iostream>
using namespace std;

class Hucre
{
private:
    string dna_bar;

public:
    string get_DNA_bar();
    void set_DNA_bar(string dnab);
};

#endif