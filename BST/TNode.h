#pragma once
#include <iostream>
using namespace std;
template <class Tkey, class Tvalue>
class TNode
{
public:
	TNode(Tkey key, Tvalue value);
	~TNode();


	//bool addOrUpdate(TNode <Tkey, Tvalue>* Node );
	bool tryGet(Tkey key, Tvalue& value);

	//setters & getters

	void setKey(Tkey aKey);
	Tkey getKey();

	void setValue(Tvalue aValue);
	Tvalue getValue();

	void set_Left(TNode<Tkey, Tvalue>* node);
	TNode<Tkey,Tvalue>* get_Left();

	void set_Right(TNode<Tkey, Tvalue>* node);
	TNode<Tkey,Tvalue>* get_Right();

private:
	Tkey key;
	Tvalue value;
	TNode<Tkey, Tvalue>* _Left;
	TNode<Tkey, Tvalue>* _Right;
};





