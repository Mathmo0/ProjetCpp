#include "CArc.h"

/**
 * Constructeur par defaut

	@brief constructeur permettant d'initialiser un arc en mettant uiARCDestination a 0

	@param aucun

	return rien
 */
CArc ::CArc()
{
	uiARCDestination = 0;
}

/** Constructeur par recopie

	@brief constructeur permettant d'initialiser un arc a partir d'un autre

	@param ARCarg : un arc

	@return rien
*/
CArc ::CArc( CArc & ARCarg)
{
	uiARCDestination = ARCarg.uiARCDestination;
}

/** Constructeur de confort

	@brief constructeur permettant d'initialiser un arc en donnant un numero de sommet

	@param uiNumSommet : entier naturel qui sera le numero du sommet de destination

	@return rien
*/
CArc::CArc(unsigned int uiNumSommet)
{
	uiARCDestination = uiNumSommet;
}

/** Constructeur de confort

	@brief constructeur permettant d'initialiser un arc depuis un pointeur de type CArc

	@param pARCarg : pointeur de type CArc

	@return rien
*/
CArc :: CArc(CArc * pARCarg)
{
	uiARCDestination = pARCarg->uiARCDestination;
}

/** Accesseur en lecture pour l'attribut uiARCDestination

	@brief permet de lire le contenue de l'attribut uiARCDestination

	@param aucun

	@return uiARCDestination : le numero de destination d'un sommet
*/
unsigned int CArc::ARCLireDestination()
{
	return uiARCDestination;
}

/** Accesseur en ecriture pour l'attribut uiARCDestination

	@brief permet de modifier le contenue de l'attribut uiARCDestination

	@param unsigned int uiNouveauNumSommet : le numero de destination d'un sommet

	@return rien
*/
void CArc :: ARCModifier(unsigned int uiNouveauNumSommet)
{
	uiARCDestination = uiNouveauNumSommet;
}

/* Affichage de la destination

	@brief Affiche la destination de l'arc

	@param rien

	@return rien
*/
void CArc :: ARCAfficherDestination()
{
	std::cout << "La destination de l'arc est le sommet numero " << uiARCDestination << "\n";
}

/* Surcharge de l'operateur ==

@brief Permet de savoir si deux objet de la classe CArc sont egaux

@param CArc ARCEquivalent : objet de la classe CArc

@return 0 si les 2 objets sont egaux, 1 sinon

*/
int CArc::operator==(CArc & ARCEquivalent)
{
	if ( uiARCDestination == ARCEquivalent.uiARCDestination)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/* Surcharge de l'operateur !=

	@brief Permet de savoir si deux objet de la classe CArc sont different

	@param CArc ARCDifferent : objet de la classe CArc

	@return 0 si les 2 objets sont different, 1 sinon

*/
int CArc::operator!=(CArc & ARCDifferent)
{
	if (uiARCDestination == ARCDifferent.uiARCDestination)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



