/*
 ============================================================================
 Name        : TP2-ListesChaînées.c
 Author      : Groupe Ti106
 Version     :
 Copyright   : CC
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "repertoire.h"


int main(void) {
	repertoire rep;
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	menu (rep);
	freeRepertoire(rep);
	return EXIT_SUCCESS;
}

