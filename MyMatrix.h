#include <iostream>

#ifndef MYMATRIX_H
#define MYMATRIX_H

#pragma once

using namespace std;

class MyMatrix
{
private:
	//initiating data vars that represent the rows and the columns 
	int _m;
	int _n;
	//initiating dynamic pointer for two dimensional array 
	double** _matrix;

public:
	//setters
	void set(int n, int m);

	//getters
	int getM() { return _m; }
	int getN() { return _n; }
	double** getMat() { return _matrix; }

	//functions
	const MyMatrix operator+(const MyMatrix& other) const  throw(const char*);
	const MyMatrix operator-(const MyMatrix& other) const throw(const char*);
	const MyMatrix operator*(const MyMatrix& other) const throw(const char*);
	friend MyMatrix operator*(double num, const MyMatrix& other);
	const MyMatrix operator*(double scalar) const;
	MyMatrix& operator=(const MyMatrix& other) throw(const char*);
	bool operator==(const MyMatrix& other)const;
	friend ostream& operator<<(ostream& out, const MyMatrix& other);
	friend istream& operator>>(istream& in, MyMatrix& other);
	double* operator[](int row) const;
	operator double() const;

	//constructors
	MyMatrix();
	MyMatrix(int m, int n);
	MyMatrix(int m, int n, double** matrix);
	MyMatrix(const MyMatrix& other);
	~MyMatrix();
};

#endif // !MYMATRIX_H