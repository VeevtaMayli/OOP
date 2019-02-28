@echo off

SET PROGRAM="%~1"

SET OUT="%TEMP%\output.txt"

::�������� �� ���������� ������������ ����������
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% no-arguments-out.txt || goto err

::��������� ����� ��� ��������� unsigned int
%PROGRAM% 9876543210 > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% out-of-unsigned-int-out.txt || goto err

::��������� ����� ���� ��������� <0, 255>
%PROGRAM% 1000 > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% out-of-range-out.txt || goto err

::��������� ����� ���� ��������� <0, 255>
%PROGRAM% -1 > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% out-of-range-out.txt || goto err

::�������� �� ����������� �����
%PROGRAM% 0 > %OUT% || err
fc %OUT% flip-min-out.txt || err

::�������� �� ������������ �����
%PROGRAM% 255 > %OUT% || err
fc %OUT% flip-max-out.txt || err

::�������� �� ����� �����
%PROGRAM% 176 > %OUT% || err
fc %OUT% flip-176-out.txt || err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1