#ifndef __SOM__
#define __SOM__

#include "CArc.h"
#include "CListe.h"

//Outils pour les verifier les fuites memoires
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

class CSommet
{
private:

	/*----------attributs----------*/ 

	unsigned int uiSOMNumSommet = 0;
	CListe<CArc> LISSOMListeArcArrivant;
	CListe<CArc> LISSOMListeArcPartant;

	
public :
	/*----------constructeurs et destructeur----------*/

	/**
	 * Constructeur par defaut 
		
		@brief ne fait rien 

		@param aucun 

		@return rien 
	 */
	CSommet();

	/**
	 * Constructeur par recopie 

		@brief constructeur permettant d'initialiser tous les attributs a partir de ceux d'un sommet deja existant

		@param SOMarg : un sommet

		@return rien
	 */
	CSommet(CSommet & SOMarg);

	/* Constructeur de confort 

	@brief initialise les listes LISSOMListeArcArrivant et LISSOMListeArcPartant avec une taille. Initialise aussi uiSOMNumSommet avec un numero de sommet donnee.

	@param unsigned int uiARG : la taille des listes

	@param unsigned int uiNumero : numero du sommet, la valeur par defaut est 0 

	@return rien
	*/
	CSommet(unsigned int uiTailleListe, unsigned int uiNumero = 0);

	/* Destructeur 

		@brief detruit un objet de type CSommet

		@param rien 

		@return rien
	*/
	~CSommet();

public :
	/*----------Mehode----------*/

	/* Accesseur en lecture numero de sommet

		@brief renvoie le numero du sommet

		@param rien 

		@return uiSOMNumSommet : le numero du sommet
	*/
	unsigned int SOMLireNumSommet();

	/* Accesseur en lecture de la taille de la liste des arrivants

		@brief renvoie la taille de la liste des arrivants

		@param rien

		@return uiSOMTailleListeArrivant : la taille de la liste des arrivants
	*/
	unsigned int SOMLireTailleListeArrivant();

	/* Accesseur en lecture de la taille de la liste des arrivants

		@brief renvoie la taille de la liste des Partants 

		@param rien

		@return uiSOMTailleListePartant : la taille de la liste des Partants
	*/
	unsigned int SOMLireTailleListePartant();
	
	/** Accesseur en lecture pour l'attribut ARCSOMListeArcArrivant

		@brief renvoie la liste des arc arrivants
		
		@param aucun 

		@return ARCSOMListeArcArrivant : liste des arcs arrivants de type CArc ** 
	 */
	CArc ** SOMLireListeArrivant();

	/** Accesseur en lecture pour l'attribut ARCSOMListeArcPartant

		@brief renvoie la liste des arc partants

		@param aucun

		@return ARCSOMListeArcPartant : liste des arcs partants de type CArc ** 
	 */
	CArc ** SOMLireListePartant();

	/** Accesseur en ecriture pour modifier le numero d'un sommet

		@brief modifie le numero du sommet

		@param uiArg : le nouveau numero du sommet

		@return rien 
	 */
	void SOMModifierNumSommet(unsigned int uiArg);

	/** Accesseur en ecriture pour modifier la taille de la liste des arrivant

		@brief modifie la taille de la liste des arrivants

		@param iArg : la nouvelle taille de la liste des arrivants

		@return rien 
	 */
	void SOMModifierTailleListeArrivant(unsigned int uiArg);

	/** Accesseur en ecriture pour modifier la taille de la liste des Partants

		@brief modifie la taille de la liste des Partants

		@param iArg : la nouvelle taille de la liste des Partants

		@return rien 
	 */
	void SOMModifierTailleListePartant(unsigned int uiArg);
	
	/* Accesseur en ecriture pour modifier un element de la liste des arrivants

		@brief modifie un element de la liste des arrivants

		@param pARCArg : un objet de la classe CArc

		@param unsigned int uiIndice : position a laquelle on veut modifier l'arc

		@return rien
	*/
	void SOMModifierListeArrivant(CArc * pARCArg, unsigned int uiIndice);

