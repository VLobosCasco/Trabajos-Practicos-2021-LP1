﻿#pragma once
#define NMAX 20
#include <string>
#include <iostream>
using namespace std;
template<class T>
class cListaT
{
protected:
	T** vector;
	unsigned int CA, TAM;
	void Redimensionalizar();
	bool eliminar_lista;

public:
	cListaT(unsigned int TAM = NMAX, bool eliminar_lista = true);
	~cListaT();

	bool AgregarItem(T *item);
	void operator+(T * item);

	T* Quitar(string clave);
	T* Quitar(const T *item);
	T* QuitarenPos(unsigned int pos);

	void Eliminar(string clave);
	void Eliminar(const T *item);
	void operator-(const T *item);
	void Eliminar(unsigned int pos);

	void Listar();
	T* BuscarItem(string clave);
	T* operator [](unsigned int pos);
	T* getItem(unsigned int pos);
	string To_String();

	unsigned int getItemPos(string clave);
	unsigned int getCA();
	unsigned int getTAM();
	friend ostream& operator<<(ostream& os, const cListaT<T>& Lista);
};

template<class T>
unsigned int cListaT<T>::getTAM()
{
	return TAM;
}

template<class T>
unsigned int cListaT<T>::getCA()
{
	return CA;
}

template<class T>
void cListaT<T>::Redimensionalizar()
{
	TAM += 10;
	T** aux = new T * [TAM];

	for (int i = 0; i < TAM; i++) 
	{
		if (i < CA)
			aux[i] = vector[i];
		aux[i] = NULL;
	}

	delete[] vector;

	vector = aux;

}

template<class T>

cListaT<T>::cListaT(unsigned int TAM, bool eliminar_lista)
{
	vector = new T*[TAM];
	for (unsigned int i = 0; i < TAM; i++)
		vector[i] = NULL;

	this->TAM = TAM;
	this->eliminar_lista = eliminar_lista;
	CA = 0;
}

template<class T>
cListaT<T>::~cListaT()
{
	if (vector != NULL)
	{
		if (eliminar_lista) {
			for (unsigned int i = 0; i < CA; i++)
			{
				if (vector[i] != NULL)
					delete vector[i];
			}
		}

		delete[] vector;
	}
}

template<class T>
void cListaT<T>::Listar()
{
	for (unsigned int i = 0; i < CA; i++)
		vector[i]->Imprimir();// imprimir
}

template<class T>
bool cListaT<T>::AgregarItem(T * item)
{
	T *i_f = BuscarItem(item->getclave());
	if (i_f != NULL)
		throw new exception("Ya se encuentra en la lista");

	if (CA < TAM)
		vector[CA++] = item;
	else
		throw new exception("No hay tamaño suficiente para agregar el item");
	return true;
}


template<class T>
T* cListaT<T>::Quitar(string clave) 
{
	unsigned int pos = getItemPos(clave);
	T* aux = NULL;

	aux = QuitarenPos(pos);
	return aux;
}

template<class T>
T* cListaT<T>::Quitar(const T *item) 
{
	unsigned int pos = getItemPos(item->getclave());
	if (pos >= CA)
		return NULL;

	T* aux = NULL;
	aux = QuitarenPos(pos);

	return aux;
}

template<class T>
T* cListaT<T>::QuitarenPos(unsigned int pos) {

	if (pos >= CA||pos<0)
		throw new exception("Posicion invalida");

	T *aux = vector[pos];

	for (unsigned int i = pos; i < CA - 1; i++)
		vector[i] = vector[i + 1];

	vector[CA - 1] = NULL;
	CA--;

	return aux;
}


template<class T>
void cListaT<T>::Eliminar(string clave) {

	unsigned int pos = getItemPos(clave);
	Eliminar(pos);
}

template<class T>
void cListaT<T>::Eliminar(const T *item) {

	Eliminar(item->getclave());
}

template<class T>
void cListaT<T>::Eliminar(unsigned int pos) {
	
	T* dato = NULL;
	dato = QuitarenPos(pos);

	if(dato != NULL)
		delete dato;
}

template<class T>
T* cListaT<T>::BuscarItem(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getclave() == clave)	//SOBRECARGA!!!!!!
			return vector[i];
	}
	return NULL;
}

template<class T>
T* cListaT<T>::getItem(unsigned int pos)
{
	if (pos < CA && pos>=0)
		return vector[pos];
	else 
		throw new exception("Posición inválida");
}

template<class T>
string cListaT<T>::To_String()
{
	string Total;
	for (unsigned int i = 0; i < CA; i++)
	{
		Total+= vector[i]->To_string();// imprimir
	}
	return Total;
}

template<class T>
unsigned int cListaT<T>::getItemPos(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		string comp = vector[i]->getclave();
		if (comp == clave)
			return i;
	}
	return -1;
}


template <class T>
void cListaT<T>::operator+(T * item) 
{
	AgregarItem(item);
}

template<class T>
inline T * cListaT<T>::operator[](unsigned int pos)
{
	return getItem(pos);
}

template<class T>
void cListaT<T>::operator -(const T *item) 
{
	Eliminar(item);
}

template <class T>

void operator<<(ostream& os, const cListaT<T>& Lista)
{
	for(int i = 0; i < Lista.CA ; i++)
		os << Lista.vector[i].To_string() << endl;
}
