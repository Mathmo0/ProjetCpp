
#ifndef __LMAT__
#define __LMAT__


#include "CMatrice.h"

#define EXCIndice 2

//Outils pour les fuites memoires
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif


template <class TTypeMatrice> class CListeMatrice
{

	//Attribus :
private:
	unsigned int uiLMTTailleListe; //Taille du tableau d'objet
	CMatrice<TTypeMatrice> * LMTTableau; //Tableau d'objet de type CMatrice<TTypeMatrice>

	//Constructeurs et deconstructeurs :
public:

	/*  Constructeur par defaut :
	@brief : initialise les attributs a nulle ou 0

	@param : aucun

	@return : rien
*/
	CListeMatrice<TTypeMatrice>();

	/* Constructeur de confort :
		@brief :  permet de construire une liste d'objet de type CMatrice<TTypeMatrice>

		@param unsigned int uiArg : Taille de la liste, la valeur par defaut est 1

		@return : rien
*/
	CListeMatrice<TTypeMatrice>(unsigned int uiArg = 1);

	/*Deconstructeur :
	@brief : Detruit l'objet en supprimmant la liste d'objet

	@param : rien

	@return : rien
*/
	~CListeMatrice<TTypeMatrice>();

	//Methodes :
public:
	
	/**
		@brief : Surcharge de l'operateur []  pour permettre de retourner la matrice de la liste a la position voulu

		@param  unsigned int uiArg: un entier naturel qui correspond a la position dans la liste

		@return CMatrice<TTypeMatrice> : Une matrice de type TTypeMatrice
	*/
	CMatrice<TTypeMatrice> & operator[](unsigned int uiArg);

};
#include "CListeMatrice.cpp"

#endif 
