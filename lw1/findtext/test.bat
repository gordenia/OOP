rem %1 - значение первого аргумента командной строки bat-файла (какой он есть)
rem %~1 - значение первого аргумента командной строки bat-файла с удалением обрамл€ющих кавычек (если они были)

rem ѕеременна€ PROGRAM будет хранить первый аргумент командной строки заключЄнный в кавычки
set PROGRAM="%~1"

rem ѕри запуске без параметров ожидаетс€ ненулевой код возврата
echo test1
%PROGRAM% >nul
if NOT ERRORLEVEL 1 goto err

rem ѕри неудачном открытии файла ожидаетс€ ненулевой код возврата
echo test2
%PROGRAM% fileNotFound.txt "search line" >nul
if NOT ERRORLEVEL 1 goto err

rem ѕри запуске с правильными параметрами ожидаетс€ нулевой код возврата(строка найдена)
echo test3
%PROGRAM% test-data\test.txt "need" > nul
if ERRORLEVEL 1 goto err

rem ѕри запуске с правильными параметрами ожидаетс€ нулевой код возврата(строка не найдена)
echo test4
%PROGRAM% test-data\test.txt "cat" > nul
if NOT ERRORLEVEL 1 goto err

rem ѕри запуске с правильными параметрами ожидаетс€ нулевой код возврата(исходный и результирующий файлы совпадают)
echo test5
%PROGRAM% test-data\inputFile.txt "need" > "%TEMP%\result.txt" 
fc.exe "%TEMP%\result.txt" test-data\resultAfterSearchNeed.txt > nul
if ERRORLEVEL 1 goto err

rem ѕри запуске с правильными параметрами ожидаетс€ ненулевой код возврата(исходный и результирующий файлы не совпадают)
echo test6
%PROGRAM% test-data\inputFile.txt "hamster" > "%TEMP%\result.txt" 
fc.exe "%TEMP%\result.txt" test-data\resultAfterSearchNeed.txt > nul
if NOT ERRORLEVEL 1 goto err

rem ѕри запуске с правильными параметрами ожидаетс€ ненулевой код возврата(разный регистр строк)
echo test7
%PROGRAM% test-data\inputFile.txt "Need" > "%TEMP%\result.txt" 
fc.exe "%TEMP%\result.txt" test-data\resultAfterSearchNeed.txt > nul
if NOT ERRORLEVEL 1 goto err

rem ѕри запуске с правильными параметрами ожидаетс€ ненулевой код возврата(пустой файл)
echo test8
%PROGRAM% emptyFile.txt "search line" >nul
if NOT ERRORLEVEL 1 goto err

echo OK
exit 0

:err
echo Program testing failed
exit 1