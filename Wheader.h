#pragma once
using namespace std;

class Weather
{
public:
	//defaults
	static const int MAXROWS = 2;
	static const int MAXCOLS = 2;

	//Overload the stream insertion and extraction operators
	friend ostream& operator << (ostream&, const Weather &);
	friend istream& operator >> (istream&, Weather &);
	Weather();
	Weather(int, int);
	Weather(Weather & c);

	//bool isNum(string);
	void read(const char * fileName);
	void read(fstream &fileIn);
	float sumRow(const int r)const;
	float avgCol(int c);
	float avgRow(int r);
	float highestForRow(int r);
	float highestForCol(int c);
	float lowestForRow(int r);
	float lowestForCol(int c);
	Weather operator + (Weather mat);
	Weather operator * (Weather & m);
	const Weather & operator = (const Weather & mat);
	float & operator () (int, int);
	float get(int, int);
	void set(int, int, float);
	void print();
	~Weather(void);
private:
	int numRows;
	int numCols;
	float ** matrix;							//dynamically allocated

};
