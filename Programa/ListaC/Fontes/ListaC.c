#include "ListaC.h"

#include <stdlib.h>
#include "NoLista.h"

typedef struct LSTC_tgListaC {
	NOLST_tppNoLista pNoCorr;
	int NumElem;
	void (* ExcluirElem)(void* pInfo);
} LSTC_tpListaC;

static LSTC_tpCondRet JumpToPos(LSTC_tppListaC pLstC, int iPos, NOLST_tppNoLista* pNoRet);

static int CriterioPadrao(void* pElemBuscado, void* pElemLista);

LSTC_tpCondRet LSTC_CriarListaC(LSTC_tppListaC* pLstCRet, void (* ExcluirElem)(void* pInfo)) {
	*pLstCRet = (LSTC_tppListaC)malloc(sizeof(LSTC_tpListaC));
	if (!pLstCRet)	return LSTC_CondRetSemMemoria;
	(*pLstCRet)->pNoCorr = NULL;
	(*pLstCRet)->NumElem = 0;
	(*pLstCRet)->ExcluirElem = ExcluirElem;
	return LSTC_CondRetOK;
}

LSTC_tpCondRet LSTC_DestruirListaC(LSTC_tppListaC pLstC) {
	NOLST_tpCondRet debugNo;
	if (!pLstC)	return LSTC_CondRetListaInexistente;
	while (pLstC->pNoCorr) {
		void* tempInfo;
		NOLST_tppNoLista temp = pLstC->pNoCorr;
		debugNo = NOLST_ObterProxNoh(pLstC->pNoCorr, &pLstC->pNoCorr);
		if (debugNo)	return LSTC_CondRetErroNo;
		debugNo = NOLST_ObterInfoNoh(temp, &tempInfo);
		if (debugNo)	return LSTC_CondRetErroNo;
		if (pLstC->ExcluirElem && tempInfo)
			pLstC->ExcluirElem(tempInfo);
		free(temp); // Implementação não assume erro em free
	}
	free(pLstC);
	return LSTC_CondRetOK;
}

LSTC_tpCondRet LSTC_EhListaCVazia(LSTC_tppListaC pLstC, int* pEhVaziaRet) {
	if (!pLstC)	return LSTC_CondRetListaInexistente;
	if (!pLstC->pNoCorr)
		*pEhVaziaRet = 1;
	else
		*pEhVaziaRet = 0;
	return LSTC_CondRetOK;
}

LSTC_tpCondRet LSTC_InserirElemento(LSTC_tppListaC pLstC, int iPos, void* pInfo) {

	NOLST_tppNoLista novo = NULL, temp;
	NOLST_tpCondRet debugNo;
	LSTC_tpCondRet debug;

	if (!pLstC)	return LSTC_CondRetListaInexistente;
	if (iPos < 0 || iPos > pLstC->NumElem)
		return LSTC_CondRetPosInvalida;

	if (iPos == 0) {
		if (pLstC->NumElem == 0) {
			debugNo = NOLST_CriarNoh(&novo, pInfo, novo, novo);
			if (debugNo)	return LSTC_CondRetNoNaoCriado;
			pLstC->pNoCorr = novo;
		} else {
			debugNo = NOLST_CriarNoh(&novo, pInfo, NULL, NULL);
			if (debugNo)	return LSTC_CondRetNoNaoCriado;
			debugNo = NOLST_ColocarNohEmFrente(pLstC->pNoCorr, novo);
			if (debugNo)	return LSTC_CondRetErroNo;
		}
		debugNo = NOLST_AtribuirInfoNoh(novo, pInfo);
		if (debugNo)	return LSTC_CondRetErroNo;
		pLstC->NumElem++;
		return LSTC_CondRetOK;
	}

	debug = JumpToPos(pLstC, iPos, &temp);
	if (debug)	return debug;
	debugNo = NOLST_CriarNoh(&novo, pInfo, NULL, NULL);
	if (debugNo)	return LSTC_CondRetNoNaoCriado;
	debugNo = NOLST_AtribuirInfoNoh(novo, pInfo);
	if (debugNo)	return LSTC_CondRetErroNo;
	debugNo = NOLST_ColocarNohEmFrente(temp, novo);
	if (debugNo)	return LSTC_CondRetErroNo;
	pLstC->NumElem++;
	return LSTC_CondRetOK;
}

LSTC_tpCondRet LSTC_RetirarElemento(LSTC_tppListaC pLstC, int iPos) {

	NOLST_tppNoLista temp;
	NOLST_tpCondRet debugNo;
	LSTC_tpCondRet debug;
	void* tempInfo;

	if (!pLstC)	return LSTC_CondRetListaInexistente;
	if (iPos < 0 || iPos >= pLstC->NumElem)
		return LSTC_CondRetPosInvalida;

	if (iPos%pLstC->NumElem == 0) {
		temp = pLstC->pNoCorr;
		debugNo = NOLST_ObterProxNoh(pLstC->pNoCorr, &pLstC->pNoCorr);
		if (debugNo)	return LSTC_CondRetErroNo;
	} else {
		debug = JumpToPos(pLstC, iPos, &temp);
		if (debug)	return debug;
	}

	debugNo = NOLST_ObterInfoNoh(temp, &tempInfo);
	if (debugNo)	return LSTC_CondRetErroNo;
	if (pLstC->ExcluirElem && tempInfo)
		pLstC->ExcluirElem(tempInfo);
	free(temp);
	pLstC->NumElem--;
	return LSTC_CondRetOK;
}

