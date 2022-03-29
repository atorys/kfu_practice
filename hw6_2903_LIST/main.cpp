//
// Created by Achiote Tory on 3/29/22.
//

#include "List.hpp"
#include <iostream>

int main()
{
	{
		List<int> list;

		list.append(10);
		list.append(666);
		list.append(0);
		list.print();

		std::cout << "push index 10	: ";
		list.push(10, 10);

		std::cout << "push first	: ";
		list.push(1, 0);
		list.print();

		std::cout << "push index 2	: ";
		list.push(98, 2);
		list.print();

		std::cout << "push index 4	: ";
		list.push(44, 4);
		list.print();

		std::cout << "pop index 3	: ";
		list.pop(3);
		list.print();

		std::cout << "pop first	: ";
		list.pop(0);
		list.print();

		std::cout << "pop last	: ";
		list.pop(3);
		list.print();
	}
	{
		List<std::string>	list;

		list.append("one");
		list.pop(0);

		list.push("two", 0);
		list.append("three");
		list.append("four");
		list.print();

		std::cout << "find one	: index = " << list.find("one") << "\n";
		std::cout << "find three	: index = " << list.find("three") << "\n";
		std::cout << "find four	: index = " << list.find("four") << "\n";
	}
}
