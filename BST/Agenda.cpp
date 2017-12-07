#include "stdafx.h"
#include "Agenda.h"

#include <iostream>
using namespace std;

Agenda::Agenda()
{
	this->indiceApellido = new BSTClass<string, list<Persona*>*>();
	this->indiceTelefono = new BSTClass<int, Persona*>();
}


Agenda::~Agenda()
{
	delete indiceApellido;
	delete indiceTelefono;
}

void Agenda::agregarPersona(Persona* persona)
{
	list<Persona*>* lista = new list<Persona*>();

	if (indiceApellido->tryGet(persona->getApellido(), lista)) {
		lista->push_back(persona);
		this->indiceApellido->addOrUpdate(persona->getApellido(), lista);
	}
	else {
		lista = new list<Persona*>();
		lista->push_back(persona);
		this->indiceApellido->addOrUpdate(persona->getApellido(), lista);
	}

	this->indiceTelefono->addOrUpdate(persona->getTelefono(), persona);
	
}

list<Persona*>* Agenda::buscarPorApellido(string apellido)
{
	list<Persona*>* listaPersonas;
	
	if (this->indiceApellido->tryGet(apellido, listaPersonas)) {
		return listaPersonas;
	}
	else{ throw std::invalid_argument("no hay personas con el apellido: " + apellido); }

}

Persona* Agenda::buscarPorTelefono(int telefono)
{
	Persona* persona;
	
	if (this -> indiceTelefono -> tryGet(telefono, persona)) {
		return persona;
	}
	else{ throw std::invalid_argument("no hay personas con el telefono: " + telefono); }
}


