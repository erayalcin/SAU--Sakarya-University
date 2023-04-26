/**
* @file bagli_liste.cpp
* @description çift yönlü bağlı liste ve node oluşturulması
* @course 1.Öğretim B grubu
* @assignment 1.ödev
* @date 20.11.2022
* @author Eray Alçin - eray.alcin1@ogr.sakarya.edu.tr
*/
#include "../include/bagli_liste.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

float LinkedList::getAvg()
{
    Node *n = head;
    int i = 0;
    float avg = 0.0;
    while (n != NULL)
    {
        avg += n->data;
        n = n->next;
        i++;
    }
    avg = avg / i;
    return avg;
}

int LinkedList::getKey(int s)
{
    Node *n = head;
    for (int i = 0; i < s; i++)
    {
        n = n->next;
    }

    return n->key;
}

int LinkedList::getSize()
{
    return size;
}

void LinkedList::append(float data, int key)
{
    Node *n = new Node(data, key);
    if (head == NULL)
    {
        head = n;
        tail = n;
    }
    else
    {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    size++;
}

void LinkedList::removeHeader()
{
    if (head->next == NULL)
    {
        delete (head);
        head = NULL;
        tail = NULL;
    }
    else if (head != NULL)
    {
        head = head->next;
        delete (head->prev);
        head->prev = NULL;
    }
    size--;
}

void LinkedList::removeTail()
{
    if (head->next == NULL)
        removeHeader();
    else if (head != NULL)
    {
        tail = tail->prev;
        delete (tail->next);
        tail->next = NULL;
        size--;
    }
}

void LinkedList::removeAt(int pos)
{
    if (pos > size || pos < 1)
        return;
    else if (pos == 1)
        removeHeader();
    else if (pos == size)
        removeTail();
    else if (head != NULL)
    {
        Node *current = head;
        for (int i = 1; i < pos; i++)
            current = current->next;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete (current);
        current = NULL;
        size--;
    }
}

void LinkedList::verPrint(int key, int sel)
{
    int cols = key * 16;
    int i = 0;
    Node *temp = head;
    if (key != 0)
        printf("%*c", cols, ' ');
    printf("%10s\n", "^^^^^^^^^^");
    while (temp != NULL)
    {
        if (key != 0)
            printf("%*c", cols, ' ');
        printf(" %8p \n", &temp->data);
        if (key != 0)
            printf("%*c", cols, ' ');
        printf("%10s\n", "----------");
        if (key != 0)
            printf("%*c", cols, ' ');
        printf("|%5.0f   |\n", temp->data);
        if (key != 0)
            printf("%*c", cols, ' ');
        printf("%10s", "----------");
        if (i == sel)
            printf("%25s", "   <---- silinecek secili");
        cout << endl;
        temp = temp->next;
        if (key != 0)
            printf("%*c", cols, ' ');
        printf("|%8p|\n", &temp->data);
        if (key != 0)
            printf("%*c", cols, ' ');
        printf("%10s\n\n", "----------");
        i++;
    }
    cout << endl;
}

void LinkedList::horPrint(int start, int end)
{
    Node *temp = head;
    for (int j = 0; j < start; j++)
    {
        temp = temp->next;
    }
    int i = start;
    while (temp != NULL && (i >= start && i < end))
    {
        if (i == 0)
        {
            printf("ilk-->%4s\t", " ");
        }
        else if (i % 8 == 0 && i != 0 && i < size - 1)
        {
            printf("<-----%4s\t", " ");
        }
        else if (i % 8 == 7 && i != size - 1)
        {
            printf("%4s----->\t", " ");
        }
        else if (i == size - 1)
        {
            printf("%4s<--son\t", " ");
        }
        else if (i == size - 1 && i % 8 == 1)
        {
            printf("<----- son\t");
        }
        else
        {
            printf("%10s\t", " ");
        }
        temp = temp->next;
        i++;
    }
    cout << endl;
    temp = head;
    for (int j = 0; j < start; j++)
    {
        temp = temp->next;
    }
    i = start;
    while (temp != NULL && (i >= start && i < end))
    {
        printf(" %8p \t", &temp->data);
        temp = temp->next;
        i++;
    }
    cout << endl;
    temp = head;
    for (int j = 0; j < start; j++)
    {
        temp = temp->next;
    }
    i = start;
    while (temp != NULL && (i >= start && i < end))
    {
        printf("%10s\t", "----------");
        temp = temp->next;
        i++;
    }
    cout << endl;
    temp = head;
    for (int j = 0; j < start; j++)
    {
        temp = temp->next;
    }
    i = start;
    while (temp != NULL && (i >= start && i < end))
    {
        printf("|%8p|\t", &temp->prev->data);
        temp = temp->next;
        i++;
    }
    cout << endl;
    temp = head;
    for (int j = 0; j < start; j++)
    {
        temp = temp->next;
    }
    i = start;
    while (temp != NULL && (i >= start && i < end))
    {
        printf("%10s\t", "----------");
        temp = temp->next;
        i++;
    }
    cout << endl;
    temp = head;
    for (int j = 0; j < start; j++)
    {
        temp = temp->next;
    }
    i = start;
    while (temp != NULL && (i >= start && i < end))
    {
        float f = temp->data;
        if (f - floor(f) != 0)
        {
            printf("|%6.1f  |\t", f);
        }
        else
        {

            printf("|%5.0f   |\t", f);
        }
        temp = temp->next;
        i++;
    }
    cout << endl;
    temp = head;
    for (int j = 0; j < start; j++)
    {
        temp = temp->next;
    }
    i = start;
    while (temp != NULL && (i >= start && i < end))
    {
        printf("%10s\t", "----------");
        temp = temp->next;
        i++;
    }
    cout << endl;
    temp = head;
    for (int j = 0; j < start; j++)
    {
        temp = temp->next;
    }
    i = start;
    while (temp != NULL && (i >= start && i < end))
    {
        printf("|%8p|\t", &temp->next->data);
        temp = temp->next;
        i++;
    }
    cout << endl;
    temp = head;
    for (int j = 0; j < start; j++)
    {
        temp = temp->next;
    }
    i = start;
    while (temp != NULL && (i >= start && i < end))
    {
        printf("%10s\t", "----------");
        temp = temp->next;
        i++;
    }
    cout << endl;
}

void LinkedList::bubbleSort()
{
    int swapped, i;
    Node *n = head;
    Node *ptr1;
    Node *lptr = NULL;

    if (n == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = n;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1->data, ptr1->next->data);
                swap(ptr1->key, ptr1->next->key);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

LinkedList::~LinkedList()
{
    Node *next = head->next;
    while (head != NULL)
    {
        next = head->next;
        delete (head);
        head = next;
    }
}
