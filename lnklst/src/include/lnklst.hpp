#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#if __cplusplus < 201103L
#define __cplusplus 201103L
#endif

#include <memory>
#include <iostream>
#include <stdexcept>
#include <sstream>


template <typename T>
class LinkedList
{
public:
	struct node
	{
		T data;
		std::shared_ptr<struct node> next;
	};

	typedef struct node node_t;
	typedef std::shared_ptr<node_t> node_ref_t;

	LinkedList();

	node_ref_t head();
	node_ref_t tail();

	void reset();

	T at(unsigned int i);
	node_ref_t get_at(unsigned int i);

	node_ref_t insert(const T& data, unsigned int pos);
	node_ref_t append(const T& data);
	node_ref_t prepend(const T& data);

	unsigned int length();
	bool empty();

	node_ref_t reverse();

	std::string to_string();

private:
	node_ref_t _head;
	std::size_t _length;
};

#endif //__LINKED_LIST__

