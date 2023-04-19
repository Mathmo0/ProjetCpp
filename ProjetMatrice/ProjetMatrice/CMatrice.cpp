
/** constructeur par defaut :
		 *
		 * @brief Constructeur permettant d'initialiser une matrice en mettant uiMATNbLigne = 0,uiMATNbColonne = 0 et pTMAMATMatrice = nullptr.
		 *
		 * @param aucun
		 *
		 * @return rien
*/
template<class TTypeMatrice>
CMatrice<TTypeMatrice>::CMatrice()
{
	uiMATNbColonne = 0;
	uiMATNbLigne = 0;
	pTMAMATMatrice = nullptr;
}

/** constructeur par recopie :
 *
 * @brief Constructeur permettant de recopier une matrice dans une autre.
 *
 * @param CMatrice<TTypeMatrice> MATarg : Matrice de type TTypeMatrice, on utilise un passage par reference
 *
 * @return : rien
 */
template<class TTypeMatrice>
CMatrice<TTypeMatrice>::CMatrice(CMatrice<TTypeMatrice>& MATarg)
{
	unsigned int  uiBoucleLigne = 0;
	unsigned int  uiBoucleColonne = 0;

	uiMATNbColonne = MATarg.uiMATNbColonne;
	uiMATNbLigne = MATarg.uiMATNbLigne;

	/*allocation de la matrice : */

	pTMAMATMatrice = new TTypeMatrice *[uiMATNbLigne];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		pTMAMATMatrice[uiBoucleLigne] = new TTypeMatrice[MATarg.uiMATNbColonne];
	}

	/*recopie de la matrice : */

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
		{
			pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] = MATarg.pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne];
		}
	}
}

/** constructeur de confort :
 *
 * @brief Constructeur permettant d'initialiser une matrice avec un nombre de lignes et colonnes donnees.
 *
 * @param unsigned int uiNbLigne : entier naturel qui indique le nombre de lignes dans la matrice ,on utilise un passage par valeur
 * @param unsigned int uiNbColonne : entier naturel qui indique le nombre de colonnes dans la matrice ,on utilise un passage par valeur
 *
 * @throws erreur Dimension : si une des dimension est egal a 0
 *
 * @return : rien
 */
template<class TTypeMatrice>
CMatrice<TTypeMatrice>::CMatrice(unsigned int uiNbLigne, unsigned int uiNbColonne)
{
	
	if(uiNbLigne <= 0 || uiNbColonne <= 0)
	{
		CException EXCerreur(EXCDimensionMatrice, "Une ou les deux dimensions de la matrice est negative ou nulle");
		throw(EXCerreur);
	}

	/*Declaration des variables*/

	unsigned int uiBoucleLigne;

	/* Si les deux dimensions sont egale a 0 alors on fait la meme chose que le constructeur par defaut*/
	
	if(uiNbColonne == 0 && uiNbLigne == 0)
	{
		uiMATNbColonne = 0;
		uiMATNbLigne = 0;
		pTMAMATMatrice = nullptr;
	}

	else
	{
		/*Allocation des lignes : */

		pTMAMATMatrice = new TTypeMatrice*[uiNbLigne];

		/*Allocation des colonnes : */

		for (uiBoucleLigne = 0; uiBoucleLigne < uiNbLigne; uiBoucleLigne++)
		{
			pTMAMATMatrice[uiBoucleLigne] = new TTypeMatrice[uiNbColonne];
		}

		uiMATNbLigne = uiNbLigne;
		uiMATNbColonne = uiNbColonne;
	}
}

