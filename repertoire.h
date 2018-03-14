/*
 * repertoire.h
 *
 *  Created on: 8 mars 2018
 *      Author: Hmida HMIDA
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/* Définition d'une fiche du répertoire */
typedef struct {
	char nom[21];
	char prenom[21];
	char tel[9];
} fiche, *ficheptr;

/* Définition d'un onglet */
typedef struct onglett{
	ficheptr lafiche;
	struct onglett *suivante;
} onglet, *ongletptr;

/* Définition du répertoire */
typedef ongletptr repertoire[26];

/* Définition d'une fiche du répertoire */
typedef struct {
	char nom[21];
	char prenom[21];
	char tel[9];
} fiche, *ficheptr;

/* Définition d'un onglet */
typedef struct onglett{
	ficheptr lafiche;
	struct onglett *suivante;
} onglet, *ongletptr;

/* Définition du répertoire */
typedef ongletptr repertoire[26];

//definition des fonctions
void afficheRepertoire(repertoire lerepertoire) {
	char c='A';
	for(i=0;i<26;i++)
	{
		printf("%c",c+i);
		afficheOnglet(lerepertoire[i]);
	}
}
void afficheOnglet(ongletptr longlet) {
	ongletptr p=longlet;
	
	do
	{
		afficheFiche(p->lafiche);
		p=p->suivante;
	}while(p->suivante!=NULL);
}
void afficheFiche(ficheptr lafiche) {
	printf("le nom est %s le prenom %s le telephone %s\n ",lafiche->nom,lafiche->prenom,lafiche->tel );
}
void ajouterFiche(repertoire lerepertoire, ficheptr lafiche) {
	char c='A';int i=0;
	while(toupper(lafiche->nom[0]!=c)
	{
		c++;
		i++;
	}
	majuscule(lafiche);
	ajouterDansOnglet(lerepertoire[i]->longlet,lafiche);
	
}
void majuscule(ficheptr lafiche) {
	if(lafiche->nom[0]<'A' && lafiche->nom[0]<'Z')
		lafiche->nom[0]=toupper(lafiche->nom[0]);
}
void ajouterDansOnglet(ongletptr longlet, ficheptr lafiche) {
	longlet->lafiche=lafiche;
	longlet=longlet->suivante;
}
int avant(ficheptr fiche1, ficheptr fiche2) {
	if(fiche1->nom[0]<fiche2->nom[0])
		return 1;
	else
		return 0;
}
void repertoireVide(repertoire lerepertoire) {
	int i;
	for(i=0;i<26;i++)
	{
		lerepertoire[i]=NULL;
	}
}
void rechercheTel(char *nom){
	i=0;c='A';
	while(*nom[0]!=c)
	{
		i++;
		c++;
	}
	p=lerepertoire[i]->longlet;
	while(p->suivante!=NULL)
	{
		if(strcmp(p->lafiche->nom,*nom)==0)
			
			afficheFiche(p->lafiche)
	}
}
void choix1() {
	ajouterFiche(rep,rep->lafiche);
}
void choix2() {
	afficheRepertoire(rep);
}
void choix3() {
	ajouterFiche(rep,rep->lafiche);
}
void menu(repertoire lerepertoire) {
	int choix;
	do {
		printf(
				"=============================Gestion de répertoire=============================\n");
		printf("\t\t1- choix1\n");
		printf("\t\t2- choix2\n");
		printf("\t\t3- choix3\n");
		printf("\t\t4- Quitter\n");
		printf(
				"===============================================================================\n");
		printf("\tEntrer votre choix(1-4):");
		scanf("%d", &choix);
		switch (choix) {
		case 1:
			choix1();
			break;
		case 2:
			choix2();
			break;
		case 3:
			choix3();
			break;
		case 4:
			printf("Au revoir");
			break;
		default:
			printf("Choix doit être dans [1,4]!");
			break;
		}
	} while (choix != 5);

}
void freeRepertoire(repertoire lerepertoire) {
	int i;
	for(i=0;i<26;i++)
		free(lerepertoire);
}
