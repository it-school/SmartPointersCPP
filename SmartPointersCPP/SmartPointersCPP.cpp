#include <iostream>

using namespace std;

int main()
{
	int a = 42;
	int b = 42;
	int* var1;
	int* var2;

	var1 = &a;
	var2 = &b;
	cout << "var1 = &a; var2 = &b;" << endl;
	cout << "Var1\t *var1: " << *var1 << "\t&var1: " << &var1 << "\t\tvar1: " << var1 << endl;
	cout << "Var2\t *var2: " << *var2 << "\t&var2: " << &var2 << "\t\tvar2: " << var2 << endl;

	var2 = var1;
	cout << endl << "var2 = var1;" << endl;
	cout << "Var1\t *var1: " << *var1 << "\t&var1: " << &var1 << "\t\tvar1: " << var1 << endl;
	cout << "Var2\t *var2: " << *var2 << "\t&var2: " << &var2 << "\t\tvar2: " << var2 << endl;

	var1 = NULL;
	cout << endl << "var1 = NULL;" << endl;
	cout << "Var1\t *var1: " << (var1 == NULL ? "n/a" : "" + *var1) << "\t&var1: " << &var1 << "\t\tvar1: " << var1 << endl; // error
	cout << "Var2\t *var2: " << (var2 == NULL ? "n/a" : "" + *var2) << "\t&var2: " << &var2 << "\t\tvar2: " << var2 << endl;
	cout << endl;

	return 0;

	cout << "Smart pointers in C++\n";
	/*
	Smart pointer � ��� ������, �������� � ������� ����� ��� � ������� ����������,
	�� ��� ����, � ������� �� ����������, �� ������������� ��������� �������������� ����������
	(��������, �������������� ������������ ������������ �� ���������� ������� ������).

	����� ��������� �������� ��� ������ � �������� ������, ������� ������ �������� � ������� ��������.
	��� �������� ������ � ������, ��� ��������� ����������, ��� ��� ��� ���������
	���������� ������� ��������� ����� � ������������ ��������� �������.
	� ������ �������� ��������� � ����������� ����������-���������, ��� ���� ������ ��������� �� �������������.
	� ������ ������ ��������� � ��������� ����������, ������� � ��������� ���������� ������.
	*/

	auto_ptr<int> x_ptr(new int(42));
	auto_ptr<int> y_ptr;

	// ��� ��� ��������� � ������� ������: ����� �������� ��������� ������ � y_ptr
	y_ptr = x_ptr; // x_ptr �������� ��������� �� null pointer

	cout << *x_ptr << endl; // segmentation fault
	
	

	/*
	� ����� ��������� ��������� ��������� ����� ���������: unique_ptr, shared_ptr � weak_ptr. ��� ��� ��������� � ������������ ����� <memory>

	� ������� �� auto_ptr, unique_ptr ��������� �����������.

	unique_ptr<int> x_ptr(new int(42));
	unique_ptr<int> y_ptr;

	// ������ ��� ����������
	y_ptr = x_ptr;
	// ������ ��� ����������
	std::unique_ptr<int> z_ptr(x_ptr);
	*/

	/*
	��������� ���� �������� �������� �������������� � ������� ��������������� ������� std::move(������� �������� ������ ��������� �����������).
	
	unique_ptr<int> x_ptr(new int(42));
	unique_ptr<int> y_ptr;

	// �����, ��� � � ������ � ``auto_ptr``, ����� �������� ���������
	// � y_ptr, � x_ptr �������� ��������� �� null pointer
	cout << "Before pointer move:" << endl;
	cout << "X: " << x_ptr << '\t' << *x_ptr << endl;
	//	cout << "Y: " << y_ptr << '\t' << *y_ptr << endl; // ������ ����������
	y_ptr = std::move(x_ptr);
	cout << "After pointer move:" << endl;
	//	cout << "X: " << x_ptr << '\t' << *x_ptr << endl; // ������ ����������
	cout << "Y: " << y_ptr << '\t' << *y_ptr << endl;
	*/

	/*
	� ������� �� ������������� ���� ����������, shared_ptr ��������� ������� ������ �� ������.
	������ ����������� �����, ����� ������� ������ �� ���� ����� ����� 0.
	��� �����, ������� ��������� ���� �� �������� ������ �������� ������.
	
	
	std::shared_ptr<int> x_ptr(new int(42));
	std::shared_ptr<int> y_ptr(new int(13));

	cout << "Before pointer move:" << endl;
	std::cout << *x_ptr << "\t" << *y_ptr << std::endl;

	// ����� ���������� ������ �������, ������ �� ������� �������� ����� y_ptr (int(13)) �����������,
	// � �� int(42) ����� ��������� ��� ���������
	
	cout << "After pointer move:" << endl;
	y_ptr = x_ptr;

	std::cout << *x_ptr << "\t" << *y_ptr << std::endl;
	*/

	cout << endl << endl;
}