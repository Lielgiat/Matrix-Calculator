#include <iostream>
#include "MyMatrix.h"

using namespace std;

int main()
{
	int choice;
	double c = 1.0;
	MyMatrix A, B, C, D, E, F, res;
	do
	{
		cout << endl << "Press 1 for setting matrix A" << endl << "Press 2 for setting matrix B" << endl
			<< "Press 3 for setting matrix C" << endl << "Press 4 for setting matrix D" << endl
			<< "Press 5 for changing the 'scalar' c (The default of c is 1)  " << endl << "Press 6 for printing matrix A"
			<< endl << "Press 7 for printing matrix B" << endl << "Press 8 for A + B" << endl << "press 9 for A - B"
			<< endl << "Press 10 for A * c" << endl << "Press 11 for c * B" << endl << "Press 12 for A * B" << endl
			<< "Press 13 for A * c + B" << endl << "Press 14 for A + B + C + D" << endl << "Press 15 for A * B * C * D"
			<< endl << "Press 16 for get value of matrix A by index" << endl << "Press 17 for A = B" << endl
			<< "Press 18 for A == B" << endl << "Press 19 for the sum of all A elemnts" << endl
			<< "Press 20 for checking associativity of A & B & C" << endl << "Press 21 for exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int aRow, aCol;
			cout << "Enter number of rows of matrix A" << endl;
			cin >> aRow;
			cout << "Enter number of columns of matrix A" << endl;
			cin >> aCol;

			if ((aRow < 1) || (aCol < 1))
			{             //if the (row,col) input of any of the matrices is 1,0\0,1\0,0 -  ileagal input!
				cout << "The matrix must have at lease one row and one column" << endl;
			}
			else
			{
				A.set(aRow, aCol);			// changing the sizes of the matrix
				cin >> A;
				cout << A << endl;
			}
			break;
		}
		case 2:
		{
			int bRow, bCol;
			cout << "Enter number of rows of matrix B" << endl;
			cin >> bRow;
			cout << "Enter number of columns of matrix B" << endl;
			cin >> bCol;

			if ((bRow < 1) || (bCol < 1))
				cout << "The matrix must have at lease one row and one columns" << endl;
			else
			{
				B.set(bRow, bCol);
				cin >> B;
				cout << B << endl;
			}
			break;
		}
		case 3:
		{
			int cRow, cCol;
			cout << "Enter number of rows of matrix C" << endl;
			cin >> cRow;
			cout << "Enter number of columns of matrix C" << endl;
			cin >> cCol;

			if ((cRow < 1) || (cCol < 1))
				cout << "The matrix must have at lease one row and one columns" << endl;
			else
			{
				C.set(cRow, cCol);
				cin >> C;
				cout << C << endl;
			}
			break;
		}
		case 4:
		{
			int dRow, dCol;
			cout << "Enter number of rows of matrix D" << endl;
			cin >> dRow;
			cout << "Enter number of columns of matrix D" << endl;
			cin >> dCol;

			if ((dRow < 1) || (dCol < 1))
				cout << "The matrix must have at lease one row and one columns" << endl;
			else
			{
				D.set(dRow, dCol);
				cin >> D;
				cout << D << endl;
			}
			break;
		}
		case 5:
		{
			cout << "Enter Number : " << endl;
			cin >> c;
			break;
		}
		case 6:
		{
			cout << A << endl;
			break;
		}
		case 7:
		{
			cout << B << endl;
			break;
		}
		case 8:
		{
			try
			{
				res = A + B;
				cout << res << endl;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		}
		case 9:
		{

			try
			{
				res = A - B;
				cout << res << endl;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		}
		case 10:
		{
			res = A * c;
			cout << res << endl;
			break;
		}
		case 11:
		{
			res = c * B;
			cout << res << endl;
			break;
		}
		case 12:
		{
			res = A * B;
			cout << res << endl;
			break;
		}
		case 13:
		{
			try
			{
				res = A * c + B;
				cout << res << endl;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		}
		case 14:
		{
			try
			{
				res = A + B + C + D;
				cout << res << endl;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		}
		case 15:
		{
			try
			{
				res = A * B * C * D;
				cout << res << endl;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			break;
		}
		case 16:
		{
			int indexRow, indexCol;
			cout << "Enter index row" << endl;
			cin >> indexRow;
			cout << "Enter index col" << endl;
			cin >> indexCol;
			if (indexRow == 0 || indexRow > A.getN() || indexCol == 0 || indexCol > A.getM())
			{
				cout << "Error - Out of range!!" << endl;
				break;
			}
			cout << "The value of this element is : " << A[indexRow - 1][indexCol - 1] << endl;
		}
		case 17:
		{
			A = B;
			cout << "A is equal to B" << endl;
			break;
		}
		case 18:
		{
			if (A == B)
			{
				cout << "The martices are equal" << endl;
			}
			else
			{
				cout << "The martices aren't equal" << endl;
			}
			break;
		}
		case 19:
		{
			double sumA = (double)A;
			cout << "The sum of the elements of A is : " << sumA << endl;
			break;
		}
		case 20:
		{
			try
			{
				E = A + (B - C);
				F = (A + B) - C;
				if (E == F)
				{
					cout << "The matrices are associative" << endl;
				}
				else
				{
					cout << "The matrices aren't associative" << endl;
				}
			}
			catch (const char* msg)
			{
				cout << msg << endl;
				cout << "The matrices aren't associative" << endl;
			}
			break;

		}
		case 21:
		{
			break;
		}
		default:
			cout << "There is no option " << choice << "." << endl;
		}
	} while (choice != 21);

	return 0;
}