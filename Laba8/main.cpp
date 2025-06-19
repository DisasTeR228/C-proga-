#include "function.h"

int main()
{
    try
    {
        int32_t inputType{};

        std::cout << "������ ������? \n 1. �� ����� �� ������� \n 2. � ������� � ���� \n 3. �� ����� � ���� \n 4. ������ � ���������� ������� \n";
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
            std::cout << "������� ������ �������: ";
            size_t size = InputSize();
            double* arr = new double[size];
            std::cout << "������� " << size << " ���������: \n";

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
            throw std::runtime_error("�������� ��� �����/������.\n");
            break;
        }
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "������: " << e.what() << '\n';
    }

    return 0;
}
