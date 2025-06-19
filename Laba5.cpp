#include <iostream>
#include <ctime>




//-----------------------------------------------------
//4 и 16 задания
//-----------------------------------------------------





void EnteringChoice(bool& method) {
	std::cout << "Input 0 if you want to fill matrix by yourself, 1 if you want fill with random: ";
	{
		std::cin >> method;
		while (std::cin.fail()) 
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Wrong type, try again: ";
			std::cin >> method;
		}
	}
}

void EnteringRowsAndCols(int32_t& rows, int32_t& cols)
{
	std::cout << "Input rows: ";
	std::cin >> rows;
	while (std::cin.fail() || rows < 2)
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Wrong type, try again: ";
		std::cin >> rows;
	}
	std::cout << "Input cols: ";
	std::cin >> cols;
	while (std::cin.fail() || cols < 2)
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Wrong type, try again: ";
		std::cin >> cols;
	}
}
		
void FillMatrixByPerson(int32_t** mtr, int32_t rows, int32_t cols) {
	std::cout << "Input " << rows * cols << " elements in matrix:\n";
	for (size_t i{}; i < rows; ++i) {
		for (size_t j{}; j < cols; ++j) {
			std::cin >> mtr[i][j];
			while (std::cin.fail()) 
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Wrong type, try again: ";
				std::cin >> mtr[i][j];
			}
		}
	}
}

			

void FillMatrixWithRandom(int32_t** mtr, int32_t rows, int32_t cols) {
	int32_t leftBorder{};
	int32_t rightBorder{};
	std::cout << "Input borders of interval ";
	std::cin >> leftBorder >> rightBorder;
	if (leftBorder == rightBorder) {
		throw std::invalid_argument("Invalid argument");
	}
	if (leftBorder > rightBorder) {
		std::swap(leftBorder, rightBorder);
	}
	srand(time(0));
	for (size_t i{}; i < rows; ++i)
	{
		for (size_t j{}; j < cols; ++j)
		{
			mtr[i][j] = leftBorder + rand() % (rightBorder - leftBorder + 1);
		}
	}
}


void OutputMatrix(int32_t** mtr, int32_t rows, int32_t cols)
{
	for (size_t i{}; i < rows; ++i)
	{
		for (size_t j{}; j < cols; ++j)
		{
			std::cout.width(rows / 2);
			std::cout << mtr[i][j] << ' ';
		}
		std::cout << "\n\n";
	}
}

void SearchForLocalMinima(int32_t** mtr, int32_t rows, int32_t cols)
{
	int32_t count{};
	std::cout << "rows cols:\n";
	for (size_t i{1}; i < rows - 1; ++i)
	{
		for (size_t j{1}; j < cols - 1; ++j)
		{
			if (mtr[i][j] < mtr[i + 1][j + 1] && mtr[i][j] < mtr[i + 1][j] && mtr[i][j] < mtr[i + 1][j - 1] && mtr[i][j] < mtr[i][j + 1] && mtr[i][j] < mtr[i][j - 1] && mtr[i][j] < mtr[i - 1][j + 1] && mtr[i][j] < mtr[i - 1][j] && mtr[i][j] < mtr[i - 1][j - 1])
			{
				std::cout << i+1 << ' ' << j+1 << '\n';
				++count;
			}
		}
	}
	for (size_t i{1}; i < rows - 1; ++i)
	{
		if (mtr[i][0] < mtr[i + 1][0] && mtr[i][0] < mtr[i - 1][0] && mtr[i][0] < mtr[i + 1][1] && mtr[i][0] < mtr[i][1] && mtr[i][0] < mtr[i - 1][1])
		{
			std::cout << i + 1 << " 1\n";
			++count;
		}
	}
	for (size_t i{1}; i < rows - 1; ++i)
	{
		if (mtr[i][cols - 1] < mtr[i + 1][cols - 1] && mtr[i][cols - 1] < mtr[i - 1][cols - 1] && mtr[i][cols - 1] < mtr[i + 1][cols - 2] && mtr[i][cols - 1] < mtr[i][cols - 2] && mtr[i][cols - 1] < mtr[i - 1][cols - 2])
		{
			std::cout << i + 1 << ' ' << cols << '\n';
			++count;
		}
	}
	for (size_t j{1}; j < cols - 1; ++j)
	{
		if (mtr[0][j] < mtr[0][j + 1] && mtr[0][j] < mtr[0][j - 1] && mtr[0][j] < mtr[1][j + 1] && mtr[0][j] < mtr[1][j] && mtr[0][j] < mtr[1][j - 1])
		{
			std::cout << "1 " << j + 1 << '\n';
			++count;
		}
	}
	for (size_t j{1}; j < cols - 1; ++j)
	{
		if (mtr[rows - 1][j] < mtr[rows - 1][j + 1] && mtr[rows - 1][j] < mtr[rows - 1][j - 1] && mtr[rows - 1][j] < mtr[rows - 2][j + 1] && mtr[rows - 1][j] < mtr[rows - 2][j] && mtr[rows - 1][j] < mtr[rows - 2][j - 1])
		{
			std::cout << rows << ' ' << j + 1 << '\n';
			++count;
		}
	}
	if (mtr[0][0] < mtr[1][0] && mtr[0][0] < mtr[1][1] && mtr[0][0] < mtr[0][1])
	{
		std::cout << "1 1\n";
		++count;
	}
	if (mtr[rows-1][0] < mtr[rows - 2][0] && mtr[rows - 1][0] < mtr[rows - 1][1] && mtr[rows - 1][0] < mtr[rows - 2][1])
	{
		std::cout << rows << " 1\n";
		++count;
	}
	if (mtr[rows - 1][cols - 1] < mtr[rows - 2][cols - 1] && mtr[rows - 1][cols - 1] < mtr[rows - 1][cols - 2] && mtr[rows - 1][cols - 1] < mtr[rows - 2][cols - 2])
	{
		std::cout << rows << cols <<"\n";
		++count;
	}
	if (mtr[0][cols - 1] < mtr[1][cols - 1] && mtr[0][cols - 1] < mtr[1][cols - 2] && mtr[0][cols - 1] < mtr[0][cols - 2])
	{
		std::cout << "1" << cols << "\n";
		++count;
	}
	if (count == 0)
	{
		std::cout << "No local minima";
	}
	else
	{
		std::cout << "\nNumber of local minima: " << count;
	}
}

