/**
* @file kontrol.hpp
* @description Kontrol
* @course 1.Öğretim B grubu
* @assignment 2
* @date 14.12.2022
* @author eray.alcin1@ogr.sakarya.edu.tr
*/
#ifndef KONTROL_H
#define KONTROL_H
#define MAS 128
#define MSS 1024
#define MTS 20
#define MOS 100

class Kontrol
{
private:
    int SOD_phase[5];
    int countedLines;
    int organizmVolume;

public:
    int *Sistem_Organ_Doku_index(int S = -1, int O = -1, int D = -1);
    int kacSatir();
    void startSimulation();
    int getOrganizmVolue();
};

#endif