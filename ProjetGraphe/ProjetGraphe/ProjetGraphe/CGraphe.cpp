#include "CGraphe.h"

/** Constructeur par defaut

	   @brief permet d'initialiser un objet de type CGraphe

	   @param aucun

       @return rien
*/
CGraphe::CGraphe()
{

}

/** Constructeur de recopie
	 
	   @brief permet de d'initialiser un objet de type CGraphe a partir d'un autre objet de type CGraphe

	   @param CGraphe GRAarg : objet de type CGraphe

	   @return rien

*/
CGraphe::CGraphe(CGraphe & GRAarg)
{
	LISGRAListeSommet = GRAarg.LISGRAListeSommet;
}

/** Constructeur de confort 
	 
	   @brief permet d'initialiser un objet de type CGraphe avec une taille de liste donnee

	   @param unsigned uiTaille  : un entier naturel 

	   @return rien 
*/
CGraphe::CGraphe(unsigned int uiTaille)
{
	LISGRAListeSommet.LISModifierTailleTableau(uiTaille);
}

/** constructeur de confort
	 
	   @brief permet d'initialier un objet de type graphe en donne une liste de sommet

	   @param CListe<CSommet> LISarg : une liste de type CSommet

	   @return rien
*/
CGraphe::CGraphe(CListe<CSommet> LISarg)
{
	LISGRAListeSommet = LISarg;
}

