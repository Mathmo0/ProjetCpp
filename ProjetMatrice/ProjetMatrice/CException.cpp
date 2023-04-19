#include "CException.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

/*Constructeur par defaut
	 @brief  constructeur par defaut initialisant les attibuts a null

	 @param : aucun

	 @return : rien
*/
CException::CException()
{
	uiEXCCodeErreurs = 0;
	sEXCErreurs[500] = NULL;
}

/*Constructeur de confort 

	@brief construit un objet Exception auquel est attribue un message d'erreur

	@param unisgned int uiEXCArg : numero de l'erreur

	@param const char sEXCArg[500] : une chaine de caracteres contenant le message d'erreur

	@return : rien
*/
CException::CException(unsigned int uiEXCArg, const char sEXCArg[500])
{
	uiEXCCodeErreurs = uiEXCArg;
	strcpy_s(sEXCErreurs, 500, sEXCArg);
}


/*Affichage de l'erreur
	@brief : Affiche le message d'erreur
	
	@param : rien

	@return : rien
*/
void CException::EXCAfficherErreur()
{
	std::cout << sEXCErreurs << "\n\n";
}

/*Affiche le code erreur

@brief : Affiche le code erreur

@param : rien

@return : code erreur
*/
unsigned int CException::EXCLireValeur()
{
	return uiEXCCodeErreurs;
}