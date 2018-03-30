rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамляющих кавычек (если они были)

rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
set PROGRAM="%~1"

rem При запуске без параметров ожидается ненулевой код возврата
echo test1
%PROGRAM% >nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с некорректными параметрами ожидается ненулевой код возврата(неверный параметр)
echo test2
%PROGRAM% hamster test-data\inputFile.txt test-data\outputFile.txt >nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с корректными параметрами ожидается ненулевой код возврата(одинаковое название входного и выходного файлов)
echo test3
%PROGRAM% pack test-data\inputFile.txt test-data\inputFile.txt >nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с некорректными параметрами ожидается ненулевой код возврата(входной файл не найден)
echo test4
%PROGRAM% pack test-data\fileNotFound.txt test-data\outputFile.txt >nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с некорректными параметрами ожидается ненулевой код возврата(выходной файл не найден)
echo test5
%PROGRAM% pack test-data\fileNotFound.txt outputFile.txt >nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с корректными параметрами ожидается нулевой код возврата(входной файл пустой, файл на выходе должен быть пустым)
echo test6
%PROGRAM% pack test-data\emptyInputFile.txt test-data\outputFile.txt >nul
fc.exe test-data\outputFile.txt test-data\emptyInputFile.txt > nul
if ERRORLEVEL 1 goto err

rem При запуске с корректными параметрами ожидается нулевой код возврата(Длина последовательности одинаковых символов = 255)
echo test7
%PROGRAM% pack test-data\input_A_255.txt test-data\outputFile.txt >nul
fc.exe test-data\outputFile.txt test-data\output_A_255.bin > nul
if ERRORLEVEL 1 goto err

rem При запуске с корректными параметрами ожидается нулевой код возврата(Длина последовательности одинаковых символов = 256)
echo test8
%PROGRAM% pack test-data\input_b_256.txt test-data\outputFile.txt >nul
fc.exe test-data\outputFile.txt test-data\output_b_256.bin > nul
if ERRORLEVEL 1 goto err

rem При запуске с корректными параметрами ожидается нулевой код возврата(Длина последовательности одинаковых символов = 257)
echo test9
%PROGRAM% pack test-data\input_m_257.txt test-data\outputFile.txt >nul
fc.exe test-data\outputFile.txt test-data\output_m_257.bin > nul
if ERRORLEVEL 1 goto err

rem При запуске с корректными параметрами ожидается ненулевой код возврата(нечетная длина запакованного файла)
echo test10
%PROGRAM% unpack test-data\inputFileOddLength.txt test-data\outputFile.txt >nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с корректными параметрами ожидается ненулевой код возврата(в запакованном файле есть кол-во символов = 0)
echo test11
%PROGRAM% unpack test-data\inputFileWithCountCharNull.bin test-data\outputFile.txt >nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с корректными параметрами ожидается нулевой код возврата(фактический и ожидаемый результат совпадают)
echo test12
%PROGRAM% pack test-data\inputFile.txt test-data\outputFile.txt >nul
%PROGRAM% unpack test-data\outputFile.txt "%TEMP%\decompressionFile.txt" >nul
fc.exe test-data\inputFile.txt "%TEMP%\decompressionFile.txt" > nul
if ERRORLEVEL 1 goto err

rem При запуске с корректными параметрами ожидается нулевой код возврата(во входном файле есть символ с кодом FF )
echo test13
%PROGRAM% pack test-data\inputFileWithCountCharNull.bin test-data\outputFile.txt >nul
if ERRORLEVEL 1 goto err

echo OK
exit 0

:err
echo Program testing failed
exit 1