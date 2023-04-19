#include "CMatriceDoubleExtract.h"
#include "CMatrice.h"
#include "CException.h"
#include <istream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

CMatriceDoubleExtract::CMatriceDoubleExtract():CMatrice<double>()
{
	
}

CMatriceDoubleExtract::CMatriceDoubleExtract(char* PATH)
{
	/*verification si le fichier est bien un .txt*/
	char* cTemp = strrchr(PATH, '.');

	if (cTemp == nullptr || strcmp(cTemp,".txt"))
	{
		CException err(0, "Le fichier c'est pas au bon format, il doit être en .txt");
		throw(err);
	}

	/*ouverture du fichier*/
	std::ifstream fFichierMatrice(PATH);

	if (fFichierMatrice.is_open())
	{
		int iBoucleColonnes = 0;
		int iBoucleLignes = 0;

		int iNBLignes = 0;
		int iNBColonnes = 0;

		double dTemp = 0;

		char cBuffer[100];

		char* cType;

		fFichierMatrice >> cBuffer;
		strtok_s(cBuffer, "=", &cType);

		if (strcmp(cType,"double"))
		{
			CException err(1, "Le type de de la matrice doit être \"double\"");
			throw(err);
		}

		fFichierMatrice >> cBuffer;
		strtok_s(cBuffer, "=", &cTemp);
		iNBLignes = atoi(cTemp);
		MATModifierDimensionLigne(iNBLignes);

		fFichierMatrice >> cBuffer;
		strtok_s(cBuffer, "=", &cTemp);
		iNBColonnes = atoi(cTemp);
		MATModifierDimensionColonne(iNBColonnes);

		fFichierMatrice >> cBuffer;

		strtok_s(cBuffer, "=", &cTemp);

		if (strcmp(cTemp, "["))
		{
			CException err(2, "Lors de la saisie de la matrice dans le fichier texte veillez respecter le format suivant :\nTypeMatrice=<type_base_C>\nNBLignes = <Nombre_de_lignes_de_la_matrice>\nNBColonnes = <Nombre_de_colonnes_de_la_matrice>\nMatrice = [\n<Ligne_1:autant d’éléments que de colonnes>\n<Ligne_n:autant d’éléments que de colonnes>\n...\n<Ligne_NBLignes:autant d’éléments que de colonnes>\n]\n");
			throw(err);
		}

		for (iBoucleLignes; iBoucleLignes < iNBLignes; iBoucleLignes++)
		{
			iBoucleColonnes = 0;
			for (iBoucleColonnes; iBoucleColonnes < iNBColonnes; iBoucleColonnes++)
			{
				fFichierMatrice >> dTemp;
				MATModifierUneValeurDeLMatrice(dTemp, iBoucleLignes, iBoucleColonnes);
			}
		}
	}
	else
	{
		CException err(3, "Echec lors de l'ouverture du fichier");
		throw(err);
	}

	fFichierMatrice.close();
}

void CMatriceDoubleExtract::CMDEModifierMatriceExtract(char* PATH)
{
	/*verification si le fichier est bien un .txt*/
	char* cTemp = strrchr(PATH, '.');

	if (cTemp == nullptr || strcmp(cTemp, ".txt"))
	{
		CException err(0, "Le fichier c'est pas au bon format, il doit être en .txt \n");
		throw(err);
	}

	/*ouverture du fichier*/
	std::ifstream fFichierMatrice(PATH);

	if (fFichierMatrice.is_open())
	{
		int iBoucleColonnes = 0;
		int iBoucleLignes = 0;

		int iNBLignes = 0;
		int iNBColonnes = 0;

		double dTemp = 0;

		char cBuffer[100];

		char* cType;

		fFichierMatrice >> cBuffer;
		strtok_s(cBuffer, "=", &cType);

		if (strcmp(cType, "double"))
		{
			CException err(1, "Le type de de la matrice doit être \"double\" \n");
			throw(err);
		}

		fFichierMatrice >> cBuffer;
		strtok_s(cBuffer, "=", &cTemp);
		iNBLignes = atoi(cTemp);
		MATModifierDimensionLigne(iNBLignes);

		fFichierMatrice >> cBuffer;
		strtok_s(cBuffer, "=", &cTemp);
		iNBColonnes = atoi(cTemp);
		MATModifierDimensionColonne(iNBColonnes);

		fFichierMatrice >> cBuffer;

		strtok_s(cBuffer, "=", &cTemp);

		if (strcmp(cTemp, "["))
		{
			CException err(2, "Lors de la saisie de la matrice dans le fichier texte veillez respecter le format suivant :\nTypeMatrice=<type_base_C>\nNBLignes = <Nombre_de_lignes_de_la_matrice>\nNBColonnes = <Nombre_de_colonnes_de_la_matrice>\nMatrice = [\n<Ligne_1:autant d’éléments que de colonnes>\n<Ligne_n:autant d’éléments que de colonnes>\n...\n<Ligne_NBLignes:autant d’éléments que de colonnes>\n]\n");
			throw(err);
		}

		for (iBoucleLignes; iBoucleLignes < iNBLignes; iBoucleLignes++)
		{
			iBoucleColonnes = 0;
			for (iBoucleColonnes; iBoucleColonnes < iNBColonnes; iBoucleColonnes++)
			{
				fFichierMatrice >> dTemp;
				MATModifierUneValeurDeLMatrice(dTemp, iBoucleLignes, iBoucleColonnes);
			}
		}
	}
	else
	{
		CException err(3, "Echec lors de l'ouverture du fichier");
		throw(err);
	}

	fFichierMatrice.close();
}