#include "BigVector.h"
     
BigVector::BigVector() { }

double BigVector::valorDe(const unsigned long i) const {
	
	double valorDicc = 0;
	DiccionarioHash<unsigned int, double>::ConstIterator iterDicc = diccionarioVectorDisperso.cbusca(i);
	DiccionarioHash<unsigned int, double>::ConstIterator iterDiccFin = diccionarioVectorDisperso.cend();

	if (iterDicc != iterDiccFin) {

		valorDicc = iterDicc.valor();
	}

	return valorDicc;
} 

void BigVector::ponValor(unsigned long i, double v) {

	diccionarioVectorDisperso.inserta(i, v);
}  

double BigVector::productoEscalar(const BigVector& v) const {

	double prodEscalar = 0;
	DiccionarioHash<unsigned int, double>::ConstIterator iterDiccV = v.diccionarioVectorDisperso.cbegin();
	DiccionarioHash<unsigned int, double>::ConstIterator iterDicc = diccionarioVectorDisperso.cbegin();
	DiccionarioHash<unsigned int, double>::ConstIterator iterDiccFin = diccionarioVectorDisperso.cend();
	
	while (iterDicc != iterDiccFin && iterDicc != iterDiccFin) {

		if (iterDicc.clave() == iterDiccV.clave()) {

			prodEscalar += v.valorDe(iterDiccV.clave()) * valorDe(iterDicc.clave());
		}

		iterDicc.next();
		iterDiccV.next();
	}
	return prodEscalar;
}