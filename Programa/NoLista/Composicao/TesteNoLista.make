##################################################
###
### Diretivas de MAKE para o construto: TesteNoLista
### Gerado a partir de: TesteNoLista.comp
###
### ----- Arquivo gerado, N�O EDITE!!! -----
###
##################################################

### Nomes globais

NOME            = TesteNoLista


### Nomes de paths

Pobj                 = .
Perr                 = .
PDEFAULT             = .
Pc                   = .

### Nomes de diret�rios para gera��o

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


### Regras de gera��o

all : limpa \
   $(Fobj)\TesteNoLista.obj   $(Fobj)\NoLista.obj \
   Construto

### Limpar arquivos

limpa :
   if exist $(Ferr)\$(NOME).err  del $(Ferr)\$(NOME).err


### Depend�ncias de m�dulos objeto a compilar

$(Fobj)\TesteNoLista.obj :  {$(Pc)}\TesteNoLista.c \
    {$(PDEFAULT)}Generico.h           {$(PDEFAULT)}LerParm.h            {$(PDEFAULT)}NoLista.h            \
    {$(PDEFAULT)}TST_Espc.h          
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err

$(Fobj)\NoLista.obj :  {$(Pc)}\NoLista.c \
    {$(PDEFAULT)}NoLista.h           
   cl $(O) $(OPT) /Fo$(Fobj)\ $(Fc)\$(@B).c >> $(Ferr)\$(NOME).err


### Termina��o

Construto : \
   $(Fobj)\TesteNoLista.obj   $(Fobj)\NoLista.obj
    cd $(Fobj)
    LINK $(L) @$(NOME).build >> $(Ferr)\$(NOME).err

##################################################
###
### Fim de diretivas MAKE para o construto: TesteNoLista
###
##################################################

