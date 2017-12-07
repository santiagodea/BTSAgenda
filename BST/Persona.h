#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;

class Persona
{
public:
	Persona(string nombre, string apellido, string direccion, int tel);
	~Persona();

	void setNombre(string nombre);
	string getNombre();
	void setApellido(string apellido);
	string getApellido();
	void setDireccion(string direccion);
	string getDireccion();
	void setTelefono(int tel);
	int getTelefono();

private:
	string nombre;
	string apellido;
	string direccion;
	int telefono;

};

