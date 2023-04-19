#include "COperation.h"

/* Fonction pour desorienter un graphe

		@brief Desoriente un graphe

		@param CGraphe & GRAGrapheOriente : un graphe oriente que l'on veut desorienter

		@return rien
	*/
CGraphe * COperation::OPEGrapheNonOriente(CGraphe & GRAGrapheOriente)
{
	unsigned int uiBoucle;
	unsigned int uiTailleListeSommet = GRAGrapheOriente.GRALireListeSommet().LISLireTailleTableau();

	CGraphe * pGRATemp = new CGraphe(GRAGrapheOriente);
	CGraphe GRATempBis;
	CSommet SOMTemp;

	for (uiBoucle = 0; uiBoucle < uiTailleListeSommet; uiBoucle++)
	{
		SOMTemp = pGRATemp->GRALireListeSommet()[uiBoucle];
		SOMTemp.SOMConcatenationListes();
		pGRATemp->GRAModifierSommet(&SOMTemp, uiBoucle);
	}
	GRAGrapheOriente = *pGRATemp;
	GRAGrapheOriente.GRASuppresionDoublon();

	delete pGRATemp;

	return &GRAGrapheOriente;
}

/* Fonction pour recuperer un ensemble independant de sommets de cardinalite maximale

		@brief recuperer un ensemble independant de sommets de cardinalite maximale pour un graphe donne, le graphe est systematiquement desoriente au debut

		@pram GRAGrapheNonOriente : un graphe qui sera desoriente par precaution au debut

		@return : rien
	*/
CGraphe * COperation::OPEEssembleIndependantSommet(CGraphe GRAGrapheNonOriente)
{
	/*Desorientation du graphe : */
	COperation::OPEGrapheNonOriente(GRAGrapheNonOriente);

	/*Declaration des variables*/
	CListe<CSommet> * pLISEssembleStable = new CListe<CSommet>();
	CListe<CSommet> * pLISEssembleStableTemp = new CListe<CSommet>();

	CGraphe * pGRATemp = new CGraphe(GRAGrapheNonOriente);
	CGraphe * pGRATemp2 = new CGraphe();
	CGraphe * pGRAEssembleStable = nullptr;
	CSommet SOMTemp;

	unsigned int uiBoucle;
	unsigned int uiBoucleBis;
	unsigned int uiBoubleSommet = 0;
	unsigned int uiTailleListeSommet = GRAGrapheNonOriente.GRALireListeSommet().LISLireTailleTableau();
	unsigned int uiTaille;
	unsigned int uiNumSommet;
	unsigned int uiTailleGRAtemp2 = 0;

	/*on repete les actions de recuperation de sommets independants en commencant par chaque sommet pour avoir la cardinalite maximale*/
	while (uiBoubleSommet < uiTailleListeSommet) 
	{
		*pGRATemp2 = *pGRATemp;
		
		while (pGRATemp2->GRALireListeSommet().LISLireTailleTableau() !=0 && pGRATemp2->GRALireListeSommet().LISLireTableau() != nullptr) //tant que le graphe n'est pas vide
		{
			uiTailleGRAtemp2 = pGRATemp2->GRALireListeSommet().LISLireTailleTableau();

			if (uiBoubleSommet < uiTailleGRAtemp2) 
			{
				SOMTemp = pGRATemp2->GRALireListeSommet()[uiBoubleSommet];
			}
			else
			{
				SOMTemp = pGRATemp2->GRALireListeSommet()[uiTailleGRAtemp2-1];
			}

			pLISEssembleStableTemp->LISAjouterUnElementDansLeTableau(&SOMTemp); //on recupere le sommet pour le mettre dans une liste

			pGRATemp2->GRASupprimerSommet(uiBoubleSommet); //on supprime le sommet du graphe

			/*on parcours la liste des arcs arrivants*/
			for (uiBoucle = 0; uiBoucle < SOMTemp.SOMLireTailleListeArrivant(); uiBoucle++) 
			{
				uiBoucleBis = 0;
				uiTaille = pGRATemp2->GRALireListeSommet().LISLireTailleTableau();
				uiNumSommet = SOMTemp.SOMLireListeArrivant()[uiBoucle]->ARCLireDestination();

				/*on parcours la listes des graphes pour supprimer les sommets qui sont present dans la liste d'arc*/
				while (uiBoucleBis < uiTaille && pGRATemp2->GRALireListeSommet().LISLireTableau() != nullptr)
				{
					/*on regarde si le numero de l'arc est le meme que le sommet lu*/
					if (uiNumSommet == pGRATemp2->GRALireListeSommet()[uiBoucleBis].SOMLireNumSommet()) 
					{
						pGRATemp2->GRASupprimerSommet(uiBoucleBis);
						uiTaille--;
					}
					uiBoucleBis++;
				}
			}
		}

		if (pLISEssembleStableTemp->LISLireTailleTableau() > pLISEssembleStable->LISLireTailleTableau()) //on garde la liste la plus grande
		{
			*pLISEssembleStable = *pLISEssembleStableTemp;
		}

		delete pLISEssembleStableTemp;
		pLISEssembleStableTemp = new CListe<CSommet>();
		uiBoubleSommet++;
	}

	pGRAEssembleStable = new CGraphe(*pLISEssembleStable);

	delete pGRATemp;
	delete pGRATemp2;
	delete pLISEssembleStable;
	delete pLISEssembleStableTemp;

	return pGRAEssembleStable;
}
