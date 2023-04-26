/**
* @file organizma.hpp
* @description Organizma
* @course 1.Öğretim B grubu
* @assignment 2
* @date 14.12.2022
* @author eray.alcin1@ogr.sakarya.edu.tr
*/
#ifndef ORGANIZMA_H
#define ORGANIZMA_H

#include <iostream>
using namespace std;
class Organizma
{
private:
    int count;

public:
    Organizma();
    int *sistemGroup;
    int get_Sistem_count();
    void set_Sistem_count(int cnt);
};

#endif