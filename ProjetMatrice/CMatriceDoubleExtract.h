#pragma once
#include "CMatrice.h"

class CMatriceDoubleExtract :public CMatrice<double>
{
	//Constructeurs et deconstructeurs
public:
	/*Constructeur par d�faut
	@param : rien
	
	@fn : C'est le constructeure par d�faut de la class CMatrice<double>
	
	@return : rien*/
	CMatriceDoubleExtract();

	/*Constructeur de confort
	@param PATH : le chemin d'acces au fichier 
	
	@fn : Construit une Matrice double � partir d'un fichier de format .txt
	
	@return : rien
	*/
	CMatriceDoubleExtract(char* PATH); 

	//M�thodes
public:
	/*Modificateur de Matrice � partir d'un fichier
	@param PATH : le chemin d'acces au fichier  
	
	@fn : Extrait une matrice d'un fichier dans une Matrice existante
	
	@return : rien
	*/
	void CMDEModifierMatriceExtract(char* PATH);
	
	
};