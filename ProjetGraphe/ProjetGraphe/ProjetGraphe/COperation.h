#ifndef __OPE__
#define __OPE__

#include "CGraphe.h"

class COperation 
{
	/*----------Methodes----------*/
public:
	/* Fonction pour desorienter un graphe

		@brief Desoriente un graphe

		@param CGraphe & GRAGrapheOriente : un graphe oriente que l'on veut desorienter

		@return rien
	*/
	static CGraphe * OPEGrapheNonOriente(CGraphe & GRAGrapheOriente);

	/* Fonction pour recuperer un ensemble independant de sommets de cardinalite maximale

		@brief recuperer un ensemble independant de sommets de cardinalite maximale pour un graphe donne, le graphe est systematiquement desoriente au debut

		@pram GRAGrapheNonOriente : un graphe qui sera desoriente par precaution au debut

		@return : rien
	*/
	static CGraphe * OPEEssembleIndependantSommet(CGraphe GRAGrapheNonOriente);

};

#endif