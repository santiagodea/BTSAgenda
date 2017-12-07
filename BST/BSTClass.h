#pragma once
#include "TNode.cpp"
#include <iostream>
using namespace std;

template <class Tkey, class Tvalue>
class BSTClass
{
public:
	BSTClass();
	~BSTClass();

	void addOrUpdate(Tkey key, Tvalue value);
	//key nueva -> agrega
	//key existente -> cambia el valor
	bool tryGet(Tkey key, Tvalue& value);
	bool isEmpty();
	int getLenght();
	void setLenght(int value);
	
	void deleteKey(Tkey key);

	


private:

	TNode<Tkey, Tvalue>* addOrUpdateint(TNode<Tkey, Tvalue>* node, Tkey key, Tvalue value);
	TNode<Tkey, Tvalue>* deleteInt(Tkey key, TNode<Tkey, Tvalue>* node);
	TNode<Tkey, Tvalue>* buscarReemplazante(TNode<Tkey, Tvalue>* node);
	bool tryGetInt(TNode<Tkey, Tvalue>* node, Tkey key, Tvalue& value);
	TNode<Tkey, Tvalue>* root;
	int Lenght;

};