bool SearchingForZeroInColumn(int32_t** mtr, int32_t rows, size_t j)
{
	bool zero{};
	for (size_t i{}; i < rows; ++i)
	{
		if (mtr[i][j] == 0)
		{
			zero = 1;
		}
	}
	return zero;
}

void SearchingForSumColumnElements(int32_t** mtr, int32_t rows, int32_t cols)
{
	int64_t sum{};
	bool presenceOfZeros{};
	for (size_t j{}; j < cols; ++j)
	{
		if (SearchingForZeroInColumn(mtr, rows, j))
		{
			for (size_t i{}; i < rows; ++i)
			{
				sum += mtr[i][j];
			}
			presenceOfZeros = true;
		}
	}
	if (!presenceOfZeros)
	{
		std::cout << "There are no zeros in the array";
	}
	else
	{
		std::cout << sum;
	}
}

void FindingSumOverDiagonal(int32_t** mtr, int32_t rows, int32_t cols)
{
	int64_t sum{};
	for (size_t j{1}; j < rows; ++j)
	{
		for (size_t i{}; i < j; ++i)
		{
			sum += mtr[i][j];
		}
	}
	std::cout << "The sum above the diagonal: " << sum;
}

void BubbleSortOptimized(int32_t** mtr, int32_t cols, size_t i) {
	bool swapped{};
	if ((i + 1) % 2 == 0)
	{
		for (int l{}; l < cols - 1; ++l) {
			swapped = false;
			for (int j{}; j < cols - l - 1; ++j) {
				if (mtr[i][j] > mtr[i][j + 1]) {
					std::swap(mtr[i][j], mtr[i][j + 1]);
					swapped = true;
				}
			}
			if (!swapped) break;
		}
		
	}
	else
	{
		for (int l{}; l < cols - 1; ++l) {
			swapped = false;
			for (int j{ cols - 1 }; j > l; --j) {
				if (mtr[i][j - 1] < mtr[i][j]) {
					std::swap(mtr[i][j - 1], mtr[i][j]);
					swapped = true;
				}
			}
			if (!swapped) break;
		}
	}

}

void SortingMatrix(int32_t** mtr, int32_t rows, int32_t cols)
{
	for (size_t i{}; i < rows; ++i)
	{
		BubbleSortOptimized(mtr, cols, i);
	}
	OutputMatrix(mtr, rows, cols);
}

void DeleteMatrix(int32_t** mtr, int32_t rows) {
	for (int i{}; i < rows; ++i)
	{
		delete[] mtr[i];
	}
	delete[] mtr;
}

int main()
{
	bool choice{};
	int32_t rows{};
	int32_t cols{};
	
	try
	{
		EnteringRowsAndCols(rows, cols);
		int** mtr = new int* [rows];
		for (int i = 0; i < cols; i++) {
			mtr[i] = new int[cols];
		}
		EnteringChoice(choice);
		if(choice)
		{
			FillMatrixWithRandom(mtr, rows, cols);
			OutputMatrix(mtr, rows, cols);
		}
		else
		{
			FillMatrixByPerson(mtr, rows, cols);
			OutputMatrix(mtr, rows, cols);
		}

		SearchForLocalMinima(mtr, rows, cols);

		std::cout << "\n\n";

		FindingSumOverDiagonal(mtr, rows, cols);

		std::cout << "\n\n";

		SearchingForSumColumnElements(mtr, rows, cols);

		std::cout << "\n\n";

		SortingMatrix(mtr, rows, cols);
		DeleteMatrix(mtr, rows);
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}