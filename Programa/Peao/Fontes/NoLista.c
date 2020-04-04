#include "NoLista.h"

#include <stdlib.h>

typedef struct NOLST_tgNoLista {
	NOLST_tppNoLista pAnt;
	NOLST_tppNoLista pProx;
	void* pInfo;
} NOLST_tpNoLista;

static NOLST_tpCondRet Ligar(NOLST_tppNoLista pEsq, NOLST_tppNoLista pDir);

NOLST_tpCondRet NOLST_CriarNoh(NOLST_tppNoLista* pNohRet, void* pInfo, NOLST_tppNoLista pNohAnterior,NOLST_tppNoLista pNoProximo) {
	NOLST_tpCondRet debug;
	*pNohRet = (NOLST_tppNoLista)malloc(sizeof(NOLST_tpNoLista));
	if (!*pNohRet)	return NOLST_CondRetSemMemoria;
	debug = Ligar(pNohAnterior, *pNohRet);
	if (debug)	return debug; // Se Ligar não retornou OK
	debug = Ligar(*pNohRet, pNoProximo);
	if (debug)	return debug; // Se Ligar não retornou OK
	(*pNohRet)->pInfo = pInfo;
	return NOLST_CondRetOK;
}

NOLST_tpCondRet  NOLST_DestruirNoh(NOLST_tppNoLista pNoLst) {
	NOLST_tpCondRet debug;
	if (!pNoLst)	return NOLST_CondRetNoInexistente;
	debug = Ligar(pNoLst->pAnt, pNoLst->pProx);
	if (debug)	return debug;
	free(pNoLst); // Implementação não assume erro em free
	return NOLST_CondRetOK;
}

NOLST_tpCondRet  NOLST_ColocarNohEmFrente(NOLST_tppNoLista pNoLst, NOLST_tppNoLista pNovoNo) {
	NOLST_tpCondRet debug;
	NOLST_tppNoLista velhoProx;
	if (!pNoLst)	return NOLST_CondRetNoInexistente;
	velhoProx = pNoLst->pProx;
	if (pNovoNo->pAnt || pNovoNo->pProx)	return NOLST_CondRetNoOcupado;
	debug = Ligar(pNoLst, pNovoNo);
	if (debug)	return debug; // Se Ligar não retornou OK
	debug = Ligar(pNovoNo, velhoProx);
	if (debug)	return debug; // Se Ligar não retornou OK
	return NOLST_CondRetOK;
}

NOLST_tpCondRet  NOLST_ColocarNohAtras(NOLST_tppNoLista pNoLst, NOLST_tppNoLista pNovoNo) {
	NOLST_tpCondRet debug;
	NOLST_tppNoLista velhoAnt;
	if (!pNoLst)	return NOLST_CondRetNoInexistente;
	velhoAnt = pNoLst->pAnt;
	if (pNovoNo->pAnt || pNovoNo->pProx)	return NOLST_CondRetNoOcupado;
	debug = Ligar(pNovoNo, pNoLst);
	if (debug)	return debug; // Se Ligar não retornou OK
	debug = Ligar(velhoAnt, pNovoNo);
	if (debug)	return debug; // Se Ligar não retornou OK
	return NOLST_CondRetOK;
}

NOLST_tpCondRet  NOLST_ObterProxNoh(NOLST_tppNoLista pNoLst, NOLST_tppNoLista* pNoProxRet) {
	if (!pNoLst)	return NOLST_CondRetNoInexistente;
	*pNoProxRet = pNoLst->pProx;
	return NOLST_CondRetOK;
}

NOLST_tpCondRet  NOLST_ObterNohPrevio(NOLST_tppNoLista pNoLst, NOLST_tppNoLista* pNoPrevioRet) {
	if (!pNoLst)	return NOLST_CondRetNoInexistente;
	*pNoPrevioRet = pNoLst->pAnt;
	return NOLST_CondRetOK;
}

NOLST_tpCondRet  NOLST_AtribuirInfoNoh(NOLST_tppNoLista pNoLst, void* pInfo) {
	if (!pNoLst)	return NOLST_CondRetNoInexistente;
	pNoLst->pInfo = pInfo;
	return NOLST_CondRetOK;
}

NOLST_tpCondRet  NOLST_ObterInfoNoh(NOLST_tppNoLista pNoLst, void** pInfoRet) {
	if (!pNoLst)	return NOLST_CondRetNoInexistente;
	*pInfoRet = pNoLst->pInfo;
	return NOLST_CondRetOK;
}

NOLST_tpCondRet Ligar(NOLST_tppNoLista pEsq, NOLST_tppNoLista pDir) {
	if (pEsq)
		pEsq->pProx = pDir;
	if (pDir)
		pDir->pAnt = pEsq;
	return NOLST_CondRetOK;
}