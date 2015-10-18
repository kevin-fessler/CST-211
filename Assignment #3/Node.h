/***********************************************************
* Author:					Kevin Fessler
* Date Created :			10/13/2015
* Last Modification Date :  10/17/2015
* Lab Number :				CST 211 - Data Structures
* File name :				Node.h
*
*  Overview: Definitions of the Node Class
*
*    Input : Data to be set to a node or access to 
*				any node pointer
*
*   Output : Appropriate setting of the data and access
*
*****************************************************************/

#ifndef _NODE_H
#define _NODE_H

#include <iostream>

using namespace std;



template<typename T>
class Node {

public:

public: 
	T m_data;		// Stores the data in one element of a node
	Node* m_next;	// Pointer points to the next node
	Node* m_prev;	// Pointer points to the previous node

};

#endif //_NODE_H