rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамляющих кавычек (если они были)

rem Переменная PROGRAM будет хранить первый аргумент командной строки заключённый в кавычки
set PROGRAM="%~1"

rem При запуске без параметров ожидается ненулевой код возврата
echo test1
%PROGRAM% >nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с некорректными параметрами ожидается ненулевой код возврата
echo test2
%PROGRAM% "256">nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с некорректными параметрами ожидается ненулевой код возврата
echo test3
%PROGRAM% "-1">nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с некорректными параметрами ожидается ненулевой код возврата
echo test4
%PROGRAM% "A">nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата(проверка для 8 бита)
echo test5
%PROGRAM% "1"> "%TEMP%\result8.txt" 
fc.exe "%TEMP%\result8.txt" test-data\8.txt > nul
if ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата(проверка для 7 бита)
echo test6
%PROGRAM% "2"> "%TEMP%\result7.txt" 
fc.exe "%TEMP%\result7.txt" test-data\7.txt > nul
if ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата(проверка для 6 бита)
echo test7
%PROGRAM% "4"> "%TEMP%\result6.txt" 
fc.exe "%TEMP%\result6.txt" test-data\6.txt > nul
if ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата(проверка для 5 бита)
echo test8
%PROGRAM% "8"> "%TEMP%\result5.txt" 
fc.exe "%TEMP%\result5.txt" test-data\5.txt > nul
if ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата(проверка для 4 бита)
echo test9
%PROGRAM% "16"> "%TEMP%\result4.txt" 
fc.exe "%TEMP%\result4.txt" test-data\4.txt > nul
if ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата(проверка для 3 бита)
echo test10
%PROGRAM% "32"> "%TEMP%\result3.txt" 
fc.exe "%TEMP%\result3.txt" test-data\3.txt > nul
if ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата(проверка для 2 бита)
echo test11
%PROGRAM% "64"> "%TEMP%\result2.txt" 
fc.exe "%TEMP%\result2.txt" test-data\2.txt > nul
if ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата(проверка для 1 бита)
echo test12
%PROGRAM% "128"> "%TEMP%\result1.txt" 
fc.exe "%TEMP%\result1.txt" test-data\1.txt > nul
if ERRORLEVEL 1 goto err

rem При запуске с некорректными параметрами ожидается ненулевой код возврата
echo test13
%PROGRAM% "">nul
if NOT ERRORLEVEL 1 goto err


echo OK
exit 0

:err
echo Program testing failed
exit 1