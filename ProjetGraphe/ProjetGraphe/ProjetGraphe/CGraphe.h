
#ifndef __GRA__
#define __GRA__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <istream>
#include <fstream>
#include "CException.h"
#include "CSommet.h"
#include "CListe.h"

//Outils pour les verifier les fuites memoires
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

//Exception fichier
#define EXCFormatFichier 21
#define EXCCheminFichier 22
#define EXCLectureGrapheDansFichier 23

class CGraphe
{

private : 
	/*----------Attribut----------*/
	CListe<CSommet> LISGRAListeSommet;
	
	 
public : 
	/*----------Constrcuteur et destructeur----------*/

	/** Constructeur par defaut 
	 * 
	   @brief permet d'initialiser un objet de type CGraphe

	   @param aucun 

	   @return rien 
	 */
	CGraphe();

	/** Constructeur de recopie 
	 * 
	   @brief permet de d'initialiser un objet de type CGraphe a partir d'un autre objet de type CGraphe
	   
	   @param CGraphe GRAarg : objet de type CGraphe

	   @return rien 

	 */
	CGraphe(CGraphe & GRAarg);

	/** Constructeur de confort 
	 *
	   @brief permet d'initialiser un objet de type CGraphe avec une taille de liste donnee

	   @param unsigned uiTaille  : un entier naturel 

	   @return rien 
	 */
	CGraphe(unsigned int uiTaille);

	/** constructeur de confort 
	 * 
	   @brief permet d'initialier un objet de type graphe en donne une liste de sommet

	   @param CListe<CSommet> LISarg : une liste de type CSommet 

	   @return rien 
	 */
	CGraphe(CListe<CSommet> LISarg);

	/* Constructeur a partir d'un fichier .txt

	@brief : construit un graphe a partir d'un fichier .txt

	@param char * sPath : un chemin vers le fichier .txt

	@throw exceptions liee aux fichiers 

	@return rien
	*/
	CGraphe(char * sPath);

	/** Destructeur
	 * 
	   @brief detruit l'objet 

	   @param aucun 

	   @return rien 
	 */
	~CGraphe();

	
public : 
	/*----------Methodes----------*/

	/* Accesseur en lecture pour l'attribut LISGRAListeSommet

		@brief permet de lire l'attribut LISGRAListeSommet

		@param aucun 

		@return LISGRAListeSommet  : un objet CListe de type CSommet 
	*/
	CListe<CSommet> GRALireListeSommet();

	/** Accesseur en ecriture pour l'attribut LISGRAListeSommet. la position commence a 0

		@brief permet de modifier un sommet du graphe

		@param * CSommet SOMarg : un CSommet
		@param unsigned int uiIndice : la position dans la liste 

		@return rien 
	 * 
	 */
	void GRAModifierSommet(CSommet * pSOMarg, unsigned int uiIndice);

	/* Fonction d'ajout d'un sommet

		 @brief Permet d'ajouter un sommet a LISGRAListeSommet en derniere position

		 @param CSommet * pARCarg : Element a ajouter de type CSommet *, par default on ajoute un CSommet initialiser avec le contructeur par defaut

		 @return rien
	 */
	void GRAAjouterSommet(CSommet * pSOMArg);

	/* Suppression d'un sommet

		@brief Permet de supprimer le dernier element de LISGRAListeSommet

		@param aucun

		@return rien
	*/
	void GRASupprimerSommet();

	/* Suppression d'un sommet

		@brief Permet de supprimer un element de LISGRAListeSommet a une position donne

		@param aucun

		@return rien
	*/
	void GRASupprimerSommet(unsigned int uiPosition);

	/* Modifier un graphe a partir d'un fichier .txt

	@brief : modifie un graphe a partir d'un fichier .txt

	@param char * sPath : un chemin vers le fichier .txt

	@return rien
	*/
	void GRAModifierGraphe(char * sPath);

	/* Affichage du graphe

	   @brief permet d'afficher toutes les informations concernant un graphe
		
	   @param aucun

	   @return rien 
	*/
	void GRAAfficherGraphe();

	/* Inversion du graphe

		@brief permet dinverser un graphe pour en obtenir un nouveau

		@param rien

		@return CGraphe
	*/
	CGraphe & GRAInverserGraphe();


	/* Suppresion Doublon
	
		@brief Permet de supprimer les sommet en double dans la liste

		@param aucun 

		@return rien
	
	*/
	void GRASuppresionDoublon();

	/*----------Surcharge d'operateur-------------*/

	/* Surcharge de l'operateur =

		@brief permet l'operation "=" entre les objets de type CGraphe

		@param CGraphe GRAArg : un graphe

		@return CGraphe
	*/
	CGraphe & operator=(CGraphe GRAArg);

	/* Surcharge de l'operateur ==  
	
		@brief Permet si deux objet de la classe CGraphe sont identique ou non

		@param GRAEquivalent : objet de type CGraphe

		@return 0 si les 2 objets sont egale, 1 sinon
	
	*/
	int operator==(CGraphe & GRAEquivalent);

	/* Surcharge de l'operateur !=

	@brief Permet de savoir si 2 objet de type CGraphe sont different

	@param CGraphe GRADifferent : objet de type CGraphe, objet utilise pour la comparaison

	@return 0 si les 2 objets sont differents, 1 sinon

	*/
	int operator!=(CGraphe & GRADifferent);

};



#endif