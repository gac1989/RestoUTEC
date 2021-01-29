#include "CantidadProd.h"
#include "Menu.cpp"
#ifndef CANTIDADPROD_CPP
#define CANTIDADPROD_CPP

CantidadProd::CantidadProd(int cantidad, Producto * p){
	if(p==NULL){
		throw "Se esperaba un producto";
	}
	this->cantidad = cantidad;
	this->producto=p;
}

bool CantidadProd::coincideProd(Producto * p){
	return this->producto==p;
}

void CantidadProd::sumarCantidad(int cantProd){
	this->cantidad+=cantProd;
}

void CantidadProd::restarCantidad(int cantProd){
	this->cantidad-=cantProd;
}

Producto * CantidadProd::getProducto(){
	return this->producto;
}

DtProducto * CantidadProd::getDtProducto(){
	DtProducto * dp = this->producto->getDatos();
	dp->setCantidad(this->cantidad);
	return dp;
}

bool CantidadProd::esMenu(){
	Menu * m = dynamic_cast<Menu*>(this->producto);
	return (m!=NULL);
}

int CantidadProd::getCantidadRestada(int cantProd){
	return this->cantidad-cantProd;
}

int CantidadProd::getCantidad(){
	return this->cantidad;
}

CantidadProd::~CantidadProd(){
	
}


#endif
