/**
* @file sistem.cpp
* @description Sistem
* @course 1.Öğretim B grubu
* @assignment 2
* @date 14.12.2022
* @author eray.alcin1@ogr.sakarya.edu.tr
*/
#include "sistem.hpp"
#include "kontrol.hpp"

Sistem::Sistem()
{
    nSistem = new int[MOS * MAS];
    mSistem = new int[MOS * MAS];
}
int Sistem::get_Organ_count()
{
    return count;
}

void Sistem::set_Organ_count(int cnt)
{
    count = cnt;
}