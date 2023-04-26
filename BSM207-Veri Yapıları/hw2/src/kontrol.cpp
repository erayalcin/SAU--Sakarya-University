/**
* @file kontrol.cpp
* @description Kontrol
* @course 1.Öğretim B grubu
* @assignment 2
* @date 14.12.2022
* @author eray.alcin1@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "kontrol.hpp"
#include "radix.hpp"
#include "queue.hpp"
#include "bst.hpp"
#include "hucre.hpp"
#include "doku.hpp"
#include "organ.hpp"
#include "sistem.hpp"
#include "organizma.hpp"

using namespace std;

int *Kontrol::Sistem_Organ_Doku_index(int S, int O, int D)
{
    if (S != -1)
    {
        O = S * 100;
        D = O * 20;
    }
    if (O != -1)
    {
        S = (O % 100) / 100;
        D = O * 20 + 19;
    }
    if (D != -1)
    {
        O = (D - D % 20) / 20;
        S = (O - O % 100) / 100;
    }
    SOD_phase[0] = S;
    SOD_phase[1] = S * 100;
    SOD_phase[2] = S * 100 + 99;
    SOD_phase[3] = O * 20;
    SOD_phase[4] = O * 20 + 19;

    return SOD_phase;
}

int Kontrol::kacSatir()
{
    string str;
    ifstream dosya;
    countedLines = 0;

    dosya.open("Veri.txt");
    while (!dosya.eof())
    {
        getline(dosya, str);
        countedLines++;
    }
    dosya.close();
    return countedLines;
}

int Kontrol::getOrganizmVolue()
{
    return kacSatir() / MOS;
}

void Kontrol::startSimulation()
{
    int kac = kacSatir();
    int siz = getOrganizmVolue() + 1;
    BST_r bst;
    Radix radix;
    Hucre hucre;
    Doku doku=Doku();
    Organ organ=Organ();
    Sistem sistem = Sistem();
    Organizma organizma = Organizma();
    string str;
    ifstream dosya;
    dosya.open("Veri.txt");
    string dna = hucre.get_DNA_bar();
    int boyut = 0;
    int i = 0;
    organ.dna_value = new int[kac];
    while (getline(dosya, str))
    {
        str.erase(str.find_last_not_of(" ") + 1);
        string arr[1024];
        boyut = 0;
        stringstream ssin(str);
        doku.dna_cells = new int[MAS];
        while (ssin.good() && boyut < MSS)
        {
            ssin >> dna;
            doku.dna_cells[boyut] = stoi(dna);
            ++boyut;
        }
        radix.radixSiralamasi(doku.dna_cells, boyut);
        organ.dna_value[i] = doku.dna_cells[boyut / 2];
        delete[] doku.dna_cells;
        i++;
    }
    dosya.close();
    int s = 0;

    Node *root = new Node();
    bst.node = root;
    root = NULL;
    for (int j = 1; j <= i; j++)
    {
        if (j % 20 == 0 && root != NULL)
        {
            sistem.nSistem[s] = bst.get_balance_factor(root);
            sistem.mSistem[s] = bst.get_balance_factor(root);
            if (root->data % 50 == 0)
            {
                bst.index = 0;
                bst.mutate(root);
                int head = bst.arrm[bst.index / 2];
                for (int swap = (bst.index / 2) - 1; swap >= 0; swap--)
                {
                    bst.arrm[swap + 1] = bst.arrm[swap];
                }
                bst.arrm[0] = head;
                BST_r mbst;
                root = NULL;
                for (int m = 0; m < bst.index; m++)
                {
                    root = mbst.insert(root, bst.arrm[m]);
                }
                sistem.mSistem[s] = mbst.get_balance_factor(root);
                mbst.~BST_r();
            }
            bst.~BST_r();
            root = NULL;
            s++;
        }
        root = bst.insert(root, organ.dna_value[j]);
    }
    delete[] organ.dna_value;

    system("cls");
    cout << "                                ORGANIZMA\n";
    for (int i = 1; i < s; i++)
    {
        if (sistem.nSistem[i] >= -1 && sistem.nSistem[i] <= 1)
        {
            cout << " ";
        }
        else
        {
            cout << "#";
        }
        if (i % 100 == 0)
            cout << endl;
    }
    cout << endl;
    cin.ignore();
    system("cls");
    cout << "                      ORGANIZMA (MUTASYONA UGRADI)\n";
    for (int i = 1; i < s; i++)
    {
        if (sistem.mSistem[i] >= -1 && sistem.mSistem[i] <= 1)
        {
            cout << " ";
        }
        else
        {
            cout << "#";
        }
        if (i % 100 == 0)
            cout << endl;
    }
    cout << endl;
    delete[] sistem.nSistem;
    delete[] sistem.mSistem;
    cin.ignore();
    system("cls");
    system("pause");
}