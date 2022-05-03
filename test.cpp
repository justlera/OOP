#include<iostream>
#include <stdlib.h>
#include <vector>
#include <limits>
#include <list>
#include <cassert>
#include "library.h"

//создать объект класса library, добавить туда 2-3 книги разных типов
//удалить одну из них, попытаться удалить отсутствующую в библиотеке книгу
//вывести то, что осталось

void test_library(){
    Library library;

    PBook p1("Harry Potter", "J.K. Rowling", 13, 300, 8, 5);
    PBook p2("Twilight", "Stephenie Meyer", 20, 500, 10, 3);
    PBook p3("Sherlock Holmes", "A.C. Doyle", 15, 555, 10, 10);

    Ebook e1("Gospel", "Luca", 23, 100, 99);
    Ebook e2("Dune", "Frank Herbert", 1000, 800, 70);

    /*
    assert(library.Add(&p1));
    assert(library.Add(&p2));
    assert(library.Add(&e1));
    assert(library.Add(&e2));

    assert(library.Del(&e1));
    assert(library.Del(&e3));

    int x = library.Count();
    assert(library.Show(x));
    */
    library.Add(&p1);
    library.Add(&p2);
    library.Add(&e1);
    library.Add(&e2);

    library.Del(&e2);
    library.Del(&p3);

    int x = library.Count();
    library.Show();

}

int main() {
    test_library();
    return 0;
}