/*Constructeur d'une Matrice double a partir d'un fichier .txt

@brief : creer une Matrice a partie d'un fichier texte

@param char * sPath : chaine de caracteres du lien du fichier text

@return : rien
*/
template<class TTypeMatrice>
CMatrice<TTypeMatrice>::CMatrice(char * sPath)
{
	/*verification si le fichier est bien un .txt*/
	char* sTemp = strrchr(sPath, '.');

	if (sTemp == nullptr || strcmp(sTemp, ".txt"))
	{
		CException EXCerreur(EXCFormatFichier, "Le fichier c'est pas au bon format, il doit être en .txt \n");
		throw(EXCerreur);
	}

	/*ouverture du fichier*/

	std::ifstream fFichierMatrice(sPath);
	std::ifstream fFMCop(sPath);

	if (fFichierMatrice.is_open() && fFMCop.is_open())
	{
		int iBoucleColonnes = 0;
		int iBoucleLignes = 0;
		unsigned int iBoucle = 0;

		int iNBLignes = 0;
		int iNBColonnes = 0;

		double dTemp = 0;

		char sBuffer[100];
		char sBuffer2[100];

		char* sType;

		fFichierMatrice.getline(sBuffer, 100);
		fFMCop.getline(sBuffer2, 100);
		while (!strcmp(sBuffer, ""))
		{
			fFichierMatrice.getline(sBuffer, 100);
			fFMCop.getline(sBuffer2, 100);
			if (fFichierMatrice.eof())
			{
				CException EXCerreur(EXCLectureMatriceDansFichier, "Lors de la saisie de la matrice dans le fichier texte veillez respecter le format suivant :\nTypeMatrice=<type_base_C>\nNBLignes = <Nombre_de_lignes_de_la_matrice>\nNBColonnes = <Nombre_de_colonnes_de_la_matrice>\nMatrice = [\n<Ligne_1:autant d’elements que de colonnes>\n<Ligne_n:autant d’elements que de colonnes>\n...\n<Ligne_NBLignes:autant d’elements que de colonnes>\n]\n");
				throw(EXCerreur);
			}
		}

		strtok_s(sBuffer, "=", &sTemp);
		sType = strtok_s(NULL, " ", &sTemp);
		for (iBoucle; iBoucle < strlen(sType); iBoucle++)
		{
			sType[iBoucle] = tolower(sType[iBoucle]);
		}
		if (strcmp(sType, "double"))
		{
			CException EXCerreur(EXCTypeMatriceDansFichier, "Le type de de la matrice doit être \"double\" \n");
			throw(EXCerreur);
		}

		fFichierMatrice.getline(sBuffer, 100);
		fFMCop.getline(sBuffer2, 100);
		while (!strcmp(sBuffer, ""))
		{
			fFichierMatrice.getline(sBuffer, 100);
			fFMCop.getline(sBuffer2, 100);
			if (fFichierMatrice.eof())
			{
				CException EXCerreur(EXCLectureMatriceDansFichier, "Lors de la saisie de la matrice dans le fichier texte veillez respecter le format suivant :\nTypeMatrice=<type_base_C>\nNBLignes = <Nombre_de_lignes_de_la_matrice>\nNBColonnes = <Nombre_de_colonnes_de_la_matrice>\nMatrice = [\n<Ligne_1:autant d’elements que de colonnes>\n<Ligne_n:autant d’elements que de colonnes>\n...\n<Ligne_NBLignes:autant d’elements que de colonnes>\n]\n");
				throw(EXCerreur);
			}
		}

		strtok_s(sBuffer, "=", &sTemp);
		sTemp = strtok_s(NULL, " ", &sTemp);
		iNBLignes = atoi(sTemp);
		MATModifierDimensionLigne(iNBLignes);

		fFichierMatrice.getline(sBuffer, 100);
		fFMCop.getline(sBuffer2, 100);
		while (!strcmp(sBuffer, ""))
		{
			fFichierMatrice.getline(sBuffer, 100);
			fFMCop.getline(sBuffer2, 100);
			if (fFichierMatrice.eof())
			{
				CException EXCerreur(EXCLectureMatriceDansFichier, "Lors de la saisie de la matrice dans le fichier texte veillez respecter le format suivant :\nTypeMatrice=<type_base_C>\nNBLignes = <Nombre_de_lignes_de_la_matrice>\nNBColonnes = <Nombre_de_colonnes_de_la_matrice>\nMatrice = [\n<Ligne_1:autant d’elements que de colonnes>\n<Ligne_n:autant d’elements que de colonnes>\n...\n<Ligne_NBLignes:autant d’elements que de colonnes>\n]\n");
				throw(EXCerreur);
			}
		}

		strtok_s(sBuffer, "=", &sTemp);
		sTemp = strtok_s(NULL, " ", &sTemp);
		iNBColonnes = atoi(sTemp);
		MATModifierDimensionColonne(iNBColonnes);

		fFichierMatrice.getline(sBuffer, 100);
		fFMCop.getline(sBuffer2, 100);
		while (!strcmp(sBuffer, ""))
		{
			fFichierMatrice.getline(sBuffer, 100);
			fFMCop.getline(sBuffer2, 100);
			if (fFichierMatrice.eof())
			{
				CException EXCerreur(EXCLectureMatriceDansFichier, "Lors de la saisie de la matrice dans le fichier texte veillez respecter le format suivant :\nTypeMatrice=<type_base_C>\nNBLignes = <Nombre_de_lignes_de_la_matrice>\nNBColonnes = <Nombre_de_colonnes_de_la_matrice>\nMatrice = [\n<Ligne_1:autant d’elements que de colonnes>\n<Ligne_n:autant d’elements que de colonnes>\n...\n<Ligne_NBLignes:autant d’elements que de colonnes>\n]\n");
				throw(EXCerreur);
			}
		}

		strtok_s(sBuffer, "=", &sTemp);
		sTemp = strtok_s(NULL, " ", &sTemp);
		if (strcmp(sTemp, "["))
		{
			CException EXCerreur(EXCLectureMatriceDansFichier, "Lors de la saisie de la matrice dans le fichier texte veillez respecter le format suivant :\nTypeMatrice=<type_base_C>\nNBLignes = <Nombre_de_lignes_de_la_matrice>\nNBColonnes = <Nombre_de_colonnes_de_la_matrice>\nMatrice = [\n<Ligne_1:autant d’elements que de colonnes>\n<Ligne_n:autant d’elements que de colonnes>\n...\n<Ligne_NBLignes:autant d’elements que de colonnes>\n]\n");
			throw(EXCerreur);
		}

		for (iBoucleLignes; iBoucleLignes < iNBLignes; iBoucleLignes++)
		{
			iBoucleColonnes = 0;
			for (iBoucleColonnes; iBoucleColonnes < iNBColonnes; iBoucleColonnes++)
			{
				fFMCop >> sBuffer;
				strtok_s(sBuffer, ",;/:!'`_(=", &sTemp);
				if (strcmp(sTemp, ""))
				{
					CException EXCerreur(EXCLectureMatriceDansFichier, "Echec lors de la lecture des valeurs");
					throw(EXCerreur);
				}
				fFichierMatrice >> dTemp;
				MATModifierUneValeurDeLaMatrice(dTemp, iBoucleLignes, iBoucleColonnes);
			}
		}
	}
	else
	{
		CException EXCerreur(EXCFormatFichier, "Echec lors de l'ouverture du fichier");
		throw(EXCerreur);
	}

	fFichierMatrice.close();
	fFMCop.close();
}

