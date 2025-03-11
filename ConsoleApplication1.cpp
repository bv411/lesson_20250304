#include <iostream>
#include <stdio.h>


//https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/reference/fopen-s-wfopen-s?view=msvc-170
//https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170
//https://en.cppreference.com/w/c/io/fread

/*
HW

Написать викторину
Создайте файл, в котором сохраните вопросы, варианты ответов и правильные ответы (Здесь вам помогут структуры)
Напишите программу, которой можно подать на вход разные файлы с викторинами и она сможет ее провести, подойдите к задание с огоньком.


*/

struct Point;
struct Line;



void write_point(FILE* file, const Point& p);
void write_line(FILE* file, const Line& l);
void read_point(FILE* file, Point& p);
void read_line(FILE* file, Line& l);
void print_error(errno_t err);
FILE* open_file(const char* path, const char* mod);
void print_line(const Line& l);
void print_point(const Point& p);




struct Point {

    int x = 0;
    int y = 0;
};

struct Line {

    Point p1{};
    Point p2{};
};

struct Circle {
    int r = 0;
    Point p{};
};

struct Test {
    int a = 3;
    Point* point;
};

void write_circle(FILE* file, const Circle& c) {
    fprintf(file, "%d ", c.r);
    write_point(file, c.p);
}

void write_point(FILE *file, const Point& p) {
    fprintf(file, "%d %d ", p.x, p.y);
}

void write_line(FILE* file, const Line& l) {
    write_point(file, l.p1);
    write_point(file, l.p2);
}

void read_circle(FILE* file, Circle& c) {
    fscanf_s(file, "%d", &(c.r));
    read_point(file, c.p);
}

void read_point(FILE* file, Point& p) {
    fscanf_s(file, "%d %d", &(p.x), &(p.y));
}

void read_line(FILE* file, Line& l) {
    read_point(file, l.p1);
    read_point(file, l.p2);
}

FILE* open_file(const char* path, const char* mod) {
    
    FILE* file{ nullptr };
    errno_t err{};

    err = fopen_s(&file, path, mod);
    if (err != 0) {
        print_error(err);
        return nullptr;
    }

    return file;

}

void print_line(const Line& l) {
    print_point(l.p1);
    std::cout << " - ";
    print_point(l.p2);
    std::cout << "\n";
}
void print_point(const Point& p) {
    std::cout << " ( " << p.x << ", " << p.y << " ) ";
}


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
        std::cout << "Ошибка неизвестна!  " << err << " \n";
        break;
    }
}


