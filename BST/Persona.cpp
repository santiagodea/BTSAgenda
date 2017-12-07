#include "stdafx.h"
#include "Persona.h"

Persona::Persona(string nombre, string apellido, string direccion, int tel)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->direccion = direccion;
	this->telefono = tel;
}

Persona::~Persona()
{
}

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Persona::getNombre()
{
	return this->nombre;
}

void Persona::setApellido(string apellido)
{
	this->apellido = apellido;
}

string Persona::getApellido()
{
	return this->apellido;
}

void Persona::setDireccion(string direccion)
{
	this->direccion = direccion;
}

string Persona::getDireccion()
{
	return this->direccion;
}

void Persona::setTelefono(int tel)
{
	this->telefono = tel;
}

int Persona::getTelefono()
{
	return this->telefono;
}
