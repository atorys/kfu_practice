//
// Created by atory on 3/29/22.
//

#pragma once

#include <iostream>
#define GREEN "\033[32m"
#define RED "\033[31m"
#define DEF "\033[0m"

template < class T >
struct Node {
	T		element;
	Node*	prev;
	Node*	next;
};

template < class T >
class List {
	Node<T>*	_head;
public:

	List(): _head(nullptr) { std::cout << GREEN << "[ New empty list constructed. ]\n" << DEF; }
	~List()
	{
		Node<T>*	ptr = this->_head;
		Node<T>*	tmp;

		while (ptr) {
			tmp = ptr->next;
			delete ptr;
			ptr = tmp;
		}
		std::cout << GREEN << "[ List destructed. ]\n" << DEF;
	}

	int		find(const T& X)
	{
		Node<T>*	ptr = this->_head;
		for (int i = 0; ptr != nullptr; ++i, ptr = ptr->next){
			if (ptr->element == X)
				return i;
		}
		return -1;
	}

	void	push(const T& X, int index)
	{
		Node<T>*	ptr = this->_head;
		int 		i = 0;

		for (; i < index; ++i) {
			ptr = ptr->next;
			if (ptr == nullptr)
				break;
		}
		if (i != index)
			std::cout << RED << "index out of range!\n" << DEF;
		else if (!ptr)
			this->append(X);
		else {
			Node<T>*	newNode = new Node<T>();

			newNode->element = X;
			newNode->prev = ptr->prev;
			newNode->next = ptr;

			if (ptr == this->_head)
				this->_head = newNode;
			else
				ptr->prev->next = newNode;
			ptr->prev = newNode;
		}
	}

	void	pop(int index)
	{
		Node<T>*	ptr = this->_head;
		int 		i = 0;

		for (; i < index; ++i) {
			ptr = ptr->next;
			if (ptr == nullptr)
				break;
		}
		if (i != index)
			std::cout << RED << "index out of range!\n" << DEF;
		else if (!ptr)
			std::cout << RED << "no elements to pop!\n" << DEF;
		else {
			Node<T>*	tmp = ptr;

			if (ptr == this->_head)
				this->_head = ptr->next;
			else
				ptr->prev->next = ptr->next;
			if (ptr->next)
				ptr->next->prev = ptr->prev;
			delete tmp;
		}
	}

	void	append(const T& X)
	{
		Node<T>*	newNode = new Node<T>();

		newNode->element = X;
		newNode->prev = nullptr;
		newNode->next = nullptr;

		add_back(newNode);
	}
	void	add_back(Node<T>* newNode)
	{
		Node<T>*	ptr = this->_head;

		if (!this->_head) {
			this->_head = newNode;
		}
		else {
			while (ptr->next)
				ptr = ptr->next;
			ptr->next = newNode;
			newNode->prev = ptr;
		}
	}

	void	print() const
	{
		Node<T>*	ptr = this->_head;

		std::cout << "List : ";
		while (ptr) {
			std::cout << ptr->element;
			ptr = ptr->next;
			if (ptr)
				std::cout << ", ";
		}
		std::cout << "\n";
	}
};
