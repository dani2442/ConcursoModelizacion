#pragma once
#include <string>
#include <iostream>
#include <signal.h>
#include <stdlib.h>

class NumberToWord {
private:

	static std::string result;
	const static int MILLON, MIL, CIEN, DIEZ;
	const static std::string numeros[],dieces[],decenas[],centenas[],millares_[];
	
	static const std::string& enletras(int indice1, int indice2) {
		switch(indice2) {
		case 0: return numeros[indice1];
		case 1: return dieces[indice1];
		case 2: return decenas[indice1];
		case 3: return centenas[indice1];
		}
		return millares_[indice1];
	}

	static void millares(const int a_numerode, const int indice) {

		int indice2=0, indice3=0;

		if(indice == 0) indice3 = 0;
		else {indice2 = 2; indice3 = 1;}
		if(a_numerode > 1) result+= " " + enletras(indice2,4);
		else result+= enletras(0,0) + " " + enletras(indice3,4);
	}

	static void i_enletras(const long a_numerode) {
		if(a_numerode == 1) result+=" "+enletras(a_numerode,0);
		else if(a_numerode > 1 && a_numerode < 10) result+=" "+enletras(a_numerode,0);
		else if(a_numerode > 10 && a_numerode < 20) result+=" "+enletras(a_numerode % DIEZ - 1,1);
		else if((a_numerode % DIEZ) == 0 && a_numerode < CIEN) result+=" "+enletras((a_numerode/DIEZ)-1,2);
		else if((a_numerode % CIEN) == 0 && a_numerode < MIL) {
			result+=" "+enletras((a_numerode/CIEN)-1,3);
			if(a_numerode==100) result+="to ";
		}

		else if((a_numerode % MIL) == 0 && a_numerode < MILLON) millares(a_numerode / MIL,0);
		else if((a_numerode % MILLON) == 0) millares(a_numerode / MILLON,1);
	}

	static void residuo(long *cantidad, const long valor) {
		i_enletras(*cantidad-(*cantidad % valor));
		*cantidad = *cantidad % valor;
	}

	static void imprimir(long a_cantidad) {
		if(a_cantidad < 1 || a_cantidad > 2147483647) raise(SIGFPE); // Desbordamiento
		while(a_cantidad > 0) 
		{
			if(a_cantidad >= MILLON) {
				if(a_cantidad/MILLON > 1) {
					imprimir (a_cantidad/MILLON); 
				} 
			residuo(&a_cantidad, MILLON);
			}
			else if(a_cantidad >= MIL) {
				if(a_cantidad/MIL > 1) { 
					imprimir (a_cantidad/MIL); 
				} // --> Recursi¢n
				residuo(&a_cantidad, MIL);
			}
			else if(a_cantidad >= CIEN) {
				residuo(&a_cantidad, CIEN);
			}
			else if(a_cantidad == DIEZ || a_cantidad > 19) {
				residuo(&a_cantidad, DIEZ);
				if(a_cantidad > 0) result+=" y";
			}
			else residuo(&a_cantidad, a_cantidad);
		}
	}

public:
	static std::string calculate(long cantidad) { result = ""; imprimir(cantidad);	return result; }
};

std::string NumberToWord::result = "";
const int NumberToWord::DIEZ = 10;
const int NumberToWord::CIEN = 100;
const int NumberToWord::MIL = 1000;
const int NumberToWord::MILLON = 1000000;

const std::string NumberToWord::numeros[]={"un","uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
const std::string NumberToWord::dieces[]={"once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve"};
const std::string NumberToWord::decenas[]={"diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
const std::string NumberToWord::centenas[]={"cien", "doscientos", "trescientos", "cuatrocientos","quinientos", "seiscientos" ,"setecientos","ochocientos" ,"novecientos"};
const std::string NumberToWord::millares_[]={"mil", "millon", "millones"};



