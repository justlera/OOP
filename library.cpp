#include<iostream>
#include <stdlib.h>
#include <vector>
#include <limits>
#include <list>

using namespace std;

class Book{
public:
    virtual bool set_mark(int mark) = 0;
private:
    string name;
    string author;
    int date;
};

class PBook : public Book {
private:
    int pages;
    int mark;
    int state;
public:
    // проставляем оценку с требуемыми пределами
    bool set_mark(int mark) {
        if (mark < 1 || mark > 10) {
            return false;
        }
        else {
            this->mark = mark;
            return true;
        }
    }

    PBook(const string& name, const string& author, int date, int pages, int mark, int state)
        : name(name), author(author), date(date), pages(pages), mark(mark), state(state) {}

};

class Ebook:public Book {
private:
    int volume;
    //std::vector<int> dates;
    int date;
    int mark;
public:
    // то же, но пределы другие
    bool set_mark(int mark) {
        if (mark < 1 || mark > 100) {
            return false;
        }
        else {
            this->mark = mark;
            return true;
        }
    }

    Ebook(const string& name, const string& author, int volume, int date, int mark)
            : name(name), author(author), date(date), volume(volume), mark(mark) {}
};

struct Node{
    Book *pBook;
    Node *Next;
};

class Library{
    Node *Head, *Tail;                                            //Первый элемент и тот что последний
    int size;                                                     //Число элементов в списке
public:
    Library():Head(NULL),Tail(NULL),size(0){};                       //Инициализация элементов в ноль с помощью конструктора
    ~Library();                                                       //Прототип деструктор: в деструкторе освободим память
    void Add(Book *pb);                                              //Прототип функции добавления элементов в списов
    void Show(int temp);                                         //Прототип функции отображения элементов списка
    int Count();                                                  //Прототип функции возвращающей число элементов в списке
    void Del(Book *pb);
};

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
        Node*t2 = temp->Next->Next; // сохраняем указатель Next удаляемого элемента
        delete temp->Next->pBook; // удаляем книгу; надо использовать delete
        // вместо free, если память выделялась new
        delete temp->Next; // удаляем хранивший книгу элемент списка
        temp->Next = t2->Next; // восстанавливаем целостность списка

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

