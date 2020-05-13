// queuetp.h
#ifndef QUEUE_H_
#define QUEUE_H_
#include "workermi.h"

template <typename T>
class QueueTP
{
private:
	struct Node
	{
		T item;
		struct Node* next;
	};
	enum { Q_SIZE = 10 };
	Node* front;
	Node* rear;
	int items;
	const int qsize;
	QueueTP(const QueueTP& q);
	QueueTP& operator=(const QueueTP& q) { return *this; }
public:
	explicit QueueTP(int qs = Q_SIZE)
		: qsize(qs), front(nullptr), rear(nullptr), items(0) {}
	~QueueTP();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const T& item);
	bool dequeue(T& item);
};
#endif

// queue.cpp
#include <cstdlib>

template <typename T>
QueueTP<T>::~QueueTP()
{
	Node* temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template<typename T>
bool QueueTP<T>::isempty() const
{
	return items == 0;
}


template <typename T>
bool QueueTP<T>::isfull() const
{
	return items == qsize;
}

template <typename T>
int QueueTP<T>::queuecount() const
{
	return items;
}

template <typename T>
bool QueueTP<T>::enqueue(const T& item)
{
	if (isfull())
		return false;
	Node* add = new Node;
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

template <typename T>
bool QueueTP<T>::dequeue(T& item)
{
	if (front == NULL)
		return false;
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = NULL;
	return true;
}
