##################################################
###
### Diretivas de MAKE para o construto: TesteListaC
### Gerado a partir de: TesteListaC.comp
###
### ----- Arquivo gerado, NÃO EDITE!!! -----
###
##################################################

### Nomes globais

NOME            = TesteListaC


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
   $(Fobj)\TesteListaC.obj   $(Fobj)\ListaC.obj   $(Fobj)\NoLista.obj \
   Construto

### Limpar arquivos

limpa :
   if exist $(Ferr)\$(NOME).err  del $(Ferr)\$(NOME).err


### Dependências de módulos objeto a compilar

$(Fobj)\TesteListaC.obj :  {$(Pc)}\TesteListaC.c \
    {$(PDEFAULT)}Generico.h           {$(PDEFAULT)}LerParm.h            {$(PDEFAULT)}ListaC.h             \
    {$(PDEFAULT)}TST_Espc.h          
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\ListaC.obj :  {$(Pc)}\ListaC.c \
    {$(PDEFAULT)}ListaC.h             {$(PDEFAULT)}NoLista.h           
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\NoLista.obj :  {$(Pc)}\NoLista.c \
    {$(PDEFAULT)}NoLista.h           
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err


### Terminação

Construto : \
   $(Fobj)\TesteListaC.obj   $(Fobj)\ListaC.obj   $(Fobj)\NoLista.obj
    cd $(Fobj)
    LINK $(L) @$(NOME).build >> $(Ferr)\$(NOME).err

##################################################
###
### Fim de diretivas MAKE para o construto: TesteListaC
###
##################################################

