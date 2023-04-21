#include "lab1.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	TList L;
	int ord = 1;
	int elem, index;
	while (ord != 0) {
		cout << "Введите номер команды: " << endl << "1 — добавить элемент в начало списка" << endl << "2 — добавить элемент в конец списка" << endl << "3 — добавить элемент в заданную позицию" << endl << "4 — удалить элемент по значению" << endl << "5 — удалить элемент по номеру позиции" << endl << "6 — найти элемент по значению" << endl << "7 — найти элемент в заданной позиции" << endl << "8 — вывод всех элементов списка" << endl << "0 — завершить исполнение программы" << endl;
		cout << "Номер необходимой операции — ";
		cin >> ord;
		if (ord == 1) {
			cout << "Какой элемент вы желаете добавить в начало списка?" << endl;
			cin >> elem;
			if (L.is_empty()) L.push(elem);
			else L.push1(elem);
		}
		if (ord == 2) {
			cout << "Какой элемент вы желаете добавить в конец списка?" << endl;
			cin >> elem;
			if (L.is_empty()) L.push_back(elem);
			else L.push_back1(elem);
		}
		if (ord == 3) {
			cout << "Какой элемент в какую позицию вы желаете добавить?" << endl;
			cin >> elem >> index;
			cout << endl;
			L.push_index(index, elem);
		}
		if (ord == 4) {
			cout << "Введите значение элемента, который вы желаете удалить." << endl;
			cin >> elem;
			L.remove(elem);
		}
		if (ord == 5) {
			cout << "Введите позицию элемента, который вы желаете удалить." << endl;
			cin >> index;
			L.remove_index(index);
		}
		if (ord == 6) {
			cout << "Введите значение элемента, который вы желаете найти." << endl;
			cin >> elem;
			L.find_value(elem);
		}
		if (ord == 7) {
			cout << "Введите позицию элемента, который вы желаете найти." << endl;
			cin >> index;
			L.find_index(index);
		}
		if (ord == 8) {
			L.print();
		}
	}
	return 0;
}