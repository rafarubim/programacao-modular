/***************************************************************************
*  $MCI M�dulo de implementa��o: TTAB Teste lista de s�mbolos
*
*  Arquivo gerado:              TesteTabuleiro.c
*  Letras identificadoras:      TTAB
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: rrc
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1       rrc   19/out/2016 desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "Tabuleiro.h"


static const char RESET_VETOR_CMD			 [ ] = "=resetteste"	;
static const char CRIAR_TABULEIRO_CMD		 [ ] = "=cria"			;
static const char DESTRUIR_TABULEIRO_CMD	 [ ] = "=destroi"		;
static const char DISPONIBILIDADE_CASA_CMD	 [ ] = "=disponivel"	;
static const char RETORNAR_CASA_CMD			 [ ] = "=retornacasa"	;
static const char RETORNAR_CASA_SAIDA_CMD	 [ ] = "=casasaida"		;
static const char EH_CASA_FINAL_CMD			 [ ] = "=ehcasafinal"	;

#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1
#define IRRELEVANTE 2

#define DIM_VT_LISTA   10
#define DIM_VALOR     100

TAB_tppTabuleiro	vtTabs[ DIM_VT_LISTA ] ;
TAB_tppCasa			vtCasas[ DIM_VT_LISTA ] ;

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

   static void DestruirValor( void * pValor ) ;

   static int ValidarInxVec( int inxLista , int Modo ) ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TLIS &Testar lista
*
*  $ED Descri��o da fun��o
*     Podem ser criados at� 10 tabuleiros, identificados pelos �ndices 0 a 10
*	  Algumas casas ser�o criadas, tamb�m identificadas por �ndices 0 a 10
*
*     Comandos dispon�veis:
*
*     =resetteste
*           - anula o vetor de listas. Provoca vazamento de mem�ria
*     =cria       inxLista
*     =destroi    inxLista
*     =disponivel	 inxLista  inxRet	
*     =retornacasa	         inxLista  iPos		inxChar		CondRetEsp
*     =casasaida		 inxLista  iPos		CondRetEsp
*     =ehcasafinal		 inxLista  iPos		inxChar
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      int numLidos   = -1 ,
          debugEsp = -1  ;

	  TST_tpCondRet CondRet;
      TAB_tpCondRet debug;

	  int parmInt[10];
	  char parmChar[10];

	  //vtCasas[0] = {};

      int i ;

      /* Efetuar reset de teste de lista */

         if ( strcmp( ComandoTeste , RESET_VETOR_CMD ) == 0 )
         {

            for( i = 0 ; i < DIM_VT_LISTA ; i++ )
            {
               vtTabs[ i ] = NULL ;
            } /* for */

            return TST_CondRetOK ;

         } /* fim ativa: Efetuar reset de teste de lista */

   

         else if ( strcmp( ComandoTeste , CRIAR_TABULEIRO_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                       &parmInt[0], &debugEsp) ;

            if ( ( numLidos != 2 )
              || ( ! ValidarInxVec( parmInt[0] , VAZIO )))
            {
               return TST_CondRetParm ;
            } /* if */

            debug = TAB_CriarTabuleiro(&vtTabs[parmInt[0]]);

			CondRet = TST_CompararInt(debugEsp, debug, "Condicao de retorno inesperada em CriarTabuleiro");
			if (CondRet)	return (CondRet);

            return TST_CompararPonteiroNulo( 1 , vtTabs[parmInt[0]] ,
               "Erro em ponteiro de nova listaC.");

         }

         else if ( strcmp( ComandoTeste , DESTRUIR_TABULEIRO_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                               &parmInt[0], &debugEsp);

            if ( ( numLidos != 2)
              || ( ! ValidarInxVec( parmInt[0] , IRRELEVANTE )))
            {
               return TST_CondRetParm ;
            } /* if */

            debug = TAB_DestruirTabuleiro(vtTabs[parmInt[0]]);
			vtTabs[parmInt[0]] = NULL;

			return TST_CompararInt(debugEsp, debug, "Condicao de Retorno inesperado em teste DestruirTabuleiro");

         }

    

         else if ( strcmp( ComandoTeste , DISPONIBILIDADE_CASA_CMD ) == 0 )
         {
			/*FUN��O N�O � DO T2- N�O IMPLEMENTADA!!!*/
			 return TST_CondRetParm ;
         }


         else if ( strcmp( ComandoTeste , RETORNAR_CASA_CMD ) == 0 )
         {
			/*FUN��O N�O � DO T2- N�O IMPLEMENTADA!!!*/
			 return TST_CondRetParm ;

         } 

         else if ( strcmp( ComandoTeste , RETORNAR_CASA_SAIDA_CMD ) == 0 )
         {
			TAB_tppCasa retorno;
            numLidos = LER_LerParametros( "iiii" ,
                       &parmInt[0] , &parmInt[1] , &parmInt[2], &debugEsp ) ;

            if ( ( numLidos != 4 )
              || ( ! ValidarInxVec( parmInt[0] , IRRELEVANTE )) )
            {
               return TST_CondRetParm ;
            } /* if */

			debug = TAB_RetornarCasaDeSaida(vtTabs[parmInt[0]], parmInt[1], &retorno);
			CondRet = TST_CompararInt( debugEsp, debug ,
                     "Condicao de retorno errada ao retornar casa de saida.") ;
			if (CondRet)	return CondRet;

            return TST_CompararPonteiro( vtCasas[parmInt[2]], retorno ,
                     "Retorno inesperado de casa de saida.") ;

         }

         else if ( strcmp( ComandoTeste , EH_CASA_FINAL_CMD ) == 0 )
         {
			int retorno;
            numLidos = LER_LerParametros( "iii" ,
                  &parmInt[0] , &parmInt[1], &debugEsp) ;

            if ( ( numLidos != 3 )
              || ( ! ValidarInxVec( parmInt[0] , IRRELEVANTE )) )
            {
               return TST_CondRetParm ;
            } /* if */

			debug = TAB_EhCasaFinal(vtCasas[parmInt[0]], &retorno);
			CondRet = TST_CompararInt( debugEsp , debug,
				"Condi��o de retorno errada em EhCasaFinal.") ;
			if (CondRet)	return CondRet;

            return TST_CompararInt( parmInt[1] , retorno,
				"Retorno inesperado de EhCasaFinal.") ;

         }

      return TST_CondRetNaoConhec ;

   }


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TLIS -Validar indice de lista
*
***********************************************************************/

   int ValidarInxVec( int inxLista , int Modo )
   {

      if ( ( inxLista <  0 )
        || ( inxLista >= DIM_VT_LISTA ))
      {
         return FALSE ;
      } /* if */
      if ( Modo == IRRELEVANTE )
		return TRUE;
      if ( Modo == VAZIO )
      {
         if ( vtTabs[ inxLista ] != 0 )
         {
            return FALSE ;
         } /* if */
      } else
      {
         if ( vtTabs[ inxLista ] == 0 )
         {
            return FALSE ;
         } /* if */
      } /* if */
         
      return TRUE ;

   } /* Fim fun��o: TLIS -Validar indice de lista */

/********** Fim do m�dulo de implementa��o: TLIS Teste lista de s�mbolos **********/

