/**
* @file verioku.hpp
* @description dosyadan okuma işlemleri
* @course 1.Öğretim B grubu
* @assignment 1.ödev
* @date 20.11.2022
* @author Eray Alçin - eray.alcin1@ogr.sakarya.edu.tr
*/
#ifndef VERIOKU_H
#define VERIOKU_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <cctype>

using namespace std;

class VeriOku
{
public:
    int *arrx;
    string *strLines;
    int count;
    int size;
    string fileName;
    void getHowManyLines();
    void getEachLine();
    void isolateNumbersOf(int myLine);
};

#endif