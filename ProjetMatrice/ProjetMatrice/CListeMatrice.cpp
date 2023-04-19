/*  Constructeur par defaut :
	@brief : initialise les attributs a nulle ou 0

	@param : aucun

	@return : rien
*/
template<class TTypeMatrice>
CListeMatrice<TTypeMatrice>::CListeMatrice()
{
	uiLMTTailleListe = 0;
	LMTTableau = nullptr;
}


/* Constructeur de confort :
	@brief :  permet de construire une liste d'objet de type CMatrice<TTypeMatrice>

	@param unsigned int uiArg : Taille de la liste, la valeur par defaut est 1

	@return : rien
*/
template<class TTypeMatrice>
CListeMatrice<TTypeMatrice>::CListeMatrice(unsigned int uiArg)
{
	/*Si uiArg == 0 alors on initialise comme le contructeur par defaut*/
	if (uiArg == 0)
	{
		LMTTableau = nullptr;
	}
	else
	{
		uiLMTTailleListe = uiArg;
		LMTTableau = new CMatrice<TTypeMatrice>[uiArg];
	}
}

/*Deconstructeur :
@brief : Detruit l'objet en supprimmant la liste d'objet

@param : rien

@return : rien
*/
template<class TTypeMatrice>
CListeMatrice<TTypeMatrice>::~CListeMatrice()
{
	uiLMTTailleListe = 0;
	delete[] LMTTableau;
}

/**
	@brief : Surcharge de l'operateur []  pour permettre de retourner la matrice de la liste a la position voulu

	@param  unsigned int uiArg: un entier naturel qui correspond a la position dans la liste

	@return CMatrice<TTypeMatrice> : Une matrice de type TTypeMatrice
*/
template<class TTypeMatrice>
CMatrice<TTypeMatrice> & CListeMatrice<TTypeMatrice>::operator[](unsigned int uiArg)
{

	if (uiArg >uiLMTTailleListe)
	{
		CException EXCerreur(EXCIndice, "indice d'acces superieur a la taille du tableau");
		throw(EXCerreur);
	}

	return LMTTableau[uiArg];
}