/** destructeur :
	 *
	 * @brief  desalloue pTMAMATMatrice
	 *
	 * @param aucun
	 *
	 * @return  rien
	 */
template<class TTypeMatrice>
CMatrice<TTypeMatrice>::~CMatrice()
{
	unsigned int uiBoucleLigne;

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		delete[] pTMAMATMatrice[uiBoucleLigne];
	}

	delete[] pTMAMATMatrice;
}

/**
	 * @brief accesseur en lecture pour la variable uiMATNbLigne

	   @param aucun

	   @return uiMATNbLigne : Nombre de lignes dans la matrice
	 */
template<class TTypeMatrice>
inline unsigned int CMatrice<TTypeMatrice>::MATLireDimensionLigne()
{
	return uiMATNbLigne;
};

/**
	 * @brief accesseur en lecture pour la variable uiMATNbColonne

	   @param aucun

	   @return uiMATNbColonne : Nombre de colonnes dans la matrice
	 */
template<class TTypeMatrice>
inline unsigned int CMatrice<TTypeMatrice>::MATLireDimensionColonne()
{
	return uiMATNbColonne;
}

/**
	 * @brief accesseur en ecriture pour la variable uiMATNbLigne

	   @param unsigned int uiLigne : nouveaux nombre(s) de ligne(s) qu'on veut avoir dans la matrice, utilise un passage par valeur

	   @throw erreur dimension :  uiLigne = 0
	 */
template<class TTypeMatrice>
inline void CMatrice<TTypeMatrice>::MATModifierDimensionLigne(unsigned int uiLigne)
{
	unsigned int  uiBoucleLigne = 0;
	unsigned int  uiBoucleColonne = 0;

	//exception dimension :

	if (uiLigne <= 0)
	{
		CException err(EXCDimensionMatrice, "La dimention des lignes ne peut pas etre negative ou nulle");
		throw(err);
	}

	/*Allocation de la nouvelle matrice : */

	TTypeMatrice ** TMAMatriceModifier = new TTypeMatrice*[uiLigne];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiLigne; uiBoucleLigne++)
	{
		TMAMatriceModifier[uiBoucleLigne] = new TTypeMatrice[uiMATNbColonne];
	}

	/* recopie des valeur possible de pTMAMATMatrice dans TMAMatriceModifier.pTMAMATMatrice et init des autres valeurs a 0  : */

	for (uiBoucleLigne = 0; uiBoucleLigne < uiLigne; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
		{
			if (uiBoucleLigne >= uiMATNbLigne)
			{
				TMAMatriceModifier[uiBoucleLigne][uiBoucleColonne] = 0;
			}
			else
			{
				TMAMatriceModifier[uiBoucleLigne][uiBoucleColonne] = pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne];
			}
		}
	}

	/*suppresion de  l'ancienne matrice */

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		delete[] pTMAMATMatrice[uiBoucleLigne];
	}

	delete[] pTMAMATMatrice;

	/* affection de la nouvelle matrice : */
	
	
	pTMAMATMatrice = TMAMatriceModifier;
	uiMATNbLigne = uiLigne;
}

/**
 * @brief accesseur en ecriture pour la variable uiMATNbColonne

   @param unsigned int uiColonne : nouveaux nombre(s) de colonne(s) qu'on veut avoir dans la matrice, utilise un passage par valeur

   @throw erreur dimension :  uiColonne = 0 ou uiMATNbLigne = 0

 */
template<class TTypeMatrice>
inline void CMatrice<TTypeMatrice>::MATModifierDimensionColonne(unsigned int uiColonne)
{

	

	unsigned int  uiBoucleLigne = 0;
	unsigned int  uiBoucleColonne = 0;

	//exception allocation des colonne alors que les lignes ne sont pas allouees

	if (uiColonne <= 0)
	{
		CException EXCerreur(EXCDimensionMatrice, "La dimention des colonnes ne peut pas etre negative ou nulle");
		throw(EXCerreur);
	}

	if (uiMATNbLigne == 0 && pTMAMATMatrice == nullptr)
	{
		CException EXCerreur(EXCMatriceNULL, "Le nombre de lignes est null ou la matrice n'est pas allouee");
		throw(EXCerreur);
	}

	/*Allocation de la nouvelle matrice : */

	TTypeMatrice ** TMAMatriceModifier = new TTypeMatrice*[uiMATNbLigne];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++) 
	{
		TMAMatriceModifier[uiBoucleLigne] = new TTypeMatrice[uiColonne];
	}
	
	/* recopie des valeur possible de pTMAMATMatrice dans TMAMatriceModifier.pTMAMATMatrice et init des autres valeurs a 0  : */

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiColonne; uiBoucleColonne++)
		{
			if (uiBoucleColonne >= uiMATNbColonne)
			{
				TMAMatriceModifier[uiBoucleLigne][uiBoucleColonne] = 0;
			}
			else
			{
				TMAMatriceModifier[uiBoucleLigne][uiBoucleColonne] = pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne];
			}
		}
	}

	/*suppresion de  l'ancienne matrice */

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		delete[] pTMAMATMatrice[uiBoucleLigne];
	}

	delete[] pTMAMATMatrice;

	/* affection de la nouvelle matrice : */

	uiMATNbColonne = uiColonne;
	pTMAMATMatrice = TMAMatriceModifier;

}

