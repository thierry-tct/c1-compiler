/*
 * Functions of Symbolic Table
 * Author: Yu Zhang (yuzhang@ustc.edu.cn)
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"

/*** by me **/
#define PROCEDURE 3
#define CONST 0
#define INT 1
#define TYPEDEF 2
/***********/
/*******  P4 *********/
#ifndef MY_CURRENT_TAB
#define MY_CURRENT_TAB
static Table current_tab=0;     //when exitint the bloc or procedure on YACC set this to its parent
#endif
/*********************/

/**
 * Creates a symbolic table
 */
Table
newTable(Table T)
{
	Table new;
	NEW0(new);
	/*** by me **/
	new->parent = T;
	if(T==NULL)
		new->dx = 3;
	else if(T->parent == NULL)
		new->dx = 3+1;		//+1 for returned value of the function
	else
		new->dx = T->dx;
	new->lev = (T==NULL)? 0 : 1;
	current_tab = new;
	new->func_num = 0;
	/**********/
	return new;
}

static void
destroyBucket(Entry *list)
{
	Entry node = *list, temp;
	while ( node != NULL ) {
		temp = node;
		free(node);
		node = temp->next;
	}
	*list = NULL;
}

/**
 * Destroys the specified table
 */
void
destroyTable(Table *tab)
{
	int i=0;
	/*****  by me ***/
	//if(*tab=current_tab)
       // current_tab=(*tab)->parent;
    /****************/
	Entry *bucket = (*tab)->buckets, *bucket_end = (*tab)->buckets+256;
	while (bucket < bucket_end ) {
		destroyBucket(bucket);
		bucket++;
	}
	free(*tab);
	*tab = NULL;
}

// Look up the symbolic table to get the symbol with specified name
Symbol
lookup(Table ptab, const char *name, short kind)
{
	Entry pent;
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE-1);
	/****  by me : while and  ptab=ptab.parent;****/
	while(ptab!=NULL)
	{
	    for (pent = ptab->buckets[hashkey]; pent!=NULL; pent = pent->next)
            if ( strcmp(name, pent->sym.name) == 0 && (pent->sym.type==kind || pent->sym.type==0 && kind ==1))
                return &pent->sym;
            ptab=ptab->parent;
	}
	//printf("error:%s undefined and undeclared in this scope",name);
	return NULL;
}

/*// Get value of the specified name from the symbolic table
float
getVal(Table ptab, const char *name)
{
	Entry pent;
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE-1);

    Table q=ptab;       //save ptab
	while(ptab!=NULL)
	{
        for (pent = ptab->buckets[hashkey]; pent!=NULL; pent = pent->next)
            if ( strcmp(name, pent->sym.name) == 0 )
            {

                if(pent->sym.type==PROCEDURE)
                {
                    ptab=NULL;
                    break;
                }

                return (*(pent->sym.val))->val;
            }
        ptab=ptab->parent;
	}
	ptab=q;             //restore ptab

	NEW0(pent);
	pent->sym.name = (char *)name;
	pent->sym.val = 0;

	pent->sym.type = INT;
	pent->sym.addr = ptab->dx;
	ptab->dx = ptab->dx + 1;
	pent->sym.lev = ptab->lev;

	printf("Warn: %s(%d) was not initialized before, set it 0 as default\n",
		(char *)name, hashkey);
	pent->next = ptab->buckets[hashkey];
	ptab->buckets[hashkey] = pent;
	return 0;
}*/

Symbol
getSym(Table ptab, const char *name, short kind)
{
	Entry pent;
	static int func_link_addr = 1;
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE-1);
        for (pent = ptab->buckets[hashkey]; pent!=NULL; pent = pent->next)
            if ( strcmp(name, pent->sym.name) == 0 && pent->sym.type==kind)
	    {
		printf("\nerror : %s aready declared in this scope\n",name);exit(-1);
                return &pent->sym;
	    }
	if(kind == PROCEDURE)
	{
		Symbol s=lookup(ptab, name, kind);
		if(s!=NULL) return s;
	}
	NEW0(pent);
	pent->sym.name = (char *)name;
	switch(kind){
	case CONST :
		pent->sym.val = 0;
		pent->sym.isInitial = FALSE;
		pent->sym.type = CONST;
		break;
	case INT :
		pent->sym.val = 0;
		pent->sym.isInitial = FALSE;
		pent->sym.type = INT;
		//pent->sym.addr = ptab->dx;
		//ptab->dx = ptab->dx + 1;
		//pent->sym.lev = ptab->lev;
	case TYPEDEF :
		pent->sym.type = TYPEDEF;
		break;
	case PROCEDURE :
		pent->sym.type = PROCEDURE;
		pent->sym.function_link_pos=func_link_addr;
		ptab->func_num = func_link_addr;
		func_link_addr++;
		break;
	}
	pent->next = ptab->buckets[hashkey];
	ptab->buckets[hashkey] = pent;
	return &pent->sym;
}
/*
// Set value of the specified name into the symbolic table
Symbol
setVal(Table ptab, const char *name, float val)
{
	short type;
	Entry pent;
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE-1);

    Table q=ptab;       //save ptab
	while(ptab!=NULL)
	{
        for (pent = ptab->buckets[hashkey]; pent!=NULL; pent = pent->next) {
            if ( strcmp(name, pent->sym.name) == 0 ) {
                (*(pent->sym.val))->val = val;
#if DEBUG
                printf("update %s(%d)  %f\n",
                    (char *)name, hashkey, val);
#endif
                return &pent->sym;
            }
        }
        ptab = ptab->parent;
	}
	ptab=q;             //restore ptab

	NEW0(pent);
	pent->sym.name = (char *)name;
	(*(pent->sym.val))->val = val;
	pent->sym.type = type;
	if(type==2)
	{
		pent->sym.addr = ptab->dx;
		ptab->dx = ptab->dx + 1;
		pent->sym.lev = ptab->lev;
	}
#if DEBUG
	printf("create %s(%d) %f\n", (char *)name,
		hashkey, val);
#endif
	pent->next = ptab->buckets[hashkey];
	ptab->buckets[hashkey] = pent;
	return &pent->sym;
}
*/
/*// Set value of the specified name into the symbolic table
Symbol
setProc(Table ptab, const char *name)
{
	Entry pent;
	unsigned hashkey = (unsigned long)name[0] & (HASHSIZE-1);
    for (pent = ptab->buckets[hashkey]; pent!=NULL; pent = pent->next) {
        if ( strcmp(name, pent->sym.name) == 0 ) {
#if DEBUG
            printf("Error : procedure %s(%d)  already declared\n",
                (char *)name, hashkey);
#endif
            return &pent->sym;
            }
        }
	NEW0(pent);
	pent->sym.name = (char *)name;
	pent->sym.tab = newTable(ptab);
	pent->sym.type = PROCEDURE;
#if DEBUG
	printf("create procedure %s(%d)\n", (char *)name,
		hashkey);
#endif
	pent->next = ptab->buckets[hashkey];
	ptab->buckets[hashkey] = pent;
	return &pent->sym;
}*/

