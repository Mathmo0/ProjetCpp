
#ifndef __OPE__
#define __OPE__

#include "CMatrice.h"

#define EXCDimensionMatrice 10 
#define EXCMatriceNULL 11


//Outils pour les fuites memoires
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

class COperation
{
	//methode : 

	/**
	 *  @brief methode static generique permettant de determiner la transposee d'une matrice de type TTypeMatrice

		@param  CMatrice<TTypeMatrice> MATarg : Matrice de type TTypeMatrice, en passage par reference

		@return CMatrice<TTypeMatrice> * :  un pointeur sur une matrice de type TTypeMatrice
	 */
public : 
	template <class TTypeMatrice>  static CMatrice<TTypeMatrice> * OPETransposeMatrice(CMatrice<TTypeMatrice> & MATarg);

};

/**
 *  @brief surchage de l'operateur * permettant de faire l'operation suivante : double*CMatrice<TTypeMatrice> 

	@param double dConstante 

	@param : CMatrice<TTypeMatrice> MAtarg : Matrice de type TTypeMatrice, en passage par reference

	@return CMatrice<TTypeMatrice> * : un pointeur sur une matrice de type TTypeMatrice
 */
template<class TTypeMatrice>
CMatrice<TTypeMatrice> * operator*(double dConstante, CMatrice<TTypeMatrice> & MATarg);

/**
 *  @brief surcharge de l'operateur + permettant de faire l'operation suivante : (CMatrice<TTypeMatrice>*) + CMatrice<TTypeMatrice>

	@param CMatrice<TTypeMatrice> * pMATarg1 : un pointeur sur une matrice de type TTypeMatrice

	@param CMatrice<TTypeMatrice> MATarg2: Matrice de type TTypeMatrice

	@return CMatrice<TTypeMatrice> * : Un pointeur sur une Matrice de type TTypeMatrice
 */
template<class TTypeMatrice>
CMatrice<TTypeMatrice> * operator+(CMatrice<TTypeMatrice> * pMATarg1, CMatrice<TTypeMatrice> MATarg2);

/**
 *  @brief surcharge de l'operateur - permettant de faire l'operation suivante : (CMatrice<TTypeMatrice>*) - CMatrice<TTypeMatrice>

	@param CMatrice<TTypeMatrice> * pMATarg1 : un pointeur sur une matrice de type TTypeMatrice

	@param CMatrice<TTypeMatrice> MATarg2: Matrice de type TTypeMatrice

	@return CMatrice<TTypeMatrice> * : Un pointeur sur une Matrice de type TTypeMatrice
 */
template<class TTypeMatrice>
CMatrice<TTypeMatrice> * operator-(CMatrice<TTypeMatrice> * pMATarg1, CMatrice<TTypeMatrice> MATarg2);

/**
 *  @brief surcharge de l'operateur * permettant de faire l'operation suivante : (CMatrice<TTypeMatrice>*) * CMatrice<TTypeMatrice>

	@param CMatrice<TTypeMatrice> * pMATarg1 : un pointeur sur une matrice de type TTypeMatrice

	@param CMatrice<TTypeMatrice> MATarg2: Matrice de type TTypeMatrice

	@return CMatrice<TTypeMatrice> * : Un pointeur sur une Matrice de type TTypeMatrice
 */
template<class TTypeMatrice>
CMatrice<TTypeMatrice> * operator*(CMatrice<TTypeMatrice> * pMATarg1, CMatrice<TTypeMatrice> MATarg2);


#include "COperation.cpp"

#endif