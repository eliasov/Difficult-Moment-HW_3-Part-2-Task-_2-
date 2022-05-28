#include "Task_2 (Part 2).h"
#include "Task_2 Class(Part 2).h"


using namespace std;
int main()
{


	cout << "\n\n================ Task_2 Part(2) ================\n\n"; 

	vector<int> iMatrix = { 2, 4, 3, 5, 7, 8, 6, 9, 1 }; // Determinant = 51

	Matrix<int> intMtx(3, iMatrix);
	intMtx.PrintMatrix();
	auto initialIntMatrix = intMtx.GetMatrix();
	cout << intMtx.Determinant(3, initialIntMatrix) << "\n\n";

	vector<float> fMatrix = { 2.2, 4.1, 3.2, 5.7, 7.1, 8.0, 6.6, 9.3, 1.2 }; // Determinant = 61.95

	Matrix<float> floatMtx(3, fMatrix);
	floatMtx.PrintMatrix();
	auto initialFloatMatrix = floatMtx.GetMatrix();
	cout << floatMtx.Determinant(3, initialFloatMatrix);

	
}