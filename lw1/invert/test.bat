rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ��� ������� ��� ���������� ��������� ��������� ��� ��������
echo test1
%PROGRAM% >nul
if NOT ERRORLEVEL 1 goto err

rem ��� ��������� �������� ����� ��������� ��������� ��� ��������
echo test2
%PROGRAM% fileNotFound.txt >nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ��������� ��� ��������(������ ����)
echo test3
%PROGRAM% test-data\emptyFile.txt >nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ��������� ��� ��������(������������ ������ � �����)
echo test4
%PROGRAM% test-data\matrixErr1.txt >nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ��������� ��� ��������(������������ ������ � �����)
echo test5
%PROGRAM% test-data\matrixErr2.txt >nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ��������� ��� ��������(������������ = 0)
echo test6
%PROGRAM% test-data\matrixErr3.txt >nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(�������� � �������������� ����� ���������)
echo test7
%PROGRAM% test-data\matrix1.txt> "%TEMP%\invertedMatrixResult.txt" 
fc.exe "%TEMP%\invertedMatrixResult.txt" test-data\invertedMatrix.txt > nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(�������� � �������������� ����� �� ���������)
echo test8
%PROGRAM% test-data\matrix1.txt> "%TEMP%\invertedMatrixResult.txt" 
fc.exe "%TEMP%\invertedMatrixResult.txt" test-data\invertedMatrixErr.txt > nul
if NOT ERRORLEVEL 1 goto err

echo OK
exit 0

:err
echo Program testing failed
exit 1
