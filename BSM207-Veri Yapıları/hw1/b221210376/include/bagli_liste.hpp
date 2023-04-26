/**
* @file bagli_liste.hpp
* @description çift yönlü bağlı liste ve node oluşturulması
* @course 1.Öğretim B grubu
* @assignment 1.ödev
* @date 20.11.2022
* @author Eray Alçin - eray.alcin1@ogr.sakarya.edu.tr
*/
#ifndef BAGLI_LISTE_H
#define BAGLI_LISTE_H

#include <iostream>

class Node
{
public:
    float data;
    Node *next;
    Node *prev;
    int key;
    Node(float data , int key)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
        this->key = key;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    float getAvg();
    int getKey(int s);
    int getSize();
    void append(float data, int key);
    void removeHeader();
    void removeTail();
    void removeAt(int pos);
    void verPrint(int key, int sel);
    void horPrint(int start, int end);
    void bubbleSort();
    ~LinkedList();
};
#endif