/* Constructeur a partir d'un fichier .txt

		@brief : construit un graphe a partir d'un fichier .txt

		@param char * sPath : un chemin vers le fichier .txt

		@throw exceptions liee aux fichiers
	
		@return rien
*/
CGraphe::CGraphe(char * sPath)
{
	/*Verification si le fichier est bien un .txt*/
	char* sTemp = strrchr(sPath, '.');

	if (sTemp == nullptr || strcmp(sTemp, ".txt"))
	{
		CException EXCerreur(EXCCheminFichier, "Le fichier c'est pas au bon format, il doit etre en .txt \n");
		throw(EXCerreur);
	}

	/*Ouverture du fichier*/
	std::ifstream fFichierGraphe(sPath);
	std::ifstream fFGCop(sPath);

	if (fFichierGraphe.is_open() && fFGCop.is_open())
	{
		unsigned int uiNbSommet = 0; 
		unsigned int uiNbArc = 0; 
		unsigned int uiBoucleSommet = 0; //Variable pour la boucle for de creation des sommets
		unsigned int uiBoucleArc = 0; //Variable pour la boucle for de creation des arcs
		unsigned int uiBoucle = 0; //Variable pour la boucle for de mise en minuscule
		unsigned int uiNumSommet = 0;  
		unsigned int uiNumSommetDeb = 0; 
		unsigned int uiNumSommetFin = 0; 
		unsigned int uiTailleListe = 0; 

		char* sBuffer; //Variable pour stocker une chaine de caractere lu dans le fichier
		char* sBufferBis; //Variable pour stocker une chaine de caractere lu dans le fichier
		char* sTempBis; //Variable pour stocker une chaine de caractere 
		sBuffer = (char*)malloc(100 * sizeof(char));
		sBufferBis = (char*)malloc(100 * sizeof(char));

		CArc * pARCTemp = new CArc(); 
		CSommet * pSOMTemp = new CSommet(); 
		CSommet ** pSOMTempBis = nullptr; 

		/*Nombre de sommet*/
		fFichierGraphe.getline(sBuffer, 100);
		fFGCop.getline(sBufferBis, 100);
		while (!strcmp(sBuffer, ""))
		{
			fFichierGraphe.getline(sBuffer, 100);
			fFGCop.getline(sBufferBis, 100);

			if (fFichierGraphe.eof())
			{
				//Si on atteint la fin du fichier
				delete pSOMTemp;
				delete pARCTemp;
				free(sBuffer);
				free(sBufferBis);
				CException EXCerreur(EXCFormatFichier, "Lors de la saisie du graphe dans le fichier texte veillez respecter le format suivant : \nNBSommets=<Nombre_de_Sommets_du_graphe> \nNBArcs = < Nombre_d_arcs_du_graphe > \nSommets = [ \nNumero = <Numero_sommet > \nNumero = <Numero_sommet> \n . . . \nNumero = <Numero_sommet> \n] \nArcs = [ \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n . . . \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n] \n");
				throw(EXCerreur);
			}
		}
		strtok_s(sBuffer, "=", &sTemp);
		sTemp = strtok_s(NULL, " /.;?$!", &sTemp);
		if (sTemp == NULL)
		{
			CException EXCerreur(EXCLectureGrapheDansFichier, "Aucune valeur n'a pu etre lu comme nombre de sommet");
			throw(EXCerreur);
		}
		uiNbSommet = atoi(sTemp);

		/*Nombre d'arc*/
		fFichierGraphe.getline(sBuffer, 100);
		fFGCop.getline(sBufferBis, 100);
		while (!strcmp(sBuffer, ""))
		{
			fFichierGraphe.getline(sBuffer, 100);
			fFGCop.getline(sBufferBis, 100);

			if (fFichierGraphe.eof())
			{
				//Si on atteint la fin du fichier
				free(sBuffer);
				free(sBufferBis);
				delete pSOMTemp;
				delete pARCTemp;
				CException EXCerreur(EXCFormatFichier, "Lors de la saisie du graphe dans le fichier texte veillez respecter le format suivant : \nNBSommets=<Nombre_de_Sommets_du_graphe> \nNBArcs = < Nombre_d_arcs_du_graphe > \nSommets = [ \nNumero = <Numero_sommet > \nNumero = <Numero_sommet> \n . . . \nNumero = <Numero_sommet> \n] \nArcs = [ \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n . . . \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n] \n");
				throw(EXCerreur);
			}
		}
		strtok_s(sBuffer, "=", &sTemp);
		sTemp = strtok_s(NULL, " /.;?$!", &sTemp);
		if (sTemp == NULL)
		{
			CException EXCerreur(EXCLectureGrapheDansFichier, "Aucune valeur n'a pu etre lu comme nombre d'arc");
			throw(EXCerreur);
		}
		uiNbArc = atoi(sTemp);

		/*Sommet*/
		fFichierGraphe.getline(sBuffer, 100);
		fFGCop.getline(sBufferBis, 100);
		while (!strcmp(sBuffer, ""))
		{
			fFichierGraphe.getline(sBuffer, 100);
			fFGCop.getline(sBufferBis, 100);

			if (fFichierGraphe.eof())
			{
				//Si on atteint la fin du fichier
				delete pSOMTemp;
				delete pARCTemp;
				free(sBuffer);
				free(sBufferBis);
				CException EXCerreur(EXCFormatFichier, "Lors de la saisie du graphe dans le fichier texte veillez respecter le format suivant : \nNBSommets=<Nombre_de_Sommets_du_graphe> \nNBArcs = < Nombre_d_arcs_du_graphe > \nSommets = [ \nNumero = <Numero_sommet > \nNumero = <Numero_sommet> \n . . . \nNumero = <Numero_sommet> \n] \nArcs = [ \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n . . . \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n] \n");
				throw(EXCerreur);
			}
		}
		strtok_s(sBuffer, "=", &sTemp);
		sTemp = strtok_s(NULL, " ", &sTemp);
		if (strcmp(sTemp, "["))
		{
			//Si le Format n'est pas respecte
			delete pSOMTemp;
			delete pARCTemp;
			free(sBuffer);
			free(sBufferBis);
			CException EXCerreur(EXCFormatFichier, "Lors de la saisie du graphe dans le fichier texte veillez respecter le format suivant : \nNBSommets=<Nombre_de_Sommets_du_graphe> \nNBArcs = < Nombre_d_arcs_du_graphe > \nSommets = [ \nNumero = <Numero_sommet > \nNumero = <Numero_sommet> \n . . . \nNumero = <Numero_sommet> \n] \nArcs = [ \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n . . . \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n] \n");
			throw(EXCerreur);
		}
		for (uiBoucleSommet; uiBoucleSommet < uiNbSommet; uiBoucleSommet++)
		{
			do
			{
				fFichierGraphe.getline(sBuffer, 100);
				fFGCop.getline(sBufferBis, 100);

				if (fFichierGraphe.eof())
				{
					//Si on atteint la fin du fichier
					delete pSOMTemp;
					delete pARCTemp;
					free(sBuffer);
					free(sBufferBis);
					CException EXCerreur(EXCFormatFichier, "Lors de la saisie du graphe dans le fichier texte veillez respecter le format suivant : \nNBSommets=<Nombre_de_Sommets_du_graphe> \nNBArcs = < Nombre_d_arcs_du_graphe > \nSommets = [ \nNumero = <Numero_sommet > \nNumero = <Numero_sommet> \n . . . \nNumero = <Numero_sommet> \n] \nArcs = [ \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n . . . \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n] \n");
					throw(EXCerreur);
				}
			} while (!strcmp(sBuffer, ""));
			strtok_s(sBuffer, "=", &sTemp);
			sTemp = strtok_s(NULL, " /.;?$!", &sTemp);
			if (sTemp == NULL)
			{
				CException EXCerreur(EXCLectureGrapheDansFichier, "Aucune valeur n'a pu etre lu comme numero de sommet");
				throw(EXCerreur);
			}
			pSOMTemp->SOMModifierNumSommet(atoi(sTemp));
			LISGRAListeSommet.LISAjouterUnElementDansLeTableau(pSOMTemp);
			
		}
		delete pSOMTemp;

		/*Arc*/
		do
		{
			fFichierGraphe.getline(sBuffer, 100);
			fFGCop.getline(sBufferBis, 100);

			if (fFichierGraphe.eof())
			{
				//Si on atteint la fin du fichier
				delete pARCTemp;
				free(sBuffer);
				free(sBufferBis);
				CException EXCerreur(EXCFormatFichier, "Lors de la saisie du graphe dans le fichier texte veillez respecter le format suivant : \nNBSommets=<Nombre_de_Sommets_du_graphe> \nNBArcs = < Nombre_d_arcs_du_graphe > \nSommets = [ \nNumero = <Numero_sommet > \nNumero = <Numero_sommet> \n . . . \nNumero = <Numero_sommet> \n] \nArcs = [ \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n . . . \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n] \n");
				throw(EXCerreur);
			}
		} while (!strcmp(sBuffer, "]") || !strcmp(sBuffer, ""));
		strtok_s(sBuffer, "=", &sTemp);
		sTemp = strtok_s(NULL, " ", &sTemp);
		if (strcmp(sTemp, "[") != 0)
		{
			//Si le Format n'est pas respecte
			delete pARCTemp;
			free(sBuffer);
			free(sBufferBis);
			CException EXCerreur(EXCFormatFichier, "Lors de la saisie du graphe dans le fichier texte veillez respecter le format suivant : \nNBSommets=<Nombre_de_Sommets_du_graphe> \nNBArcs = < Nombre_d_arcs_du_graphe > \nSommets = [ \nNumero = <Numero_sommet > \nNumero = <Numero_sommet> \n . . . \nNumero = <Numero_sommet> \n] \nArcs = [ \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n . . . \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n] \n");
			throw(EXCerreur);
		}
		for (uiBoucleArc; uiBoucleArc < uiNbArc; uiBoucleArc++)
		{
			do
			{
				fFichierGraphe.getline(sBuffer, 100);
				fFGCop.getline(sBufferBis, 100);

				
				if (strcmp(sBuffer, "]") == 0)
				{
					free(sBuffer);
					free(sBufferBis);
					delete pARCTemp;
					return;
				}
				else if (fFichierGraphe.eof())
				{
					//Si on atteint la fin du fichier
					delete pARCTemp;
					free(sBuffer);
					free(sBufferBis);
					CException EXCerreur(EXCFormatFichier, "Lors de la saisie du graphe dans le fichier texte veillez respecter le format suivant : \nNBSommets=<Nombre_de_Sommets_du_graphe> \nNBArcs = < Nombre_d_arcs_du_graphe > \nSommets = [ \nNumero = <Numero_sommet > \nNumero = <Numero_sommet> \n . . . \nNumero = <Numero_sommet> \n] \nArcs = [ \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n . . . \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n] \n");
					throw(EXCerreur);
				}
			} while (!strcmp(sBuffer, ""));
			
			

			strtok_s(sBuffer, "=", &sTemp);
			strtok_s(sTemp,"=", &sTempBis);
			sTempBis = strtok_s(NULL, " /.;?$!", &sTempBis);
			sTemp = strtok_s(NULL, ",", &sTemp);  
			sTemp = strtok_s(NULL, " /.;?$!", &sTemp);  
			sBuffer = strtok_s(NULL, " ", &sBuffer);
			if (sTemp == NULL)
			{
				CException EXCerreur(EXCLectureGrapheDansFichier, "Aucune valeur n'a pu etre lu dans l'arc");
				throw(EXCerreur);
			}
			else if (sTempBis == NULL)
			{
				CException EXCerreur(EXCLectureGrapheDansFichier, "Aucune valeur n'a pu etre lu dans l'arc");
				throw(EXCerreur);
			}
			
			uiNumSommetDeb = atoi(sTemp);
			uiNumSommetFin = atoi(sTempBis);

			strtok_s(sBufferBis, ",", &sTempBis);
			
			strtok_s(sTempBis, "=", &sTemp);
			
			sTempBis = strtok_s(NULL, " ", &sTempBis);
			
			if (sBuffer == NULL || sTempBis == NULL)
			{
				//Si le Format n'est pas respecte
				free(sBuffer);
				free(sBufferBis);
				delete pARCTemp;
				CException EXCerreur(EXCFormatFichier, "Lors de la saisie du graphe dans le fichier texte veillez respecter le format suivant : \nNBSommets=<Nombre_de_Sommets_du_graphe> \nNBArcs = < Nombre_d_arcs_du_graphe > \nSommets = [ \nNumero = <Numero_sommet > \nNumero = <Numero_sommet> \n . . . \nNumero = <Numero_sommet> \n] \nArcs = [ \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n . . . \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n] \n");
				throw(EXCerreur);
			}
			
			for (uiBoucle = 0; uiBoucle < strlen(sBuffer); uiBoucle++)
			{
				sTemp[uiBoucle] = tolower(sBuffer[uiBoucle]);
			}
			sTemp[strlen(sBuffer)] = '\0';
			
			for (uiBoucle = 0; uiBoucle < strlen(sTempBis); uiBoucle++)
			{
				sTempBis[uiBoucle] = tolower(sTempBis[uiBoucle]);
			}
			if ((strcmp(sTemp, "debut") != 0) || (strcmp(sTempBis, "fin") != 0))
			{
				//Si le Format n'est pas respecte
				free(sBuffer);
				free(sBufferBis);
				delete pARCTemp;
				CException EXCerreur(EXCFormatFichier, "Lors de la saisie du graphe dans le fichier texte veillez respecter le format suivant : \nNBSommets=<Nombre_de_Sommets_du_graphe> \nNBArcs = < Nombre_d_arcs_du_graphe > \nSommets = [ \nNumero = <Numero_sommet > \nNumero = <Numero_sommet> \n . . . \nNumero = <Numero_sommet> \n] \nArcs = [ \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n . . . \nDebut = <Sommet_depart_arc>, Fin = <Sommet_arrivee_arc> \n] \n");
				throw(EXCerreur);
			}

			pSOMTempBis = LISGRAListeSommet.LISLireTableau();

			for (uiBoucleSommet = 0; uiBoucleSommet < uiNbSommet; uiBoucleSommet++)
			{
				uiNumSommet = pSOMTempBis[uiBoucleSommet]->SOMLireNumSommet();
				if (uiNumSommet == uiNumSommetDeb)
				{
					
					pSOMTemp = pSOMTempBis[uiBoucleSommet];
					break;
				}
				else if(uiBoucleSommet == uiNbSommet - 1)
				{
					//le sommet d'un arc n'est pas dans le graphe
					free(sBuffer);
					free(sBufferBis);
					delete pARCTemp;
					CException EXCerreur(EXCLectureGrapheDansFichier, "Un arc est incoherent, le numero du sommet ne correspond pas");
					throw(EXCerreur);
				}
			}

			pARCTemp->ARCModifier(uiNumSommetFin);
			
			pSOMTemp->SOMAjouterUnArcListePartant(pARCTemp);

			pSOMTempBis = LISGRAListeSommet.LISLireTableau();

			for (uiBoucleSommet = 0; uiBoucleSommet < uiNbSommet; uiBoucleSommet++)
			{
				uiNumSommet = pSOMTempBis[uiBoucleSommet]->SOMLireNumSommet();
				if (uiNumSommet == uiNumSommetFin)
				{
					pSOMTemp = pSOMTempBis[uiBoucleSommet];
					break;
				}
				else if (uiBoucleSommet == uiNbSommet - 1)
				{
					//le sommet d'un arc n'est pas dans le graphe
					free(sBuffer);
					free(sBufferBis);
					delete pARCTemp;
					CException EXCerreur(EXCLectureGrapheDansFichier, "Un arc est incoherent, le numero du sommet ne correspond pas");
					throw(EXCerreur);
				}
			}

			pARCTemp->ARCModifier(uiNumSommetDeb);
			
			pSOMTemp->SOMAjouterUnArcListeArrivant(pARCTemp);

			
		}
		delete pARCTemp;
		free(sBuffer);
		free(sBufferBis);

	}
	else
	{
		//Si l'ouverture du fichier echoue
		CException EXCerreur(EXCCheminFichier, "Le fichier n'a pas pu etre ouvert, verifier que le chemin d'acces est bien correct \n");
		throw(EXCerreur);
	}
}

