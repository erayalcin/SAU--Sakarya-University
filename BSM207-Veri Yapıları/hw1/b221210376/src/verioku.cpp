/**
* @file verioku.cpp
* @description dosya okuma
* @course 1.Öğretim B grubu
* @assignment 1.ödev
* @date 20.11.2022
* @author Eray Alçin - eray.alcin1@ogr.sakarya.edu.tr
*/
#include "../include/verioku.hpp"

void VeriOku::getHowManyLines()
{
    string str;
    ifstream file;
    count = 0;

    file.open(fileName);
    while (!file.eof())
    {
        getline(file, str);
        count++;
    }
    file.close();
}

void VeriOku::getEachLine()
{
    string str;
    ifstream file;
    strLines = new string[count];
    file.open(fileName);
    for (int i = 0; i < count; i++)
    {
        getline(file, str);
        strLines[i] = str;
    }
    file.close();
}

void VeriOku::isolateNumbersOf(int myLine)
{
    arrx = new int[255];
    string line = strLines[myLine];
    line.erase(line.find_last_not_of(" ") + 1);
    string arr[255];
    size = 0;
    stringstream ssin(line);
    int no = 0;
    while (ssin.good() && size < 255)
    {
        ssin >> arr[size];
        arrx[size] = stoi(arr[size]);
        ++size;
    }
}