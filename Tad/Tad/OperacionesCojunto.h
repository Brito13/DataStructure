#pragma once
#include "TAD.h"
#include <iostream>
#include <fstream>
class OperacionesCojuntos
{
	TAD tad;
	TAD Union(TAD elemento) {
		for (int i = 0; i < elemento.cantidadElementos; i++)
		{
			tad.Alta(elemento.datos[i]);
		}
		for (int i = 0; i < elemento.cantidadElementos; i++)
		{
			tad.Alta(elemento.datos[i]);
		}
		return tad;
	}

	TAD unionDistinct( TAD elemto) {
		
	}
};

