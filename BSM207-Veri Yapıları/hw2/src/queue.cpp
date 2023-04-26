/**
* @file queue.cpp
* @description Queue
* @course 1.Öğretim B grubu
* @assignment 2
* @date 14.12.2022
* @author eray.alcin1@ogr.sakarya.edu.tr
*/
#include <iostream>
#include "queue.hpp"
#include "kontrol.hpp"

using namespace std;

Que::Que()
{
    size = MOS * MAS;
    data = new int[size];
    front = -1;
    rear = -1;
}

bool Que::isFull()
{
    if (front == 0 && rear == size - 1)
    {
        return true;
    }
    return false;
}

bool Que::isEmpty()
{
    if (front == -1)
        return true;
    else
        return false;
}

void Que::enQue(int value)
{
    if (isFull())
    {
        cout << endl
             << "Que is full!!";
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        data[rear] = value;
    }
}
int Que::deQue()
{
    int value;
    if (isEmpty())
    {
        cout << "Que is empty!!" << endl;
        return (-1);
    }
    else
    {
        value = data[front];
        if (front >= rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        cout << endl
             << "Deleted => " << value << " from data";
        return (value);
    }
}

void Que::changeData(int index, int newData)
{
    int i;
    if (isEmpty())
    {
        cout << endl
             << "Que is Empty!!" << endl;
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            if (i == index)
                data[i] = newData;
        }
    }
}

void Que::displayQue()
{
    int i, j = 0;
    char c;
    if (isEmpty())
    {
        cout << endl
             << "Que is Empty!!" << endl;
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            data[i] >= -1 && data[i] <= 1 ? c = ' ' : c = '#';
            cout << c;
            j++;
        }
        if (j % 100 == 0)
            cout << endl;
    }
}
