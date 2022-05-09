import ctypes

lib_book = ctypes.CDLL('.\\libshared.dll')

# create_pbook = lib_book.create_pbook
lib_book.create_pbook.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_int, ctypes.c_int, ctypes.c_int,
                                  ctypes.c_int]
lib_book.create_pbook.restype = ctypes.c_void_p
lib_book.name.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_int,]
lib_book.name.restype = ctypes.c_void_p

p1 = lib_book.create_pbook("Harry Potter", "J.K. Rowling", 13, 300, 8, 5)
name1 = lib_book.name(p1)
print(name1)
lib_book.dispose_pbook(p1)
"""
operation = "0"


def add_book():
    flag = 1
    get_type = input("Выберите тип книги -- бумажная (p, 1) или электронная (e, 2): ")
    while flag == 1:
        name = input("Введите имя книги: ")
        author = input("Введите имя автора книги: ")
        date = input("Введите дату прочтения: ")
        if get_type == 'p' or get_type == '1':
            pages = input("Введите кол-во страниц в книге: ")
            mark = input("Оцените книгу по шкале от 1 до 10: ")
            state = input("Каково состояние книги? Оцените от 1 до 10: ")
            flag = 0
        elif get_type == 'e' or get_type == '2':
            volume = input("Введите объем книги: ")
            mark = input("Оцените книгу по шкале от 1 до 100: ")
            flag = 0
        else:
            print("Ошибка! Попробуйте ввести формат книги еще раз")
    print("Олично! Ваши данные считаны")
    print("Добавляю книгу в библиотеку...")
    # добавление
    pbook = lib_book.create_pbook(name, author, date, pages, mark, state)
    lib_book.add_book(p1, l1)
    print("Книга " + name + " добавлена успешно!")


def del_book():
    name = input("Введите имя книги: ")
    author = input("Введите имя автора книги: ")
    print("Удаляю книгу из библиотеки...")
    #удаление
    print("Книга " + name + " успешно удалена!")

def show_lib():
    #добавление
    pass

while operation != "4":
    operation = input("Что вы хотите сделать? Выберите одну опперацию: "
                    "\n1. Добавить книгу\n2. Удалить книгу\n3. Показать библиотеку\n4. Выйти из программы\n")
    if operation == "1":
        add_book()
    elif operation == "2":
        del_book()
    elif operation == "3":
        show_lib()
    elif operation == "4":
        print("Всего доброго!")
        break
    else:
        print("ОШИБКА. Такой комманды не существует. Попробуйте еще раз.")


"""

#пользователю нужно ввести поля книги и но померам операций выбрать нужную, что с книгой сделать
#проверить, если пользователь ввел бред, например, книгу с -5 страницами
#интерфейс может быть консоль графический итд