#include <iostream>
#include <stdio.h>


//https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/reference/fopen-s-wfopen-s?view=msvc-170

//https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170

void print_error(errno_t err) {
    std::cout << "The file cannot be opened " << "\n";
    
    switch (err)
    {
    case 2:
        std::cout << "Отсутствует такой файл или каталог. " << "\n";
        break;
    case 13:
        std::cout << "в разрешении отказано.  " << "\n";
        break;
    default:
        std::cout << "Ошибка неизвестна!  " << "\n";
        break;
    }
}

void write_file(const char* path) {

    FILE* in_file{ nullptr };
    errno_t err{};

    err = fopen_s(&in_file, path, "w");
    if (err != 0) {
        print_error(err);
        return;
    }

    std::cout << "The file be opened \n";

    for (int i = 0; i < 5; i++) {
        char str[255]{};
        std::cout << "Enter string :";
        std::cin.getline(str, 255);
        fputs(str, in_file);
        fputs("\n", in_file);
    }

    fclose(in_file);
}

void write_file2(const char* path) {

    FILE* in_file{ nullptr };
    errno_t err{};

    err = fopen_s(&in_file, path, "w");
    if (err != 0) {
        print_error(err);
        return;
    }

    std::cout << "The file be opened \n";

        char str[255]{};
        std::cout << "Enter name :";
        std::cin.getline(str, 255);
        char str2[255]{};
        std::cout << "Enter surname :";
        std::cin.getline(str2, 255);
        int age;
        std::cout << "Enter age :";
        std::cin >> age;

        fprintf_s(in_file, "%s %s %d", str, str2,  age);
                
    
    fclose(in_file);
}

void read_file2(const char* path) {

    FILE* in_file{ nullptr };
    errno_t err{};

    err = fopen_s(&in_file, path, "r");
    if (err != 0) {
        print_error(err);
        return;
    }

    std::cout << "The file be opened \n";

    while (!feof(in_file)) {
        char str[255]{};
        char str2[255]{};
        int age;

        fscanf_s(in_file, "%s %s %d", str, 255, str2, 255, &age);
        //std::cout << "Name = " << str << std::endl;
        //std::cout << "Surname = " << str2 << std::endl;
        //std::cout << "Age = " << age << std::endl;

        printf("My name is %s, my surname is %s, my age = %d \n", str, str2, age);

    }
    fclose(in_file);
}

void read_file(const char* path) {
    FILE* in_file{ nullptr };
    errno_t err{};

    err = fopen_s(&in_file, path, "r+");
    if (err != 0) {
        print_error(err);
        return;
    }

    std::cout << "The file be opened \n";
    
    while (! feof(in_file)) {
        char str[255]{};        
        fgets(str, 255, in_file);
        std::cout << str;
    }
    fclose(in_file);
}


int main()
{
    setlocale(LC_ALL,"Ru");
    const char* path = "C:\\temp\\test.txt";

    //write_file(path);
    //read_file(path); 
    // 
    //write_file2(path);     
    read_file2(path);
}

/*
Задание 1. Дан текстовый файл. Подсчитать количество
слов, начинающихся с символа, который задаёт пользо-
ватель.

Задание 2. Дан текстовый файл. Необходимо создать
новый файл, в который переписать из исходного файла
все слова, состоящие не менее чем из семи букв.

*/