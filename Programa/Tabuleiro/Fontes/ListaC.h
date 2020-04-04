/*******************************************************
* $MCD Modulo de defini�ao: Modulo ListaC
* Arquivo:   ListaC.h
*
* Autores: jnk - Julio Neuman Kessel
*          rrc - Rafael Rubim Cabral
*          phf - Pedro Henrique Frayha
*******************************************************/
#pragma once

typedef struct LSTC_tgListaC* LSTC_tppListaC;

typedef enum {
	LSTC_CondRetOK,
	LSTC_CondRetSemMemoria,
	LSTC_CondRetPosInvalida,
	LSTC_CondRetElemInexistente,
	LSTC_CondRetNoNaoCriado,
	LSTC_CondRetErroNo,
	LSTC_CondRetListaInexistente
} LSTC_tpCondRet;


/***********************************************************************
* $FC Fun��oLST_CriarListaC
* 
* $FV Valores de Retorno
*     LSTC_CondRetSemMemoria - Falta de Memoria
*     LSTC_CondRetOK - Criou sem problemas
***********************************************************************/
LSTC_tpCondRet LSTC_CriarListaC(LSTC_tppListaC* pLstCRet, void (* ExcluirElem)(void* pInfo));

/***********************************************************************
* $FC Fun��oLST_DestruirLista
* 
* $FV Valores de Retorno
*     LSTC_CondRetErroNo - Erro na destrui��o da lista
*     LSTC_CondRetOK - Destruiu sem problemas
*	  LSTC_CondRetListaInexistente - N�o existe lista
***********************************************************************/
LSTC_tpCondRet LSTC_DestruirListaC(LSTC_tppListaC pLstC);

/***********************************************************************
* $FC Fun��oLST_EhListaCVazia
* 
* $FV Valores de Retorno
*     LSTC_CondRetOK
*	  LSTC_CondRetListaInexistente - N�o existe lista
***********************************************************************/
LSTC_tpCondRet LSTC_EhListaCVazia(LSTC_tppListaC pLstC, int* pEhVaziaRet);

/***********************************************************************
* $FC Fun��oLST_InserirElemento
* 
* $FV Valores de Retorno
*     LSTC_CondRetPosInvalida - Erro posi��o invalida
*     LSTC_CondRetNoNaoCriado - Erro na cria��o do n�
*     LSTC_CondRetErroNo - Erro ao manipular n�
*     LSTC_CondRetOK - Elemento inserido sem problemas
*	  LSTC_CondRetListaInexistente - N�o existe lista
***********************************************************************/
LSTC_tpCondRet LSTC_InserirElemento(LSTC_tppListaC pLstC, int iPos, void* pInfo);

/***********************************************************************
* $FC Fun��oLST_RetirarElemento
* 
* $FV Valores de Retorno
*     LSTC_CondRetPosInvalida - Erro posi��o invalida
*     LSTC_CondRetErroNo - Erro ao manipular n�
*     LSTC_CondRetOK - Elemento retirado sem problemas
*	  LSTC_CondRetListaInexistente - N�o existe lista
***********************************************************************/
LSTC_tpCondRet LSTC_RetirarElemento(LSTC_tppListaC pLstC, int iPos);

/***********************************************************************
* $FC Fun��oLST_AtribuirElemento
* 
* $FV Valores de Retorno
*     LSTC_CondRetPosInvalida - Erro posi��o invalida
*     LSTC_CondRetErroNo - Erro ao manipular n�
*     LSTC_CondRetOK - Atribui��o realizada sem problemas
*	  LSTC_CondRetListaInexistente - N�o existe lista
***********************************************************************/
LSTC_tpCondRet LSTC_AtribuirElemento(LSTC_tppListaC pLstC, int iPos, void* pInfo);

/***********************************************************************
* $FC Fun��oLST_ObterElemento
* 
* $FV Valores de Retorno
*     LSTC_CondRetPosInvalida - Erro posi��o invalida
*     LSTC_CondRetErroNo - Erro ao manipular n�
*     LSTC_CondRetOK - Elemento obtido sem problemas
*	  LSTC_CondRetListaInexistente - N�o existe lista
***********************************************************************/
LSTC_tpCondRet LSTC_ObterElemento(LSTC_tppListaC pLstC, int iPos, void** pInfoRet);

/***********************************************************************
* $FC Fun��oLST_MoverCorrente
* 
* $FV Valores de Retorno
*     LSTC_CondRetOK - Opera��o realizada sem problemas
*     LSTC_CondRetErroNo - Erro ao manipular n�
*	  LSTC_CondRetListaInexistente - N�o existe lista
***********************************************************************/
LSTC_tpCondRet LSTC_MoverCorrente(LSTC_tppListaC pLstC, int iN);

/***********************************************************************
* $FC Fun��oLST_ProcurarElemento
* 
* $FV Valores de Retorno
*     LSTC_CondRetErroNo - Erro ao manipular n�
*     LSTC_CondRetElemInexistente - Erro elemento n�o existe
*     LSTC_CondRetOK - Busca realizada sem problemas
*	  LSTC_CondRetListaInexistente - N�o existe lista
***********************************************************************/
// Retorna o indice do elemento procurado ou -1 se inexistente. "criterio" � a fun��o que retorna 1 caso seu par�metro corresponda ao que se procura (O tipo de elemBuscado pode ser diferente do tipo padr�o da lista)
LSTC_tpCondRet LSTC_ProcurarElemento(LSTC_tppListaC pLstC, void* pElemBuscado, int* pIndiceRet, int (*Criterio)(void* pElemBuscado, void* pElemLista));

/***********************************************************************
* $FC Fun��oLST_ObterTamanhoListaC
* 
* $FV Valores de Retorno
*     LSTC_CondRetOK - Opera��o realizada sem problemas
*	  LSTC_CondRetListaInexistente - N�o existe lista
***********************************************************************/
LSTC_tpCondRet LSTC_ObterTamanhoListaC(LSTC_tppListaC pLstC, int* pTamanhoRet);