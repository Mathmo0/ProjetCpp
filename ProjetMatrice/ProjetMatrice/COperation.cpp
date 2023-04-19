#include "COperation.h"


/**
 *  @brief methode static generique permettant de determiner la transposee d'une matrice de type TTypeMatrice

	@param  CMatrice<TTypeMatrice> MATarg : Matrice de type TTypeMatrice, en passage par reference

	@return CMatrice<TTypeMatrice> * :  un pointeur sur une matrice de type TTypeMatrice
 */
template<class TTypeMatrice>
static CMatrice<TTypeMatrice> * COperation::OPETransposeMatrice(CMatrice<TTypeMatrice> & MATarg)
{
	if (MATarg.MATLireMatrice() == nullptr)
	{
		CException EXCerreur(EXCDimensionMatrice, " La matrice n'est pas initialise");
		throw(EXCerreur);
	}

	unsigned int  uiLigneTrans = MATarg.MATLireDimensionLigne();
	unsigned int  uiColonneTrans = MATarg.MATLireDimensionColonne();
	unsigned int  uiBoucleLigne = 0;
	unsigned int  uiBoucleColonne = 0;

	CMatrice<TTypeMatrice> * MATResultatTranspose = new CMatrice<TTypeMatrice>(uiColonneTrans,uiBoucleLigne);
	
	/* Transposition de la matrice :  */

	for (uiBoucleLigne = 0; uiBoucleLigne < uiLigneTrans; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiColonneTrans; uiBoucleColonne++)
		{
			MATResultatTranspose->MATModifierUneValeurDeLaMatrice(MATarg.MATLireUneValeurDeLaMatrice(uiBoucleLigne, uiBoucleColonne), uiBoucleColonne, uiBoucleLigne);
		}
	}

	return MATResultatTranspose;
}

/**
 *  @brief surchage de l'operateur * permettant de faire l'operation suivante : double*CMatrice<TTypeMatrice>

	@param double dConstante

	@param : CMatrice<TTypeMatrice> MAtarg : Matrice de type TTypeMatrice, en passage par reference

	@return CMatrice<TTypeMatrice> * : un pointeur sur une matrice de type TTypeMatrice
 */
template<class TTypeMatrice>
CMatrice<TTypeMatrice> * operator*( double dConstante, CMatrice<TTypeMatrice> & MATarg)
{
	//erreur si matrice non initialise

	if (MATarg.MATLireMatrice() == nullptr)
	{
		CException EXCerreur(EXCDimensionMatrice, " La matrice n'est pas initialise");
		throw(EXCerreur);
	}

	/* Declaration et initialisation des variables : */

	unsigned int NbLigne = MATarg.MATLireDimensionLigne();
	unsigned int NbColonne = MATarg.MATLireDimensionColonne();

	CMatrice<TTypeMatrice> * MATResultatMultiplicationParConstante = new CMatrice<TTypeMatrice>(NbLigne,NbColonne);

	unsigned int  uiBoucleLigne = 0;
	unsigned int  uiBoucleColonne = 0;
	TTypeMatrice TMAValeur;

	/* Multiplication de la Matrice par la constante : */

	for (uiBoucleLigne = 0; uiBoucleLigne < NbLigne; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < NbColonne; uiBoucleColonne++)
		{
			TMAValeur = MATarg.MATLireUneValeurDeLaMatrice(uiBoucleLigne, uiBoucleColonne) * dConstante;
			MATResultatMultiplicationParConstante->MATModifierUneValeurDeLaMatrice(TMAValeur, uiBoucleLigne, uiBoucleColonne);
		}
	}

	return MATResultatMultiplicationParConstante;
}

/**
 *  @brief surcharge de l'operateur + permettant de faire l'operation suivante : (CMatrice<TTypeMatrice>*) + CMatrice<TTypeMatrice>

	@param CMatrice<TTypeMatrice> * pMATarg1 : un pointeur sur une matrice de type TTypeMatrice

	@param CMatrice<TTypeMatrice> MATarg2: Matrice de type TTypeMatrice

	@return CMatrice<TTypeMatrice> * : Un pointeur sur une Matrice de type TTypeMatrice
 */
template<class TTypeMatrice>
CMatrice<TTypeMatrice>* operator+(CMatrice<TTypeMatrice>* pMATarg1, CMatrice<TTypeMatrice> MATarg2)
{
		/*exception :*/

		if (pMATarg1->MATLireMatrice() == nullptr || MATarg2.MATLireMatrice() == nullptr)
		{
			CException EXCerreur(EXCMatriceNULL, "Une des deux matrices n'est pas initialisees");
			throw(EXCerreur);
		}
		if (pMATarg1->MATLireDimensionLigne() != MATarg2.MATLireDimensionLigne() || pMATarg1->MATLireDimensionColonne() != MATarg2.MATLireDimensionColonne())
		{
			CException EXCerreur(EXCDimensionMatrice, "Les deux matrices ne sont pas de la meme taille");
			throw(EXCerreur);
		}

		/* Declaration et initialisation des variables : */

		CMatrice<TTypeMatrice> * MATResultatAddition = new CMatrice<TTypeMatrice>(pMATarg1->MATLireDimensionLigne(), MATarg2.MATLireDimensionColonne());

		unsigned int  uiBoucleLigne = 0;
		unsigned int  uiBoucleColonne = 0;
		TTypeMatrice TMAValeur;

		/* Addition de 2 matrice : */

		for (uiBoucleLigne = 0; uiBoucleLigne < pMATarg1->MATLireDimensionLigne(); uiBoucleLigne++)
		{
			for (uiBoucleColonne = 0; uiBoucleColonne < pMATarg1->MATLireDimensionColonne(); uiBoucleColonne++)
			{
				TMAValeur = pMATarg1->MATLireUneValeurDeLaMatrice(uiBoucleLigne, uiBoucleColonne) + MATarg2.MATLireUneValeurDeLaMatrice(uiBoucleLigne, uiBoucleColonne);
				MATResultatAddition->MATModifierUneValeurDeLaMatrice(TMAValeur, uiBoucleLigne, uiBoucleColonne);
			}
		}

		return MATResultatAddition;
}