/** Destructeur
	 
		@brief detruit l'objet

		@param aucun

		@return rien
*/
CGraphe::~CGraphe()
{

}

/* Accesseur en lecture pour l'attribut LISGRAListeSommet

		@brief permet de lire l'attribut LISGRAListeSommet

		@param aucun

		@return LISGRAListeSommet  : un objet CListe de type CSommet
*/
CListe<CSommet> CGraphe::GRALireListeSommet()
{
	return LISGRAListeSommet;
}

/** Accesseur en ecriture pour l'attribut LISGRAListeSommet. la position commence a 0

		@brief permet de modifier un sommet du graphe

		@param * CSommet SOMarg : un CSommet
		@param unsigned int uiIndice : la position dans la liste

		@return rien
	 
*/
void CGraphe::GRAModifierSommet(CSommet * pSOMarg, unsigned int uiIndice)
{
	LISGRAListeSommet.LISModifierUnElementDuTableau(uiIndice,pSOMarg);
}

/* Fonction d'ajout d'un sommet

		 @brief Permet d'ajouter un sommet a LISGRAListeSommet en derniere position

		 @param CSommet * pARCarg : Element a ajouter de type CSommet *, par default on ajoute un CSommet initialiser avec le contructeur par defaut

		 @return rien
*/
void CGraphe :: GRAAjouterSommet(CSommet * pSOMArg)
{
	LISGRAListeSommet.LISAjouterUnElementDansLeTableau(pSOMArg);
}

