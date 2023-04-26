/**
* @file organizma.cpp
* @description Organizma
* @course 1.Öğretim B grubu
* @assignment 2
* @date 14.12.2022
* @author eray.alcin1@ogr.sakarya.edu.tr
*/
#include "organizma.hpp"
#include "kontrol.hpp"

Organizma::Organizma()
{
    sistemGroup = new int[MOS];
}

int Organizma::get_Sistem_count()
{
    return count;
}

void Organizma::set_Sistem_count(int cnt)
{
    count = cnt;
}