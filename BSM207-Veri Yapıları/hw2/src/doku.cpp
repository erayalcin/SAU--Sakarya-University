/**
* @file doku.cpp
* @description Doku
* @course 1.Öğretim B grubu
* @assignment 2
* @date 14.12.2022
* @author eray.alcin1@ogr.sakarya.edu.tr
*/
#include "doku.hpp"
#include "kontrol.hpp"

Doku::Doku()
{
    dna_cells = new int[MAS];
}

int Doku::get_DNA_count()
{
    return count;
}

void Doku::set_DNA_count(int cnt)
{
    count = cnt;
}