#pragma once
#include "CMatrice.h"

class CMatriceDoubleExtract :public CMatrice<double>
{
	//Constructeurs et deconstructeurs
public:
	/*Constructeur par défaut
	@param : rien
	
	@fn : C'est le constructeure par défaut de la class CMatrice<double>
	
	@return : rien*/
	CMatriceDoubleExtract();

	/*Constructeur de confort
	@param PATH : le chemin d'acces au fichier 
	
	@fn : Construit une Matrice double à partir d'un fichier de format .txt
	
	@return : rien
	*/
	CMatriceDoubleExtract(char* PATH); 

	//Méthodes
public:
	/*Modificateur de Matrice à partir d'un fichier
	@param PATH : le chemin d'acces au fichier  
	
	@fn : Extrait une matrice d'un fichier dans une Matrice existante
	
	@return : rien
	*/
	void CMDEModifierMatriceExtract(char* PATH);
	
	
};