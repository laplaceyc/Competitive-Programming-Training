#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

void print_answer(double real_part, double imag_part) {
	if (imag_part == 0 && real_part == 0)
		printf("%.2f", 0);
	else if (imag_part == 0)
		printf("%.2f", real_part);
	else if (real_part == 0)
		printf("%.2fi", imag_part);
	else if (imag_part < 0)
		printf("%.2f%.2fi\n", real_part, imag_part);
	else
		printf("%.2f%+.2fi\n", real_part, imag_part);
	return;
}

int main()
{
	double real1, imag1, real2, imag2;
	char operand;
	cin >> real1 >> imag1 >> operand >> real2 >> imag2;
	double real_part, imag_part;
	double denominator;
	switch (operand)
	{
	case '+':
		real_part = real1 + real2;
		imag_part = imag1 + imag2;
		print_answer(real_part, imag_part);
		break;
	case '-':
		real_part = real1 - real2;
		imag_part = imag1 - imag2;
		print_answer(real_part, imag_part);
		break;
	case '*':
		real_part = real1 * real2 - imag1 * imag2;
		imag_part = real1 * imag2 + real2 * imag1;
		print_answer(real_part, imag_part);
		break;
	case '/':
		denominator = real2 * real2 + imag2 * imag2;
		real_part = (real1 * real2 + imag1 * imag2) / denominator;
		imag_part = (real2 * imag1 - real1 * imag2) / denominator;
		print_answer(real_part, imag_part);
		break;
	default:
		cout << "Nothing else";
		break;
	}
	return 0;
}
