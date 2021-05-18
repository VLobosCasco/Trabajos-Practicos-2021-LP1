﻿
#if !defined(EA_B9741D49_13D8_46c1_8B11_F0F70B4304B8__INCLUDED_)
#define EA_B9741D49_13D8_46c1_8B11_F0F70B4304B8__INCLUDED_
#define NMAX 10000
#include <string>
using namespace std;
template<class T>
class cListaT
{
protected:
	T * *vector;
	unsigned int CA, TAM;
	void Redimensionalizar();

public:
	cListaT(unsigned int TAM = NMAX);
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


	unsigned int getItemPos(string clave);
	unsigned int getMinimo;
	unsigned int getCA();
	unsigned int getTAM();
	T** getvector();
};

template<class T>
unsigned int cListaT<T>::getTAM()
{
	return TAM;
}

template<class T>
inline T ** cListaT<T>::getvector()
{
	return vector;
}

template<class T>
unsigned int cListaT<T>::getCA()
{
	return CA;
}

template<class T>
void cListaT<T>::Redimensionalizar()
{
}

template<class T>

cListaT<T>::cListaT(unsigned int TAM)
{
	vector = new T*[TAM];
	for (unsigned int i = 0; i < TAM; i++)
	{
		vector[i] = NULL;
	}

	this->TAM = TAM;
	CA = 0;


}

template<class T>
cListaT<T>::~cListaT()
{
	if (vector != NULL)
	{
		for (unsigned int i = 0; i < CA; i++)
		{
			if (vector[i] != NULL)
				delete vector[i];
		}
		delete[] vector;
	}
}

template<class T>
void cListaT<T>::Listar()
{

	for (unsigned int i = 0; i < CA; i++)
	{
		vector[i]->Imprimir();// imprimir
	}
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
T* cListaT<T>::Quitar(string clave) {

	unsigned int pos = getItemPos(clave);
	T* aux = NULL;
	try {
		aux = QuitarenPos(pos);
	}
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		ex = new exception(("Error en Quitar: " + error).c_str());
		throw ex;
	}
	return aux;

}

template<class T>
T* cListaT<T>::Quitar(const T *item) {
	unsigned int pos = getItemPos(item->getclave());
	if (pos >= CA)return NULL;
	T* aux = NULL;
	try {
		aux = QuitarenPos(pos);
	}
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		ex = new exception(("Error en Quitar: " + error).c_str());
		throw ex;
	}
	return aux;
}

template<class T>
T* cListaT<T>::QuitarenPos(unsigned int pos) {

	if (pos >= CA||pos<0)
		throw new exception("Posicion invalida");

	T *aux = vector[pos];

	for (unsigned int i = pos; i < CA - 1; i++)
	{
		vector[i] = vector[i + 1];
	}

	vector[CA - 1] = NULL;
	CA--;
	return aux;
}


template<class T>
void cListaT<T>::Eliminar(string clave) {

	unsigned int pos = getItemPos(clave);

	if (pos < CA)
		Eliminar(pos);
	//sino algo

}

template<class T>
void cListaT<T>::Eliminar(const T *item) {

	try {
		Eliminar(item->getclave());
	}
	catch (exception* e)
	{
		throw e;
	}
}

template<class T>
void cListaT<T>::Eliminar(unsigned int pos) {
	
	T* dato = NULL;
	try {
		dato=QuitarenPos(pos);
	}
	catch (exception* e) {
		string error = e->what();
		delete e;
		e = new exception(("Error en Quitar pos: " + error).c_str());
		throw e;
	}

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
void cListaT<T>::operator+(T * item) {
	try {
		AgregarItem(item);
	}
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		ex = new exception(("Error en Agregar: " + error).c_str());
		throw ex;
	}
}

template<class T>
inline T * cListaT<T>::operator[](unsigned int pos)
{
	T* aux = NULL;
	try{
		aux = getItem(pos);
	}
	catch (exception* ex) {
		string error = ex->what();
		delete ex;
		ex = new exception(("Error en GetItem: " + error).c_str());
		throw ex;
	}
	return aux;
}

template<class T>
void cListaT<T>::operator -(const T *item) {
	try {
		Eliminar(item);
	}
	catch (exception* ex)
	{
		string error = ex->what();
		delete ex;
		ex = new exception(("Error en Eliminar:" + error).c_str());
		throw ex;

	}
}
