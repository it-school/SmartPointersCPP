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
	Smart pointer — это объект, работать с которым можно как с обычным указателем,
	но при этом, в отличии от последнего, он предоставляет некоторый дополнительный функционал
	(например, автоматическое освобождение закрепленной за указателем области памяти).

	Умные указатели призваны для борьбы с утечками памяти, которые сложно избежать в больших проектах.
	Они особенно удобны в местах, где возникают исключения, так как при последних
	происходит процесс раскрутки стека и уничтожаются локальные объекты.
	В случае обычного указателя — уничтожится переменная-указатель, при этом ресурс останется не освобожденным.
	В случае умного указателя — вызовется деструктор, который и освободит выделенный ресурс.
	*/

	auto_ptr<int> x_ptr(new int(42));
	auto_ptr<int> y_ptr;

	// вот это нехороший и неявный момент: права владения ресурсами уходят в y_ptr
	y_ptr = x_ptr; // x_ptr начинает указывать на null pointer

	cout << *x_ptr << endl; // segmentation fault
	
	

	/*
	В новом стандарте появились следующие умные указатели: unique_ptr, shared_ptr и weak_ptr. Все они объявлены в заголовочном файле <memory>

	В отличии от auto_ptr, unique_ptr запрещает копирование.

	unique_ptr<int> x_ptr(new int(42));
	unique_ptr<int> y_ptr;

	// ошибка при компиляции
	y_ptr = x_ptr;
	// ошибка при компиляции
	std::unique_ptr<int> z_ptr(x_ptr);
	*/

	/*
	Изменение прав владения ресурсом осуществляется с помощью вспомогательной функции std::move(которая является частью механизма перемещения).
	
	unique_ptr<int> x_ptr(new int(42));
	unique_ptr<int> y_ptr;

	// также, как и в случае с ``auto_ptr``, права владения переходят
	// к y_ptr, а x_ptr начинает указывать на null pointer
	cout << "Before pointer move:" << endl;
	cout << "X: " << x_ptr << '\t' << *x_ptr << endl;
	//	cout << "Y: " << y_ptr << '\t' << *y_ptr << endl; // ошибка выполнения
	y_ptr = std::move(x_ptr);
	cout << "After pointer move:" << endl;
	//	cout << "X: " << x_ptr << '\t' << *x_ptr << endl; // ошибка выполнения
	cout << "Y: " << y_ptr << '\t' << *y_ptr << endl;
	*/

	/*
	В отличие от рассмотренных выше указателей, shared_ptr реализует подсчет ссылок на ресурс.
	Ресурс освободится тогда, когда счетчик ссылок на него будет равен 0.
	Как видно, система реализует одно из основных правил сборщика мусора.
	
	
	std::shared_ptr<int> x_ptr(new int(42));
	std::shared_ptr<int> y_ptr(new int(13));

	cout << "Before pointer move:" << endl;
	std::cout << *x_ptr << "\t" << *y_ptr << std::endl;

	// после выполнения данной строчки, ресурс на который указывал ранее y_ptr (int(13)) освободится,
	// а на int(42) будут ссылаться оба указателя
	
	cout << "After pointer move:" << endl;
	y_ptr = x_ptr;

	std::cout << *x_ptr << "\t" << *y_ptr << std::endl;
	*/

	cout << endl << endl;
}