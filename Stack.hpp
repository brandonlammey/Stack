/*
 * File Name: Stack.hpp
 * Author: Brandon Lammey 
 * Description: Implements stack class. 
 */

template<typename T>
Stack<T>::Stack()
{
	m_size = 0;
	m_topPtr = nullptr;//initialize top pointer to null empty stack  
}

template<typename T>
Stack<T>::~Stack()
{
	while(m_size!=0)
	{
		Node<T>* tempNodePtr = m_topPtr->getNext(); //create temp pointer to next node 
		delete(m_topPtr);//delete top node
		m_topPtr = tempNodePtr; //set top pointer to next node 		 

		m_size--;//decrease size of stack
	}

}

template<typename T>
bool Stack<T>::isEmpty() const
{
	if(m_size == 0)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

template<typename T>
int Stack<T>::size() const
{
	return(m_size);
}

template<typename T>
void Stack<T>::push(const T value)
{
	//create new node and set value to passed in parameter	
	Node<T>* newNodePtr = new Node<T>();
	newNodePtr->setValue(value);
	
	//set new node to point to what top is pointing to
	//set top to new node
	newNodePtr->setNext(m_topPtr);
	m_topPtr = newNodePtr; 

	//increment size 
	m_size++; 
	
}

template<typename T>
void Stack<T>::pop() throw(PreconditionViolationException)
{
	if(m_size == 0)//check to see if stack is empty and handle error
	{
		throw PreconditionViolationException("Pop attempted on an empty stack");
	}
	else
	{
		if(m_topPtr->getNext() == nullptr)//case when only one node in stack
		{
			delete(m_topPtr);//delete top node
			m_topPtr = nullptr;//avoid dangling pointer
			m_size--;//decrease size of stack
		}
		else
		{		
			Node<T>* tempNodePtr = m_topPtr->getNext(); //create temp pointer to next node 
			delete(m_topPtr);//delete top node
			m_topPtr = tempNodePtr; //set top pointer to next node 		 

			m_size--;//decrease size of stack 
		}	
	}
}

template<typename T>
T Stack<T>::peek() const throw(PreconditionViolationException)
{
	if(m_size == 0)//check to see if stack is empty and handle error
	{
		throw PreconditionViolationException("Peek attempted on empty stack");
	}
	else
	{
		return(m_topPtr->getValue());
	}
}
