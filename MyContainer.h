#pragma once
#include <iostream>

using namespace std;

//That container is extensioned singly linked list,
//which allows you to do operations at indexes without having to specify capacity in advance
template<typename T>
class MyContainer
{
private:
	class Node {
	public:
		int index;
		T value;
		Node* prev;
		Node(const T& value, int index, Node* prev = nullptr)
			: index(index), value(value), prev(prev) {
		}
	};
	Node* head;
	int size;

public:

	MyContainer() : head(nullptr), size(0) { }
	~MyContainer() { clear(); }

	void push_front(const T& value)
	{
		head = new Node(value, size, head);
		++size;
	}

	void pop_front() {
		if (head) {
			Node* temp = head;
			head = head->prev;
			delete temp;
			--size;
		}
	}
	void pop_at_index(int index)
	{
		if (index == size - 1)
		{
			pop_front();
		}
		else
		{
			Node* temp = head;
			if (index >= size || index < 0)
			{
				cout << "Incorrect index (MyContainer)";
				abort();
			}

			int currentIndex = size - 1;
			while (currentIndex != index)
			{

				if (currentIndex - 1 == index)
				{
					Node* temp2 = temp;
					temp2 = temp2->prev;
					temp2 = temp2->prev;
					temp->prev = temp2;
					break;
				}
				--(temp->index);

				--currentIndex;
				temp = temp->prev;
			}
			--size;
		}
	}

	T& front()
	{
		return head->value;
	}

	bool empty() const
	{
		return size == 0;
	}

	int getSize() const
	{
		return size;
	}

	void clear()
	{
		while (head) {
			Node* temp = head;
			head = head->prev;
			delete temp;
		}
		size = 0;
	}

	T& operator[](int index)
	{
		Node* temp = head;
		if (index >= size || index < 0)
		{
			cout << "Incorrect index (MyContainer)";
			abort();
		}
		int currentIndex = size;
		while (currentIndex != index + 1)
		{
			--currentIndex;
			temp = temp->prev;

		}

		return temp->value;
	}
	void print()
	{
		Node* temp = head;
		for (int i = 0; i < size; i++)
		{
			cout << temp->value << endl;
			temp = temp->prev;
		}
	}

};
