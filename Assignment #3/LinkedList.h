/***********************************************************
* Author:					Kevin Fessler
* Date Created :			10/13/2015
* Last Modification Date :  10/17/2015
* Lab Number :				CST 211 - Data Structures
* File name :				LinkedList.h
*
*  Overview: LinkedList class Definitions
*
*    Input : LinkedList calls from the client class or main program
*
*   Output : Proper access to all of the member data
*
*****************************************************************/


#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "Node.h"
#include "Iterator.h"

using namespace std;



template<typename T>
class LinkedList {

private:

	Node* m_head;	// Pointer to the head (start) of the list
	Node* m_tail;	// Pointer to the tail (end) of the list
	int m_length;

public: 

	// True if list is empty, false otherwise 
	bool isEmpty() 	{ return(m_head == NULL); } 

    const Node& First();	// Points to the first node
    const Node& Last();		// Points to the last node
    
    void Prepend( T*);			// Add an element to the front of the list 
    void Append( T*);			// Add and element to the end of the list
    
    void Purge();				// Purge the list of all elements
    
    Node& Extract(T);		// Get an element from the list- "at()" function

    void InsertAfter( T,  T*);	// insert an item after the current node
    void InsertBefore( T,  T*);	// insert an item before the current node
    
    Iterator Begin();	// The start of the iterator
    Iterator End();		// The last position of the iterator

};


#endif //_LINKEDLIST_H