/* Suppression d'un sommet

		@brief Permet de supprimer le dernier element de LISGRAListeSommet

		@param aucun

		@return rien
	*/
void CGraphe :: GRASupprimerSommet()
{
	LISGRAListeSommet.LISSUpprimerUnElementDansLeTableau();
}

/* Suppression d'un sommet

		@brief Permet de supprimer un element de LISGRAListeSommet a une position donne

		@param aucun

		@return rien
	*/
void CGraphe::GRASupprimerSommet(unsigned int uiPosition)
{
	LISGRAListeSommet.LISSUpprimerUnElementDansLeTableau(uiPosition);
}

/* Modifier un graphe a partir d'un fichier .txt

		@brief : modifie un graphe a partir d'un fichier .txt

		@param char * sPath : un chemin vers le fichier .txt

		@return rien
*/
void CGraphe::GRAModifierGraphe(char * sPath)
{
	CGraphe GRATemp(sPath);

	LISGRAListeSommet = GRATemp.LISGRAListeSommet;
}

/* Affichage du graphe

	   @brief permet d'afficher toutes les informations concernant un graphe

	   @param aucun

	   @return rien
*/
void CGraphe::GRAAfficherGraphe()
{
	unsigned int uiBoucleSommet = 0; //Variable pour les boucles for pour parcourir les sommets
	unsigned int uiBoucleArc = 0; //Variable pour les boucles for pour parcourir les arcs
	unsigned int uiNbSommets = 0; 
	unsigned int uiNbArc = 0;

	CSommet * pSOMTemp = nullptr;
	CArc * pARCTemp = nullptr;
	CSommet ** pSOMTempBis = nullptr;
	CArc ** pARCTempBis = nullptr;
	

	uiNbSommets = LISGRAListeSommet.LISLireTailleTableau();
	pSOMTempBis = LISGRAListeSommet.LISLireTableau();

	//Affichage de la liste des sommets
	std::cout << "Liste des Sommets : ";

	for (uiBoucleSommet = 0; uiBoucleSommet < uiNbSommets; uiBoucleSommet++)
	{
		pSOMTemp = pSOMTempBis[uiBoucleSommet];

		std::cout << pSOMTemp->SOMLireNumSommet(); //Affiche le numero du sommet

		if (uiBoucleSommet != uiNbSommets - 1)
		{
			std::cout << " ; ";
		}
	}

	//Affichage de la liste des arcs
	std::cout << "\nListe des arcs : \n";

	for (uiBoucleSommet = 0; uiBoucleSommet < uiNbSommets; uiBoucleSommet++)
	{
		pSOMTemp = pSOMTempBis[uiBoucleSommet];
		pARCTempBis = pSOMTemp->SOMLireListePartant();
		uiNbArc = pSOMTemp->SOMLireTailleListePartant();
		for (uiBoucleArc = 0; uiBoucleArc < uiNbArc; uiBoucleArc++)
		{
			pARCTemp = pARCTempBis[uiBoucleArc];
			std::cout << pSOMTemp->SOMLireNumSommet() << "->" << pARCTemp->ARCLireDestination() << "\n";
		}
	}
}

