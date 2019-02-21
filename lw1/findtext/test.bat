@echo off

SET PROGRAM="%~1"

SET OUT="%TEMP%\output.txt"

::�������� �� ���������� ������������ ����������
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% no-arguments-out.txt || goto err

::�������� �� ������� �������� �����
%PROGRAM% somefile.txt "any string" > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% no-input-file-out.txt || goto err

::�������� �� ������ ������� �����
%PROGRAM% empty.txt "any string" > %OUT% || err
fc %OUT% empty-out.txt
if ERRORLEVEL 1 goto err

::�������� �� ������ ������� ������
%PROGRAM% input.txt "" > %OUT% || goto err
fc %OUT% empty-string-out.txt
if ERRORLEVEL 1 goto err

::������� ������ �� �������
%PROGRAM% input.txt "We are young" > %OUT% || goto err
fc %OUT% nothing-found-out.txt || goto err

::�c����� ������ �������
%PROGRAM% input.txt "Last own loud" > %OUT% || goto err
fc %OUT% string-found-out.txt || goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1