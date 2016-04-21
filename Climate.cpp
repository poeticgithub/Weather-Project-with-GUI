#include <fstream>
#include <iostream>
#include "Wheader.h"

//default constructor - dynamically allocated 2d array
Weather::Weather() :numRows(MAXROWS), numCols(MAXCOLS)
{
	matrix = new float*[numRows];
	for (int i = 0; i<numRows; i++)
		matrix[i] = new float[numCols];
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			matrix[row][col] = 0;
		}
	}
}

Weather::Weather(int r, int c) :numRows(r), numCols(c)
{
	matrix = new float*[numRows];
	for (int i = 0; i<numRows; i++)
		matrix[i] = new float[numCols];
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			matrix[row][col] = 0;
		}
	}
}


//copy constructor
Weather::Weather(Weather &c)
{

	numRows = c.numRows;
	numCols = c.numCols;
	matrix = new float*[numRows];
	for (int i = 0; i<numRows; i++)
		matrix[i] = new float[numCols];

	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			matrix[row][col] = c.matrix[row][col];
		}
	}
}

void Weather::read(const char * fileName)
{
	fstream fileIn;

	fileIn.open(fileName);
	if (!fileIn.is_open())
	{
		cerr << fileName << " is not open";
	}
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			fileIn >> matrix[row][col];
		}
	}
}

void Weather::read(fstream &fileIn)
{
	if (!fileIn.is_open())
	{
		cerr << " file is not open";
	}
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			fileIn >> matrix[row][col];
		}
	}
}

float Weather::highestForRow(int r)
{
	float highest = matrix[r][0];
	for (int col = 1; col < numCols; col++)
	{
		if (matrix[r][col] > highest)
			highest = matrix[r][col];
	}

	return highest;
}

float Weather::lowestForRow(int r)
{
	float lowest = matrix[r][0];
	for (int col = 1; col < numCols; col++)
	{
		if (matrix[r][col] < lowest)
			lowest = matrix[r][col];
	}

	return lowest;
}

float Weather::highestForCol(int c)
{
	float highest = matrix[0][c];
	for (int row = 1; row < numRows; row++)
	{
		if (matrix[row][c] > highest)
			highest = matrix[row][c];
	}

	return highest;
}

float Weather::lowestForCol(int c)
{
	float lowest = matrix[0][c];
	for (int row = 1; row < numRows; row++)
	{
		if (matrix[row][c] < lowest)
			lowest = matrix[row][c];
	}

	return lowest;
}

float Weather::sumRow(const int r)const
{
	float sum = 0;

	for (int col = 0; col < numCols; col++)
	{
		sum += matrix[r - 1][col];
	}

	return sum;
}

float Weather::avgRow(int r)
{
	float sum = 0;
	//r--;
	for (int col = 0; col < numCols; col++)
	{
		sum += matrix[r][col];
	}

	return sum / numCols;
}

float Weather::avgCol(int c)
{
	float sum = 0;
	//c--;
	for (int row = 0; row < numRows; row++)
	{
		sum += matrix[row][c];
	}

	return sum / numRows;
}

Weather Weather::operator + (Weather mat)
{
	Weather *answer = new Weather;
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			answer->matrix[row][col] = matrix[row][col] + mat.matrix[row][col];
		}
	}
	//answer->print();
	return *answer;
}
const Weather & Weather::operator = (const Weather & mat)
{
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			matrix[row][col] = mat.matrix[row][col];
		}
	}

	return *this;
}

float Weather::get(int i, int j)
{
	return matrix[i][j];
}

void Weather::set(int i, int j, float value)
{
	matrix[i][j] = value;
}

void Weather::print()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			cout << matrix[row][col] << " ";
		}
		cout << endl << endl;
	}
}


Weather Weather::operator * (Weather & m)
{
	Weather * result = new Weather(numRows, m.numCols);

	// check if matricies can be multiplied
	if (numCols == m.numRows) {
		for (int i = 0; i<result->numRows; i++)
		{
			for (int j = 0; j<result->numCols; j++)
			{
				for (int k = 0; k<m.numRows; k++)
				{
					result->matrix[i][j] += matrix[i][k] * m.matrix[k][j];
				}
			}
		}
	}
	else
	{
		cout << ("Matrices cannot be multiplied!");
	}

	return *result;
}


Weather::~Weather(void)
{
	for (int row = 0; row < numRows; row++)
		delete[] matrix[row];
	delete[] matrix;
}

/*bool Weather::isNum(string s){
	int i = 0;
	while (i < s.length()){
		if (!isdigit(s[i])){
			return false;
		}
		i++;
	}
	return true;

}*/

ostream& operator << (ostream& osObject, const Weather& m)
{
	for (int row = 0; row < m.numRows; row++)
	{
		for (int col = 0; col < m.numCols; col++)
		{
			osObject << m.matrix[row][col] << " ";
		}
		osObject << endl << endl;
	}

	return osObject;
}

istream& operator >> (istream& isObject, Weather& m)
{
	isObject >> m.numRows >> m.numCols;

	return isObject;
}