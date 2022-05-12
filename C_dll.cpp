#include<iostream>
#include <cstring>
#include "library.h"

extern "C"{
    Book* create_pbook(char* name, char* author, int date, int pages, int mark, int state){
        return new PBook(name, author, date, pages, mark, state);
    }

    Book* create_ebook(char* name, char* author, int volume, int date, int mark){
        return new Ebook(name, author, volume, date, mark);
    }

    Library* create_library() {
        return new Library(nullptr, nullptr, 0);
    }

    void name(Book* pb, char* name, int max_name_len){
        strncpy(name, pb->getname().c_str(), max_name_len);
    }

    void author(Book* pb, char* author, int max_name_len){
        strncpy(author, pb->getauthor().c_str(), max_name_len);
    }

    void add_book(Book *pb, Library *pl){
        return pl->Add(pb);
    }

    int count_size(Library* pl){
        return pl->Count();
    }

    void show_library(Library *pl) {
        pl->Show();
    };

    void delete_book(char* name, char* author, Library* pl) {
        pl->Del(name, author);
    };

    // нужно уметь уничтожать созданные объекты,
    // так как Python их автоматически не убирает
    void dispose_book(Book *pb) {
        delete pb;
    }

    void dispose_library(Library *pl) {
        delete pl;
    }

}

