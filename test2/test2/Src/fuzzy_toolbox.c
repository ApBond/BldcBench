#include "fuzzy_toolbox.h"
/*???????? ?????????? ???????*/

int16_t limitedSum(int16_t A, int16_t B) {
	return fuzzyAnd(1, A + B);
}

int16_t fuzzyOr(int16_t A, int16_t B) {
	if (A > B) return A;
	else return B;
}

int16_t fuzzyAnd(int16_t A, int16_t B) {
	if (A > B) return B;
	else return A;
}

int16_t fuzzyNot(int16_t A) {
	int16_t mu;
	mu = 1 - A;
	return mu;
}

int16_t mean(int16_t a, int16_t b) {
	return (a + b) / 2;
}

/*???????????*/
int16_t fuzzifier(term Term, int16_t A) {
	int16_t mu=0;
	switch (Term.shape) {
	case TRIANGLE:
		mu = triangle(Term.min, Term.max, Term.pic, A);
		break;
	case BALL:
		mu = ball(Term.min, Term.max, A);
		break;
	case TRAPEZE:
		mu = trapeze(Term.min, Term.max, A);
		break;
	case TYPE_S:
		mu = typeS(Term.min, Term.max, A);
		break;
	case TYPE_Z:
		mu = typeZ(Term.min, Term.max, A);
		break;
	}
	return mu;
}


/*??????? ???????????*/
int16_t triangle(int16_t min, int16_t max, int16_t pic, int16_t A) {
	int16_t mu = 0;
	//float m = mean(min, max);
	if (A > max || A < min) mu = 0;
	else if (A < pic) {
		mu = (A - min) * MU_MAX / (pic-min);
	}
	else {
		mu = -(A - max) * MU_MAX / (max - pic);
	}
	return mu;
}
int16_t ball(int16_t min, int16_t max, int16_t A) {
	int16_t mu = 0;
	int16_t m = mean(min, max); 
	if (A > max || A < min) mu = 0;
	else mu = -((A - m) * (A - m)) * MU_MAX / (max - m) / (max - m) + 1;
	return mu;
}
int16_t trapeze(int16_t min, int16_t max, int16_t A) {
	int16_t mu = 0;
	int16_t dm = (max - min) / 3;
	if (A > max || A < min) mu = 0;
	else if (A > (min + dm) && A < (max - dm)) mu = MU_MAX;
	else if (A < (min + dm) && A > (min)){
		mu = (A - min) * MU_MAX / dm;
	}
	else {
		mu = -(A - max) * MU_MAX / dm;
	}
	return mu;
}
int16_t typeS(int16_t min, int16_t max, int16_t A) {
	int16_t mu = 0;
	if (A < min) mu = 0;
	else if (A > max) mu = MU_MAX;
	else {
		mu = (A - min) * MU_MAX / (max - min);
	}
	return mu;
}
int16_t typeZ(int16_t min, int16_t max, int16_t A) {
	int16_t mu = 0;
	if (A > max) mu = 0;
	else if (A < min) mu = MU_MAX;
	else {
		mu = -(A - max) * MU_MAX / (max - min);
	}
	return mu;
}

/*??????? ????????????? */
int16_t detriangle(int16_t min, int16_t max, int16_t pic, int16_t muB) {
	int16_t B = 0;
	//float m = mean(min, max);
	if (muB == 0) B = 0;
	else B = mean((muB * (pic-min)/MU_MAX + min), (-muB * (max - pic)/MU_MAX + max));
	return B;
}
int16_t deball(int16_t min, int16_t max, int16_t muB) {
	int16_t B = 0;
	int16_t m = mean(min, max);
	if (muB == 0) B = 0;
	else B = mean(sqrtf((MU_MAX - muB) * (max - m) * (max - m)) + m, -sqrtf((MU_MAX - muB) * (max - m) * (max - m)) + m);
	return B;
}
int16_t detrapeze(int16_t min, int16_t max, int16_t muB) {
	int16_t B = 0;
	int16_t dm = (max - min) / 3;
	if (muB == 0) B = 0;
	else if (muB == MU_MAX) B = mean(min + dm, max - dm);
	else B = mean((muB * dm + min), (-muB * dm + max));
	return B;
}
int16_t detypeS(int16_t min, int16_t max, int16_t muB) {
	int16_t B = 0;
	if (muB == 0) B = 0;
	else if (muB == MU_MAX) B = max;
	else B = mean((muB * (max - min)/MU_MAX + min), max);
	return B;
}
int16_t detypeZ(int16_t min, int16_t max, int16_t muB) {
	int16_t B = 0;
	if (muB == 0) B = 0;
	else if (muB == MU_MAX) B = min;
	else B = mean((-muB * (max - min)/MU_MAX + max), min);
	return B;
}

/*?????????????*/
int16_t defuzzifier(term termB, int16_t muB) {
	int16_t B = 0;
	switch (termB.shape) {
	case TRIANGLE:
		B = detriangle(termB.min, termB.max, termB.pic, muB);
		break;
	case BALL:
		B = deball(termB.min, termB.max, muB);
		break;
	case TRAPEZE:
		B = detrapeze(termB.min, termB.max, muB);
		break;
	case TYPE_S:
		B = detypeS(termB.min, termB.max, muB);
		break;
	case TYPE_Z:
		B = detypeZ(termB.min, termB.max, muB);
		break;
	}
	return B;
}

/*??????? ????????? ??????????? ??????*/
/*???????->????????*/
int16_t Mamdany_Singlton(rull *rulls, term *termB, char lenRulls) {
	int16_t outB = 0;
	int16_t B = 0;
	char i;
	int16_t sumMu = 0;

	for (i = 0; i < lenRulls; i++) {
		sumMu += rulls[i].mu;
	}

	for (i = 0; i < lenRulls; i++) {
		B = defuzzifier(termB[rulls[i].term], rulls[i].mu);
		outB += B * rulls[i].mu / sumMu;
	}
	return outB;
}