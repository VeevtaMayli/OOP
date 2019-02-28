@echo off

SET PROGRAM="%~1"

SET OUT="%TEMP%\output.txt"

::�������� �� ���������� ������������ ����������
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% no-arguments-out.txt || goto err

::�������� �� ������� �������� �����
%PROGRAM% somefile.txt > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% no-input-file-out.txt || goto err

::�������� �� ������ ������� ����
%PROGRAM% empty.txt > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% empty-out.txt || goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1