/**
	 *  @brief Permet de changer la dimension des lignes et des colonnes de la matrice

		@param unsigned int uiLigne : nouveaux nombre(s) de ligne(s) qu'on veut avoir dans la matrice, si on met aucune valeur uiMATNbLigne est mise comme par valeur defaut

		@param unsigned int uiColonne : nouveaux nombre(s) de colonne(s) qu'on veut avoir dans la matrice, si on met aucune valeur uiMATNbColonne est mise comme par valeur defaut
 */
template<class TTypeMatrice>
inline void CMatrice<TTypeMatrice>::MATModifierDimensionMatrice(unsigned int uiLigne, unsigned int uiColonne)
{

	MATModifierDimensionLigne(uiLigne);
	MATModifierDimensionColonne(uiColonne);
}

/**

@brief accesseur en lecture pour la variable pTMAMATMatrice

@param aucun

@return TTypeMatrice ** : un tableau a 2 dimension de type TTypeMatrice

 */
template<class TTypeMatrice>
inline TTypeMatrice **  CMatrice<TTypeMatrice>::MATLireMatrice()
{
	return pTMAMATMatrice;
}


/**
 * @brief accesseur en ecriture permettant de modifier une valeur de la matrice a une position donnee

   @param TTypeMatrice TMAValeur : valeur qu'on veut affecter dans la matrice, si aucune valeur est indique alors a la valeur par defaut est 0

   @param unsigned int uiLigne : position de la ligne a laquelle on veut affecter TMAValeur, si aucune valeur est indique alors a la valeur par defaut est 0

   @param unsigned int uiColonne : position de la colonne a laquelle on veut affecter TMAValeur, si aucune valeur est indique alors a la valeur par defaut est 0

   @throw erreur indice
 */
template<class TTypeMatrice>
inline void CMatrice<TTypeMatrice>::MATModifierUneValeurDeLaMatrice(TTypeMatrice TMAValeur, unsigned int uiLigne, unsigned int uiColonne)
{
	if (uiColonne > uiMATNbColonne || uiLigne > uiMATNbLigne) 
	{
		CException EXCerreur(EXCIndice, " un ou plusieurs de indice pour acceder a une valuer de la matrice est trop est trop grand ");
		throw(EXCerreur);
	}
	pTMAMATMatrice[uiLigne][uiColonne] = TMAValeur;
}

/**
 * @brief accesseur en lecture permettant de lire une valeur de la matrice

   @param unsigned int uiLigne : position de la ligne a laquelle on veut lire la valeur

   @param unsigned int uiColonne : position de la colonne a laquelle on veut lire la valeur

   @throw erreur indice

   @return une valeur du type generique TTypeMatrice
 */
template<class TTypeMatrice>
inline TTypeMatrice CMatrice<TTypeMatrice>::MATLireUneValeurDeLaMatrice(unsigned int uiLigne, unsigned int uiColonne)
{
	if (uiColonne > uiMATNbColonne || uiLigne > uiMATNbLigne)
	{
		CException EXCerreur(EXCIndice, " un ou plusieurs de indice pour acceder a une valuer de la matrice est trop est trop grand ");
		throw(EXCerreur);
	}

	return pTMAMATMatrice[uiLigne][uiColonne];
}

/**
	 * @brief Affhiche la matrice

	   @throw matrice non initialise (pTMAMATMatrice = nullptr)

	 */
template<class TTypeMatrice>
void CMatrice<TTypeMatrice>::MATAfficherMatrice()
{

	/*Declaration et initialisation des variables : */

	unsigned int  uiBoucleLigne = 0;
	unsigned int  uiBoucleColonne = 0;
	unsigned int uiCompteur = 0;

	//exception si pTMAMATMatrice = NULL;
	if (pTMAMATMatrice == nullptr)
	{
		CException EXCerreur(EXCMatriceNULL, "La matrice est null rien ne peut etre affiche");
		throw(EXCerreur);
	}

	/* Affichage Matrice  */

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
		{
			if (uiCompteur%uiMATNbColonne == 0)
			{
				printf("\n");
			}
			std::cout << pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] << ' ';
			uiCompteur++;
		}
	}
}

/**
	 * @brief initialise toute les valeurs de la matrice a 0 . Si la matrice est non initialise (pTMAMATMatrice = nullptr), la methode ne fait rien
	 */
template<class TTypeMatrice>
void CMatrice<TTypeMatrice>::MATInitMatriceANulle()
{
	unsigned int  uiBoucleLigne = 0;
	unsigned int  uiBoucleColonne = 0;

	/*Initialisation de la matrice en mettant les valeur a 0 : */
	if (pTMAMATMatrice != nullptr)
	{
		for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
		{
			for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
			{
				pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] = 0;
			}
		}
	}
}