/* Inversion du graphe

		@brief permet dinverser un graphe pour en obtenir un nouveau

		@param rien

		@return CGraphe
*/
CGraphe & CGraphe::GRAInverserGraphe()
{
	unsigned int uiBoucleSommet = 0;
	unsigned int uiNbSommets = LISGRAListeSommet.LISLireTailleTableau();
	
	CSommet ** pSOMTempBis;
	pSOMTempBis = LISGRAListeSommet.LISLireTableau();

	for (uiBoucleSommet = 0; uiBoucleSommet < uiNbSommets; uiBoucleSommet++)
	{
		pSOMTempBis[uiBoucleSommet]->SOMInverserListePartantArrivant();
		LISGRAListeSommet.LISModifierUnElementDuTableau(uiBoucleSommet, pSOMTempBis[uiBoucleSommet]);
	}


	return *this;
}

/* Suppresion Doublon

		@brief Permet de supprimer les sommet en double dans la liste

		@param aucun

		@return rien

	*/
void CGraphe::GRASuppresionDoublon() 
{
	unsigned int uiBoucle;
	CSommet SOMTemp;

	CListe<CSommet>::LISSupprimerDoublons(LISGRAListeSommet);

	for (uiBoucle = 0; uiBoucle < LISGRAListeSommet.LISLireTailleTableau(); uiBoucle++) 
	{
		SOMTemp = LISGRAListeSommet[uiBoucle];
		SOMTemp.SupprimerArcDoublon();
		//LISGRAListeSommet.LISModifierUnElementDuTableau(uiBoucle, &SOMTemp);
		this->GRAModifierSommet(&SOMTemp, uiBoucle);
	}

	//delete SOMTemp;

	
}

