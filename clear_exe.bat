::dir .\* /a:D/b > list.txt
::del list.txt

for /f "tokens=* delims=" %%i in ('dir /s /b /a:-d *.exe') do (del "%%i")

pause