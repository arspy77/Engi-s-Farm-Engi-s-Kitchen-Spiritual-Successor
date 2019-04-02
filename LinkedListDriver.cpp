#include <bits/stdc++.h>
#include "LinkedList.h"

int main() {
	/*
	LinkedList<int>* L1;
	L1 = new LinkedList<int>();
	L1->add(3);
	L1->add(5);
	L1->add(7);
	LinkedList<int> L2 = *L1;
	LinkedList<int> L3;
	L3 = *L1;	
	L1->add(1);
	L1->add(2);
	L1->add(3);
	L1->add(4);
	std::cout << "L1 : ";
	L1->print();
	std::cout << std::endl;
	std::cout << "/////////////////////////////////////////" << std::endl;
	std::cout << "L2 : "; L2.print(); std::cout << std::endl;
	std::cout << "/////////////////////////////////////////" << std::endl;
	std::cout << "L3 : ";
	L3.print();
	std::cout << std::endl;
	std::cout << "/////////////////////////////////////////" << std::endl;
	std::cout << "L1 : ";
	L1->print();
	std::cout << std::endl;
	std::cout << "len : " << L1->len() << std::endl;
	std::cout << (*L1)[0] << std::endl;
	std::cout << (*L1)[2] << std::endl;
	std::cout << (*L1)[3] << std::endl;
	std::cout << (*L1)[6] << std::endl;
	delete L1;
	*/
	LinkedList<char> Ehem;
	Ehem.add('a');
	Ehem.add('b');
	Ehem.add('c');
	Ehem.add('d');
	Ehem.add('e');
	Ehem.add('f');
	Ehem.add('g');
	Ehem.print(); std::cout << '\n';
	std::cout << Ehem.len() << '\n';
	return 0;
}