/*Modificateur de Matrice a partir d'un fichier

@brief : Extrait une matrice d'un fichier dans une Matrice existante

@param sPath : le chemin d'acces au fichier

@return : rien
*/
template<class TTypeMatrice>
void CMatrice<TTypeMatrice>::MATModifierMatriceExtract(char* sPath)
{
	/*verification si le fichier est bien un .txt*/
	char* sTemp = strrchr(sPath, '.');

	if (sTemp == nullptr || strcmp(sTemp, ".txt"))
	{
		CException EXCerreur(EXCFormatFichier, "Le fichier c'est pas au bon format, il doit être en .txt \n");
		throw(EXCerreur);
	}

	/*ouverture du fichier*/

	std::ifstream fFichierMatrice(sPath);
	std::ifstream fFMCop(sPath);

	if (fFichierMatrice.is_open() && fFMCop.is_open())
	{
		int iBoucleColonnes = 0;
		int iBoucleLignes = 0;
		unsigned int iBoucle = 0;

		int iNBLignes = 0;
		int iNBColonnes = 0;

		double dTemp = 0;

		char sBuffer[100];
		char sBuffer2[100];

		char* sType;
		
		fFichierMatrice.getline(sBuffer, 100);
		fFMCop.getline(sBuffer2, 100);
		while (!strcmp(sBuffer, ""))
		{
			fFichierMatrice.getline(sBuffer, 100);
			fFMCop.getline(sBuffer2, 100);
			if (fFichierMatrice.eof())
			{
				CException EXCerreur(EXCLectureMatriceDansFichier, "Lors de la saisie de la matrice dans le fichier texte veillez respecter le format suivant :\nTypeMatrice=<type_base_C>\nNBLignes = <Nombre_de_lignes_de_la_matrice>\nNBColonnes = <Nombre_de_colonnes_de_la_matrice>\nMatrice = [\n<Ligne_1:autant d’elements que de colonnes>\n<Ligne_n:autant d’elements que de colonnes>\n...\n<Ligne_NBLignes:autant d’elements que de colonnes>\n]\n");
				throw(EXCerreur);
			}
		}

		strtok_s(sBuffer, "=", &sTemp);
		sType = strtok_s(NULL, " ", &sTemp);
		for (iBoucle; iBoucle < strlen(sType); iBoucle++)
		{
			sType[iBoucle] = tolower(sType[iBoucle]);
		}
		if (strcmp(sType, "double"))
		{
			CException EXCerreur(EXCTypeMatriceDansFichier, "Le type de de la matrice doit être \"double\" \n");
			throw(EXCerreur);
		}

		fFichierMatrice.getline(sBuffer, 100);
		fFMCop.getline(sBuffer2, 100);
		while(!strcmp(sBuffer, ""))
		{
			fFichierMatrice.getline(sBuffer, 100);
			fFMCop.getline(sBuffer2, 100);
			if (fFichierMatrice.eof())
			{
				CException EXCerreur(EXCLectureMatriceDansFichier, "Lors de la saisie de la matrice dans le fichier texte veillez respecter le format suivant :\nTypeMatrice=<type_base_C>\nNBLignes = <Nombre_de_lignes_de_la_matrice>\nNBColonnes = <Nombre_de_colonnes_de_la_matrice>\nMatrice = [\n<Ligne_1:autant d’elements que de colonnes>\n<Ligne_n:autant d’elements que de colonnes>\n...\n<Ligne_NBLignes:autant d’elements que de colonnes>\n]\n");
				throw(EXCerreur);
			}
		}

		strtok_s(sBuffer, "=", &sTemp);
		sTemp = strtok_s(NULL, " ", &sTemp);
		iNBLignes = atoi(sTemp);
		if (iNBLignes <= 0)
		{
			CException EXCerreur(EXCDimensionMatrice, "La dimention des lignes ne peut pas etre negative ou nulle");
			throw(EXCerreur);
		}
		MATModifierDimensionLigne(iNBLignes);

		fFichierMatrice.getline(sBuffer, 100);
		fFMCop.getline(sBuffer2, 100);
		while (!strcmp(sBuffer, ""))
		{
			fFichierMatrice.getline(sBuffer, 100);
			fFMCop.getline(sBuffer2, 100);
			if (fFichierMatrice.eof())
			{
				CException EXCerreur(EXCLectureMatriceDansFichier, "Lors de la saisie de la matrice dans le fichier texte veillez respecter le format suivant :\nTypeMatrice=<type_base_C>\nNBLignes = <Nombre_de_lignes_de_la_matrice>\nNBColonnes = <Nombre_de_colonnes_de_la_matrice>\nMatrice = [\n<Ligne_1:autant d’elements que de colonnes>\n<Ligne_n:autant d’elements que de colonnes>\n...\n<Ligne_NBLignes:autant d’elements que de colonnes>\n]\n");
				throw(EXCerreur);
			}
		}

		strtok_s(sBuffer, "=", &sTemp);
		sTemp = strtok_s(NULL, " ", &sTemp);
		iNBColonnes = atoi(sTemp);
		if (iNBColonnes <= 0)
		{
			CException EXCerreur(EXCDimensionMatrice, "La dimention des colonnes ne peut pas etre negative ou nulle");
			throw(EXCerreur);
		}
		MATModifierDimensionColonne(iNBColonnes);

		fFichierMatrice.getline(sBuffer, 100);
		fFMCop.getline(sBuffer2, 100);
		while (!strcmp(sBuffer, ""))
		{
			fFichierMatrice.getline(sBuffer, 100);
			fFMCop.getline(sBuffer2, 100);
			if (fFichierMatrice.eof())
			{
				CException EXCerreur(EXCLectureMatriceDansFichier, "Lors de la saisie de la matrice dans le fichier texte veillez respecter le format suivant :\nTypeMatrice=<type_base_C>\nNBLignes = <Nombre_de_lignes_de_la_matrice>\nNBColonnes = <Nombre_de_colonnes_de_la_matrice>\nMatrice = [\n<Ligne_1:autant d’elements que de colonnes>\n<Ligne_n:autant d’elements que de colonnes>\n...\n<Ligne_NBLignes:autant d’elements que de colonnes>\n]\n");
				throw(EXCerreur);
			}
		}

		strtok_s(sBuffer, "=", &sTemp);
		sTemp = strtok_s(NULL, " ", &sTemp);
		if (strcmp(sTemp, "["))
		{
			CException EXCerreur(EXCLectureMatriceDansFichier, "Lors de la saisie de la matrice dans le fichier texte veillez respecter le format suivant :\nTypeMatrice=<type_base_C>\nNBLignes = <Nombre_de_lignes_de_la_matrice>\nNBColonnes = <Nombre_de_colonnes_de_la_matrice>\nMatrice = [\n<Ligne_1:autant d’elements que de colonnes>\n<Ligne_n:autant d’elements que de colonnes>\n...\n<Ligne_NBLignes:autant d’elements que de colonnes>\n]\n");
			throw(EXCerreur);
		}

		for (iBoucleLignes; iBoucleLignes < iNBLignes; iBoucleLignes++)
		{
			iBoucleColonnes = 0;
			for (iBoucleColonnes; iBoucleColonnes < iNBColonnes; iBoucleColonnes++)
			{
				fFMCop >> sBuffer;
				strtok_s(sBuffer, ",;/:!'`_)(=", &sTemp);
				if (strcmp(sTemp, ""))
				{
					CException EXCerreur(EXCLectureMatriceDansFichier, "Echec lors de la lecture des valeurs");
					throw(EXCerreur);
				}
				fFichierMatrice >> dTemp;
				MATModifierUneValeurDeLaMatrice(dTemp, iBoucleLignes, iBoucleColonnes);
			}
		}
	}
	else
	{
		CException EXCerreur(EXCFormatFichier, "Echec lors de l'ouverture du fichier");
		throw(EXCerreur);
	}

	fFichierMatrice.close();
	fFMCop.close();
}

