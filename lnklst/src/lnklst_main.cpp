#include <lnklst.hpp>

int main()
{
	LinkedList<int> llist;
	std::cout << "length: " << llist.length() << std::endl;
	std::cout << llist.to_string();
	llist.reverse();
	std::cout << llist.to_string();
	llist.append(1);
	llist.reverse();
	std::cout << llist.to_string();
	llist.append(2);
	llist.reverse();
	std::cout << llist.to_string();

	llist.append(3);
	std::cout << llist.to_string();
	llist.append(2);
	llist.reverse();
	std::cout << llist.to_string();

	std::cout << llist.at(2) << std::endl;
	std::cout << llist.to_string() ;

	std::cout << "get at 1: " << llist.at(1) << std::endl;
	std::cout << "get at 1: " << llist.at(1) << std::endl;
	std::cout << "get at 1: " << llist.at(1) << std::endl;
	std::cout << "get at 1: " << llist.at(1) << std::endl;

	std::cout << "insert 5 at 1: " << llist.insert(5, 1)->data << std::endl;

	std::cout << llist.at(1) << std::endl;

	std::cout << llist.to_string();

	return 0;
}