/**
 *  @brief surcharge de l'operateur - permettant de faire l'operation suivante : (CMatrice<TTypeMatrice>*) - CMatrice<TTypeMatrice>

	@param CMatrice<TTypeMatrice> * pMATarg1 : un pointeur sur une matrice de type TTypeMatrice

	@param CMatrice<TTypeMatrice> MATarg2: Matrice de type TTypeMatrice

	@return CMatrice<TTypeMatrice> * : Un pointeur sur une Matrice de type TTypeMatrice
 */
template<class TTypeMatrice>
CMatrice<TTypeMatrice>* operator-(CMatrice<TTypeMatrice>* pMATarg1, CMatrice<TTypeMatrice> MATarg2)
{
	/*exception :*/

	if (pMATarg1->MATLireMatrice() == nullptr || MATarg2.MATLireMatrice() == nullptr)
	{
		CException EXCerreur(EXCMatriceNULL, "Une des deux matrices n'est pas initialisees");
		throw(EXCerreur);
	}

	if (pMATarg1->MATLireDimensionLigne() != MATarg2.MATLireDimensionLigne() || pMATarg1->MATLireDimensionColonne() != MATarg2.MATLireDimensionColonne())
	{
		CException EXCerreur(EXCDimensionMatrice, "Les deux matrices ne sont pas de la meme taille");
		throw(EXCerreur);
	}

	/* Declaration et initialisation des variables : */

	CMatrice<TTypeMatrice> * MATResultatSoustraction = new CMatrice<TTypeMatrice>(pMATarg1->MATLireDimensionLigne(), MATarg2.MATLireDimensionColonne());

	unsigned int  uiBoucleLigne = 0;
	unsigned int  uiBoucleColonne = 0;
	TTypeMatrice TMAValeur;

	/* Soustraction de 2 matrices : */

	for (uiBoucleLigne = 0; uiBoucleLigne < pMATarg1->MATLireDimensionLigne(); uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < pMATarg1->MATLireDimensionColonne(); uiBoucleColonne++)
		{
			TMAValeur = pMATarg1->MATLireUneValeurDeLaMatrice(uiBoucleLigne, uiBoucleColonne) - MATarg2.MATLireUneValeurDeLaMatrice(uiBoucleLigne, uiBoucleColonne);
			MATResultatSoustraction->MATModifierUneValeurDeLaMatrice(TMAValeur, uiBoucleLigne, uiBoucleColonne);
		}
	}

	return MATResultatSoustraction;
};

/**
 *  @brief surcharge de l'operateur * permettant de faire l'operation suivante : (CMatrice<TTypeMatrice>*) * CMatrice<TTypeMatrice>

	@param CMatrice<TTypeMatrice> * pMATarg1 : un pointeur sur une matrice de type TTypeMatrice

	@param CMatrice<TTypeMatrice> MATarg2: Matrice de type TTypeMatrice

	@return CMatrice<TTypeMatrice> * : Un pointeur sur une Matrice de type TTypeMatrice
 */
template<class TTypeMatrice>
CMatrice<TTypeMatrice>* operator*(CMatrice<TTypeMatrice>* pMATarg1, CMatrice<TTypeMatrice> MATarg2)
{
	/*exception :*/

	if (pMATarg1->MATLireMatrice() == nullptr || MATarg2.MATLireMatrice() == nullptr)
	{
		CException EXCerreur(EXCMatriceNULL, "Une des deux matrices n'est pas initialisees");
		throw(EXCerreur);
	}

	if (pMATarg1->MATLireDimensionColonne() != MATarg2.MATLireDimensionLigne())
	{
		CException EXCerreur(EXCDimensionMatrice,"Le nombre de colonne de la premiere matrice est differents du nombre de ligne de la seconde matrice");
		throw(EXCerreur);
	}

	/* Declaration et initialisation des variables : */

	CMatrice<TTypeMatrice> * MATResultatMultiplication = new CMatrice<TTypeMatrice>(pMATarg1->MATLireDimensionLigne(), MATarg2.MATLireDimensionColonne());
	MATResultatMultiplication->MATInitMatriceANulle();

	unsigned int uiBoucleLigne = 0;
	unsigned int uiBoucleColonne = 0;
	unsigned int uiBouble3 = 0;
	TTypeMatrice TMAValeur = 0;

	/* Multiplication de 2 matrices : */

	for (uiBoucleLigne = 0; uiBoucleLigne < pMATarg1->MATLireDimensionLigne(); uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < pMATarg1->MATLireDimensionColonne(); uiBoucleColonne++)
		{
			TMAValeur = MATResultatMultiplication->MATLireUneValeurDeLaMatrice(uiBoucleLigne, uiBoucleColonne);
			for (uiBouble3 = 0; uiBouble3 < MATarg2.MATLireDimensionColonne(); uiBouble3++)
			{
				TMAValeur += pMATarg1->MATLireUneValeurDeLaMatrice(uiBoucleLigne, uiBouble3) * MATarg2.MATLireUneValeurDeLaMatrice(uiBouble3, uiBoucleColonne);
			}
			MATResultatMultiplication->MATModifierUneValeurDeLaMatrice(TMAValeur, uiBoucleLigne, uiBoucleColonne);
		}
	}

	return MATResultatMultiplication;
}