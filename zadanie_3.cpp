// zadanie_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>
#include <fstream>
#include <locale.h>
#include "Student.h"
#include "sort.h"
#include "MyList.h"

using namespace std;

//template <class T>
//void printArr(T* a, int n) {
//    for (int i = 0; i < n; i++)
//        cout << a[i] << " ";
//}
//
int main() {
    setlocale(LC_ALL, ".UTF8");
    //
    //    int arr[8] = { 42, 55, 12, 44, 94, 18, 6, 67 };
    //
    //    Student students[10];
    //
    ifstream in("text.txt");
    Student arr[10];
    int i = 0;
    int n;
    Student help;
    while (in >> help) {
        arr[i] = help;
        i++;
    }
    n = i;
    //    for (int i = 0; i < 10; i++) {
    //        in >> students[i];
    //    }
    //    /* qsort(students, 10, sizeof(Student), Student::compStudName);
    //     for (Student s : students)
    //         cout << s << "\n";*/
    //         //boobleSort(students, 10);
    //         //insert(students, 10);
    //         //qsort(students, 0, 9);
    //         //select(students, 10);
    //         //shell(students, 10);
    //         //cout << "\n after sort\n";
    MyList<Student> list;

    if (list.isEmpty()) {
        cout << "Ne pusto" << "\n\n";
    }
    else {
        cout << "Pusto" << "\n\n";
    }

    for (Student s : arr)
        list.addEnd(s);
    cout << list << "\n";

    for (Student s : arr)
        list.addBegin(s);
    cout << list << "\n";

    Student searchStudent;
    strcpy_s(searchStudent.name, "BulgakovaS.V.");
    searchStudent.group = 101;
    searchStudent.marks[0] = 5;
    searchStudent.marks[1] = 4;
    searchStudent.marks[2] = 3;
    searchStudent.marks[3] = 2;
    searchStudent.marks[4] = 5;
    cout << list;
    list.addEnd(searchStudent);
    if (list.find(searchStudent)) {
        cout << "FIND: " << searchStudent << "\n";
    }
    else {
        cout << "NOT FIND " << searchStudent << "\n";
    }

    Student delStudent;
    strcpy_s(delStudent.name, "BulgakovaS.V.");
    delStudent.group = 101;
    delStudent.marks[0] = 5;
    delStudent.marks[1] = 4;
    delStudent.marks[2] = 3;
    delStudent.marks[3] = 2;
    delStudent.marks[4] = 5;

    list.addEnd(delStudent);
    if (list.deleteNode(delStudent) == 0) {
        cout << "Deleted: " << delStudent << "\n";
    }
    else {
        cout << "NOT Deleted " << delStudent << "\n";
    }


    MyList<Student> sortedList;
    for (int j = 0; j < i; j++) {
        sortedList.addSort(arr[j]);
    }
    cout << sortedList;

    int marks[] = { 5,5,5,5,5 };
    Student newStudent("Ivanov", 101, marks);
    cout << newStudent << "\n\n";
    sortedList.addSort(newStudent);
    cout << sortedList << "\n";

    return 0;
}


    ////пишем двоичный файл
    //ofstream of("students.bin",ios::binary);
    //of.write((char*)students, 50 * sizeof(Student));
    //of.close();

    //fstream in2 = fstream("students.bin", ios_base::binary | ios_base::ate | ios_base::in | ios_base::out);
    //in2.seekg(sizeof(Student) * 4, ios_base::beg);
    //Student studens;
    //in2.read((char*)&students, sizeof(Student));
    //cout << students;

    //// читаем двоичный файл
    //ifstream in1 = ifstream("students.bin");
    ////длина файла
    //in1.seekg(0, ios::end);
    //// устанавливает указатель файла в конец файла
    //int dl_fila = in1.tellg(); // Возвращает сколько байт до указателя так получается длина файла
    //in1.seekg(0, ios::beg);
    ////кол-во записей
    //int nZ= dl_fila / sizeof(Student);
    //Student* ar = new Student[nZ];

    //in1.read((char*)ar, nZ * sizeof(Student));
    //for (int f = 0; f < nZ; f++) {
    //    cout << ar[f] << "\n";
    //}

      




//    Student students[] = { s1, s2, s3 };
//    int count = 3;
//
//    bool found = false;
//
//    cout << "Student with mark '2':\n";
//    for (int i = 0; i < count; i++)
//    {
//        if (students[i].markTwo())
//        {
//            students[i].print();
//            found = true;
//        }
//    }
//
//    if (!found)
//    {
//        cout << "No student with mark '2' found.\n";
//    }
//    return 0;
//}

//    PRACTIKA
//const int m = 10;
//
//// создание хеш-таблицы
//void create_hashTable(int hesh[m][2], Student* arr, int n)
//{
//    for (int i = 0; i < m; i++) {
//        hesh[i][0] = -1;
//        hesh[i][1] = -1;
//    }
//
//    for (int i = 0; i < n; i++) {
//
//        int key = arr[i].group;
//
//        int i1 = 0;
//        int j;
//
//        while (1) {
//
//            j = (key + i1 * i1) % m;
//
//            if (hesh[j][1] == -1)
//                break;
//
//            i1++;
//        }
//
//        hesh[j][0] = key;
//        hesh[j][1] = i;
//    }
//}
//
//// поиск
//int search(int key, int hesh[m][2])
//{
//    int i1 = 0;
//    int j;
//
//    while (1) {
//
//        j = (key + i1 * i1) % m;
//
//        if (hesh[j][0] == key)
//            break;
//
//        i1++;
//    }
//
//    return hesh[j][1];
//}
//
//int main()
//{
//    setlocale(LC_ALL, ".UTF8");
//    const int n = 10;
//
//    Student arr[n];
//
//    // чтение из текстового файла
//    ifstream fin("text.txt");
//    if (!fin) {
//        cout << "FAILED\n";
//        return 1;
//    }
//
//    for (int i = 0; i < n; i++) {
//        fin >> arr[i];
//    }
//
//    fin.close();
//
//    // запись в бинарный файл
//    ofstream fout("students.bin", ios::binary);
//
//    for (int i = 0; i < n; i++) {
//        fout.write((char*)&arr[i], sizeof(Student));
//    }
//
//    fout.close();
//
//    // создание хеш-таблицы
//    int hesh[m][2];
//
//    create_hashTable(hesh, arr, n);
//
//    cout << "HASH TABLE\n";
//
//    for (int i = 0; i < m; i++) {
//        cout << hesh[i][0]
//            << " | "
//            << hesh[i][1]
//            << endl;
//    }
//
//    // поиск по группе
//    int key = 101;
//
//    // чтение одной записи из бинарного файла
//    ifstream fbin("students.bin", ios::binary);
//
//    Student temp;
//
//    for (int i = 0; i < m; i++) {
//        if (hesh[i][0] == key) {
//            int n_record = hesh[i][1];
//            fbin.seekg(n_record * sizeof(Student), ios::beg);
//
//            fbin.read((char*)&temp, sizeof(Student));
//            cout << temp << endl;
//        }
//    }
//    fbin.close();
//
//    return 0;
//}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
