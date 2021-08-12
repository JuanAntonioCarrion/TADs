#ifndef _PARQUE_NATURAL_H
#define _PARQUE_NATURAL_H

#include "diccionario.h"
#include "lista.h"
#include "DiccionarioHash.h"
#include <string>
using namespace std;

/*
Excepciones levantadas por las operaciones
*/
class EEcosistemaDuplicado {};
class EEcosistemaNoExiste {};

class ParqueNatural {
public:
	ParqueNatural();
	void an_ecosistema(const string& ecosistema);
	void an_ejemplares(const string& ecosistema, const string& especie, int n);
	Lista<string> lista_especies_ecosistema(const string& ecosistema, int n) const;
	int numero_ejemplares_en_ecosistema(const string& ecosistema, const string& especie) const;
	Lista<string> lista_especies_parque() const;
	int numero_ejemplares_en_parque(const string& especie) const;

private:
	/* Incluir los detalles de representación que se consideren oportunos */
	/*class Especie {
	string _nombreEspecie;
	int _nEjemplares;
	Especie(string nombreEspecie, int nEjemplares) {
	_nombreEspecie = nombreEspecie;
	_nEjemplares = nEjemplares;
	}
	};*/

	class Ecosistema {
	public:
		Lista <string> _ultimasEspecies;
		DiccionarioHash<string, int> _especiesEcosistema;
	
		Ecosistema(const Lista <string> &ultimasEspecies, const DiccionarioHash<string, int> &especiesEcosistema) {
			_ultimasEspecies = ultimasEspecies;
			_especiesEcosistema = especiesEcosistema;
		}
	};

	DiccionarioHash<string, Ecosistema> _diccionarioHashParque;
	Diccionario<string, int> _especiesNumero;
};

#endif