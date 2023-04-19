#include "CListe.h"
/* Constructeur par defaut :
	@brief : initialise la liste

	@param : aucun

	@return : rien
	*/
template<class TType> 
CListe<TType>::CListe()
{
	uiLISTailleListe = 0;
	pLISTableau = nullptr;
}

/* Constructeur par recopie :
	@brief : initialise la liste a partir d'une autre liste

	@param CListe LISArg : une liste d'objet

	@return : rien
	*/
template<class TType>
CListe<TType>::CListe(CListe<TType> & LISArg)
{
	unsigned int uiBoucle;

	uiLISTailleListe = LISArg.uiLISTailleListe;

	pLISTableau = (TType **)malloc(uiLISTailleListe * sizeof(TType *));

	for (uiBoucle = 0; uiBoucle < uiLISTailleListe; uiBoucle++)
	{
		pLISTableau[uiBoucle] = new TType;
		*pLISTableau[uiBoucle] = *(LISArg.pLISTableau[uiBoucle]);
	}
}

/* Constructeur de confort :
	@brief : initialise la liste

	@param unsigned int uiTailleListe : la taille de la liste

	@return : rien
	*/
template<class TType>
CListe<TType>::CListe(unsigned int uiTailleListe)
{
	/*Si uiTailleListe == 0 alors on initialise comme le contructeur par defaut*/
	
	unsigned int uiBoucle = 0;

	if (uiTailleListe == 0)
	{
		uiLISTailleListe = uiTailleListe;
		pLISTableau = nullptr;
	}
	else
	{
		uiLISTailleListe = uiTailleListe;
		pLISTableau = (TType **) malloc(uiTailleListe * sizeof(TType * ));

		for (uiBoucle = 0; uiBoucle < uiLISTailleListe;uiBoucle++)
		{
			pLISTableau[uiBoucle] = new TType();
		}
	}
}

/* Deconstructeur :
@brief : Detruit l'objet en supprimmant la liste d'objet

@param : rien

@return : rien
*/
template<class TType>
CListe<TType>::~CListe()
{
	unsigned int uiBoucle;

	
	for (uiBoucle = 0; uiBoucle < uiLISTailleListe; uiBoucle++)
	{
		delete pLISTableau[uiBoucle];
		pLISTableau[uiBoucle] = nullptr;
	}
	
	if (uiLISTailleListe > 0) {


		free(pLISTableau);
	}

	uiLISTailleListe = 0;
}

/**
	 * @brief accesseur en lecture pour l'attribut uiLISTailleListe

	   @param aucun

	   @return uiLISTailleListe : taille du tableau
*/
template<class TType>
unsigned int CListe<TType> :: LISLireTailleTableau()
{
	return uiLISTailleListe;
}

/**
	 * @brief accesseur en ecriture pour l'attribut uiLISTailleListe

	   @param unsigned int uiNouvelleTailleListe : entier representant un entier naturel

	   @throws Nouvelle taille du tableau nulle

	   @return rien
*/
template<class TType>
void CListe<TType> ::LISModifierTailleTableau(unsigned int uiNouvelleTailleListe)
{

	unsigned int uiBoucleColonne = 0;
	int iDifference = uiNouvelleTailleListe - uiLISTailleListe;
	
	if (uiNouvelleTailleListe == 0)
	{
		CException EXCerreur(EXCDimensionTableau, "Un tableau ne peut avoir une taille nulle");
		throw(EXCerreur);
	}

	if (pLISTableau == nullptr)
	{
		pLISTableau = (TType **)malloc(uiNouvelleTailleListe * sizeof(TType *));

		for (uiBoucleColonne = 0; uiBoucleColonne < uiNouvelleTailleListe; uiBoucleColonne++)
		{
			pLISTableau[uiBoucleColonne] = new TType();
		}
	}

	else
	{
		/*on a ajoute des arc, on alloue donc l'espace necessaire pour ces arc
			Sinon on en a enleves mais on ne fait rien car la desalocation est gere par la fonction realloc*/
		if (iDifference > 0)
		{
			pLISTableau = (TType **)realloc(pLISTableau, uiNouvelleTailleListe * sizeof(TType *));

			for (uiBoucleColonne = uiLISTailleListe; uiBoucleColonne < uiNouvelleTailleListe; uiBoucleColonne++)
			{
				pLISTableau[uiBoucleColonne] = new TType;
			}
		}

		else if (iDifference < 0)
		{
			for (uiBoucleColonne = uiLISTailleListe-1; uiBoucleColonne >= uiNouvelleTailleListe ; uiBoucleColonne--)
			{
				delete pLISTableau[uiBoucleColonne];
				pLISTableau[uiBoucleColonne] = nullptr;
			}

			pLISTableau = (TType**)realloc(pLISTableau, uiNouvelleTailleListe * sizeof(TType *));
		}
	}

	/*Affectation de la nouvelle taille */

	uiLISTailleListe = uiNouvelleTailleListe;
}

