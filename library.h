#ifndef LIBRARY_H
#define LIBRARY_H
#include<iostream>
#include <stdlib.h>
#include <vector>
#include <limits>
#include <list>
void test_library();

using std::list;
using namespace std;

class Book{
private:
    int date;
public:
    int id;
    string name;
    string author;
    virtual bool set_mark(int mark) = 0;

    Book(const string& name, const string& author, int date)
            : name(name), author(author), date(date) {}
    virtual Book *clone() const = 0;
    //int GetID() { return id; }
    virtual string getname() const { return name;}
    virtual string getauthor() const { return author;}
    //virtual string getall() const {return *this; }

    virtual ~Book() {};
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
            : Book(name, author, date), pages(pages), mark(mark), state(state) {}

    Book *clone() const;

};

class Ebook : public Book {
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
            : Book(name, author, date), volume(volume), mark(mark) {}
    Book *clone() const;
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
    void Show();                                         //Прототип функции отображения элементов списка
    int Count();                                                  //Прототип функции возвращающей число элементов в списке
    void Del(Book *pb);
};

/*void Add(Book *pb);
void Count();
void Del(Book *pb);
void Show();*/

#endif // LIBRARY_H
