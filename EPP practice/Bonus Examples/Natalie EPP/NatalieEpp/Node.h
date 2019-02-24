#pragma once
#include <string>
#include <iostream>
#include "stdafx.h"
using namespace std;


class Node 
{
public:
	Node()
	{
	}
	~Node() 
	{
	}


	int data;
	Node * nextptr = NULL;

	void insertNode(int num);
	void deleteNode(int num);

private:
	Node * head = NULL;
};
