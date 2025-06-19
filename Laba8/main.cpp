#include "function.h"

int main()
{
    try
    {
        int32_t inputType{};

        std::cout << "Откуда данные? \n 1. Из файла на консоль \n 2. С консоли в файл \n 3. Из файла в файл \n 4. Работа с структурой студент \n";
        inputType = InputInputType();
        switch (inputType)
        {
        case 1:
        {
            std::ifstream fin("in.txt");
            CheckInputFile(fin);

            size_t size = CountNumbersInFile(fin);

            double* arr = new double[size];

            FillArrayFile(fin, arr, size);
            SortArray(arr, size);
            PrintArray(arr, size);
            delete[] arr;
            break;
        }
        case 2:
        {
            std::cout << "Введите размер массива: ";
            size_t size = InputSize();
            double* arr = new double[size];
            std::cout << "Введите " << size << " элементов: \n";

            arr = FillArrayConsole(arr, size);
            SortArray(arr, size);

            std::ofstream fout("out.txt");
            CheckOutputFile(fout);
            OutputArray(fout, arr, size);

            delete[] arr;
            break;
        }
        case 3:
        {
            std::ifstream fin("in.txt");
            CheckInputFile(fin);

            size_t size = CountNumbersInFile(fin);

            double* arr = new double[size];

            FillArrayFile(fin, arr, size);
            SortArray(arr, size);

            std::ofstream fout("out.txt");
            CheckOutputFile(fout);
            OutputArray(fout, arr, size);

            delete[] arr;
            break;
        }
        case 4:
        {
            std::ifstream fin("student.txt");
            CheckInputFile(fin);

            size_t size = CountStudentInFile(fin);

            Student* students = new Student[size];

            FillStudentsFromFile(fin, students, size);

            SelectionSortStudents(students, size);
            PrintStudents(students, size);

            delete[] students;
            break;
        }
        default:
        {
            throw std::runtime_error("Неверный вид ввода/вывода.\n");
            break;
        }
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << '\n';
    }

    return 0;
}
