#include "CSommet.h"
#include "CListe.h"
#include <stdlib.h>
#include <iostream>

/**
 * Constructeur par defaut

	@brief ne fait rien 

	@param aucun

	@return rien
 */

CSommet :: CSommet()
{

}

/**
	 constructeur par recopie

		@brief : constructeur permettant d'initialiser tous les attribus a partir de ceux d'un sommet deja existant

		@param SOMarg : un sommet

		@return rien
*/
CSommet::CSommet(CSommet & SOMarg)
{
	/* Recopie de SOMarg : */

	uiSOMNumSommet = SOMarg.uiSOMNumSommet;

	LISSOMListeArcArrivant = SOMarg.LISSOMListeArcArrivant;
	LISSOMListeArcPartant = SOMarg.LISSOMListeArcPartant;
}

/* Constructeur de confort

	@brief initialise les listes LISSOMListeArcArrivant et LISSOMListeArcPartant avec une taille. Initialise aussi uiSOMNumSommet avec un numero de sommet donnee.

	@param unsigned int uiARG : la taille des listes

	@param unsigned int uiNumero : numero du sommet, la valeur par defaut est 0

	@return rien
*/
CSommet :: CSommet(unsigned int uiTailleListe, unsigned int uiNumero)
{
	LISSOMListeArcArrivant.LISModifierTailleTableau(uiTailleListe);
	LISSOMListeArcPartant.LISModifierTailleTableau(uiTailleListe);
	uiSOMNumSommet = uiNumero;
}

/* Destructeur

		@brief detruit un objet de type CSommet

		@param rien

		@return rien
*/
CSommet::~CSommet()
{

}

/* Accesseur en lecture numero de sommet

		@brief renvoie le numero du sommet

		@param rien

		@return uiSOMNumSommet : le numero du sommet
	*/
unsigned int CSommet:: SOMLireNumSommet()
{
	return uiSOMNumSommet;
}

/* Accesseur en lecture de la taille de la liste des arrivants

		@brief renvoie la taille de la liste des arrivants

		@param rien

		@return uiSOMTailleListeArrivant : la taille de la liste des arrivants
*/
unsigned int CSommet::SOMLireTailleListeArrivant()
{
	return LISSOMListeArcArrivant.LISLireTailleTableau();
}

/* Accesseur en lecture de la taille de la liste des arrivants

		@brief renvoie la taille de la liste des Partants

		@param rien

		@return uiSOMTailleListePartant : la taille de la liste des Partants
	*/
unsigned int CSommet::SOMLireTailleListePartant() 
{
	return LISSOMListeArcPartant.LISLireTailleTableau();
}

/** Accesseur en lecture pour l'attribut ARCSOMListeArcArrivant

		@brief renvoie la liste des arc arrivants

		@param aucun

		@return ARCSOMListeArcArrivant : liste des arcs arrivants de type CArc **
*/
CArc ** CSommet::SOMLireListeArrivant()
{
	return LISSOMListeArcArrivant.LISLireTableau();
}

/** Accesseur en lecture pour l'attribut ARCSOMListeArcPartant

		@brief renvoie la liste des arc partants

		@param aucun

		@return ARCSOMListeArcPartant : liste des arcs partants de type CArc **
*/
CArc ** CSommet::SOMLireListePartant()
{
	return LISSOMListeArcPartant.LISLireTableau();
}

/** Accesseur en ecriture pour modifier le numero d'un sommet

		@brief modifie le numero du sommet

		@param uiArg : le nouveau numero du sommet

		@return rien
*/
void CSommet :: SOMModifierNumSommet(unsigned int uiArg)
{
	uiSOMNumSommet = uiArg;
}

/** Accesseur en ecriture pour modifier la taille de la liste des arrivant

		@brief modifie la taille de la liste des arrivants

		@param iArg : la nouvelle taille de la liste des arrivants

		@return rien
*/
void CSommet :: SOMModifierTailleListeArrivant(unsigned int uiArg)
{
	LISSOMListeArcArrivant.LISModifierTailleTableau(uiArg);
}

/** Accesseur en ecriture pour modifier la taille de la liste des Partants

		@brief modifie la taille de la liste des Partants

		@param iArg : la nouvelle taille de la liste des Partants

		@return rien
*/
void CSommet::SOMModifierTailleListePartant(unsigned int uiArg) 
{
	LISSOMListeArcPartant.LISModifierTailleTableau(uiArg);
}

