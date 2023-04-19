#include "CException.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

/* Constructeur par defaut

	@brief constructeur par defaut initialisant les attibuts a null

	@param aucun

	@return rien
*/
CException::CException()
{
	uiEXCCodeErreurs = 0;
	sEXCErreurs[500] = NULL;
}

/* Constructeur de confort

	@brief construit un objet Exception auquel est attribue un message d'erreur

	@param unisgned int uiArg : numero de l'erreur

	@param const char sArg[500] : une chaine de caracteres contenant le message d'erreur

	@return rien
*/
CException::CException(unsigned int uiEXCArg, const char sEXCArg[500])
{
	uiEXCCodeErreurs = uiEXCArg;
	strcpy_s(sEXCErreurs, 500, sEXCArg);
}

/*Destructeur

	@brief detruit l'objet

	@param rien

	@return rien
*/
CException::~CException()
{

}

/* Affichage de l'erreur

	@brief accesseur en lecture pour la variable sEXCErreurs

	@param rien

	@return rien
*/
void CException::EXCAfficherErreur()
{
	std::cout << sEXCErreurs << "\n\n";
}

/* Affiche le code erreur

	@brief : accesseur en lecture pour la variable uiEXCCodeErreurs

	@param : rien

	@return : code erreur
*/
unsigned int CException::EXCLireValeur()
{
	return uiEXCCodeErreurs;
}