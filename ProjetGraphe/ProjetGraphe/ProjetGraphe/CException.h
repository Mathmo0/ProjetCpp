#ifndef __EXC__
#define __EXC__

//Outils pour les verifier les fuites memoires
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

class CException 
{
	
private:
	/*----------Attributs----------*/
	unsigned int uiEXCCodeErreurs; //Code d'erreur
	char sEXCErreurs[500]; //Chaine de caracteres contenant un message d'erreur

	 
public:
	/*----------Constructeurs et deconstructeurs----------*/

	/* Constructeur par defaut
		 @brief constructeur par defaut initialisant les attibuts a null

		 @param aucun

		 @return rien
	*/
	CException(); 

	/* Constructeur de confort

		@brief construit un objet Exception auquel est attribue un message d'erreur

		@param unisgned int uiArg : numero de l'erreur

		@param const char sArg[500] : une chaine de caracteres contenant le message d'erreur

		@return rien
	*/
	CException(unsigned int uiArg, const char sArg[500]); 

	/*Destructeur

	@brief detruit l'objet

	@param rien

	@return rien
	*/
	~CException();

	
public:
	/*----------Methodes----------*/

	/* Affichage de l'erreur
		@brief accesseur en lecture pour la variable sEXCErreurs

		@param rien

		@return rien
	*/
	void EXCAfficherErreur();

	/* Affiche le code erreur

	@brief : accesseur en lecture pour la variable uiEXCCodeErreurs 

	@param : rien

	@return : code erreur
	*/
	unsigned int EXCLireValeur();
};

#endif