/* Accesseur en ecriture pour modifier un element de la liste des arrivants

		@brief modifie un element de la liste des arrivants

		@param ARCArg : un objet de la classe CArc

		@param unsigned int uiIndice : position a laquelle on veut modifier l'arc

		@return rien
*/
void CSommet::SOMModifierListeArrivant(CArc * pARCArg, unsigned int uiIndice)
{
	LISSOMListeArcArrivant.LISModifierUnElementDuTableau(uiIndice, pARCArg);
}

/* Accesseur en ecriture pour modifier un element de la liste des Partants

		@brief modifie un element de la liste des Partants

		@param pARCArg : un objet de la classe CArc

		@param unsigned int uiIndice : position a laquelle on veut modifier l'arc

		@return rien
*/
void CSommet::SOMModifierListePartant(CArc * pARCArg, unsigned int uiIndice)
{
	LISSOMListeArcPartant.LISModifierUnElementDuTableau(uiIndice, pARCArg);
}

/* Fonction d'ajout d'un arc dans la liste des arrivants

		@brief permet d'ajouter un arc LISSOMListeArcArrivant en derniere position

		@param CArc * pARCarg : Element a ajouter de type CArc *, par default on ajoute un CArc initialiser avec le contructeur de confort

		@return rien
	*/
void CSommet ::SOMAjouterUnArcListeArrivant(CArc  * pARCarg)
{
	LISSOMListeArcArrivant.LISAjouterUnElementDansLeTableau(pARCarg);
}

/* Fonction d'ajout d'un arc dans la liste des partants

		 @brief permet d'ajouter un arc a LISSOMListeArcPartant en derniere position

		 @param CArc * pARCarg : element a ajouter de type CArc *, par default on ajoute un CArc initialiser avec le contructeur de confort

		 @return rien
*/
void CSommet :: SOMAjouterUnArcListePartant(CArc  * pARCarg)
{
	LISSOMListeArcPartant.LISAjouterUnElementDansLeTableau(pARCarg);
}

/* Suppression d'un arc dans la liste des arrivants

		@brief permet de supprimer le dernier element de LISSOMListeArcArrivant

		@param aucun

		@return rien
	*/
void CSommet :: SOMSupprimerArcListeArrivant() 
{
	LISSOMListeArcArrivant.LISSUpprimerUnElementDansLeTableau();
}

/* Suppression d'un arc dans la liste des partants

		@brief permet de supprimer le dernier element de LISSOMListeArcPartant

		@param aucun

		@return rien
*/
void CSommet :: SOMSupprimerArcListePartant()
{
	LISSOMListeArcPartant.LISSUpprimerUnElementDansLeTableau();
}

/* Inversion les listes d'arcs

		@brief permet d'inverser LISSOMListeArcPartant et LISSOMListeArcArrivant

		@fn LISSOMListeArcArrivant devient LISSOMListeArcPartant et LISSOMListeArcPartant devient LISSOMListeArcArrivant

		@param aucun

		@return rien

*/
void CSommet :: SOMInverserListePartantArrivant()
{
	CListe<CArc> LISTemp;

	LISTemp = LISSOMListeArcArrivant;
	LISSOMListeArcArrivant = LISSOMListeArcPartant;
	LISSOMListeArcPartant = LISTemp;
}

/** Affichage du sommet

	   @brief permet d'afficher le numero du sommet

	   @param aucun

	   @return rien
*/
void CSommet :: SOMAfficherSommet()
{
	unsigned int uiBoucle = 0;

	std::cout << uiSOMNumSommet;

	std::cout << "Sommet numero: " << uiSOMNumSommet << " \n" << "Liste des Arrivant : \n";

	for (uiBoucle = 0; uiBoucle < LISSOMListeArcArrivant.LISLireTailleTableau(); uiBoucle++)
	{
		LISSOMListeArcArrivant[uiBoucle].ARCAfficherDestination();
	}

	printf("Liste des Partants : \n");

	for (uiBoucle = 0; uiBoucle < LISSOMListeArcPartant.LISLireTailleTableau(); uiBoucle++)
	{
		LISSOMListeArcPartant[uiBoucle].ARCAfficherDestination();
	}
}

