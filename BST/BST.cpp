// BST.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Agenda.h"
#include <list>

#include <iostream>
using namespace std;



int main()

{

	BSTClass<int, int>* arbol = new BSTClass<int,int>();
	int variable = 900;
	int variable2 = 800;
	arbol->addOrUpdate(5,100);
	arbol->addOrUpdate(6,200);
	arbol->addOrUpdate(3,300);
	arbol->addOrUpdate(3, 900);

	arbol->tryGet(3, variable);
	arbol->tryGet(3, variable2);
	arbol->tryGet(2, variable2);
	//PROBAR LOS CASOS LIMITES!
	arbol->deleteKey(6);

	Persona* juan = new Persona("juan", "perez", "soler 28", 2);
	Persona* roberto = new Persona("roberto", "gomez", "rivadavia 25", 3);
	Persona* jose = new Persona("jose", "perez", "27", 1);
	
	Agenda* agenda = new Agenda();

	agenda->agregarPersona(juan);
	agenda->agregarPersona(roberto);
	agenda->agregarPersona(jose);


	Persona* personaBuscarda = agenda->buscarPorTelefono(2);

	list<Persona*>* personasBuscadas = agenda -> buscarPorApellido("perez");


}

