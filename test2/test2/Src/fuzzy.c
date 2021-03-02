#include "fuzzy.h"

/*int main() {
	float der = 2;//error' = (v-v_t)'
	float er = 8;//error = (v-v_t)
	float TargetMoment = 0;
	TargetMoment = fuzzyController(er, der);
	return 0;
}*/

int16_t fuzzyController(int16_t er, int16_t der) {
	/*????????????? ??????? ??????????????*/
	int16_t muEr[ER_TERMS_COUNT] = { 0,0,0 };
	int16_t muDEr[DER_TERMS_COUNT] = { 0,0,0 };

	/*???????? ??????????*/
	int16_t TargetMoment = 0;

	/*???????*/
	rull MomRull[MOMENT_RULLS_COUNT];

	/*????????????? ??????*/
	term er_var[ER_TERMS_COUNT];
	term der_var[DER_TERMS_COUNT];
	term moment_var[MOMENT_TERMS_COUNT];

	/*????? ????????*/
	char i = 0;

	/*???????? ??????????????? ??????????*//*??????????? ??????*/
	er_var[OB].min = -300;
	er_var[OB].max = -200;
	er_var[OB].shape = TYPE_Z;

	er_var[OC].min = -300;
	er_var[OC].max = -100;
	er_var[OC].pic = -200;
	er_var[OC].shape = TRIANGLE;

	er_var[OM].min = -200;
	er_var[OM].max = -10;
	er_var[OM].pic = -100;
	er_var[OM].shape = TRIANGLE;

	er_var[H].min = -10;
	er_var[H].max = 10;
	er_var[H].pic = 0;
	er_var[H].shape = TRIANGLE;

	er_var[PM].min = 10;
	er_var[PM].max = 200;
	er_var[PM].pic = 100;
	er_var[PM].shape = TRIANGLE;

	er_var[PC].min = 100;
	er_var[PC].max = 300;
	er_var[PC].pic = 200;
	er_var[PC].shape = TRIANGLE;

	er_var[PB].min = 200;
	er_var[PB].max = 300;
	er_var[PB].shape = TYPE_S;


	der_var[OB].min = -300;
	der_var[OB].max = -200;
	der_var[OB].shape = TYPE_Z;

	der_var[OC].min = -300;
	der_var[OC].max = -100;
	der_var[OC].pic = -200;
	der_var[OC].shape = TRIANGLE;

	der_var[OM].min = -200;
	der_var[OM].max = -10;
	der_var[OM].pic = -100;
	der_var[OM].shape = TRIANGLE;

	der_var[H].min = -10;
	der_var[H].max = 10;
	der_var[H].pic = 0;
	der_var[H].shape = TRIANGLE;

	der_var[PM].min = 10;
	der_var[PM].max = 200;
	der_var[PM].pic = 100;
	der_var[PM].shape = TRIANGLE;

	der_var[PC].min = 100;
	der_var[PC].max = 300;
	der_var[PC].pic = 200;
	der_var[PC].shape = TRIANGLE;

	der_var[PB].min = 200;
	der_var[PB].max = 300;
	der_var[PB].shape = TYPE_S;



	moment_var[OB].min = -10;
	moment_var[OB].max = -6;
	moment_var[OB].shape = TYPE_Z;

	moment_var[OC].min = -10;
	moment_var[OC].max = -3;
	moment_var[OC].pic = -6;
	moment_var[OC].shape = TRIANGLE;

	moment_var[OM].min = -6;
	moment_var[OM].max = -1;
	moment_var[OM].pic = -3;
	moment_var[OM].shape = TRIANGLE;

	moment_var[H].min = -1;
	moment_var[H].max = 1;
	moment_var[H].pic = 0;
	moment_var[H].shape = TRIANGLE;

	moment_var[PM].min = 1;
	moment_var[PM].max = 6;
	moment_var[PM].pic = 3;
	moment_var[PM].shape = TRIANGLE;

	moment_var[PC].min = 3;
	moment_var[PC].max = 10;
	moment_var[PC].pic = 6;
	moment_var[PC].shape = TRIANGLE;

	moment_var[PB].min = 6;
	moment_var[PB].max = 10;
	moment_var[PB].shape = TYPE_S;
												
	/*???????????*/
	for (i = 0; i < ER_TERMS_COUNT; i++) {
		muEr[i] = fuzzifier(er_var[i], er);
	}

	for (i = 0; i < DER_TERMS_COUNT; i++) {
		muDEr[i] = fuzzifier(der_var[i], der);
	}

	/*???? ?????? + ??????????*/
	//???? ? ????, ?? ? ????, ?????, ????? ?', ??????? ?' 
	//? ???????? ?????????????? mu
	//??????? ????????? ? ????????? (?????) i


	// ??????? ??? ????????? ?-??????????
	// ????? ??? ??????? ?????? ??????
	MomRull[0].mu = muEr[OB];
	MomRull[0].term = OB;
	MomRull[1].mu = muEr[OC];
	MomRull[1].term = OC;
	MomRull[2].mu = muEr[OM];
	MomRull[2].term = OM;
	MomRull[3].mu = muEr[H];
	MomRull[3].term = H;
	MomRull[4].mu = muEr[PM];
	MomRull[4].term = PM;
	MomRull[5].mu = muEr[PC];
	MomRull[5].term = PC;
	MomRull[6].mu = muEr[PB];
	MomRull[6].term = PB;

	/*MomRull[0].mu = fuzzyAnd(muEr[OB], muDEr[OB]);		
	MomRull[0].term = OB;
	MomRull[1].mu = fuzzyAnd(muEr[OC], muDEr[OB]);
	MomRull[1].term = OB;
	MomRull[2].mu = fuzzyAnd(muEr[OM], muDEr[OB]);
	MomRull[2].term = OB;
	MomRull[3].mu = fuzzyAnd(muEr[H], muDEr[OB]);
	MomRull[3].term = OB;
	MomRull[4].mu = fuzzyAnd(muEr[OB], muDEr[OC]);
	MomRull[4].term = OB;
	MomRull[5].mu = fuzzyAnd(muEr[OC], muDEr[OC]);
	MomRull[5].term = OB;
	MomRull[6].mu = fuzzyAnd(muEr[OM], muDEr[OC]);
	MomRull[6].term = OB;
	MomRull[7].mu = fuzzyAnd(muEr[OB], muDEr[OM]);
	MomRull[7].term = OB;
	MomRull[8].mu = fuzzyAnd(muEr[OC], muDEr[OM]);
	MomRull[8].term = OB;
	MomRull[9].mu = fuzzyAnd(muEr[OB], muDEr[H]);
	MomRull[9].term = OB;


	MomRull[10].mu = fuzzyAnd(muEr[OB], muDEr[PM]);
	MomRull[10].term = OC;
	MomRull[11].mu = fuzzyAnd(muEr[OC], muDEr[H]);
	MomRull[11].term = OC;
	MomRull[12].mu = fuzzyAnd(muEr[OM], muDEr[OM]);
	MomRull[12].term = OC;
	MomRull[13].mu = fuzzyAnd(muEr[H], muDEr[OC]);
	MomRull[13].term = OC;
	MomRull[14].mu = fuzzyAnd(muEr[PM], muDEr[OB]);
	MomRull[14].term = OC;


	MomRull[15].mu = fuzzyAnd(muEr[OB], muDEr[PC]);
	MomRull[15].term = OM;
	MomRull[16].mu = fuzzyAnd(muEr[OC], muDEr[PM]);
	MomRull[16].term = OM;
	MomRull[17].mu = fuzzyAnd(muEr[OM], muDEr[H]);
	MomRull[17].term = OM;
	MomRull[18].mu = fuzzyAnd(muEr[H], muDEr[OM]);
	MomRull[18].term = OM;
	MomRull[19].mu = fuzzyAnd(muEr[PM], muDEr[OC]);
	MomRull[19].term = OM;
	MomRull[20].mu = fuzzyAnd(muEr[PC], muDEr[OB]);
	MomRull[20].term = OM;


	MomRull[21].mu = fuzzyAnd(muEr[OB], muDEr[PB]);
	MomRull[21].term = H;
	MomRull[22].mu = fuzzyAnd(muEr[OC], muDEr[PC]);
	MomRull[22].term = H;
	MomRull[23].mu = fuzzyAnd(muEr[OM], muDEr[PM]);
	MomRull[23].term = H;
	MomRull[24].mu = fuzzyAnd(muEr[H], muDEr[H]);
	MomRull[24].term = H;
	MomRull[25].mu = fuzzyAnd(muEr[PM], muDEr[OM]);
	MomRull[25].term = H;
	MomRull[26].mu = fuzzyAnd(muEr[PC], muDEr[OC]);
	MomRull[26].term = H;
	MomRull[27].mu = fuzzyAnd(muEr[PB], muDEr[OB]);
	MomRull[27].term = H;


	MomRull[28].mu = fuzzyAnd(muEr[PB], muDEr[OC]);
	MomRull[28].term = PM;
	MomRull[29].mu = fuzzyAnd(muEr[PC], muDEr[OM]);
	MomRull[29].term = PM;
	MomRull[30].mu = fuzzyAnd(muEr[PM], muDEr[H]);
	MomRull[30].term = PM;
	MomRull[31].mu = fuzzyAnd(muEr[H], muDEr[PM]);
	MomRull[31].term = PM;
	MomRull[32].mu = fuzzyAnd(muEr[OM], muDEr[PC]);
	MomRull[32].term = PM;
	MomRull[33].mu = fuzzyAnd(muEr[OC], muDEr[PB]);
	MomRull[33].term = PM;


	MomRull[34].mu = fuzzyAnd(muEr[PB], muDEr[OM]);
	MomRull[34].term = PC;
	MomRull[35].mu = fuzzyAnd(muEr[PC], muDEr[H]);
	MomRull[35].term = PC;
	MomRull[36].mu = fuzzyAnd(muEr[PM], muDEr[PM]);
	MomRull[36].term = PC;
	MomRull[37].mu = fuzzyAnd(muEr[H], muDEr[PC]);
	MomRull[37].term = PC;
	MomRull[38].mu = fuzzyAnd(muEr[OM], muDEr[PB]);
	MomRull[38].term = PC;


	MomRull[39].mu = fuzzyAnd(muEr[PB], muDEr[PB]);
	MomRull[39].term = PB;
	MomRull[40].mu = fuzzyAnd(muEr[PB], muDEr[PC]);
	MomRull[40].term = PB;
	MomRull[41].mu = fuzzyAnd(muEr[PB], muDEr[PM]);
	MomRull[41].term = PB;
	MomRull[42].mu = fuzzyAnd(muEr[PB], muDEr[H]);
	MomRull[42].term = PB;
	MomRull[43].mu = fuzzyAnd(muEr[PC], muDEr[PB]);
	MomRull[43].term = PB;
	MomRull[44].mu = fuzzyAnd(muEr[PC], muDEr[PC]);
	MomRull[44].term = PB;
	MomRull[45].mu = fuzzyAnd(muEr[PC], muDEr[PM]);
	MomRull[45].term = PB;
	MomRull[46].mu = fuzzyAnd(muEr[PM], muDEr[PB]);
	MomRull[46].term = PB;
	MomRull[47].mu = fuzzyAnd(muEr[PM], muDEr[PC]);
	MomRull[47].term = PB;
	MomRull[48].mu = fuzzyAnd(muEr[H], muDEr[PB]);
	MomRull[48].term = PB;*/
	/*??????????+?????????????*/
	TargetMoment = Mamdany_Singlton(MomRull, moment_var, MOMENT_RULLS_COUNT);

	return TargetMoment;
}