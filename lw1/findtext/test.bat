@echo off

SET PROGRAM="%~1"

SET OUT="%TEMP%\output.txt"

::Проверка на количество передаваемых аргументов
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% no-arguments-out.txt
if ERRORLEVEL 1 goto err

::Проверка на наличие входного файла
%PROGRAM% somefile.txt "any string" > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% no-input-file-out.txt
if ERRORLEVEL 1 goto err

::Проверка на пустой входной файл
%PROGRAM% empty.txt "any string" > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% empty-out.txt
if ERRORLEVEL 1 goto err

::Проверка на пустую уискомую строку
%PROGRAM% input.txt "" > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% empty-string-out.txt
if ERRORLEVEL 1 goto err

::Искомая строка не найдена
%PROGRAM% input.txt "We are young" > %OUT% || goto err
fc %OUT% nothing-found-out.txt
if ERRORLEVEL 1 goto err

::Иcкомая строка найдена
%PROGRAM% input.txt "Last own loud" > %OUT% || goto err
fc %OUT% string-found-out.txt
if ERRORLEVEL 1 goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1