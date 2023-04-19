#ifndef __ARC__
#define __ARC__

#include <stdio.h>
#include <iostream>

//Outils pour les verifier les fuites memoires
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

class CArc
{
	
private : 
	/*----------Attribut----------*/
	unsigned int uiARCDestination; //Numero du sommet de destination

public : 
	/*----------Constructeurs et destructeur----------*/

	/**
	 * Constructeur par defaut

		@brief constructeur permettant d'initialiser un arc en mettant uiARCDestination a 0 

		@param aucun 

		return rien 
	 */
	CArc();

	/**
	 * Constructeur par recopie 
		
		@brief constructeur permettant d'initialiser un arc a partir d'un autre

		@param ARCarg : un arc

		@return rien
	 */
	CArc(CArc & ARCarg);

	/**
	 * Constructeur de confort 
	 
		@brief constructeur permettant d'initialiser un arc en donnant un numero de sommet

		@param uiNumSommet : entier naturel qui sera le numero du sommet de destination

		@return rien 
	 */
	CArc(unsigned int uiNumSommet);

	/**
	 * Constructeur de confort

		@brief constructeur permettant d'initialiser un arc depuis un pointeur de type CArc

		@param pARCarg : pointeur de type CArc

		@return rien
	 */
	CArc(CArc * pARCarg);


public :
	/*----------Methodes----------*/

	/**
	 * Accesseur en lecture pour l'attribut uiARCDestination

		@brief permet de lire le contenue de l'attribut uiARCDestination

		@param aucun 

		@return uiARCDestination : le numero de destination d'un sommet
	 */
	unsigned int ARCLireDestination();

	/**
	 * Accesseur en ecriture pour l'attribut uiARCDestination

		@brief permet de modifier le contenue de l'attribut uiARCDestination

		@param unsigned int uiNouveauNumSommet : le numero de destination d'un sommet

		@return rien 
	 */
	void ARCModifier(unsigned int uiNouveauNumSommet);

	/* Affichage de la destination

		@brief Affiche la destination de l'arc

		@param rien

		@return rien
	*/
	void ARCAfficherDestination();

/*--------------------Surcharges d'operateur ---------------------------*/

	/* Surcharge de l'operateur ==
	
	@brief Permet de savoir si deux objet de la classe CArc sont egaux

	@param CArc ARCEquivalent : objet de la classe CArc

	@return 0 si les 2 objets sont egaux, 1 sinon
	
	*/
	int operator==(CArc & ARCEquivalent);

	/* Surcharge de l'operateur !=

	@brief Permet de savoir si deux objet de la classe CArc sont different

	@param CArc ARCDifferent : objet de la classe CArc

	@return 0 si les 2 objets sont different, 1 sinon

	*/
	int operator!=(CArc & ARCDifferent);
	
};

#endif