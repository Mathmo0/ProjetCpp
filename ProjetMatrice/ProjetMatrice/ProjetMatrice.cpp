// ProjetMatrice.cpp : Ce fichier contient la fonction 'main'. L'execution du programme commence et se termine a cet endroit.

//Outils pour les fuites memoires
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

#include <iostream>
#include <stdlib.h>
#include "CMatrice.h"
#include "CException.h"
#include "COperation.h"
#include "CListeMatrice.h"


int main(int argc, char** argv) 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //verification des fuites de memoire
	
	unsigned int uiBoucle = 1;
	int iValeur;
	int iAlt = 0;
	
	CListeMatrice<double> MATListe(argc);

	CMatrice<double> MATResultat;
	CMatrice<double> MATNull;
	
	std::cout << "\n _______________________initialisation des Matrices_______________________ \n";

	for (uiBoucle; uiBoucle < argc; uiBoucle++)
	{
		try
		{
			MATListe[uiBoucle].MATModifierMatriceExtract(argv[uiBoucle]);
			std::cout << "\nM" << uiBoucle << "=";
			MATListe[uiBoucle].MATAfficherMatrice();
			std::cout << "\n";

		}
		catch (CException EXCerreur)
		{
			MATListe[uiBoucle] = MATNull;
			std::cout << "\nLexception n" << EXCerreur.EXCLireValeur() << " a ete levee \n";			
			EXCerreur.EXCAfficherErreur();
		}
	}

	/*Operations*/
	std::cout << "\n _______________________operations sur les Matrices_______________________ \n";
	std::cout << "\nDivisions : \n";
	std::cout << "Saisir une valeur pour c \n";
	std::cin >> iValeur;

	for (uiBoucle = 1; uiBoucle < argc; uiBoucle++)
	{
		try
		{
			std::cout << "M" << uiBoucle << "/" << iValeur << "=";
			MATResultat = MATListe[uiBoucle] / iValeur;
			MATResultat.MATAfficherMatrice();
			std::cout << "\n\n";
		}
		catch (CException EXCerreur)
		{
			std::cout << "\nLexception n" << EXCerreur.EXCLireValeur() << " a ete levee \n";
			EXCerreur.EXCAfficherErreur();
		}
	}

	MATResultat = MATNull;

	std::cout << "\nSomme de toutes les matrices : \n";
	
	for (uiBoucle = 1; uiBoucle < argc; uiBoucle++)
	{
		try
		{
			if (MATListe[uiBoucle].MATLireMatrice() != nullptr)
			{
				if (MATResultat.MATLireMatrice() == nullptr)
				{
					MATResultat = MATListe[uiBoucle];
				}
				else
				{
					MATResultat = MATResultat + MATListe[uiBoucle];
				}
			}
		}
		catch (CException EXCerreur)
		{
			std::cout << "\nLexception n" << EXCerreur.EXCLireValeur() << " a ete levee \n";
			EXCerreur.EXCAfficherErreur();
		}
	}
	
	try
	{
		MATResultat.MATAfficherMatrice();
	}
	catch (CException EXCerreur)
	{
		std::cout << "\nLexception n" << EXCerreur.EXCLireValeur() << " a ete levee \n";
		EXCerreur.EXCAfficherErreur();
	}
	
	MATResultat = MATNull;

	std::cout << "\n\nOperation de type M1 - M2 + M3 - M4 ... : \n";

	for (uiBoucle = 1; uiBoucle < argc; uiBoucle++)
	{
		try
		{
			if (MATListe[uiBoucle].MATLireMatrice() != nullptr)
			{
				if (MATResultat.MATLireMatrice() == nullptr)
				{
					MATResultat = MATListe[uiBoucle];
				}
				else
				{
					if (iAlt == 0)
					{
						CMatrice<double> MATTemp(MATResultat);
						MATResultat = MATTemp - MATListe[uiBoucle];
						iAlt = 1;
					}
					else
					{
						MATResultat = MATResultat + MATListe[uiBoucle];
						iAlt = 0;
					}
				}
			}
		}
		catch (CException EXCerreur)
		{
			std::cout << "\nLexception n" << EXCerreur.EXCLireValeur() << " a ete levee \n";
			EXCerreur.EXCAfficherErreur();
		}
	}

	try
	{
		MATResultat.MATAfficherMatrice();
	}
	catch (CException EXCerreur)
	{
		std::cout << "\nLexception n" << EXCerreur.EXCLireValeur() << " a ete levee \n";
		EXCerreur.EXCAfficherErreur();
	}

	MATResultat = MATNull;

	std::cout << "\n\nMultiplication de toutes les matrices entre elles : \n";

	for (uiBoucle = 1; uiBoucle < argc; uiBoucle++)
	{
		try
		{
			if (MATListe[uiBoucle].MATLireMatrice() != nullptr)
			{
				if (MATResultat.MATLireMatrice() == nullptr)
				{
					MATResultat = MATListe[uiBoucle];
				}
				else
				{
					MATResultat = MATResultat * MATListe[uiBoucle];
				}
			}
		}
		catch (CException EXCerreur)
		{
			std::cout << "\nLexception n" << EXCerreur.EXCLireValeur() << " a ete levee \n";
			EXCerreur.EXCAfficherErreur();
		}
	}

	try
	{
		MATResultat.MATAfficherMatrice();
	}
	catch (CException EXCerreur)
	{
		std::cout << "\nLexception n" << EXCerreur.EXCLireValeur() << " a ete levee \n";
		EXCerreur.EXCAfficherErreur();
	}

	printf("\n ____________________\n ");

	_CrtDumpMemoryLeaks();

	return 0;
}