#include <iostream>
#include "int_box.h"

using namespace std;

int main() {
	Container my_int;

	my_int.add(5);
	my_int.add(7);
	my_int.add(3);
	my_int.add(9);
	my_int.add(11);

	my_int.add_pos(1, 1);
	my_int.add_pos(2, 2);
	my_int.add_pos(4, 12);
	my_int.add_pos(6, 8);

	my_int.remove(9);
	my_int.remove_first();
	my_int.remove_last();
	my_int.remove(3);
	my_int.remove(7);

	my_int.display();

	cout << endl;

	cout << "data in position: " << my_int.get_data(7) << endl;
	cout << "      first data: " << my_int.get_first() << endl;
	cout << "       last data: " << my_int.get_last() << endl;
	cout << "   data position: " << my_int.get_pos(3) << endl;

	return 0;
}