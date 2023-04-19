#ifndef __LLIS__
#define __LLIS__

#include <stdio.h>
#include <stdlib.h>
#include "CException.h"

//Outils pour les verifier les fuites memoires
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

//categorie Valeur
#define EXCIndice 1

// categorie exception dimension 
#define EXCDimensionTableau 10 


template <class TType> class CListe
{
	//Attributs :
private : 
	unsigned int uiLISTailleListe; 
	TType ** pLISTableau; //Tableau d'objet

	//Constructeurs et deconstructeurs :
public :

	/* Constructeur par defaut 

	@brief initialise la liste

	@param aucun

	@return rien
	*/
	CListe<TType>();

	/* Constructeur par recopie 

	@brief initialise la liste a partir d'une autre liste

	@param CListe LISArg : une liste d'objet

	@return rien
	*/
	CListe<TType>(CListe<TType>& LISArg);

	/* Constructeur de confort 

	@brief initialise la liste

	@param unsigned int uiTailleListe : la taille de la liste

	@return rien
	*/
	CListe<TType>(unsigned int uiTailleListe);

	/* Deconstructeur 

	@brief detruit l'objet en supprimmant la liste d'objet

	@param rien

	@return rien
	*/
	~CListe<TType>();

	//Methodes 
public :

	/** accesseur en lecture pour l'attribut uiLISTailleListe

	 * @brief permet de lire la taille du tableau

	   @param aucun

	   @return uiLISTailleListe : taille du tableau 
	 */
	unsigned int LISLireTailleTableau();

	/** accesseur en ecriture pour l'attribut uiLISTailleListe

	 * @brief permet de modifier la taille du tableau

	   @param unsigned int uiNouvelleTailleListe : entier representant un entier naturel  

	   @throws Nouvelle taille du tableau nulle

	   @return rien 
	 */
	void LISModifierTailleTableau(unsigned int uiNouvelleTailleListe);

	/** accesseur en lecture pour l'attribut pLISTableau

	 * @brief permet de lire le tableau

	   @param aucun 

	   @return pLISTableau : tableau contenant des valeurs de type TType
	 */
	TType ** LISLireTableau();

	/* Accesseur en ecriture pour modifier un element de la liste

		@brief modifie un element de la liste des Partants

		@param pTYPArg : un objet de type TType

		@param unsigned int uiIndice : position a laquelle on veut modifier l'element

		@throws Erreur d'indice 

		@return rien
	*/
	void LISModifierUnElementDuTableau(unsigned int uiIndice, TType * pTYPArg);

	/* Fonction d'ajout d'un element dans la liste a la derniere position

		@brief permet d'ajouter un element a la liste en derniere position

		@param TType * pTYParg : element a ajouter de type TType *, par default on ajoute un TType initialiser avec le contructeur par defaut

		@return rien 
	*/
	void LISAjouterUnElementDansLeTableau(TType * pTYParg = new TType());

	/* Suppression d'un element du tableau

		@brief permet de supprimer le dernier element de la Liste

		@param aucun 

		@return rien 
	*/
	void LISSUpprimerUnElementDansLeTableau();

	/* Suppression d'un element du tableau

		@brief permet de supprimer un element de la Liste a une position donne

		@param aucun

		@return rien
	*/
	void LISSUpprimerUnElementDansLeTableau(unsigned int uiPosition);

	/** Fonction de concatenation de listes

		@brief Permet de concatener deux objets de type CListe<TType>

		@param CListe<TType> * LISarg : objet CListe qu'on veut concatener a l'objet actuelle

		@return rien
	 */
	void LISConcatenation(CListe<TType> * pLISarg);

	/** Fonction pour supprimer les doublons d'une liste

		@brief Permet de supprimer les doublons d'une liste de type CListe<TType>

		@param CListe<TType> LISarg : objet CListe dans laquelle nous voulons supprimer les doublons

		@return rien
	 */
	void static LISSupprimerDoublons(CListe<TType> &  LISarg);

	/*----------Surcharge d'operateur-------------*/

	/* Surcharge de l'operateur []

		@brief surcharge de l'operateur [] pour permettre de retourner l'objet a la position voulu

		@param unsigned int uiARG : Entier qui correspond a la position

		@throws Erreur d'indice 

		@return TType : Un objet de type TType
	*/
	TType & operator[](unsigned int uiArg);

	/** Surcharge de l'operateur = 
	
		@brief surcharge de l'operteur = permettant d'affecter un objet de type CListe<TType> dans un autre objet de type CListe<TType>

		@param CListe<TType> LISarg : objet CListe qu'on veut affecter dans l'objet actuelle

		@return rien
	 */
	CListe<TType> & operator=(CListe<TType> & LISarg);

	/** Surcharge de l'operateur =

		@brief surcharge de l'operteur = permettant d'affecter un pointeur d'objet de type CListe<TType> * dans un autre objet de type CListe<TType> *

		@param CListe<TType> * LISarg : objet CListe qu'on veut affecter dans l'objet actuelle

		@return rien
	 */
	CListe<TType> * operator=(CListe<TType> * pLISarg);

	/** Surcharge de l'operateur == 
	
		@brief Permet si deux objet de la classe CListe sont identique ou non

		@param LISEquivalent : objet de type CListe

		@return 0 si les 2 objets sont egale, 1 sinon
	*/
	int operator==(CListe<TType> & LISEquivalent);

};

#include "CListe.cpp"

#endif



