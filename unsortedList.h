#include<iostream>
#include"Node.h"
using namespace std;

//Linked List(unsorted)
template<typename T>
class UList
{
private:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* it;
public:
	UList()
	{
		head = NULL;
		tail = NULL;
		it = NULL;
	}

	UList(const UList& obj)
	{

		if (obj.head == NULL)
		{
			this->head = NULL;
		}
		else
		{
			Node<T>* curr = obj.head;
			while (curr != NULL)
			{
				this->insert(curr->data);
				curr = curr->next;
			}
		}

	}

	UList& operator=(const UList& obj)
	{
		if (obj.head == NULL)
		{
			this->head = NULL;
		}
		else
		{
			Node<T>* curr = obj.head;
			while (curr != NULL)
			{
				this->insert(curr->data);
				curr = curr->next;
			}
		}
		return *this;
	}

	void insert(T d)
	{
		if (head == NULL && tail == NULL)
		{
			head = new Node<T>;
			head->data = d;
			head->next = NULL;
			head->prev = NULL;
			tail = head;
			return;

		}
		Node<T>* New_Node = new Node<T>;
		New_Node->data = d;
		New_Node->next = NULL;
		New_Node->prev = tail;
		tail->next = New_Node;
		tail = New_Node;
	}

	bool update(T olddata, T newdata)
	{
		if (IsEmpty())
		{
			cout << "List is empty" << endl;
			return false;
		}

		Node<T>* curr = head;
		while ((curr != NULL) && (curr->data != olddata))
		{
			curr = curr->next;
		}

		if (curr == NULL)
		{
			cout << "Data not found in the List" << endl;
			return false;
		}
		else
		{
			curr->data = newdata;
			cout << "Updated" << endl;
			return true;
		}

	}

	Node<T>* find(T d)
	{
		if (IsEmpty())
		{
			cout << "List is empty" << endl;
			return NULL;
		}

		Node<T>* curr = head;
		while ((curr != NULL) && (curr->data != d))
		{
			curr = curr->next;
		}

		if (curr == NULL)
		{
			//cout << "Data not found in the List" << endl;
			return NULL;
		}
		else
		{
			return curr;
		}
	}

	void remove(T d)
	{
		Node<T>* curr = head;

		if (head == NULL && tail == NULL)
		{
			cout << "The List is Empty" << endl;
			return;
		}

		while ((curr != NULL) && curr->data != d)
		{
			curr = curr->next;
		}

		if (curr == NULL)
		{
			return;
		}

		if (curr->prev == NULL && curr->next == NULL)
		{
			delete curr;
			head = tail = NULL;
		}
		else if (curr->prev == NULL)
		{
			curr->next->prev = NULL;
			head = curr->next;
			delete curr;
		}
		else if (curr->next == NULL)
		{
			curr->prev->next = NULL;
			tail = curr->prev;
			delete curr;
		}
		else
		{
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			delete curr;
		}

	}

	void clear()
	{
		if (head == NULL)
			return;

		Node<T>* curr = head;
		Node<T>* next = NULL;
		while (curr != head)
		{
			next = curr->next;
			delete curr;
			curr = next;
		}

		delete head;
		head = tail = NULL;

	}

	bool IsEmpty()
	{
		if (head == NULL && tail == NULL)
		{
			return true;
		}

		return false;
	}

	T front()
	{
		if (!IsEmpty())
		{
			return head->data;
		}
		else
		{
			return T();
		}
	}

	T back()
	{
		if (!IsEmpty())
		{
			return tail->data;
		}
		else
		{
			return T();
		}
	}

	void display()
	{
		Node<T>* curr = head;

		if (IsEmpty())
		{
			return;
		}

		while (curr)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}

	~UList()
	{
		clear();
	}

	void reset_h()
	{
		it = head;
	}

	bool islast()
	{
		return it == NULL;
	}

	T get_next_h()
	{
		T temp;
		temp = it->data;
		it = it->next;
		return temp;
	}

	void reset_t()
	{
		it = tail;
	}

	bool isfirst()
	{
		return it == NULL;
	}

	T get_next_t()
	{
		T temp;
		temp = it->data;
		it = it->prev;
		return temp;
	}
};