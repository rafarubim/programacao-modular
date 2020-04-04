
#pragma once

typedef enum {
	NOLST_CondRetOK = 0,
	NOLST_CondRetSemMemoria,
	NOLST_CondRetNoOcupado,
	NOLST_CondRetNoInexistente
} NOLST_tpCondRet;

typedef struct NOLST_tgNoLista* NOLST_tppNoLista;

NOLST_tpCondRet NOLST_CriarNoh(NOLST_tppNoLista* pNohRet, void* pInfo, NOLST_tppNoLista pNohAnterior, NOLST_tppNoLista pNoProximo);
NOLST_tpCondRet NOLST_DestruirNoh(NOLST_tppNoLista pNoLst);

NOLST_tpCondRet NOLST_ColocarNohEmFrente(NOLST_tppNoLista pNoLst, NOLST_tppNoLista pNovoNo);
NOLST_tpCondRet NOLST_ColocarNohAtras(NOLST_tppNoLista pNoLst, NOLST_tppNoLista pNovoNo);

NOLST_tpCondRet NOLST_ObterProxNoh(NOLST_tppNoLista pNoLst, NOLST_tppNoLista* pNoProxRet);
NOLST_tpCondRet NOLST_ObterNohPrevio(NOLST_tppNoLista pNoLst, NOLST_tppNoLista* pNoPrevioRet);

NOLST_tpCondRet NOLST_AtribuirInfoNoh(NOLST_tppNoLista pNoLst, void* pInfo);
NOLST_tpCondRet NOLST_ObterInfoNoh(NOLST_tppNoLista pNoLst, void** pInfoRet);