/**
 * @brief surcharge de l'operateur + pour permettre d'additioner  de 2 matrices

   @param CMatrice<TTypeMatrice> MATarg :  Matrice de type TTypeMatrice, passage par reference

   @throw erreur Dimension : addtioner 2 matrices de dimension differentes

   @return CMatrice<TTypeMatrice> * :  pointeur sur une matrice de type TTypeMatrice representant le resultat de l'addition de 2 Matrice
 */
template<class TTypeMatrice>
inline CMatrice<TTypeMatrice> * CMatrice<TTypeMatrice>::operator+(CMatrice<TTypeMatrice> & MATarg)
{
		//erreur si dimension des 2 matrices sont differentes 

		if (uiMATNbLigne != MATarg.uiMATNbLigne || uiMATNbColonne != MATarg.uiMATNbColonne)
		{
			CException EXCerreur(EXCDimensionMatrice, "Les deux matrices ne sont pas de la meme taille");
			throw(EXCerreur);
		}

		/* Declaration et initialisation des variables : */

		CMatrice<TTypeMatrice> * MATResultatAddition = new CMatrice<TTypeMatrice>(MATarg.uiMATNbLigne, MATarg.uiMATNbColonne);

		unsigned int  uiBoucleLigne = 0;
		unsigned int  uiBoucleColonne = 0;


		/* Addition de 2 matrice : */

		for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
		{
			for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
			{
				MATResultatAddition->pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] = pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] + MATarg.pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne];
			}
		}

		return MATResultatAddition;
}

/**
 * @brief surcharge de l'operateur - pour permettre la soustraction 2 matrices

   @param CMatrice<TTypeMatrice> MATarg : Matrice de type TTypeMatrice, passage par reference

   @throw erreur Dimension : soustraire 2 matrices de dimension differentes

   @return CMatrice<TTypeMatrice> * :  pointeur sur une matrice de type TTypeMatrice representant le resultat de la soustraction de 2 Matrice
 */
template<class TTypeMatrice>
inline CMatrice<TTypeMatrice> * CMatrice<TTypeMatrice> :: operator-(CMatrice<TTypeMatrice>& MATarg)
{
	//erreur si dim des 2 matrice sont differentes 

	if (uiMATNbLigne != MATarg.uiMATNbLigne || uiMATNbColonne != MATarg.uiMATNbColonne)
	{
		CException EXCerreur(EXCDimensionMatrice, "Les deux matrices ne sont pas de la meme taille");
		throw(EXCerreur);
	}

	/*Declaration et initialisation des variables : */

	CMatrice<TTypeMatrice> * MATResultatSoustraction = new CMatrice<TTypeMatrice>(MATarg.uiMATNbLigne, MATarg.uiMATNbColonne);

	unsigned int  uiBoucleLigne = 0;
	unsigned int  uiBoucleColonne = 0;


	/* Soustraction de 2 matrice : */

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
		{
			MATResultatSoustraction->pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] = pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] - MATarg.pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne];
		}
	}

	return MATResultatSoustraction;

};

/**
 * @brief surcharge de l'operateur * pour permettre de multiplier 2 matrices

   @param CMatrice<TTypeMatrice> MATarg : Matrice de type TTypeMatrice

   @throw erreur Dimension

   @return CMatrice<TTypeMatrice> * :  pointeur sur une matrice de type TTypeMatrice representant le resultat de la multiplication de 2 Matrice
 */
