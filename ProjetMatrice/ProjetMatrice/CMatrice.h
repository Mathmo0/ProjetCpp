#include <stdio.h>
#include <stdlib.h>
#include <istream>
#include <fstream>
#include <string.h>
#include "CException.h"

#ifndef __MAT__
#define __MAT__

// categorie exception dimension 

#define EXCDimensionMatrice 10 
#define EXCMatriceNULL 11

//categorie Valeur

#define EXCDivisionParZero 1
#define EXCIndice 2

//categorie exception fichier : 

#define EXCFormatFichier 21
#define EXCCheminFichier 22
#define EXCTypeMatriceDansFichier 23
#define EXCLectureMatriceDansFichier 24


	//Outils pour les fuites memoires
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

/**
 * @class La classe CMatrice permet de creer et manipuler des matrice
 * @author EDELINE Maxime
 * @author MOYSE Mathis
 */ 

template < class TTypeMatrice> class CMatrice
{
	//attribut : 
	
private : 

	unsigned int uiMATNbLigne;
	unsigned int uiMATNbColonne;
	TTypeMatrice ** pTMAMATMatrice;

	//contructeur et destructeur :  

public : 

		/** constructeur par defaut :
		 *
		 * @brief Constructeur permettant d'initialiser une matrice en mettant uiMATNbLigne = 0,uiMATNbColonne = 0 et pTMAMATMatrice = nullptr. 
		 * 
		 * @param aucun 
		 *
		 * @return rien 
		 */  
	CMatrice<TTypeMatrice>();
	
	/** constructeur par recopie :
	 *
	 * @brief Constructeur permettant de recopier une matrice dans une autre.
	 *
	 * @param CMatrice<TTypeMatrice> MATarg : Matrice de type TTypeMatrice, on utilise un passage par reference 
	 *
	 * @return : rien
	 */

	CMatrice<TTypeMatrice>(CMatrice<TTypeMatrice>  & MATarg);
	
	/** constructeur de confort :
	 *
	 * @brief Constructeur permettant d'initialiser une matrice avec un nombre de lignes et colonnes donnees.
	 *
	 * @param unsigned int uiNbLigne : entier naturel qui indique le nombre de lignes dans la matrice ,on utilise un passage par valeur
	 * @param unsigned int uiNbColonne : entier naturel qui indique le nombre de colonnes dans la matrice ,on utilise un passage par valeur
	 *
	 * @throws erreur Dimension : si une des dimension est egal a 0 
	 *
	 * @return : rien
	 */
	CMatrice<TTypeMatrice>(unsigned int uiNbLigne, unsigned int uiNbColonne);
	
	/*Constructeur d'une Matrice double a partir d'un fichier .txt
	
	@brief : creer une Matrice a partie d'un fichier texte
	
	@param char * sPath : chaine de caracteres du lien du fichier text

	@return : rien
	*/
	CMatrice<TTypeMatrice>(char * sPath);

	/** destructeur :
	 * 
	 * @brief  desalloue pTMAMATMatrice
	 *
	 * @param aucun 
	 *
	 * @return  rien
	 */
	~CMatrice<TTypeMatrice>();
	

	// methode : 
public : 

	/**
	 * @brief accesseur en lecture pour la variable uiMATNbLigne 

	   @param aucun

	   @return uiMATNbLigne : Nombre de lignes dans la matrice 
	 */
	unsigned int MATLireDimensionLigne();

	/**
	 * @brief accesseur en lecture pour la variable uiMATNbColonne

	   @param aucun 

	   @return uiMATNbColonne : Nombre de colonnes dans la matrice
	 */
	unsigned int MATLireDimensionColonne();

	/**
	 * @brief accesseur en ecriture pour la variable uiMATNbLigne
	   
	   @param unsigned int uiLigne : nouveaux nombre(s) de ligne(s) qu'on veut avoir dans la matrice, utilise un passage par valeur

	   @throw erreur dimension :  uiLigne = 0 
	 */
	void MATModifierDimensionLigne(unsigned int uiLigne);

	/**
	 * @brief accesseur en ecriture pour la variable uiMATNbColonne

	   @param unsigned int uiColonne : nouveaux nombre(s) de colonne(s) qu'on veut avoir dans la matrice, utilise un passage par valeur

	   @throw erreur dimension :  uiColonne = 0 ou uiMATNbLigne = 0
	   
	 */
	void MATModifierDimensionColonne(unsigned int uiColonne);
	
	/**
	 *  @brief Permet de changer la dimension des lignes et des colonnes de la matrice

		@param unsigned int uiLigne : nouveaux nombre(s) de ligne(s) qu'on veut avoir dans la matrice, si on met aucune valeur uiMATNbLigne est mise comme par valeur defaut

		@param unsigned int uiColonne : nouveaux nombre(s) de colonne(s) qu'on veut avoir dans la matrice, si on met aucune valeur uiMATNbColonne est mise comme par valeur defaut

	 */
	void MATModifierDimensionMatrice(unsigned int uiLigne = uiMATNbLigne, unsigned int uiColonne = uiMATNbColonne);

	/**

   @brief accesseur en lecture pour la variable pTMAMATMatrice

   @param aucun

   @return TTypeMatrice ** : un tableau a 2 dimension de type TTypeMatrice

	*/
	TTypeMatrice ** MATLireMatrice();

	/**
	 * @brief accesseur en ecriture permettant de modifier une valeur de la matrice a une position donnee

	   @param TTypeMatrice TMAValeur : valeur qu'on veut affecter dans la matrice, si aucune valeur est indique alors a la valeur par defaut est 0

	   @param unsigned int uiLigne : position de la ligne a laquelle on veut affecter TMAValeur, si aucune valeur est indique alors a la valeur par defaut est 0

	   @param unsigned int uiColonne : position de la colonne a laquelle on veut affecter TMAValeur, si aucune valeur est indique alors a la valeur par defaut est 0

	   @throw erreur indice 
	 */
	void MATModifierUneValeurDeLaMatrice(TTypeMatrice TMAValeur = 0, unsigned int uiLigne = 0, unsigned int uiColonne = 0);

	/**
	 * @brief accesseur en lecture permettant de lire une valeur de la matrice 

	   @param unsigned int uiLigne : position de la ligne a laquelle on veut lire la valeur 

	   @param unsigned int uiColonne : position de la colonne a laquelle on veut lire la valeur 

	   @throw erreur indice

	   @return une valeur du type generique TTypeMatrice 
	 */
	TTypeMatrice MATLireUneValeurDeLaMatrice(unsigned int uiLigne = 0, unsigned int uiColonne = 0);
	
	/**
	 * @brief Affhiche la matrice 

	   @throw matrice non initialise (pTMAMATMatrice = nullptr)

	 */
	void  MATAfficherMatrice();

	/**
	 * @brief initialise toute les valeurs de la matrice a 0 . Si la matrice est non initialise (pTMAMATMatrice = nullptr), la methode ne fait rien 
	 */
	void MATInitMatriceANulle();

	/*Modificateur de Matrice a partir d'un fichier

	@brief : Extrait une matrice d'un fichier dans une Matrice existante

	@param sPath : le chemin d'acces au fichier

<<<<<<< HEAD
	@return : rien
	*/
	void MATModifierMatriceExtract(char* sPath);

	/*surchage d'operateur : */

	/**
	 * @brief surcharge de l'operateur + pour permettre d'additioner  de 2 matrices 

	   @param CMatrice<TTypeMatrice> MATarg :  Matrice de type TTypeMatrice, passage par reference

	   @throw erreur Dimension : addtioner 2 matrices de dimension differentes 

	   @return CMatrice<TTypeMatrice> * :  pointeur sur une matrice de type TTypeMatrice representant le resultat de l'addition de 2 Matrice  
	 */ 
	CMatrice<TTypeMatrice> * operator+(CMatrice<TTypeMatrice> &  MATarg);

	/**
	 * @brief surcharge de l'operateur - pour permettre la soustraction 2 matrices

	   @param CMatrice<TTypeMatrice> MATarg : Matrice de type TTypeMatrice, passage par reference

	   @throw erreur Dimension : soustraire 2 matrices de dimension differentes

	   @return CMatrice<TTypeMatrice> * :  pointeur sur une matrice de type TTypeMatrice representant le resultat de la soustraction de 2 Matrice  
	 */
	CMatrice<TTypeMatrice> * operator-(CMatrice<TTypeMatrice> & MATarg);

	/**
	 * @brief surcharge de l'operateur * pour permettre de multiplier 2 matrices

	   @param CMatrice<TTypeMatrice> MATarg : Matrice de type TTypeMatrice

	   @throw erreur Dimension

	   @return CMatrice<TTypeMatrice> * :  pointeur sur une matrice de type TTypeMatrice representant le resultat de la multiplication de 2 Matrice  
	 */
	CMatrice<TTypeMatrice> * operator*(CMatrice<TTypeMatrice> & MATarg);

	/**
	 * @brief surcharge de l'operateur * pour permettre de multiplier une matrice avec une variable (postfixee) de type TTypeMatrice  : CMatrice<TTypeMatrice> * variable

	   @param TTypeMatrice TMAconstante :  variable de type TTypeMatrice

	   @throw erreur matrice non initialisee

	   @return CMatrice<TTypeMatrice> * : pointeur sur une matrice de type TTypeMatrice representant le resultat de la multiplication de la matrice par la variable
	 */
	CMatrice<TTypeMatrice> * operator*(TTypeMatrice & TMAconstante);

	/**
	 * @brief surcharge de l'operateur * pour permettre de multiplier une matrice avec une constante (postfixee) de type TTypeMatrice  : CMatrice<TTypeMatrice> * constante

	   @param const TTypeMatrice TMAconstante : constante de type TTypeMatrice

	   @throw erreur matrice non initialisee

	   @return  CMatrice<TMat> * : pointeur sur une matrice de type TTypeMatrice representant le resultat de la multiplication de la matrice par la constante
	 */
	CMatrice<TTypeMatrice> * operator*(const TTypeMatrice & TMAconstante);
	
	/**
	 * @brief surcharge de l'operateur / pour permettre de multiplier une matrice avec une variable de type TTypeMatrice  : CMatrice<TTypeMatrice> / variable

	   @param const TTypeMatrice TMAconstante : variable de type TTypeMatrice

	   @throw  division par 0 impossible 

	   @return  CMatrice<TTypeMatrice> * :  pointeur sur une matrice de type TTypeMatrice representant le resultat de la division de la matrice par la variable
	 */
	CMatrice<TTypeMatrice> * operator/(TTypeMatrice & TMAconstante);

	/**
	   @brief surcharge de l'operateur / pour permettre de multiplier une matrice avec une constante de type TTypeMatrice  : CMatrice<TTypeMatrice> / constante

	   @param const TTypeMatrice TMAconstante : variable de type TTypeMatrice

	   @throw  division par 0 impossible et matrice non initialisee

	   @return  CMatrice<TTypeMatrice> * :  pointeur sur une matrice de type TTypeMatrice representant le resultat de la division de la matrice par la constante
	 */
	CMatrice<TTypeMatrice> * operator/(const TTypeMatrice & TMAconstante);

	/**
	 * @brief surcharge de l'operateur =  pour permettre d'affacter un pointeur objet de type CMatrice<TTypeMatrice>* dans un objet de type CMatrice<TTypeMatrice>

	   @param  CMatrice<TTypeMatrice> *:  pointeur sur une Matrice de type TTypeMatrice

	   @return CMatrice<TTypeMatrice> : Une matrice de type TTypeMatrice representant le resultat de l'affectation  
	 */
	CMatrice<TTypeMatrice> & operator=(CMatrice<TTypeMatrice> * MATarg);

	/**
	 * @brief surcharge de l'operateur =  pour permettre d'affacter un objet de type CMatrice<TTypeMatrice> dans un autre objet de type CMatrice<TTypeMatrice>

	   @param  CMatrice<TTypeMatrice> : Matrice de type TTypeMatrice

	   @return CMatrice<TTypeMatrice> : Une matrice de type TTypeMatrice representant le resultat de l'affectation
	 */
	CMatrice<TTypeMatrice> & operator=(CMatrice<TTypeMatrice> MATarg);
};

/*--------------------------------Definition des contructeurs,methodes et du destructeur----------------------------------------------------*/

#include "CMatrice.cpp"

#endif