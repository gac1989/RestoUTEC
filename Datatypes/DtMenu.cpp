#include<iostream>
#include "DtMenu.h"
#ifndef DTMENU_CPP
#define DTMENU_CPP

using namespace std;

DtMenu::DtMenu(int codigo, string descripcion, float precio,int cantidad, string tipo, ICollection * componentes):DtProducto(codigo, descripcion, precio,cantidad, tipo){
	this->componentes=componentes;
}

ICollection * DtMenu::getComponentes(){
	return this->componentes;
}

DtMenu::~DtMenu(){
	IIterator * it = this->componentes->getIterator();
	while(it->hasCurrent()){
		DtProducto * dp = (DtProducto*)it->getCurrent();
		it->next();
		this->componentes->remove(dp);
		delete dp;
	}
	delete it;
	delete this->componentes;
}

#endif