template<class TTypeMatrice>
inline CMatrice<TTypeMatrice> * CMatrice<TTypeMatrice> :: operator*(CMatrice<TTypeMatrice>& MATarg)
{
	// exception probleme de dimension 

	if (uiMATNbColonne != MATarg.uiMATNbLigne )
	{
		CException EXCerreur(EXCDimensionMatrice, "Le nombre de colonne de la premiere matrice est differents du nombre de ligne de la seconde matrice");
		throw(EXCerreur);
	}

	if(MATarg.pTMAMATMatrice == nullptr || pTMAMATMatrice == nullptr)
	{
		CException EXCerreur(EXCDimensionMatrice, " Une des matrices n'est pas initialise");
		throw(EXCerreur);
	}
		/* Declaration et initialisation des variables : */
	CMatrice<TTypeMatrice> * MATResultatMultiplication = new CMatrice<TTypeMatrice>(uiMATNbColonne, MATarg.uiMATNbLigne);

	unsigned int  uiBoucleLigne = 0;
	unsigned int  uiBoucleColonne = 0;
	unsigned int  uiBoucle3 = 0;



	/*Initialisation de la matrice MATResultatMultiplication a 0 : */

	MATResultatMultiplication->MATInitMatriceANulle();

	/* Multiplcation de 2 matrice : */
	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
		{
			for (uiBoucle3 = 0; uiBoucle3 < MATarg.uiMATNbColonne; uiBoucle3++)
			{
				MATResultatMultiplication->pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] += pTMAMATMatrice[uiBoucleLigne][uiBoucle3] * MATarg.pTMAMATMatrice[uiBoucle3][uiBoucleColonne];

			}
		}
	}
	return MATResultatMultiplication;
}

/**
 * @brief surcharge de l'operateur * pour permettre de multiplier une matrice avec une variable (postfixee) de type TTypeMatrice  : CMatrice<TTypeMatrice> * variable

   @param TTypeMatrice TMAconstante :  variable de type TTypeMatrice

   @throw erreur matrice non initialisee

   @return CMatrice<TTypeMatrice> * : pointeur sur une matrice de type TTypeMatrice representant le resultat de la multiplication de la matrice par la variable
 */
template<class TTypeMatrice>
inline CMatrice<TTypeMatrice> * CMatrice<TTypeMatrice>::operator*(TTypeMatrice & TMAconstante)
{
	if (pTMAMATMatrice == nullptr)
	{
		CException EXCerreur(EXCDimensionMatrice,"La matrice n'est pas initialise");
		throw(EXCerreur);
	}
	CMatrice<TTypeMatrice> * MATResultatMultiplicationParConstante = new CMatrice<TTypeMatrice>(uiMATNbLigne, uiMATNbColonne);
	unsigned int  uiBoucleLigne = 0;
	unsigned int  uiBoucleColonne = 0;


	/* Multiplication par la constante : */

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
		{
			MATResultatMultiplicationParConstante->pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] = pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] * TMAconstante;
		}
	}

	return MATResultatMultiplicationParConstante;
}

/**
 * @brief surcharge de l'operateur * pour permettre de multiplier une matrice avec une constante (postfixee) de type TTypeMatrice  : CMatrice<TTypeMatrice> * constante

   @param const TTypeMatrice TMAconstante : constante de type TTypeMatrice

   @throw erreur matrice non initialisee

   @return  CMatrice<TMat> * : pointeur sur une matrice de type TTypeMatrice representant le resultat de la multiplication de la matrice par la constante
 */
template<class TTypeMatrice>
inline CMatrice<TTypeMatrice> * CMatrice<TTypeMatrice>::operator*(const TTypeMatrice & TMAconstante)
{
	if (pTMAMATMatrice == nullptr)
	{
		CException EXCerreur(EXCDimensionMatrice, " La matrice n'est pas initialise");
		throw(EXCerreur);
	}

	CMatrice<TTypeMatrice> * MATResultatMultiplicationParConstante = new CMatrice<TTypeMatrice>(uiMATNbLigne, uiMATNbColonne);
	unsigned int  uiBoucleLigne = 0;
	unsigned int  uiBoucleColonne = 0;


	/* Multiplication par la constante : */

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
		{
			MATResultatMultiplicationParConstante->pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] = pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] * TMAconstante;
		}
	}

	return MATResultatMultiplicationParConstante;
}

/**
 * @brief surcharge de l'operateur / pour permettre de multiplier une matrice avec une variable de type TTypeMatrice  : CMatrice<TTypeMatrice> / variable

   @param const TTypeMatrice TMAconstante : variable de type TTypeMatrice

   @throw  division par 0 impossible

   @return  CMatrice<TTypeMatrice> * :  pointeur sur une matrice de type TTypeMatrice representant le resultat de la division de la matrice par la variable
 */