/* Surcharge de l'operateur =

		@brief permet l'operation "=" entre les objets de type CGraphe

		@param CGraphe GRAArg : un graphe

		@return CGraphe
*/
CGraphe & CGraphe::operator=(CGraphe GRAArg)
{
	LISGRAListeSommet = GRAArg.LISGRAListeSommet;

	return *this;
}

/* Surcharge de l'operateur ==

		@brief Permet si deux objet de la classe CGraphe sont identique ou non

		@param GRAEquivalent : objet de type CGraphe

		@return 0 si les 2 objets sont egale, 1 sinon

*/
int CGraphe::operator==(CGraphe & GRAEquivalent)
{
	return LISGRAListeSommet.operator==(GRAEquivalent.LISGRAListeSommet);
}

/* Surcharge de l'operateur !=

	@brief Permet de savoir si 2 objet de type CGraphe sont different

	@param CGraphe GRADifferent : objet de type CGraphe, objet utilise pour la comparaison

	@return 0 si les 2 objets sont differents, 1 sinon

*/
int CGraphe::operator!=(CGraphe & GRADifferent)
{
	unsigned int uiBoucle = 0;
	
	for (uiBoucle = 0; uiBoucle < LISGRAListeSommet.LISLireTailleTableau(); uiBoucle++)
	{
		if (*(LISGRAListeSommet.LISLireTableau()[uiBoucle]) != *(GRADifferent.LISGRAListeSommet.LISLireTableau()[uiBoucle]))
		{
			return 0;
		}
	}
	return 1;
}

