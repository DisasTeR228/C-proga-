
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "function.h"

bool CheckInputFile(std::ifstream& fin)
{
    if (!fin.good())
    {
        throw std::runtime_error("���� �� ����������. \n");
    }

    if (!fin)
    {
        throw std::runtime_error("������ �������� �����. \n");
    }

    if (fin.peek() == EOF)
    {
        throw std::runtime_error("���� ����. \n");
    }

    return true;
}

bool CheckOutputFile(std::ofstream& fout)
{
    if (!fout.good())
    {
        throw std::runtime_error("���� �� ����������. \n");
    }

    if (!fout)
    {
        throw std::runtime_error("������ ��������� �����. \n");
    }

    return true;
}

void FillArrayFile(std::ifstream& fin, double* arr, int64_t size)
{
    fin.clear();
    fin.seekg(0);
    for (size_t i = 0; i < size; ++i)
    {
        fin >> arr[i];
    }
}

void OutputArray(std::ostream& fout, double* arr, int64_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        fout << arr[i] << ' ';
    }

    fout << '\n';
}

double AllocationFractional(double number)
{
    number = std::abs(number);
    return number - static_cast<int>(number);
}

int64_t CountNumbersInFile(std::ifstream& fin)
{
    int64_t count{};
    double temp{};

    while (fin >> temp)
    {
        count++;
    }

    if (count == 0)
    {
        throw std::runtime_error("� ����� ����������� �������� ������.");
    }

    fin.clear();
    fin.seekg(0);

    return count;
}

void PrintArray(double* arr, int64_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }

}

int32_t InputSwitcher()
{
    int32_t switcher{};

    std::cin >> switcher;
    if (std::cin.fail() || (switcher != 0 && switcher != 1))
    {
        throw std::invalid_argument("�������� ��������. ��������� ����� �� 0 �� 1.");
    }

    return switcher;
}

int32_t InputSortType()
{
    int32_t sortType{};

    std::cin >> sortType;

    if (std::cin.fail() || sortType < 1 || sortType > 6)
    {
        throw std::invalid_argument("�������� ��������. ��������� ����� �� 1 �� 6.");
    }

    return sortType;
}

int32_t InputInputType()
{
    int32_t inputType{};

    std::cin >> inputType;

    if (std::cin.fail() || inputType < 1 || inputType > 4)
    {
        throw std::invalid_argument("�������� ��������. ��������� ����� �� 1 �� 4.");
    }

    return inputType;
}

size_t InputSize()
{
    int32_t size{};

    std::cin >> size;

    if (std::cin.fail() || size < 0)
    {
        throw std::invalid_argument("�������� ��������. ��������� ����� > 0.");
    }

    return size;
}

double* FillArrayConsole(double* arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cin >> arr[i];

        if (std::cin.fail())
        {
            throw std::invalid_argument("�������� ��������. ��������� �����.");
        }
    }

    return arr;
}

double* SortArray(double* arr, size_t size)
{
    int32_t sortType{};
    int32_t switcher{};

    std::cout << "����� ��� ����������? \n 1. QuickSort \n 2. InsertionSort \n 3. SelectionSort \n 4. MergeSort \n 5. BubbleSort \n 6. qsort(�� �������� ���� � ������� �����). \n";
    sortType = InputSortType();

    if (sortType != 6)
    {
        std::cout << "��� �����������? \n 0 - �� �������� \n 1 - �� �����������. \n";
        switcher = InputSwitcher();
    }

    switch (sortType)
    {
    case 1:
    {
        QuickSort(arr, 0, size - 1, switcher);
        break;
    }
    case 2:
    {
        InsertionSort(size, arr, switcher);
        break;
    }
    case 3:
    {
        SelectionSort(size, arr, switcher);
        break;
    }
    case 4:
    {
        MergeSort(arr, 0, size - 1, switcher);
        break;
    }
    case 5:
    {
        BubbleSort(size, arr, switcher);
        break;
    }
    case 6:
    {
        QSortArrayDown(arr, size);
        break;
    }
    default:
    {
        throw std::runtime_error("�������� ��� ����������.\n");
        break;
    }
    }

    return arr;
}

double CalculateAverageMark(Student& student)
{
    double sum = 0;
    for (size_t i = 0; i < 5; ++i)
    {
        sum += student.marks[i];
    }
    return sum / 5.0;
}

size_t CountStudentInFile(std::ifstream& fin)
{
    int64_t count{};
    std::string temp;

    while (std::getline(fin, temp))
    {
        count++;
    }

    if (count == 0)
    {
        throw std::runtime_error("���� ����.");
    }

    fin.clear();
    fin.seekg(0);

    return count;
}



void FillStudentsFromFile(std::ifstream& fin, Student* students, size_t size)
{
    std::string line;

    for (size_t i = 0; i < size; ++i)
    {
        if (!std::getline(fin, line))
        {
            throw std::runtime_error("������������ ����� � �����.");
        }

        std::istringstream ss(line);
        if (!(ss >> students[i].name >> students[i].surName >> students[i].course >> students[i].group))
        {
            throw std::runtime_error("������������ ������ ������ ��������.");
        }

        for (size_t j = 0; j < 5; ++j)
        {
            if (!(ss >> students[i].marks[j]))
            {
                throw std::runtime_error("������������ ������.");
            }
        }
    }

    fin.close();
}


void PrintStudents(Student* students, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << students[i].name << " " << students[i].surName << " ����: " << students[i].course << " ������: " << students[i].group << " ������� ����: " << CalculateAverageMark(students[i]) << "\n";
    }
}