template<class TTypeMatrice>
inline CMatrice<TTypeMatrice> * CMatrice<TTypeMatrice>::operator/(TTypeMatrice & TMAconstante)
{
	//exception si TMAconstante = 0  ou pTMAMATMatrice == nullptr

	if (pTMAMATMatrice == nullptr)
	{
		CException EXCerreur(EXCDimensionMatrice, " La matrice n'est pas initialise");
		throw(EXCerreur);
	}

	if (TMAconstante == 0)
	{
		CException EXCerreur(EXCDivisionParZero, "Division par 0 impossible");
		throw(EXCerreur);
	}

	CMatrice<TTypeMatrice> * MATResultatDivisionParConstante = new CMatrice<TTypeMatrice>(uiMATNbLigne, uiMATNbColonne);
	unsigned int  uiBoucleLigne = 0;
	unsigned int  uiBoucleColonne = 0;


	/* Division par la constante : */

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
		{
			MATResultatDivisionParConstante->pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] = pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] / TMAconstante;
		}
	}

	return MATResultatDivisionParConstante;
}

/**
   @brief surcharge de l'operateur / pour permettre de multiplier une matrice avec une constante de type TTypeMatrice  : CMatrice<TTypeMatrice> / constante

   @param const TTypeMatrice TMAconstante : variable de type TTypeMatrice

   @throw  division par 0 impossible et matrice non initialisee

   @return  CMatrice<TTypeMatrice> * :  pointeur sur une matrice de type TTypeMatrice representant le resultat de la division de la matrice par la constante
 */
template<class TTypeMatrice>
inline CMatrice<TTypeMatrice> * CMatrice<TTypeMatrice>::operator/(const TTypeMatrice & TMAconstante)
{
	//exception si TMAconstante = 0 ou pTMAMATMatrice == nullptr
	if (pTMAMATMatrice == nullptr)
	{
		CException EXCerreur(EXCDimensionMatrice, " La matrice n'est pas initialise");
		throw(EXCerreur);
	}

	if (TMAconstante == 0)
	{
		CException EXCerreur(EXCDivisionParZero, "Division par 0 impossible");
		throw(EXCerreur);
	}


	CMatrice<TTypeMatrice> * MATResultatDivisionParConstante = new CMatrice<TTypeMatrice>(uiMATNbLigne, uiMATNbColonne);
	unsigned int  uiBoucleLigne = 0;
	unsigned int  uiBoucleColonne = 0;


	/* Division par la constante : */

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
		{
			MATResultatDivisionParConstante->pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] = pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] / TMAconstante;
		}
	}

	return MATResultatDivisionParConstante;
}

/**
 * @brief surcharge de l'operateur =  pour permettre d'affacter un pointeur objet de type CMatrice<TTypeMatrice>* dans un objet de type CMatrice<TTypeMatrice>

   @param  CMatrice<TTypeMatrice> *:  pointeur sur une Matrice de type TTypeMatrice

   @return CMatrice<TTypeMatrice> : Une matrice de type TTypeMatrice representant le resultat de l'affectation
 */
template<class TTypeMatrice>
inline CMatrice<TTypeMatrice> & CMatrice<TTypeMatrice> :: operator=(CMatrice<TTypeMatrice> * MATarg)
{
	unsigned int  uiBoucleLigne = 0;
	unsigned int  uiBoucleColonne = 0;


	/*suppresion de la matrice actuelle*/

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		delete[] pTMAMATMatrice[uiBoucleLigne];
	}

	delete[] pTMAMATMatrice;

	/*reallocation de pTMAMATMatrice avec les dimension de MATarg.pTMAMATMatrice */

	uiMATNbLigne = MATarg->uiMATNbLigne;
	uiMATNbColonne = MATarg->uiMATNbColonne;

	pTMAMATMatrice = new TTypeMatrice *[uiMATNbLigne];

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		pTMAMATMatrice[uiBoucleLigne] = new TTypeMatrice[MATarg->uiMATNbColonne];
	}

	/*recopie de MATarg.pTMAMATMatrice dans pTMAMATMatrice*/

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
		{
			pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] = MATarg->pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne];
		}
	}
	
	return * this ;
};

/**
 * @brief surcharge de l'operateur =  pour permettre d'affacter un objet de type CMatrice<TTypeMatrice> dans un autre objet de type CMatrice<TTypeMatrice>

   @param  CMatrice<TTypeMatrice> : Matrice de type TTypeMatrice

   @return CMatrice<TTypeMatrice> : Une matrice de type TTypeMatrice representant le resultat de l'affectation
 */
template<class TTypeMatrice>
inline CMatrice<TTypeMatrice> & CMatrice<TTypeMatrice> :: operator=(CMatrice<TTypeMatrice> MATarg)
{
	unsigned int  uiBoucleLigne = 0;
	unsigned int  uiBoucleColonne = 0;


	/*suppresion de la matrice actuelle*/

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		delete[] pTMAMATMatrice[uiBoucleLigne];
	}

	delete[] pTMAMATMatrice;

	/*reallocation de pTMAMATMatrice avec les dimension de MATarg.pTMAMATMatrice */

	uiMATNbLigne = MATarg.uiMATNbLigne;
	uiMATNbColonne = MATarg.uiMATNbColonne;

	if (uiMATNbLigne == 0 && uiMATNbColonne == 0)
	{
		pTMAMATMatrice = nullptr;
	}
	else
	{
		pTMAMATMatrice = new TTypeMatrice *[uiMATNbLigne];

		for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
		{
			pTMAMATMatrice[uiBoucleLigne] = new TTypeMatrice[MATarg.uiMATNbColonne];
		}

		/*recopie de MATarg.pTMAMATMatrice dans pTMAMATMatrice*/

		for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
		{
			for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
			{
				pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne] = MATarg.pTMAMATMatrice[uiBoucleLigne][uiBoucleColonne];
			}
		}
	}
	return *this;
};