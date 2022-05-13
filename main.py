import ctypes

lib_book = ctypes.CDLL('./test_library.dll')

#create_pbook = lib_book.create_pbook
lib_book.create_library.argtypes = []
lib_book.create_library.restype = ctypes.c_void_p

lib_book.create_pbook.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_int, ctypes.c_int, ctypes.c_int,
                                  ctypes.c_int]
lib_book.create_pbook.restype = ctypes.c_void_p
lib_book.create_ebook.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_int, ctypes.c_int, ctypes.c_int]
lib_book.create_ebook.restype = ctypes.c_void_p

lib_book.add_book.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
lib_book.add_book.restype = ctypes.c_void_p

lib_book.show_library.argtypes = [ctypes.c_void_p]
lib_book.show_library.restype = ctypes.c_void_p

lib_book.count_size.argtypes = [ctypes.c_void_p]
lib_book.count_size.restype = ctypes.c_void_p

lib_book.delete_book.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_void_p]
lib_book.delete_book.restype = ctypes.c_int

lib_book.name.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_int]
lib_book.name.restype = ctypes.c_void_p
lib_book.author.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_int]
lib_book.author.restype = ctypes.c_void_p

operation = '0'
lp = lib_book.create_library()

def add_book():
    flag = 1
    get_type = input("Выберите тип книги -- бумажная (1) или электронная (2): ")
    while flag == 1:
        name = input("Введите имя книги: ")
        name = ctypes.c_char_p(name.encode('utf-8'))
        author = input("Введите имя автора книги: ")
        author = ctypes.c_char_p(author.encode('utf-8'))
        date = input("Введите дату прочтения положительным числом: ")
        while int(date) <= 0:
            print("Неположительное число! Такая дата не может быть записана.")
            date = input("Введите дату прочтения положительным числом: ")
        if get_type == '1':
            pages = input("Введите кол-во страниц в книге: ")
            while int(pages) <= 0:
                print("Неположительное число! Такое число не может быть записано.")
                pages = input("Введите кол-во страниц в книге: ")
            mark = input("Оцените книгу по шкале от 1 до 10: ")
            state = input("Каково состояние книги? Оцените от 1 до 10: ")
            while int(state) <= 0 or int(state) > 10:
                print("Неверное число! Такое число не может быть записано.")
                state = input("Каково состояние книги? Оцените от 1 до 10: ")
            flag = 0
        elif get_type == '2':
            volume = input("Введите объем книги: ")
            while int(volume) <= 0:
                print("Неположительное число! Такое число не может быть записано.")
                volume = input("Введите объем книги: ")
            mark = input("Оцените книгу по шкале от 1 до 100: ")
            flag = 0
        else:
            print("Ошибка! Попробуйте ввести формат книги еще раз")
    print("Олично! Ваши данные считаны")
    print("Добавляю книгу в библиотеку...")
    if get_type == '1':
        p1 = lib_book.create_pbook(name, author, int(date), int(pages), int(mark), int(state))
        lib_book.add_book(p1, lp)
    elif get_type == '2':
        e1 = lib_book.create_ebook(name, author, int(date), int(volume), int(mark))
        lib_book.add_book(e1, lp)
    print("Книга " + name.value.decode('utf-8') + " добавлена успешно!")


def del_book():
    name = input("Введите имя книги: ")
    name = ctypes.c_char_p(name.encode('utf-8'))
    author = input("Введите имя автора книги: ")
    author = ctypes.c_char_p(author.encode('utf-8'))
    print("Удаляю книгу из библиотеки...")
    f = lib_book.delete_book(name, author, lp)
    if f == 0:
        print("Книга " + name.value.decode('utf-8') + " успешно удалена!")
    if f == -100:
        print("Такой книги нет в библиотеке!")

def show_lib():
    lib_book.show_library(lp)

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


#пользователю нужно ввести поля книги и но померам операций выбрать нужную, что с книгой сделать
#проверить, если пользователь ввел бред, например, книгу с -5 страницами

