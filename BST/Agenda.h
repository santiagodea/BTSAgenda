#pragma once
#include "Persona.h"
#include "BSTClass.cpp"
#include <list>

class Agenda
{
public:
	Agenda();
	~Agenda();

	void agregarPersona(Persona* persona);

	list<Persona*>* buscarPorApellido(string apellido);
	Persona* buscarPorTelefono(int Telefono);
	//void eliminarPersona(Persona persona*);

private:
	BSTClass<string, list<Persona*>*>* indiceApellido;
	BSTClass<int, Persona*>* indiceTelefono;
};

