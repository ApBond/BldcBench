#ifndef FUZZY_H
#define FUZZY_H


 /*входные переменные*/
#define	ER_TERMS_COUNT 6	//число термов скорости
#define	DER_TERMS_COUNT 6	//число термов тока

/*выходные переменные*/
#define	MOMENT_TERMS_COUNT 6	//число термов – по скорости

/*правила*/
#define	MOMENT_RULLS_COUNT 12	//число правил дл€ – по скорости

float fuzzyController(float er, float der);

#endif