/**
	 * @brief accesseur en lecture pour l'attribut pLISTableau

	   @param aucun

	   @return pLISTableau : tableau contenant des valeurs de type TType
*/
template<class TType>
TType ** CListe<TType> :: LISLireTableau()
{
	return pLISTableau;
}

/* Accesseur en ecriture pour modifier un element de la liste

		@brief modifie un element de la liste des Partants

		@param pTYPArg : un objet de type TType

		@param unsigned int uiIndice : Position a laquelle on veut modifier l'element

		@throws Erreur d'indice 

		@return rien
*/
template<class TType> 
void CListe<TType> :: LISModifierUnElementDuTableau(unsigned int uiIndice, TType * pTYPArg)
{
	//exception si uiIndice > uiLISTailleListe 

	if(uiIndice > uiLISTailleListe)
	{
		CException EXCerreur(EXCIndice, "indice d'acces superieur a la taille du tableau");
		throw(EXCerreur);
	}

	*pLISTableau[uiIndice] = *pTYPArg;
}

/*
		@brief Permet d'ajouter un element a la liste en derniere position

		@param TType * pTYParg : Element a ajouter de type TType *, par default on ajoute un TType initialiser avec le contructeur par defaut

		@return rien
*/
template<class TType>
void CListe<TType> :: LISAjouterUnElementDansLeTableau(TType * pTYParg)
{
	this->LISModifierTailleTableau(uiLISTailleListe + 1);
	this->LISModifierUnElementDuTableau(uiLISTailleListe-1, pTYParg);
}

/*
		@brief Permet de supprimer le dernier element de la Liste

		@param aucun

		@return rien
*/
template<class TType>
void CListe<TType> ::LISSUpprimerUnElementDansLeTableau()
{
	LISModifierTailleTableau(uiLISTailleListe-1);
}

/* Suppression d'un element du tableau

		@brief permet de supprimer un element de la Liste a une position donne

		@param aucun

		@return rien
	*/
template<class TType>
void CListe<TType> ::LISSUpprimerUnElementDansLeTableau(unsigned int uiPosition)
{
	unsigned int uiBoucle;

	if (uiLISTailleListe <= 1)
	{
		if (uiLISTailleListe == 1) {
			delete pLISTableau[0];
			free(pLISTableau);
		}
		pLISTableau = nullptr;
		uiLISTailleListe = 0;
	}
	else {
		for (uiBoucle = uiPosition; uiBoucle < uiLISTailleListe - 1; uiBoucle++)
		{
			LISModifierUnElementDuTableau(uiBoucle, pLISTableau[uiBoucle + 1]);
		}
		LISModifierTailleTableau(uiLISTailleListe - 1);

	}
}
	
/** Fonction de concatenation de listes

		@brief Permet de concatener deux objets de type CListe<TType>

		@param CListe<TType> LISarg : objet CListe qu'on veut concatener a l'objet actuelle

		@return rien
	 */
template <class TType>
void CListe<TType>::LISConcatenation(CListe<TType> * pLISarg)
{
	unsigned int uiBoucle;
	unsigned int uiTailleListe = pLISarg->LISLireTailleTableau();

	for (uiBoucle = 0; uiBoucle < uiTailleListe; uiBoucle++)
	{
		this->LISAjouterUnElementDansLeTableau(pLISarg->LISLireTableau()[uiBoucle]);
	}
}

/** Fonction pour supprimer les doublons d'une liste

		@brief Permet de supprimer les doublons d'une liste de type CListe<TType>

		@param CListe<TType> LISarg : objet CListe dans laquelle nous voulons supprimer les doublons

		@return rien
	 */
template <class TType>
void CListe<TType>::LISSupprimerDoublons(CListe<TType> & LISarg)
{
	unsigned int uiBoucle;
	unsigned int uiBoucleBis;
	unsigned int uiTailleListe = LISarg.LISLireTailleTableau();

	for (uiBoucle = 0; uiBoucle < uiTailleListe; uiBoucle++)
	{
		for (uiBoucleBis = 0; uiBoucleBis < uiTailleListe; uiBoucleBis++)
		{
			if (((*(LISarg.pLISTableau[uiBoucle]) == *(LISarg.pLISTableau[uiBoucleBis])) == 0) && uiBoucle != uiBoucleBis)
			{
				LISarg.LISSUpprimerUnElementDansLeTableau(uiBoucleBis);
				uiTailleListe--;
			}
		}
	}
}

