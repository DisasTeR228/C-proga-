
#include "function.h"

int CompareDown(const void* firstElement, const void* secondElement)
{
    double first = AllocationFractional(*(double*)firstElement);
    double second = AllocationFractional(*(double*)secondElement);

    int64_t firstCount = std::to_string(first).size();
    int64_t secondCount = std::to_string(second).size();

    return secondCount - firstCount;
}


void QSortArrayDown(double* arr, int64_t size)
{
    std::qsort(arr, size, sizeof(double), CompareDown);
}

void BubbleSort(int64_t size, double* arr, int32_t switcher)
{
    bool swapped{};
    for (int64_t i = 0; i < size; ++i)
    {
        swapped = false;
        for (int64_t j = 0; j < size - i - 1; ++j)
        {
            bool shouldSwaping = switcher == 1 ? (arr[j] > arr[j + 1]) : (arr[j] < arr[j + 1]);
            if (shouldSwaping)
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

void InsertionSort(int64_t size, double* arr, int32_t switcher)
{
    for (size_t i = 1; i < size; ++i)
    {
        double temp = arr[i];
        int64_t j = i - 1;

        while (j >= 0)
        {
            bool shouldSwaping = switcher == 1 ? arr[j] > temp : arr[j] < temp;

            if (!shouldSwaping)
            {
                break;
            }

            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = temp;
    }
}

void SelectionSort(int64_t size, double* arr, int32_t switcher)
{
    for (size_t i = 0; i < size - 1; ++i)
    {
        size_t index = i;

        for (size_t j = i + 1; j < size; ++j)
        {
            bool shouldSwaping = switcher == 1 ? arr[j] < arr[index] : arr[j] > arr[index];

            if (shouldSwaping)
            {
                index = j;
            }
        }

        std::swap(arr[i], arr[index]);
    }
}

void Merge(double* arr, size_t left, size_t mid, size_t right, int32_t switcher)
{
    size_t leftSize = mid - left + 1;
    size_t rightSize = right - mid;

    double* leftArr = new double[leftSize];
    double* rightArr = new double[rightSize];

    for (size_t i = 0; i < leftSize; i++)
    {
        leftArr[i] = arr[left + i];
    }

    for (size_t i = 0; i < rightSize; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }

    size_t i = 0;
    size_t j = 0;
    size_t k = left;

    while (i < leftSize && j < rightSize)
    {
        bool shouldSwaping = switcher == 1 ? leftArr[i] <= rightArr[j] : leftArr[i] >= rightArr[j];

        if (shouldSwaping)
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < leftSize)
    {
        arr[k++] = leftArr[i++];
    }

    while (j < rightSize)
    {
        arr[k++] = rightArr[j++];
    }

    delete[] leftArr;
    delete[] rightArr;
}

void MergeSort(double* arr, size_t left, size_t right, int32_t switcher)
{
    if (left < right)
    {
        size_t mid = left + (right - left) / 2;

        MergeSort(arr, left, mid, switcher);
        MergeSort(arr, mid + 1, right, switcher);

        Merge(arr, left, mid, right, switcher);
    }
}


void QuickSort(double* arr, size_t left, size_t right, int32_t switcher)
{
    if (left >= right)
    {
        return;
    }

    double pivot = arr[right];
    size_t i = left;
    size_t j = right;
    bool shouldSwapping{};

    while (i < j)
    {
        shouldSwapping = switcher == 1 ? arr[i] < pivot : arr[i] > pivot;
        while (shouldSwapping)
        {
            i++;
            shouldSwapping = switcher == 1 ? arr[i] < pivot : arr[i] > pivot;
        }

        shouldSwapping = switcher == 1 ? arr[j] > pivot : arr[j] < pivot;
        while (shouldSwapping)
        {
            j--;
            shouldSwapping = switcher == 1 ? arr[j] > pivot : arr[j] < pivot;
        }

        if (i <= j)
        {
            std::swap(arr[i++], arr[j--]);
        }
    }

    QuickSort(arr, left, j, switcher);
    QuickSort(arr, i, right, switcher);
}

void SelectionSortStudents(Student* students, int64_t size)
{
    for (size_t i = 0; i < size - 1; ++i)
    {
        size_t index = i;

        for (size_t j = i + 1; j < size; ++j)
        {
            bool shouldSwapping = CalculateAverageMark(students[j]) > CalculateAverageMark(students[index]);

            if (shouldSwapping)
            {
                index = j;
            }
        }

        std::swap(students[i], students[index]);
    }
}
