/**
* @file queue.hpp
* @description Queue
* @course 1.Öğretim B grubu
* @assignment 2
* @date 14.12.2022
* @author eray.alcin1@ogr.sakarya.edu.tr
*/
#ifndef QUEUE_H
#define QUEUE_H

class Que
{
private:
    int *data, front, rear, size;

public:
    Que();
    bool isFull();
    bool isEmpty();
    void enQue(int value);
    int deQue();
    void displayQue();
    void changeData(int index, int newData);
};

#endif