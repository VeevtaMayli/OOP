@echo off

SET PROGRAM="%~1"

SET OUT="%TEMP%\output.txt"

::Проверка на количество передаваемых аргументов
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% no-arguments-out.txt

::Проверка на наличие входного файла
%PROGRAM% somefile.txt "any string" > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% no-input-file-out.txt

::Проверка на пустой входной файл
%PROGRAM% empty.txt "any string" > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% empty-out.txt

::Искомая строка не найдена
%PROGRAM% input.txt "We are young" > %OUT% || goto err
fc %OUT% nothing-found-out.txt

::Иcкомая строка найдена
%PROGRAM% input.txt "Last own loud" > %OUT% || goto err
fc %OUT% string-found-out.txt

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1