/**
* @file main.cpp
* @description main fonksiyonu
* @course 1.Öğretim B grubu
* @assignment 1.ödev
* @date 20.11.2022
* @author Eray Alçin - eray.alcin1@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <conio.h>
#include <ctime>
#include "../include/yonetici_listesi.hpp"

using namespace std;

int ms;
int ptd;
int sel = -1;
bool confirmed = false;
void printRange(int start, int col, SatirListesi sList, YoneticiListesi yList)
{
    cout << endl;
    yList.initList(sList);
    int end = yList.yonList.getSize();
    ms = end;
    if (end >= start + 8)
    {
        end = start + 8;
    }
    else
    {
        end = ms;
    }
    int key = (start + col) % (end - start);
    yList.yonList.horPrint(start, end);
    ptd = yList.yonList.getKey(key + start);
    if (confirmed)
        sel = -1;
    sList.satList[yList.yonList.getKey(key + start)].verPrint(key, sel);
}

int main()
{
    srand((int)time(NULL));
    YoneticiListesi yList;
    SatirListesi sList;
    sList.initList();
    printRange(0, 0, sList, yList);
    int index = 0;
    int page = 0;

    while (true)
    {
        char ch = getch();
        if (ch == '0')
        {
            break;
        }
        if (ch == 'a')
        {
            sel = -1;
            if (index > 0)
            {
                index--;
                // index = 0;

                system("cls");
                printRange(page, index, sList, yList);
            }
        }
        if (ch == 'd')
        {
            sel = -1;
            if (index < 7 && index < ms - page - 1)
            {
                index++;
                system("cls");
                printRange(page, index, sList, yList);
            }
        }
        if (ch == 'z')
        {
            sel = -1;
            if (page >= 8)
            {
                page = page - 8;

                system("cls");
                printRange(page, index, sList, yList);
            }
        }
        if (ch == 'c')
        {
            sel = -1;
            if (page < ms - 8)
            {
                page = page + 8;
                if (index > ms - page - 1)
                    index = 0;
                system("cls");
                printRange(page, index, sList, yList);
            }
        }

        if (ch == 'p')
        {
            sel = -1;
            sList.delAt(ptd);
            if (ms - page == 1)
            {
                page -= 8;
            }
            index = 0;
            system("cls");
            printRange(page, index, sList, yList);
        }

        if (ch == 'k' && confirmed)
        {
            sel = -1;
        }

        if (ch == 'k' && sel != -1)
        {
            if (sList.satList[ptd].getSize() == 1)
            {
                sel = -1;
                sList.delAt(ptd);
                if (ms - page == 1)
                {
                    page -= 8;
                }
                index = 0;
            }
            else
            {
                sList.satList[ptd].removeAt(sel + 1);
            }
            confirmed = true;
            system("cls");
            printRange(page, index, sList, yList);
                }

        if (ch == 'k' && sel == -1)
        {
            int len = sList.satList[ptd].getSize();
            sel = rand() % len;

            system("cls");
            printRange(page, index, sList, yList);
            confirmed = false;
        }
    }
    return 0;
}