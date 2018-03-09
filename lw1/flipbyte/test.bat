rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ��� ������� ��� ���������� ��������� ��������� ��� ��������
echo test1
%PROGRAM% >nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ������������� ����������� ��������� ��������� ��� ��������
echo test2
%PROGRAM% "256">nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ������������� ����������� ��������� ��������� ��� ��������
echo test3
%PROGRAM% "-1">nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ������������� ����������� ��������� ��������� ��� ��������
echo test4
%PROGRAM% "A">nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(�������� ��� 8 ����)
echo test5
%PROGRAM% "1"> "%TEMP%\result8.txt" 
fc.exe "%TEMP%\result8.txt" test-data\8.txt > nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(�������� ��� 7 ����)
echo test6
%PROGRAM% "2"> "%TEMP%\result7.txt" 
fc.exe "%TEMP%\result7.txt" test-data\7.txt > nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(�������� ��� 6 ����)
echo test7
%PROGRAM% "4"> "%TEMP%\result6.txt" 
fc.exe "%TEMP%\result6.txt" test-data\6.txt > nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(�������� ��� 5 ����)
echo test8
%PROGRAM% "8"> "%TEMP%\result5.txt" 
fc.exe "%TEMP%\result5.txt" test-data\5.txt > nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(�������� ��� 4 ����)
echo test9
%PROGRAM% "16"> "%TEMP%\result4.txt" 
fc.exe "%TEMP%\result4.txt" test-data\4.txt > nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(�������� ��� 3 ����)
echo test10
%PROGRAM% "32"> "%TEMP%\result3.txt" 
fc.exe "%TEMP%\result3.txt" test-data\3.txt > nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(�������� ��� 2 ����)
echo test11
%PROGRAM% "64"> "%TEMP%\result2.txt" 
fc.exe "%TEMP%\result2.txt" test-data\2.txt > nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(�������� ��� 1 ����)
echo test12
%PROGRAM% "128"> "%TEMP%\result1.txt" 
fc.exe "%TEMP%\result1.txt" test-data\1.txt > nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ������������� ����������� ��������� ��������� ��� ��������
echo test13
%PROGRAM% "">nul
if NOT ERRORLEVEL 1 goto err


echo OK
exit 0

:err
echo Program testing failed
exit 1