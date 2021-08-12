#include "ParqueNatural.h"

/*
COMPLEJIDAD

O(1)
*/
ParqueNatural::ParqueNatural() {}

/*
COMPLEJIDAD

O(1)
Búsqueda en un diccionarioHash es constante
Insertar en un diccionarioHash es constante
*/
void ParqueNatural::an_ecosistema(const string& ecosistema) {

	if (_diccionarioHashParque.contiene(ecosistema)) {
	
		throw EEcosistemaDuplicado();
	}

	Lista<string> l;
	DiccionarioHash<string, int> d;
	Ecosistema e(l, d);

	_diccionarioHashParque.inserta(ecosistema, e);
}

/*
COMPLEJIDAD

O(1)
Búsqueda en diccionarioHash es constante
Asignación ConstIterator final diccionario es constante
Modificar valor diccionarioHash es constante
Añadir nuevo elemento al diccionarioHash es constante
Añadir nuevo elemto a la lista es constante porque se usan nodos, y este se guarda internamente en el tad
*/
void ParqueNatural::an_ejemplares(const string& ecosistema, const string& especie, int n) {

	DiccionarioHash<string, Ecosistema>::Iterator itereco = _diccionarioHashParque.busca(ecosistema);

	if (itereco == _diccionarioHashParque.end()) {
		
		throw EEcosistemaNoExiste();
	}

	DiccionarioHash<string, int>::Iterator iteresp = itereco.valor()._especiesEcosistema.busca(especie);

	if (iteresp == itereco.valor()._especiesEcosistema.end()) {
	
		itereco.valor()._ultimasEspecies.pon_ppio(especie);
		itereco.valor()._especiesEcosistema.inserta(especie, n);
	}

	else {
	
		iteresp.setVal(iteresp.valor() + n);
	}

	Diccionario<string, int>::Iterator iternumesp = _especiesNumero.busca(especie);

	if (iternumesp == _especiesNumero.end()) {
	
		_especiesNumero.inserta(especie, n);
	}

	else {

		iternumesp.setVal(iternumesp.valor() + n);
	}
}

/*
COMPLEJIDAD

O(n)
Búsqueda en diccionarioHash es constante
Añadir elemeto al final de la lista es constante porque se guarda el índice (el tad guarda internamente el nodo)

Recorrer lista es lineal(peor caso)
Asignación ConstIterator final diccionarioHash es constante
Asignación ConstIterator final lista es constante
Asignación valor es constante
*/
Lista<string> ParqueNatural::lista_especies_ecosistema(const string& ecosistema, int n) const {

	DiccionarioHash<string, Ecosistema>::ConstIterator itereco = _diccionarioHashParque.cbusca(ecosistema);

	if (itereco == _diccionarioHashParque.cend()) {
	
		throw EEcosistemaNoExiste();
	}
	
	Lista<string>::ConstIterator iterLista = itereco.valor()._ultimasEspecies.cbegin();
	Lista<string>::ConstIterator finLista = itereco.valor()._ultimasEspecies.cend();

	Lista<string> listaUlt;
	int i = 0;

	while (iterLista != finLista && i < n) {

		listaUlt.pon_final(iterLista.elem());

		iterLista.next();
		i++;
	}
	
	return listaUlt;
}

/*
COMPLEJIDAD

O(1)
Búsqueda en diccionarioHash es constante
Asignación ConstIterator final diccionario es constante
Asignación valor es constante
*/
int ParqueNatural::numero_ejemplares_en_ecosistema(const string& ecosistema, const string& especie) const {

	int numEjemplarEco = 0;

	DiccionarioHash<string, Ecosistema>::ConstIterator itereco = _diccionarioHashParque.cbusca(ecosistema);

	if (itereco == _diccionarioHashParque.cend()) {

		throw EEcosistemaNoExiste();
	}

	else {

		DiccionarioHash<string, int>::ConstIterator iterEspecie = itereco.valor()._especiesEcosistema.cbusca(especie);

		if (iterEspecie != itereco.valor()._especiesEcosistema.cend()) {

			numEjemplarEco = iterEspecie.valor();
		}
	}

	return numEjemplarEco;
}

/*
COMPLEJIDAD

O(log(n))
Búsqueda en diccionario es logarítmica
Asignación ConstIterator final diccionario es constante
Asignación valor es constante
*/
Lista<string> ParqueNatural::lista_especies_parque() const {

	Lista<string> listaEspeciesParque;

	Diccionario<string, int>::ConstIterator iterEspecie = _especiesNumero.cbegin();
	Diccionario<string, int>::ConstIterator finEspecie = _especiesNumero.cend();

	while (iterEspecie != finEspecie) {

		listaEspeciesParque.pon_final(iterEspecie.clave());

		iterEspecie.next();
	}

	return listaEspeciesParque;
}

/*
COMPLEJIDAD

O(log(n))
Búsqueda en diccionario es logarítmica
Asignación valor es constante
*/
int ParqueNatural::numero_ejemplares_en_parque(const string& especie) const {

	int numEjemplarEspecieParq = 0;

	Diccionario<string, int>::ConstIterator iterEspecie = _especiesNumero.cbusca(especie);

	if (iterEspecie != _especiesNumero.cend()) {
		
		numEjemplarEspecieParq = iterEspecie.valor();
	}

	return numEjemplarEspecieParq;
}