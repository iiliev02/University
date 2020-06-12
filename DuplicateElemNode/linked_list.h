#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node <T>* next;

	Node(const T& data, Node <T>* next)
	{
		this->data = data;
		this->next = next;
	}
};

template<typename T>
class LinkedList
{
private:
	Node<T>* first;
	Node<T>* last;
	size_t size;
	void copy(const LinkedList& other)
	{
		Node<T>* temp = other.first;
		for (size_t i = 0; i < other.size; i++)
		{
			push_back(temp->data);
			temp = temp->next;
		}
	}

	void destroy()
	{
		while (size != 0)
		{
			this->pop_front();
		}
	}

public:
	LinkedList()
	{
		this->first = nullptr;
		this->last = nullptr;
		this->size = 0;
	}

	LinkedList(const LinkedList& other)
	{
		this->copy(other);
	}

	LinkedList& operator=(const LinkedList& other)
	{
		if (this != &other)
		{
			this->destroy();
			this->copy(other);
		}
		return *this;
	}

	~LinkedList() //в деструкторът освобождаваме елементи, ако е нужно
	{
		this->destroy();
	}

	void push_back(T data)
	{
		Node<T>* temp = new Node<T>(data, nullptr);
		if (this->size == 0)
		{
			this->first = temp;
			this->last = temp;
		}
		else
		{
			this->last->next = temp;
			this->last = temp;
		}
		this->size++;
	}

	void push_front(T data)
	{
		Node<T>* temp = new Node<T>(data, this->first);
		this->first = temp;
		this->size++;
	}

	void pop_back()
	{
		if (size == 0) return;
		Node<T>* buffer = last;
		Node<T>* temp = first;
		while (temp->next != this->last)
		{
			temp = temp->next;
		}

		temp->next = nullptr;
		this->last = temp;
		delete buffer;
		this->size--;
	}

	void pop_front()
	{
		if (size == 0) return;
		Node<T>* temp = first;
		if (size == 1)
		{
			this->first = nullptr;
			this->last = nullptr;
			delete temp;
			size--;
		}

		else
		{
			first = first->next;
			delete temp;
			size--;
		}
	}

	void push(T data, int index)
	{
		Node<T>* buffer = first;
		Node<T>* temp = new Node<T>(data, nullptr);
		while ((index - 1) != 0)
		{
			buffer = buffer->next;
			index--;
		}
		Node<T>* save = buffer->next;
		buffer->next = temp;
		temp->next = save;
		size++;
	}

	size_t getSize()
	{
		return this->size;
	}

	T get(int index)
	{
		if (index >= 0 && index < size && size != 0)
		{
			Node<T>* temp = first;
			for (int i = 0; i < index; i++)
			{
				temp = temp->next;
			}
			return temp->data;
		}
	}

	void print()
	{
		Node<T>* temp = first;
		cout << "[";
		while (temp->next != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data;
		cout << "]" << endl;
	}
};


