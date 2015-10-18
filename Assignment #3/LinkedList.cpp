/**************************************************************
* Author:					Kevin Fessler
* Date Created :			10/13/2015
* Last Modification Date :  10/17/2015
* Lab Number :				CST 211 - Data Structures
* File name :				LinkedList.cpp
*
*  Overview: Implementation of LinkedList class
*
*    Input : Data from a linked list, a location on the linked list,
*				or data to set within the list
*
*   Output : The access to a first, last or any element within
*			the linked list
*
*****************************************************************/


#include "LinkedList.h"




/**************************************************************
*   Entry:  A call from the client class to access the first 
*			element within the list
*
*    Exit:  Returns a pointer to the data within the element
*
* Purpose:  The First function will iterate through all of the 
*			elements until it finds one that is empty. If it 
*			is empty, then we have found the beginning of the list
*
***************************************************************/
template<typename T>
const Node<T>& LinkedList<T>::First() {

	Node *node_ptr;			// Create a new node pointer

	for (node_ptr = this->m_head; node_ptr != NULL;	node_ptr = node_ptr->next) 
	{
		if (isEmpty() == 0) {
			break;
		}
		End()--;				
	}
	return node_ptr->m_data;	// Return the data at the beginning of the list
}



/**************************************************************
*   Entry:  A call from the client class to access the last
*			element within the list
*
*    Exit:  Returns a pointer to the data within the element
*
* Purpose:  The Last function will iterate through all of the
*			elements until it finds one that is empty. If it
*			is empty, then we have found the end of the list
*
***************************************************************/
template<typename T>
const Node<T>& LinkedList<T>::Last() {

	Node *node_ptr;			// Create a new node pointer

	for (node_ptr = this->m_head; node_ptr != NULL; node_ptr = node_ptr->next) 
	{
		if (isEmpty() == 0) {
			break;
		}
		Begin()++;
	}
	return node_ptr->m_data;	// Return the data at the end of the list
}


/**************************************************************
*   Entry:  A call from the client class to append data to
*			the node class
*
*    Exit:  Returns a pointer to increment the length of the list
*
* Purpose:  Append data to the beginning of the node
*
***************************************************************/
template<typename T>
void LinkedList<T>::Append(T *)
{
	if (this->m_head == NULL)		// checks if at the end of the list
	{
		*T *new_node = new Node(T);
		this->m_head = new_node;	// create a new node here
	}

	else {							// if at the last node, get a new location
		Node *last_node = NULL;
		for (Node *node_ptr = this->head; node_ptr != NULL; node_ptr = node_ptr->next)
		{
			last_node = node_ptr; 
		}

		Node *new_node = new Node(value);
		last_node->next = new_node;		// Create a new node at this location
	}

	this->m_length++;	// Point to an incremented length (since a new node was created)
}


/**************************************************************
*   Entry:  A call from the client class to prepend data to
*			the node class
*
*    Exit:  Returns a pointer to increment the length of the list
*
* Purpose:  Append data to the beginning of the node
*
***************************************************************/
template<typename T>
void LinkedList<T>::Prepend(T *)
{
	Node *new_node = new Node(value);
	new_node->next = this->head;

	this->head = new_node;

	this->length++;		// Point to an incremented length (since a new node was created)
}


/**************************************************************
*   Entry:  A call from the client class to delete all of the nodes
*
*    Exit:  Does not return anything
*
* Purpose:  Delete all references and nodes in a ADT doubly-linked list
*
***************************************************************/
template<typename T>
void LinkedList<T>::Purge()
{
	Node *next_node = NULL;		// Start at the beginning element

	// Iterate through the all the nodes
	for (Node *node_ptr = this->m_head; node_ptr != NULL; node_ptr = next_node) {

		next_node = node_ptr->next;		// Point to the next element
		delete node_ptr;				// Delete the node
	}
}


/**************************************************************
*   Entry:  A call from the client class to access a single
*			node within the list
*
*    Exit:  Returns a pointer to the data within the node
*
* Purpose:  Allow the client class to access a node within 
*			the linked list
*
***************************************************************/
template<typename T>
Node<T>& LinkedList<T>::Extract( T) {

	T *node_ptr;					// Create a new node iterator

	for (node_ptr = this->head; node_ptr != NULL; node_ptr = node_ptr->next) 
	{
		if (isEmpty() == 0) {
			break;
		}
		End()--;
	}
	return node_ptr->data;			// Return the node
}


/**************************************************************
*   Entry:  A reference to the element to insert after
*
*    Exit:  Returns nothing
*
* Purpose:  Insert a node after another
*
***************************************************************/
template<typename T>
void LinkedList<T>::InsertAfter(T, T *)
{
	if (m_head == NULL)
		return false;

	Node<T> *temp = new Node;	// Create a new node

	if (temp == NULL)
		return false;

	T*->next = temp;			// set the pointer to the right node

}


/**************************************************************
*   Entry:  A reference to the element to insert before
*
*    Exit:  Returns nothing
*
* Purpose:  Insert a node before another
*
***************************************************************/
template<typename T>
void LinkedList<T>::InsertBefore(T, T *)
{
	if (m_head == NULL)
		return false;

	Node<T> *temp = new Node;	// Create a new node

	if (temp == NULL)
		return false;

	T*->prev = temp;		// set the pointer to the right node

}


/**************************************************************
*   Entry:  A call from the client class to access the first
*			element within the list
*
*    Exit:  Returns an iterator to the data within the element
*
* Purpose:  The begin function allows for iterating the beginning of 
*			the linked list
*
***************************************************************/
template<typename T>
Iterator<T> LinkedList<T>::Begin() {
    return *m_head;
}



/**************************************************************
*   Entry:  A call from the client class to access the last
*			element within the list
*
*    Exit:  Returns an iterator to the data within the element
*
* Purpose:  The begin function allows for iterating the end of
*			the linked list
*
***************************************************************/
template<typename T>
Iterator<T> LinkedList<T>::End() {
	return *m_tail;
}