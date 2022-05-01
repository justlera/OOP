#include<iostream>
#include <stdlib.h>
#include <vector>
#include <limits>
#include <list>
#include "library.cpp"

//создать объект класса library, добавить туда 2-3 книги разных типов
//удалить одну из них, попытаться удалить отсутствующую в библиотеке книгу
//вывести то, что осталось

void testlibrary(){
    Library library;

    Book: PBook p1("Harry Potter", "J.K. Rowling", 13, 300, 8, 5);
    PBook p2("Twilight", "Stephenie Meyer", 20, 500, 10, 3);

    Ebook e1("Gospel", "Luca", 23, 100, 99);
    Ebook e2("Dune", "Frank Herbert", 1000, 800, 70);

    assert(library.Add(&p1));
    assert(library.Add(&p2));
    assert(library.Add(&e1));
    assert(library.Add(&e2));

    assert(library.Del(&e1));
    assert(library.Del(&e3));

    int x = library.Count();
    assert(library.Show(x));
}

int main() {
    testlibrary();
    return 0;
}
