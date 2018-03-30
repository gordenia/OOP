rem %1 - �������� ������� ��������� ��������� ������ bat-����� (����� �� ����)
rem %~1 - �������� ������� ��������� ��������� ������ bat-����� � ��������� ����������� ������� (���� ��� ����)

rem ���������� PROGRAM ����� ������� ������ �������� ��������� ������ ����������� � �������
set PROGRAM="%~1"

rem ��� ������� ��� ���������� ��������� ��������� ��� ��������
echo test1
%PROGRAM% >nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ������������� ����������� ��������� ��������� ��� ��������(�������� ��������)
echo test2
%PROGRAM% hamster test-data\inputFile.txt test-data\outputFile.txt >nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ��������� ��� ��������(���������� �������� �������� � ��������� ������)
echo test3
%PROGRAM% pack test-data\inputFile.txt test-data\inputFile.txt >nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ������������� ����������� ��������� ��������� ��� ��������(������� ���� �� ������)
echo test4
%PROGRAM% pack test-data\fileNotFound.txt test-data\outputFile.txt >nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ������������� ����������� ��������� ��������� ��� ��������(�������� ���� �� ������)
echo test5
%PROGRAM% pack test-data\fileNotFound.txt outputFile.txt >nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(������� ���� ������, ���� �� ������ ������ ���� ������)
echo test6
%PROGRAM% pack test-data\emptyInputFile.txt test-data\outputFile.txt >nul
fc.exe test-data\outputFile.txt test-data\emptyInputFile.txt > nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(����� ������������������ ���������� �������� = 255)
echo test7
%PROGRAM% pack test-data\input_A_255.txt test-data\outputFile.txt >nul
fc.exe test-data\outputFile.txt test-data\output_A_255.bin > nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(����� ������������������ ���������� �������� = 256)
echo test8
%PROGRAM% pack test-data\input_b_256.txt test-data\outputFile.txt >nul
fc.exe test-data\outputFile.txt test-data\output_b_256.bin > nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(����� ������������������ ���������� �������� = 257)
echo test9
%PROGRAM% pack test-data\input_m_257.txt test-data\outputFile.txt >nul
fc.exe test-data\outputFile.txt test-data\output_m_257.bin > nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ��������� ��� ��������(�������� ����� ������������� �����)
echo test10
%PROGRAM% unpack test-data\inputFileOddLength.txt test-data\outputFile.txt >nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ��������� ��� ��������(� ������������ ����� ���� ���-�� �������� = 0)
echo test11
%PROGRAM% unpack test-data\inputFileWithCountCharNull.bin test-data\outputFile.txt >nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(����������� � ��������� ��������� ���������)
echo test12
%PROGRAM% pack test-data\inputFile.txt test-data\outputFile.txt >nul
%PROGRAM% unpack test-data\outputFile.txt "%TEMP%\decompressionFile.txt" >nul
fc.exe test-data\inputFile.txt "%TEMP%\decompressionFile.txt" > nul
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������(�� ������� ����� ���� ������ � ����� FF )
echo test13
%PROGRAM% pack test-data\inputFileWithCountCharNull.bin test-data\outputFile.txt >nul
if ERRORLEVEL 1 goto err

echo OK
exit 0

:err
echo Program testing failed
exit 1