/* Concatenation des deux listes arrivants et partants

		@brief concatene les deux listes, les deux listes auront les memes elements

		@param rien

		@return rien
	*/
void CSommet::SOMConcatenationListes()
{
	LISSOMListeArcPartant.LISConcatenation(&LISSOMListeArcArrivant);
	//LISSOMListeArcArrivant.LISConcatenation(LISSOMListeArcPartant);
	//LISSOMListeArcPartant = LISSOMListeArcArrivant;
	LISSOMListeArcArrivant = LISSOMListeArcPartant;
}

/* SupprimerArcDoublon

		@brief supprime les arc doubllons dans la liste LISSOMListeArcArrivant et la liste LISSOMListeArcPartant

		@param aucun

		@return rien

	*/
void CSommet::SupprimerArcDoublon() 
{
	CListe<CArc>::LISSupprimerDoublons(LISSOMListeArcArrivant);
	CListe<CArc>::LISSupprimerDoublons(LISSOMListeArcPartant);
}

/*----------Surcharge d'operateurs----------*/


/* Surcharge de l'operateur =

	@brief permet de rendre l'operation = possible pour les objets de la classe CSommet

	@param CSommet SOMarg : un objet de type CSommet

	@return CSommet : un objet de type CSommet
*/
CSommet & CSommet :: operator=(CSommet SOMArg)
{
	uiSOMNumSommet = SOMArg.uiSOMNumSommet;
	LISSOMListeArcArrivant = SOMArg.LISSOMListeArcArrivant;
	LISSOMListeArcPartant = SOMArg.LISSOMListeArcPartant;

	return *this;
}

/* Surcharge de l'operateur =

	@brief permet de rendre l'operation = possible pour les objets de la classe CSommet

	@param CSommet* SOMarg : un pointeur d'objet de type CSommet

	@return CSommet : un objet de type CSommet
*/
CSommet & CSommet :: operator=(CSommet* pSOMArg)
{
	uiSOMNumSommet = pSOMArg->uiSOMNumSommet;
	LISSOMListeArcArrivant = pSOMArg->LISSOMListeArcArrivant;
	LISSOMListeArcPartant = pSOMArg->LISSOMListeArcPartant;

	return *this;
}

/** Surcharge de l'operateur ==

		@brief Permet si deux objet de la classe CSommet sont identique ou non

		@param SOMEquivalent : objet de type CSommet

		@return 0 si les 2 objets sont egaux, 1 sinon
*/
int CSommet::operator==(CSommet & SOMEquivalent)
{
	if(uiSOMNumSommet != SOMEquivalent.uiSOMNumSommet)
	{
		return 1;
	}

	if(LISSOMListeArcArrivant.operator==(SOMEquivalent.LISSOMListeArcArrivant) == 1)
	{
		return 1;
	}

	if (LISSOMListeArcPartant.operator==(SOMEquivalent.LISSOMListeArcPartant) == 1) 
	{
		return 1;
	}

	return 0; 
}

/* Surcharge de l'operateur !=

	@brief Permet de savoir si 2 objet de type CSommet sont different

	@param CSommet SOMDifferent : objet de type CSommet, objet utilise pour la comparaison

	@return 0 si les 2 objets sont differents, 1 sinon

*/
int CSommet::operator!=(CSommet & SOMDifferent)
{
	unsigned int uiBoucle = 0;

	if (uiSOMNumSommet == SOMDifferent.uiSOMNumSommet)
	{
		return 1;
	}

	/*comparaison de la liste Arc Arrivant*/
	for (uiBoucle = 0; uiBoucle < LISSOMListeArcArrivant.LISLireTailleTableau(); uiBoucle++)
	{
		if (*(LISSOMListeArcArrivant.LISLireTableau()[uiBoucle]) != *(SOMDifferent.LISSOMListeArcArrivant.LISLireTableau()[uiBoucle]))
		{
			return 0;
		}
	}

	/* comparaison de la liste Arc Partant : */
	for (uiBoucle = 0; uiBoucle < LISSOMListeArcPartant.LISLireTailleTableau(); uiBoucle++)
	{
		if (*LISSOMListeArcPartant.LISLireTableau()[uiBoucle] != *(SOMDifferent.LISSOMListeArcPartant.LISLireTableau()[uiBoucle]))
		{
			return 0;
		}
	}
	return 1;
}


