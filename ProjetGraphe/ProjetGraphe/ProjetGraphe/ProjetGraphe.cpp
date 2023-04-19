// ProjetGraphe.cpp : Ce fichier contient la fonction 'main'. L'execution du programme commence et se termine a cet endroit.

#include <iostream>
#include "CArc.h"
#include "CGraphe.h"
#include "COperation.h"

//Outils pour les fuites memoires
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
#define EXCTableauNULL 11

//categorie exception fichier : 
#define EXCFormatFichier 21
#define EXCCheminFichier 22
#define EXCLectureGrapheDansFichier 23

int main(int argc, char** argv)
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //verification des fuites de memoire

	unsigned int uiBoucle = 1;

	CListe<CGraphe> GRAListe(argc);
	CListe<CGraphe> GRAListeInv(argc);
	CListe<CGraphe> GRAListeNonOriente(argc);
	CListe<CGraphe> GRASommetIndependant(argc);

	CGraphe GRANull;
	CGraphe GRAcop;

	std::cout << "\n _______________________Initialisation des Graphes_______________________\n";

	for (uiBoucle; uiBoucle < argc; uiBoucle++)
	{
		try
		{
			std::cout << "\nGraphe " << uiBoucle << "\n";
			GRAListe[uiBoucle].GRAModifierGraphe(argv[uiBoucle]);
			GRAListe[uiBoucle].GRAAfficherGraphe();

			GRAcop = GRAListe[uiBoucle];

			std::cout << "\nGraphe " << uiBoucle << " inverse\n";
			GRAListeInv[uiBoucle] = GRAcop.GRAInverserGraphe();
			GRAListeInv[uiBoucle].GRAAfficherGraphe();

			std::cout << "\nGraphe " << uiBoucle << " Non Oriente\n";
			GRAListeNonOriente[uiBoucle] = *COperation::OPEGrapheNonOriente(GRAcop);
			GRAListeNonOriente[uiBoucle].GRAAfficherGraphe();

			std::cout << "\nEnsemble independant maximum du graphe " << uiBoucle << " Non Oriente\n";
			GRASommetIndependant[uiBoucle] = *COperation::OPEEssembleIndependantSommet(GRAListeNonOriente[uiBoucle]);
			GRASommetIndependant[uiBoucle].GRAAfficherGraphe();
		}
		catch (CException EXCerreur)
		{
			GRAListe[uiBoucle] = GRANull;
			std::cout << "\nLexception n" << EXCerreur.EXCLireValeur() << " a ete levee\n";
			EXCerreur.EXCAfficherErreur();
		}
	}

	_CrtDumpMemoryLeaks();

	return 0;
}

