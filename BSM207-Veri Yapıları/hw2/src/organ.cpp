/**
* @file organ.cpp
* @description Organ
* @course 1.Öğretim B grubu
* @assignment 2
* @date 14.12.2022
* @author eray.alcin1@ogr.sakarya.edu.tr
*/
#include "organ.hpp"
#include "kontrol.hpp"

Organ::Organ()
{
    dna_value = new int[MAS * MSS];
}

int Organ::get_Doku_count()
{
    return count;
}

void Organ::set_Doku_count(int cnt)
{
    count = cnt;
}