/*-----------------Surcharge d'operateur-----------------*/

/* Surcharge de l'operateur []
	@brief Surcharge de l'operateur [] pour permettre de retourner l'objet a la position voulu

	@param unsigned int uiARG : Entier qui correspond a la position

	@throws Erreur d'indice

	@return TType : Un objet
	*/
template<class TType>
TType & CListe<TType>::operator[](unsigned int uiArg)
{
	if(uiArg > uiLISTailleListe )
	{
		//Si l'indice est superieur a la taille de la liste
		CException EXCerreur(EXCIndice, "indice d'acces superieur a la taille du tableau");
		throw(EXCerreur);
	}

	return *pLISTableau[uiArg];
}

/** Surcharge de l'operateur =

	@brief Surcharge de l'operteur = permettant d'affecter un objet de type CListe<TType> dans un autre objet de type CListe<TType>

	@param CListe<TType> LISarg : objet CListe qu'on veut affecter dans l'objet actuelle

	@return rien
	 */
template<class TType>
CListe<TType> & CListe<TType>::operator=(CListe<TType> & LISarg)
{
	/* Declaration des variables : */

	unsigned int uiBoucle;

	/*Desallocation de la liste acttuelle : */

	for(uiBoucle = 0; uiBoucle < uiLISTailleListe;uiBoucle++)
	{
		delete pLISTableau[uiBoucle];
	}
	if (uiLISTailleListe > 0) {

		free(pLISTableau);
	}
	pLISTableau = nullptr;

	/*Allocation de la nouvelle Liste : */

	pLISTableau = (TType **)malloc(LISarg.uiLISTailleListe * sizeof(TType *));

	for(uiBoucle = 0;uiBoucle < LISarg.uiLISTailleListe;uiBoucle++)
	{
		pLISTableau[uiBoucle] = new TType();
	}

	/*Affectation de LISarg */

	uiLISTailleListe = LISarg.uiLISTailleListe;

	for (uiBoucle = 0; uiBoucle < uiLISTailleListe; uiBoucle++)
	{
		*pLISTableau[uiBoucle] = *(LISarg.pLISTableau[uiBoucle]);
	}

	return *this;
}

/** Surcharge de l'operateur =

	@brief Surcharge de l'operteur = permettant d'affecter un pointeur d'objet de type CListe<TType> * dans un autre objet de type CListe<TType> *

	@param CListe<TType> * LISarg : objet CListe qu'on veut affecter dans l'objet actuelle

	@return rien
	 */
template<class TType>
CListe<TType> * CListe<TType>::operator=(CListe<TType> * pLISarg)
{
	/* Declaration des variables : */

	unsigned int uiBoucle;

	/*Desallocation de la liste acttuelle : */

	for (uiBoucle = 0; uiBoucle < uiLISTailleListe; uiBoucle++)
	{
		delete pLISTableau[uiBoucle];
	}
	if (uiLISTailleListe > 0) {

		free(pLISTableau);
	}
	pLISTableau = nullptr;

	/*Allocation de la nouvelle Liste : */

	pLISTableau = (TType **)malloc(pLISarg->uiLISTailleListe * sizeof(TType *));

	for (uiBoucle = 0; uiBoucle < pLISarg->uiLISTailleListe; uiBoucle++)
	{
		pLISTableau[uiBoucle] = new TType();
	}

	/*Affectation de LISarg */

	uiLISTailleListe = pLISarg->uiLISTailleListe;

	for (uiBoucle = 0; uiBoucle < uiLISTailleListe; uiBoucle++)
	{
		*pLISTableau[uiBoucle] = *(pLISarg->pLISTableau[uiBoucle]);
	}

	return *this;
}

/** Surcharge de l'operateur ==

		@brief Permet si deux objet de la classe CListe sont identique ou non

		@param LISEquivalent : objet de type CListe

		@return 0 si les 2 objets sont egale, 1 sinon 
*/
template<class TType>
int CListe<TType>::operator==(CListe<TType> & LISEquivalent)
{
	unsigned int uiBoucle= 0;


	if(uiLISTailleListe != LISEquivalent.uiLISTailleListe)
	{
		return 1;
	}

	for (uiBoucle = 0; uiBoucle < uiLISTailleListe ; uiBoucle++)
	{
		if((*pLISTableau[uiBoucle] != *(LISEquivalent.pLISTableau[uiBoucle])) == 0)
		{
			return 1;
		}
	}
	return 0;
}

;

