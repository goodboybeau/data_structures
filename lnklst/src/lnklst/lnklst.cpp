#include <lnklst.hpp>


template <typename T>
LinkedList<T>::LinkedList()
		: _head(nullptr)
		, _length(0)
	{
	}

template <typename T>
unsigned int
LinkedList<T>::length()
{
	return this->_length;
}

template <typename T>
bool
LinkedList<T>::empty()
{
	return this->_length == 0;
}

template <typename T>
typename LinkedList<T>::node_ref_t
LinkedList<T>::head()
{
	return this->_head;
}

template <typename T>
typename LinkedList<T>::node_ref_t
LinkedList<T>::tail()
{
	if(this->empty())
	{
		return nullptr;
	}

	node_ref_t t = this->head();
	while(t->next != nullptr)
	{
		t = t->next;
	}
	return t;
}

template <typename T>
void
LinkedList<T>::reset()
{
	// delete links
	if(!this->empty())
	{
		this->_head.reset();
		this->_length = 0;
	}
}

template <typename T>
T
LinkedList<T>::at(unsigned int i)
{
	return this->get_at(i)->data;
}

template <typename T>
typename LinkedList<T>::node_ref_t
LinkedList<T>::insert(const T& data, unsigned int pos)
{
		node_ref_t pre = this->get_at(pos <= 0 ? 0 : pos-1);
		pre->next = node_ref_t(new node_t({data, pre->next}));
		++this->_length;
		return pre->next;
}

template <typename T>
typename LinkedList<T>::node_ref_t
LinkedList<T>::prepend(const T& data)
{
	node_ref_t new_head(new node_t({data, this->_head}));
	this->_head = new_head;
	++this->_length;
	return this->_head;
}

template <typename T>
typename LinkedList<T>::node_ref_t
LinkedList<T>::append(const T& data)
{
	node_ref_t ret;
	if(this->empty())
	{
		ret = this->prepend(data);
	}
	else
	{
		ret = this->tail();
		ret->next.reset(new struct node({data, nullptr}));
		ret = ret->next;
		++this->_length;
	}
	return ret;
}

template <typename T>
typename LinkedList<T>::node_ref_t
LinkedList<T>::get_at(unsigned int i)
{
	if(this->empty() && i != 0)
	{
		std::string msg("List is empty(): " + std::to_string(i));
		throw new std::out_of_range(msg);
	}

	node_ref_t tmp = this->head();
	while(tmp->next != nullptr && i != 0)
	{
		tmp = tmp->next;
		i--;
	}

	if(i != 0)
	{
		std::string msg("Out of range by: " + std::to_string(i) + "\n");
		throw std::out_of_range(msg);
	}
	return tmp;
}

template <typename T>
typename LinkedList<T>::node_ref_t
LinkedList<T>::reverse()
{
	if(!this->empty() && this->head()->next != nullptr)
	{
		node_ref_t prev = nullptr;
		node_ref_t curr = this->head();
		node_ref_t next = curr->next;

		while(next != nullptr)
		{
			curr->next = prev;
			prev = curr;
			curr = next;
			next = next->next;
		}

		curr->next = prev;
		this->_head = curr;
	}

	return this->head();
}

template <typename T>
std::string
LinkedList<T>::to_string()
{
	std::stringstream ss;
	node_ref_t tmp = this->head();
	while(tmp != nullptr)
	{
		ss << tmp->data << " ";
		tmp = tmp->next;
	}
	ss << "\n";
	return ss.str();
}



template class LinkedList<int>;

