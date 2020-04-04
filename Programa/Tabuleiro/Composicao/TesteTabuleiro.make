##################################################
###
### Diretivas de MAKE para o construto: TesteTabuleiro
### Gerado a partir de: TesteTabuleiro.comp
###
### ----- Arquivo gerado, NÃO EDITE!!! -----
###
##################################################

### Nomes globais

NOME            = TesteTabuleiro


### Nomes de paths

Pobj                 = .
Perr                 = .
PDEFAULT             = .
Pc                   = .

### Nomes de diretórios para geração

Fobj                 = .
Ferr                 = .
FDEFAULT             = .
Fc                   = .

### Macros da plataforma


O       = /D_CRT_SECURE_NO_DEPRECATE
OD      = /Zi /Od /D_CRT_SECURE_NO_DEPRECATE
L       =
LD      = /DEBUG /DEBUGTYPE:CV

!IFDEF PRD
O       = /Ox /D_CRT_SECURE_NO_DEPRECATE
!ENDIF

OPT     = /c /J /W4 /nologo
INCLUDE = $(INCLUDE);$(PDEFAULT)


### Regras de geração

all : limpa \
   $(Fobj)\TesteTabuleiro.obj   $(Fobj)\Tabuleiro.obj   $(Fobj)\Lista.obj \
   $(Fobj)\ListaC.obj   $(Fobj)\NoLista.obj \
   Construto

### Limpar arquivos

limpa :
   if exist $(Ferr)\$(NOME).err  del $(Ferr)\$(NOME).err


### Dependências de módulos objeto a compilar

$(Fobj)\TesteTabuleiro.obj :  {$(Pc)}\TesteTabuleiro.c \
    {$(PDEFAULT)}Definicoes.h         {$(PDEFAULT)}Generico.h           {$(PDEFAULT)}LerParm.h            \
    {$(PDEFAULT)}Lista.h              {$(PDEFAULT)}ListaC.h             {$(PDEFAULT)}TST_Espc.h           \
    {$(PDEFAULT)}Tabuleiro.h         
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\Tabuleiro.obj :  {$(Pc)}\Tabuleiro.c \
    {$(PDEFAULT)}Definicoes.h         {$(PDEFAULT)}Lista.h              {$(PDEFAULT)}ListaC.h             \
    {$(PDEFAULT)}Tabuleiro.h         
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\Lista.obj :  {$(Pc)}\Lista.c \
    {$(PDEFAULT)}LISTA.h             
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\ListaC.obj :  {$(Pc)}\ListaC.c \
    {$(PDEFAULT)}ListaC.h             {$(PDEFAULT)}NoLista.h           
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\NoLista.obj :  {$(Pc)}\NoLista.c \
    {$(PDEFAULT)}NoLista.h           
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err


### Terminação

Construto : \
   $(Fobj)\TesteTabuleiro.obj   $(Fobj)\Tabuleiro.obj   $(Fobj)\Lista.obj \
   $(Fobj)\ListaC.obj   $(Fobj)\NoLista.obj
    cd $(Fobj)
    LINK $(L) @$(NOME).build >> $(Ferr)\$(NOME).err

##################################################
###
### Fim de diretivas MAKE para o construto: TesteTabuleiro
###
##################################################

