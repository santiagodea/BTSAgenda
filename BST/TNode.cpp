#include "stdafx.h"
#include "TNode.h"
#include <iostream>
using namespace std;

template<class Tkey, class Tvalue>
TNode<Tkey, Tvalue>::TNode(Tkey key, Tvalue value)
{
	this->key = key;
	this->value = value;
	this->_Left = NULL;
	this->_Right = NULL;
}

template<class Tkey, class Tvalue>
TNode<Tkey, Tvalue>::~TNode(){
	delete _Left;
	delete _Right;

}

template<class Tkey, class Tvalue>
bool TNode<Tkey, Tvalue>::tryGet(Tkey key, Tvalue & value)
{
	return false;
}
 
template<class Tkey, class Tvalue>
void TNode<Tkey, Tvalue>::setKey(Tkey aKey)
{
	this->key = aKey;
}

template<class Tkey, class Tvalue>
Tkey TNode<Tkey, Tvalue>::getKey()
{
	return this->key;
}

template<class Tkey, class Tvalue>
void TNode<Tkey, Tvalue>::setValue(Tvalue aValue)
{
	this->value = aValue;
}

template<class Tkey, class Tvalue>
Tvalue TNode<Tkey, Tvalue>::getValue()
{
	return this->value;
}

template<class Tkey, class Tvalue>
void TNode<Tkey, Tvalue>::set_Left(TNode<Tkey, Tvalue>* node)
{
	this->_Left = node;
}

template<class Tkey, class Tvalue>
TNode<Tkey, Tvalue>* TNode<Tkey, Tvalue>::get_Left()
{
	return this->_Left;
}

template<class Tkey, class Tvalue>
void TNode<Tkey, Tvalue>::set_Right(TNode<Tkey, Tvalue>* node)
{
	this->_Right = node;
}

template<class Tkey, class Tvalue>
TNode<Tkey, Tvalue>* TNode<Tkey, Tvalue>::get_Right()
{
	return this->_Right;
}
