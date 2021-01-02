#include "MyMatrix.h"

//Set the size of the matrix 
void MyMatrix::set(int n, int m)
{
	MyMatrix matrix(m, n);
	*this = matrix;
}

//An adding operator between two matrices that receives two matrices and checks whether the adding is possible 
//according to matrix rules. the function returns the result value into an anonymous object.
const MyMatrix MyMatrix::operator+(const MyMatrix& other) const throw(const char*)
{
	if ((_n != other._n) || (_m != other._m))
	{
		throw "The rows & the columns must be in the same size";
	}
	MyMatrix res(_m, _n);
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _m; j++)
		{
			res._matrix[i][j] = _matrix[i][j] + other._matrix[i][j];
		}
	}
	return res;
}

//An subtraction operator between two matrices that receives two matrices and checks whether the subtraction is possible 
//according to matrix rules. the function returns the result value into an anonymous object.
const MyMatrix MyMatrix::operator-(const MyMatrix& other) const throw(const char*)
{
	if ((_n != other._n) || (_m != other._m))
	{
		throw "The rows & the columns must be in the same size";
	}
	MyMatrix res(_m, _n);
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _m; j++)
		{
			res._matrix[i][j] = _matrix[i][j] - other._matrix[i][j];
		}
	}
	return res;
}

//A multiplier operator between two matrices that receives two matrices and checks whether multiplication is possible according to matrix rules,
//multiplies a double row column and returns the value of the result into an anonymous object.
const MyMatrix MyMatrix::operator*(const MyMatrix& other) const throw(const char*)
{
	if (_m != other._n)
	{
		throw "The columns of the first matrix must be the same as the rows of the second matrix";
	}
	//According to the rulls of the matrices, the rows of the result matrix must be the same as the first matrix,
	//and the columns of the result matrix must be the same as the second matrix.
	MyMatrix res(_n, other._m);
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < other._m; j++)
		{
			for (int k = 0; k < _m; k++)
			{
				res._matrix[i][j] += _matrix[i][k] * other._matrix[k][j];
			}
		}
	}
	return res;
}

//Operator for scalar * matrix. receives a scalar and object and calculate the result.
//returns the result object. 
MyMatrix operator*(double num, const MyMatrix& other)
{
	MyMatrix res(other._m, other._n);
	for (int i = 0; i < other._n; i++)
	{
		for (int j = 0; j < other._m; j++)
		{
			res._matrix[i][j] = other._matrix[i][j] * num;
		}
	}
	return res;
}

//Operator for matrix * scalar. receives a scalar and object and calculate the result.
//returns the result object.
const MyMatrix MyMatrix::operator*(double scalar) const
{
	MyMatrix res(_m, _n);
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _m; j++)
		{
			res._matrix[i][j] = _matrix[i][j] * scalar;
		}
	}
	return res;
}

//A placement operator between two matrices who receives two matrices and checks whether the placement is possible according
//to the rules of matrices, if the sizes of the matrices are different, deletes and initializes the size of the matrix.
//Returns the value of the result into an anonymous object.
MyMatrix& MyMatrix::operator=(const MyMatrix& other) throw(const char*)
{	//if this is the same matrix (same adress not just equal)
	if (this == &other) return *this;
	//if the 2 matrices size isn't equal - delete and then define the matrix again
	if ((this->_m != other._m) || (this->_n != other._n))
	{
		for (int i = 0; i < this->_n; i++)
		{
			delete[] this->_matrix[i];
		}
		delete this->_matrix;
		this->_matrix = nullptr;
		this->_matrix = new double* [other._n];//columns
		for (int i = 0; i < other._n; i++)
		{
			this->_matrix[i] = new double[other._m];//rows
		}
		this->_m = other._m;
		this->_n = other._n;
	}
	if (this->_matrix == nullptr)//if the arr is NULL
	{
		this->_matrix = new double* [other._n];//columns
		for (int i = 0; i < other._n; i++)
		{
			this->_matrix[i] = new double[other._m];//rows
		}
		this->_m = other._m;
		this->_n = other._n;
	}
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _m; j++)
		{
			this->_matrix[i][j] = other._matrix[i][j];
		}
	}
	return *this;
}

//A Boolean comparison operator between two matrices that receives two matrices and 
//checks whether they are identical, whether the matrices are different or whether the matrices are different,
//returns a false value and prints a note. Otherwise, the matrices are identical and the operator returns true value.
bool MyMatrix::operator==(const MyMatrix& other)const
{
	if (_m != other._m)
	{
		return false;
	}
	if (_n != other._n)
	{
		return false;
	}
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _m; j++)
		{
			if (_matrix[i][j] != other._matrix[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

//Matrix printing operator that receives a matrix from an ostream object, and prints the matrix.
//The function return - ostream out
ostream& operator<<(ostream& out, const MyMatrix& other)
{
	for (int i = 0; i < other._n; i++)
	{
		for (int j = 0; j < other._m; j++)
		{
			cout << other._matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "******************************************";
	return out;
}

//An operator that receives two objects: istream and MyMatrix by reference 
//store the data members in the matrix and return the object in
istream& operator>>(istream& in, MyMatrix& other)
{
	for (int i = 0; i < other.getN(); i++)
		for (int j = 0; j < other.getM(); j++)
		{
			cout << "Enter the value of " << i + 1 << "," << j + 1 << " : ";
			in >> other.getMat()[i][j];
		}
	return in;
}

//An operator that returns the value of the requested member in the matrix.
//Gets the row number in the arry of pointers of the columns
double* MyMatrix::operator[](int row) const
{
	return _matrix[row];
}

//A casting operator that receives nothing but returns the sum of the matrix members
MyMatrix::operator double() const
{
	double sum = 0;
	for (int i = 0; i < this->_n; i++)
	{
		for (int j = 0; j < this->_m; j++)
		{
			sum += (*this)[i][j];
		}
	}
	return sum;
}

//Default constractor that initiate matrix in size 3*3 and initiate the values of the organs of the matrix to 0. 
MyMatrix::MyMatrix()
{
	this->_m = 3;
	this->_n = 3;
	this->_matrix = new double* [3];
	for (int i = 0; i < 3; i++)
	{
		this->_matrix[i] = new double[3];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			this->_matrix[i][j] = 0;
		}
	}
}

//This constractor receive  from the user two ints for the rows and columns of the matrix size
//constractor that initiate matrix in size n*m and initiate the values of the organs of the matrix to 0.
MyMatrix::MyMatrix(int m, int n)
{
	this->_m = m;
	this->_n = n;
	this->_matrix = new double* [n];
	for (int i = 0; i < n; i++)
	{
		this->_matrix[i] = new double[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			this->_matrix[i][j] = 0;
		}
	}
}

//The same constructor like before but the initialat isn't to zero, it is to other matrix (placement)
MyMatrix::MyMatrix(int m, int n, double** matrix)
{
	this->_m = m;
	this->_n = n;
	this->_matrix = new double* [n];
	for (int i = 0; i < n; i++)
	{
		this->_matrix[i] = new double[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			this->_matrix[i][j] = matrix[i][j];
		}
	}
}

//The copy constructor
MyMatrix::MyMatrix(const MyMatrix& other)
{	//we changing the dynamic pointer to NULL in order to avoid deleting empty cell in the operator=.
	_matrix = NULL;
	*this = other;
}

//Disructor
MyMatrix::~MyMatrix()
{
	for (int i = 0; i < _n; i++)
	{
		delete[] _matrix[i];
	}
	delete _matrix;
}