LSTC_tpCondRet LSTC_AtribuirElemento(LSTC_tppListaC pLstC, int iPos, void* pInfo) {

	NOLST_tppNoLista no;
	LSTC_tpCondRet debug;
	NOLST_tpCondRet debugNo;

	if (!pLstC)	return LSTC_CondRetListaInexistente;
	if (iPos < 0 || iPos >= pLstC->NumElem)
		return LSTC_CondRetPosInvalida;

	debug = JumpToPos(pLstC, iPos, &no);
	if (debug)	return debug;

	debugNo = NOLST_AtribuirInfoNoh(no, pInfo);
	if (debugNo)	return LSTC_CondRetErroNo;

	return LSTC_CondRetOK;
}

LSTC_tpCondRet LSTC_ObterElemento(LSTC_tppListaC pLstC, int iPos, void** pInfoRet) {

	NOLST_tppNoLista no;
	LSTC_tpCondRet debug;
	NOLST_tpCondRet debugNo;

	if (!pLstC)	return LSTC_CondRetListaInexistente;
	if (iPos < 0 || iPos >= pLstC->NumElem)
		return LSTC_CondRetPosInvalida;

	debug = JumpToPos(pLstC, iPos, &no);
	if (debug)	return debug;

	debugNo = NOLST_ObterInfoNoh(no, pInfoRet);
	if (debugNo)	return LSTC_CondRetErroNo;

	return LSTC_CondRetOK;
}

LSTC_tpCondRet LSTC_MoverCorrente(LSTC_tppListaC pLstC, int iN) {
	LSTC_tpCondRet debug;
	NOLST_tppNoLista no;
	if (!pLstC)	return LSTC_CondRetListaInexistente;
	debug = JumpToPos(pLstC, iN, &no);
	if (debug)	return debug;
	pLstC->pNoCorr = no;
	return LSTC_CondRetOK;
}

LSTC_tpCondRet LSTC_ProcurarElemento(LSTC_tppListaC pLstC, void* pElemBuscado, int* pIndiceRet, int (*Criterio)(void* pElemBuscado, void* pElemLst)) {

	int i, flag = 0;
	NOLST_tpCondRet debugNo;
	LSTC_tpCondRet debug;

	if (!pLstC)	return LSTC_CondRetListaInexistente;

	if (!Criterio)
		Criterio = CriterioPadrao;

	for (i = 0; i < pLstC->NumElem; i++) {
		void* tempInfo;
		NOLST_tppNoLista tempNo;
		debug = JumpToPos(pLstC, i, &tempNo);
		if (debug)	return debug;
		debugNo = NOLST_ObterInfoNoh(tempNo, &tempInfo);
		if (debugNo)	return LSTC_CondRetErroNo;
		if (Criterio(pElemBuscado, tempInfo)) {
			*pIndiceRet = i;
			flag = 1;
			break;
		}
	}
	if (!flag) {
		*pIndiceRet = -1;
		return LSTC_CondRetElemInexistente;
	}

	return LSTC_CondRetOK; 
}

LSTC_tpCondRet LSTC_ObterTamanhoListaC(LSTC_tppListaC pLstC, int* pTamanhoRet) {

	if (!pLstC)	return LSTC_CondRetListaInexistente;
	*pTamanhoRet = pLstC->NumElem;
	return LSTC_CondRetOK;
}

LSTC_tpCondRet JumpToPos(LSTC_tppListaC pLstC, int iPos, NOLST_tppNoLista* pNoRet) {
	
	NOLST_tppNoLista aux = pLstC->pNoCorr;
	NOLST_tpCondRet debugNo;

	if (!pLstC)	return LSTC_CondRetListaInexistente;
	if (iPos < 0 || iPos >= pLstC->NumElem)
		return LSTC_CondRetPosInvalida;

	if (iPos >= 0)
		while(iPos--) {
			debugNo = NOLST_ObterProxNoh(aux, &aux);
			if (debugNo)	return LSTC_CondRetErroNo;
		}
	else
		while(iPos++) {
			debugNo = NOLST_ObterNohPrevio(aux, &aux);
			if (debugNo)	return LSTC_CondRetErroNo;
		}

	*pNoRet = aux;
	return LSTC_CondRetOK;
}

int CriterioPadrao(void* pElemBuscado, void* pElemLista) {
	if (pElemBuscado == pElemLista)
		return 1;
	else
		return 0;
}