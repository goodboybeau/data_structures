#ifndef _BINARY_TREE_HPP_
#define _BINARY_TREE_HPP_

#include "include_c11.h"

#include <scoped_lock.hpp>

#include <memory>
#include <atomic>
#include <mutex>

#include <iostream>


#define DEBUG(s) std::cout << s << std::endl; std::flush(std::cout);

template <typename T>
struct node
{
	node() = delete;

	node(const T& t)
		: data(t)
		, left(nullptr)
		, right(nullptr)
	{}

	node(const T* t)
		: data(*t)
		, left(nullptr)
		, right(nullptr)
	{}

	~node()
	{
		if(this->left)
		{
			delete this->left;
		}

		if(this->right)
		{
			delete this->right;
		}
	}

	node<T>& operator=(const node<T>& other)
	{
		this->data = other.data;
		this->right = other.right;
		this->left = other.left;
		return *this;
	}

	T data;
	node<T>* left;
	node<T>* right;
};

template <typename T>
class BinaryTree
{
	node<T>* root;
	std::mutex m;
	int size;
public:
	BinaryTree()
		: root(nullptr)
		, size(0)
	{}

	~BinaryTree()
	{
		if(this->root)
		{
			delete this->root;
		}
	}

	void insert(const T& t)
	{
		ScopedLock<std::mutex> sl(this->m);

		if (this->root == nullptr)
		{
			size ++;
			//DEBUG("new root");
			this->root = new node<T>(t);
			return;
		}

		if (this->root->data == t)
		{
			//DEBUG("root is data");
			return;
		}

		std::reference_wrapper<node<T>*> ref = std::ref(this->root);
		while((ref.get() != nullptr) && (ref.get()->data != t))
		{
			if(t < ref.get()->data)
			{
				//DEBUG("left");
				ref = std::ref(ref.get()->left);
			}
			else
			{
				//DEBUG("right");
				ref = std::ref(ref.get()->right);
			}
		}

		if(ref.get() == nullptr)
		{
			//DEBUG("ref was null");
			ref.get() = new node<T>(t);
			size ++;
		}
		else
		{
			//DEBUG("ref was not null");
		}
	}

	static std::reference_wrapper<node<T>*> rec_search(const std::reference_wrapper<node<T>*> ref, const T& target)
	{
		if(ref.get() == nullptr || ref.get()->data == target)
		{
			return ref;
		}

		auto res = rec_search(std::ref(ref.get()->left), target);

		return res.get() == nullptr ? rec_search(std::ref(ref.get()->right), target) : res;
	}

	node<T>* search(const T& t)
	{
		return rec_search(std::ref(this->root), t).get();
	}

	bool remove(const T& t)
	{
		auto res = this->search(t);
		if(!res)
		{
			return false;
		}

		node<T>* tmp;
		if(res->right || res->left)
		{
			tmp = res->right ? res->right : res->left;

//			res->right = tmp->right;
//			res->left = tmp->left;
//			res->data = tmp->data;

			*res = *tmp;

			tmp->left = tmp->right = nullptr;

			delete tmp;
		}

		--this->size;

		return true;
	}

	int getSize()
	{
		return this->size;
	}
};



#endif /* _BINARY_TREE_HPP_ */
