#ifndef myNode
#define myNode
template<typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node<T>* prev;
};



#endif // !myNode