	/* Accesseur en ecriture pour modifier un element de la liste des Partants

		@brief modifie un element de la liste des Partants

		@param pARCArg : un objet de la classe CArc

		@param unsigned int uiIndice : position a laquelle on veut modifier l'arc

		@return rien
	*/
	void SOMModifierListePartant(CArc * pARCArg, unsigned int uiIndice);

	 /* Fonction d'ajout d'un arc dans la liste des arrivants

		 @brief permet d'ajouter un arc LISSOMListeArcArrivant en derniere position

		 @param CArc * pARCarg : Element a ajouter de type CArc *, par default on ajoute un CArc initialiser avec le contructeur de confort

		 @return rien
	 */
	void SOMAjouterUnArcListeArrivant(CArc  * pARCarg);

	/* Fonction d'ajout d'un arc dans la liste des partants

		 @brief permet d'ajouter un arc a LISSOMListeArcPartant en derniere position

		 @param CArc * pARCarg : element a ajouter de type CArc *, par default on ajoute un CArc initialiser avec le contructeur de confort

		 @return rien
	 */
	void SOMAjouterUnArcListePartant(CArc  * pARCarg);

	/* Suppression d'un arc dans la liste des arrivants 

		@brief permet de supprimer le dernier element de LISSOMListeArcArrivant

		@param aucun

		@return rien
	*/
	void SOMSupprimerArcListeArrivant();
	
	/* Suppression d'un arc dans la liste des partants

		@brief permet de supprimer le dernier element de LISSOMListeArcPartant

		@param aucun

		@return rien
	*/
	void SOMSupprimerArcListePartant();

	/* Inversion les listes d'arcs

		@brief permet d'inverser LISSOMListeArcPartant et LISSOMListeArcArrivant

		@fn LISSOMListeArcArrivant devient LISSOMListeArcPartant et LISSOMListeArcPartant devient LISSOMListeArcArrivant

		@param aucun  

		@return rien 
	
	*/
	void SOMInverserListePartantArrivant();

	/** Affichage du sommet

	 * @brief permet d'afficher le numero du sommet

	   @param aucun

	   @return rien
	*/
	void SOMAfficherSommet();

	/* Concatenation des deux listes arrivants et partants

		@brief concatene les deux listes, les deux listes auront les memes elements

		@param rien

		@return rien
	*/
	void SOMConcatenationListes();

	/* SupprimerArcDoublon
	
		@brief supprime les arc doubllons dans la liste LISSOMListeArcArrivant et la liste LISSOMListeArcPartant

		@param aucun 

		@return rien 
	
	*/
	void SupprimerArcDoublon();

	/*----------Surcharge d'operateurs----------*/

	/* Surcharge de l'operateur =

	@brief permet de rendre l'operation = possible pour les objets de la classe CSommet

	@param CSommet SOMarg : un objet de type CSommet

	@return CSommet : un objet de type CSommet
	*/
	CSommet & operator=(CSommet SOMArg);

	/* Surcharge de l'operateur =

	@brief permet de rendre l'operation = possible pour les objets de la classe CSommet

	@param CSommet* SOMarg : un pointeur d'objet de type CSommet

	@return CSommet : un objet de type CSommet
*/
	CSommet & operator=(CSommet* pSOMArg);

	/** Surcharge de l'operateur ==

		@brief Permet si deux objet de la classe CSommet sont identique ou non

		@param SOMEquivalent : pointeur de type CSommet

		@return 0 si les 2 objets sont egaux, 1 sinon 
*/
	int operator==(CSommet & SOMEquivalent);

	/* Surcharge de l'operateur !=
	
	@brief Permet de savoir si 2 objet de type CSommet sont different

	@param CSommet SOMDifferent : objet de type CSommet, objet utilise pour la comparaison

	@return 0 si les 2 objets sont differents, 1 sinon
	
	*/
	int operator!=(CSommet & SOMDifferent);

};


#endif