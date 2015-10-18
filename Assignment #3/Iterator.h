/***********************************************************
* Author:					Kevin Fessler
* Date Created :			10/17/2015
* Last Modification Date :  10/17/2015
* Lab Number :				CST 211 - Data Structures
* File name :				Iterator.h
*
*  Overview: Implementation and defintions of the Iterator class
*
*    Input : An increment or decrement call to this class
*
*   Output : Iteration through a linked list based on the overloaded
*				operator call to this class
*
*****************************************************************/

#include "node.h"
#include "LinkedList.h"

#ifndef _ITERATOR_H
#define _ITERATOR_H


template<typename T>

class Iterator {

private: 


	// Postfix increment of "this" value
	Iterator operator++() 
	{
		(*this)++;				
		return *this;
	}

	// Prefix increment of "this" value
	Iterator operator++(int) 
	{
		T temp = *this;
		++(*this);				
		return temp;
	}


	// Postfix decrement of "this" value
	Iterator operator--() 
	{
		(*this)--;		
		return *this;
	}

	// Prefix decrement of "this" value
	Iterator operator--(int)
	{
		T temp = *this;
		--(*this);	
		return temp;
	}

public:

	Node* m_node;	// Points to the current node in a linked list

};

#endif //_ITERATOR_H