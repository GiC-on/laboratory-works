// Лабораторная работа №5 вариант №11
// Чупов Максим ЭиН-2 1к.

#include <iostream>

int main()
{
    int n, m;

    std::cout << "Enter matrix rows and columns count by space: ";
    std::cin >> n >> m;

    // creating an NxM matrix
    int** mtrx = new int* [n];
    for(int i = 0; i < n; i++)
        mtrx[i] = new int [m];

    // filling matrix with user input
    std::cout << "Enter all of the matrix elements by space for columns & by newline for rows:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            std::cin >> mtrx[i][j];

	// creating a Zero NxM mask matrix
	int** maskMtrx = new int* [n];
	for(int i = 0; i < n; i++)
		maskMtrx[i] = new int [m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			maskMtrx[i][j] = 0;
	}

	// marking in mask matrix extrema elements for each row & column of source matrix 
	for(int i = 0; i < n; i++)
	{
		int rowMax = mtrx[i][0];
		int rowMin = mtrx[i][0];

		// finding row extremas
		for(int j = 1; j < m; j++)
		{
			if(mtrx[i][j] > rowMax)
				rowMax = mtrx[i][j];
			else if (mtrx[i][j] < rowMin)
				rowMin = mtrx[i][j];
		}

		// marking every row extrema into mask matrix
		for (int j = 0; j < m; j++)
		{
			if (mtrx[i][j] == rowMax)
				maskMtrx[i][j] += 1;
			else if (mtrx[i][j] == rowMin)
				maskMtrx[i][j] -= 1;
		}
	}
	
	for (int j = 0; j < m; j++)
	{
		int clmnMax = mtrx[0][j];
		int clmnMin = mtrx[0][j];

		// finding column extremas
		for (int i = 1; i < n; i++)
		{
			if (mtrx[i][j] > clmnMax)
				clmnMax = mtrx[i][j];
			else if (mtrx[i][j] < clmnMin)
				clmnMin = mtrx[i][j];
		}

		// marking every column extrema into mask matrix
		for (int i = 0; i < n; i++)
		{
			if (mtrx[i][j] == clmnMax)
				maskMtrx[i][j] -= 1;
			else if (mtrx[i][j] == clmnMin)
				maskMtrx[i][j] += 1;
		}
	}

	// outputting every element of source matrix whose mask matrix's element is -2 or 2
	std::cout << "Saddle elements of this matrix is:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (maskMtrx[i][j] == -2 || maskMtrx[i][j] == 2)
				std::cout << "a_" << i+1 << '_' << j+1 << " = " << mtrx[i][j] << '\n';
	}

	return 0;
}