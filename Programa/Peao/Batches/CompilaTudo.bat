@ECHO  OFF
REM  Compila todos os exemplos simples 

pushd  .

del *.err
del TestePeao.exe

del *.obj
nmake /Ftestepeao.make 

copy  *.err  tudo.err

notepad tudo.err

popd
