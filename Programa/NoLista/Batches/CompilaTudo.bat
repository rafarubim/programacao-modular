@ECHO  OFF
REM  Compila todos os exemplos simples 

pushd  .

del *.err
del TesteNoLista.exe

del *.obj
nmake /FtesteNolista.make 

copy  *.err  tudo.err

notepad tudo.err

popd
