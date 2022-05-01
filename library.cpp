#include<iostream>
#include <stdlib.h>
#include <vector>
#include <limits>
#include <list>
#include "library.h"

Library::~Library()
{
    while (size != 0)                        //Пока размерность списка не станет нулевой
    {
        Node *temp = Head->Next;
        delete Head;                           //Освобождаем память от активного элемента
        Head = temp;                           //Смена адреса начала на адрес следующего элемента
        size--;                                //Один элемент освобожден. корректируем число элементов
    }
}

int Library::Count(){
    return size;                             //Возвращаем число элементов списка
}

void Library::Add(Book *pb)
{
    size++;                                    //При каждом добавлении элемента увеличиваем число элементов в списке
    Node  *temp = new Node;                    //Выделение памяти для нового элемента списка
    temp->Next = Head;                         //Замыкание контура. Последний элемент - это начало списка
    temp->pBook = pb;                          //Записываем в выделенную ячейку памяти значение pb

    if (Head != NULL)                       //В том случае если список не пустой
    {
        Tail->Next = temp;                    //Запись данных в следующее за последним элементом поле
        Tail = temp;                          //Последний активный элемент=только что созданный.
    }
    else Head = Tail = temp;                //Если список пуст то создается первый элемент.
}

void Library::Del(Book *pb)
{
    if (Head == NULL) { cout << "\nСписок пуст\n\n"; }
    /*if (Head == Head->Next)
    {
        delete Head;
        Head = NULL;
    }*/
    else{
        Node* temp = Head;
        while (temp->Next && temp->Next->pBook != pb){
            temp = temp->Next;
        }
        Node* t2 = temp->Next->Next; // сохраняем указатель Next удаляемого элемента
        delete temp->Next->pBook; // удаляем книгу; надо использовать delete
        // вместо free, если память выделялась new
        delete temp->Next; // удаляем хранивший книгу элемент списка
        temp->Next = t2->Next; // восстанавливаем целостность списка
        size--;

    }
}

void Library::Show(int temp)
{
    Node *tempHead = Head;                  //Указываем на голову
    temp = size;                            //Временная переменная равная числу элементов в списке
    while (temp != 0)                        //Пока не выполнен признак прохода по всему списку
    {
        cout << tempHead->pBook << " ";           //Очередной элемент списка на экран
        tempHead = tempHead->Next;            //Указываем, что нужен следующий элемент
        temp--;                               //Один элемент считан, значит осталось на один меньше
    }
}

