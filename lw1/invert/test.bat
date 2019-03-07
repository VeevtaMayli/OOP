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

::�������� �� ������������ �������
%PROGRAM% invalid-matrix.txt > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% invalid-matrix-out.txt || goto err

::������� � ������������� < 0
%PROGRAM% zero-det.txt > %OUT% || err
fc %OUT% zero-det-out.txt || goto err

::������� ������ � �������������� ���������� � ������������� > 0
%PROGRAM% positive-matrix.txt > %OUT% || err
fc %OUT% positive-matrix-out.txt || goto err

::������� � ������ ���������� � ������������� > 0
%PROGRAM% real-matrix.txt > %OUT% || err
fc %OUT% real-matrix-out.txt || goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1