int main()
{
    setlocale(LC_ALL, "Ru");
    //const char* path = "C:\\temp\\points.txt";

    //Line l{ {10,30}, {150,450} };

    //print_line(l);

    //FILE* file = open_file(path, "w");

    //if (file != nullptr)  { // if (file)

    //    write_line(file, l);
    //    fclose(file);
    //}

    //Line l;

    //print_line(l);

    //FILE* file = open_file(path, "r");

    //if (file != nullptr) { // if (file)

    //    read_line(file, l);
    //    fclose(file);
    //
    //}

    //print_line(l);

    //Circle c{ 10 , {45,78} };

    //FILE* file = open_file(path, "w");

    //if (file != nullptr) { // if (file)

    //    write_circle(file, c);
    //    fclose(file);
    //}

    /*const int SIZE = 5;

    Point p[SIZE]{
    {10,20},
    {30,70},
    {40,80},
    {50,90},
    {60,100},
    };

    FILE* file = open_file(path, "w");
    if (file) {
        fprintf(file, "%d ", SIZE);
        for (int i = 0; i < SIZE; i++)
            write_point(file, p[i]);
        fclose(file);
    }*/

    /*FILE* file = open_file(path, "r");
    if (file) {

        int size{};
        fscanf_s(file, "%d", &size);

        Point* p = new Point[size];

        for (int i = 0; i < size; i++) {
            read_point(file, p[i]);
        }
        for (int i = 0; i < size; i++) {
            print_point(p[i]);
            std::cout << std::endl;
        }
        fclose(file);
        delete[] p;
    }*/

    /*const char* path = "C:\\temp\\data.txt";
    int a = 97;

    FILE* file = open_file(path, "wb");

    if (file) {
        fwrite(&a, sizeof(a), 1, file);
        fclose(file);
    }

    file = open_file(path, "rb");

    if (file) {
        int b{};
        fread(&b, sizeof(b), 1, file);
        fclose(file);

        std::cout << b << std::endl;

    }*/

    /*const int SIZE = 5;
    const char* path = "C:\\temp\\data_array.txt";
    int a[SIZE]{97,98,99,100,101};

    FILE* file = open_file(path, "wb");

    if (file) {
        for (int i = 0 ; i < SIZE; i++)
            fwrite(&a[i], sizeof(a[0]), 1, file);
        fclose(file);
    }*/

    /*const int SIZE = 5;
    const char* path = "C:\\temp\\data_array.txt";
    int a[SIZE]{};

    FILE* file = open_file(path, "rb");

    if (file) {
        for (int i = 0; i < SIZE; i++)
            fread(&a[i], sizeof(a[0]), 1, file);

        fclose(file);
    }

    for (int i = 0; i < SIZE; i++)
        std::cout << a[i] << " " << std::endl;*/

        /*const int SIZE = 5;
        const char* path = "C:\\temp\\data_array2.txt";
        int a[SIZE]{97,98,99,100,101};

        FILE* file = open_file(path, "wb");

        if (file) {
           fwrite(a, sizeof(a[0]), SIZE, file);
           fclose(file);
        }*/

        /*const int SIZE = 5;
        const char* path = "C:\\temp\\data_array2.txt";
        int a[SIZE]{};

        FILE* file = open_file(path, "rb");

        if (file) {
            fread(a, sizeof(a[0]), SIZE, file);
            fclose(file);
        }

        for (int i = 0; i < SIZE; i++)
            std::cout << a[i] << " " << std::endl;*/


            /*const char* path = "C:\\temp\\data_lines.txt";

            Line l = { {5,5}, {100,200} };

            FILE* file = open_file(path, "wb");

            if (file) {
                fwrite(&l, sizeof(Line), 1, file);
                fclose(file);
            }*/

            /*const char* path = "C:\\temp\\data_lines.txt";

            Line l = {};

            print_line(l);

            FILE* file = open_file(path, "rb");

            if (file) {
                fread(&l, sizeof(Line), 1, file);
                fclose(file);
            }
            print_line(l);*/

    /*const int SIZE = 5;
    const char* path = "C:\\temp\\data_lines2.txt";

    Line* l = new Line[SIZE] {
        {{5,5}, {100,200}},
        {{15,5}, {4100,200} },
        {{25,5}, {3100,200}},
        {{35,5}, {2100,200} },
        {{45,5}, {1100,200}},
    };

    FILE* file = open_file(path, "wb");

    if (file) {
        fwrite(l, sizeof(Line), SIZE, file);
        fclose(file);
    }

    Line l2[SIZE];

    file = open_file(path, "rb");

    if (file) {
        fread(l2, sizeof(Line), SIZE, file);
        fclose(file);
    }

    for (int i = 0; i < SIZE; i++)
        print_line(l2[i]);*/

    /*
    Ошибочное сохранение структуры Test
    const char* path = "C:\\temp\\data_test.txt";

    Point p{ 10,10 };
    Test t;
    t.a = 1000;
    t.point = &p;

    FILE* file = open_file(path, "wb");

    if (file) {
        fwrite(&t, sizeof(Test), 1, file);
        fclose(file);
    }*/

    /*const char* path = "C:\\temp\\data_test.txt";
    Ошибочное чтение структуры Test
    
    Test t;
    FILE* file = open_file(path, "rb");

    if (file) {
        fread(&t, sizeof(Test), 1, file);
        fclose(file);
    }

    std::cout << "t.a = " << t.a << std::endl;
    print_point(*(t.point));
    std::cout << std::endl;*/


    
        
    /*const char* path = "C:\\temp\\data_test.txt";

    Point p{ 10,10 };
    Test t;
    t.a = 1000;
    t.point = &p;

    FILE* file = open_file(path, "wb");

    if (file) {
       fwrite(&t.a, sizeof(t.a), 1, file);
       fwrite(t.point, sizeof(Point), 1, file);
       fclose(file);
    }*/

    const char* path = "C:\\temp\\data_test.txt";

    Point p;
    Test t;    
    t.point = &p;

    FILE* file = open_file(path, "rb");

    if (file) {
        fread(&t.a, sizeof(t.a), 1, file);
        fread(t.point, sizeof(Point), 1, file);
        fclose(file);
    }
    std::cout << "t.a = " << t.a << std::endl;
    print_point(*(t.point));
    std::cout << std::endl;
}

