#include <fstream>
#include <iostream>
#include <sstream>

struct Student
{
    std::string name;
    std::string surName;
    int course;
    std::string group;
    double marks[5];
};
bool CheckInputFile(std::ifstream&);
bool CheckOutputFile(std::ofstream&);
void FillArrayFile(std::ifstream&, double*, int64_t);
void OutputArray(std::ostream&, double*, int64_t);
int CompareDown(const void*, const void*);
void QSortArrayDown(double*, int64_t);
double AllocationFractional(double);
void BubbleSort(int64_t, double*, int32_t);
void InsertionSort(int64_t, double*, int32_t);
void SelectionSort(int64_t, double*, int32_t);
void Merge(double*, size_t, size_t, size_t, int32_t);
void MergeSort(double*, size_t, size_t, int32_t);
void QuickSort(double*, size_t, size_t, int32_t);
int64_t CountNumbersInFile(std::ifstream&);
void PrintArray(double*, int64_t);
int32_t InputSwitcher();
int32_t InputSortType();
int32_t InputInputType();
double* SortArray(double*, size_t);
size_t InputSize();
double* FillArrayConsole(double*, size_t);
size_t CountStudentInFile(std::ifstream&);
double CalculateAverageMark(Student&);
void FillStudentsFromFile(std::ifstream&, Student*, size_t);
void SelectionSortStudents(Student*, int64_t);
void PrintStudents(Student*, size_t);