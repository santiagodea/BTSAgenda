#include "stdafx.h"
#include "BSTClass.h"
#include <iostream>
using namespace std;

template<class Tkey, class Tvalue>
BSTClass<Tkey, Tvalue>::BSTClass()
{
	this->Lenght = 0;
	this->root = NULL;
}

template<class Tkey, class Tvalue>
BSTClass<Tkey, Tvalue>::~BSTClass()
{
	delete root;
}

template<class Tkey, class Tvalue>
void BSTClass<Tkey, Tvalue>::addOrUpdate(Tkey key, Tvalue value)
{
	root = this->addOrUpdateint(root, key, value);
	
}

template<class Tkey, class Tvalue>
bool BSTClass<Tkey, Tvalue>::tryGet(Tkey key, Tvalue& value) 
{
	return this->tryGetInt(root, key, value);
}


template<class Tkey, class Tvalue>
bool BSTClass<Tkey, Tvalue>::tryGetInt(TNode<Tkey, Tvalue>* node, Tkey key, Tvalue& value)
{
	if (node == NULL) {
		return false;
	}
	else {
		if (key == node->getKey())
		{
			value = node->getValue();
			return true;
		}
		else {
			if (key < node->getKey()) {
				this->tryGetInt(node->get_Left(), key, value);
			}
			else { this->tryGetInt(node->get_Right(), key, value); }
		}
	}
}




template<class Tkey, class Tvalue>
bool BSTClass<Tkey, Tvalue>::isEmpty()
{
	return (this->root == NULL);
}

template<class Tkey, class Tvalue>
int BSTClass<Tkey, Tvalue>::getLenght()
{
	return Lenght;
}

template<class Tkey, class Tvalue>
void BSTClass<Tkey, Tvalue>::setLenght(int value)
{
	Lenght = value;
}

template<class Tkey, class Tvalue>
TNode<Tkey, Tvalue>* BSTClass<Tkey, Tvalue>::addOrUpdateint(TNode<Tkey, Tvalue>* node, Tkey key, Tvalue value)
{
	if (node == NULL) {
		node = new TNode<Tkey, Tvalue>(key, value);
		this->setLenght(this->getLenght() + 1);
		return node;
	}
	else {
		if (key == node->getKey()) {
			node->setValue(value);
		}
		else {
			if (key < node->getKey())
			{
				node->set_Left(this->addOrUpdateint(node->get_Left(), key, value));
			}
			else { node->set_Right(this->addOrUpdateint(node->get_Right(), key, value)); }
		}
		return node;
	}
}

	template<class Tkey, class Tvalue>
	void BSTClass<Tkey, Tvalue>::deleteKey(Tkey key)
	{
		this -> deleteInt(key, root);
	}

template<class Tkey, class Tvalue>
TNode<Tkey, Tvalue>* BSTClass<Tkey, Tvalue>::deleteInt(Tkey key, TNode<Tkey, Tvalue>* node)
{
	if (node->getKey() == key) {
		if ((node->get_Left() == NULL) && (node->get_Right() == NULL)) {
			delete node;
			return NULL;
		}
		else {
			if (node->get_Left() == NULL && node->get_Right() != NULL) {
				return node->get_Left();
			}
			else {
				if (node->get_Right() == NULL && node->get_Left() != NULL) {
					return node->get_Right();
				}
				else {
					//caso en el que tiene ambos hijos
					//busco a la derecha, el valor mas chico y lo devuelvo.
					//luego borro el valor buscado (recursivamente) con deleteKey 
					TNode<Tkey, Tvalue>* nodeAux;

					nodeAux = buscarReemplazante(node->get_Right());

					this->deleteInt(nodeAux->getKey(), node->get_Right());

					node->setKey(nodeAux->getKey());
					node->setValue(nodeAux->getValue());
					return node;
				}
			}
		}
	}
	else {
		if (node->getKey() > key) {
			node->set_Left(deleteInt(key, node->get_Left()));
		}
		else {
			node->set_Right(deleteInt(key, node->get_Right()));
		}
		return NULL;
	}
	}

template<class Tkey, class Tvalue>
TNode<Tkey, Tvalue>* BSTClass<Tkey, Tvalue>::buscarReemplazante(TNode<Tkey, Tvalue>* node)
{	
	TNode<Tkey, Tvalue>* nodeAux = NULL;

	if (node->get_Left() == NULL) {
		nodeAux->setKey(node->getKey());
		nodeAux->setValue(node->getValue());
		return nodeAux;
	}
	else {
		this->buscarReemplazante(node->get_Left());
	}
}

