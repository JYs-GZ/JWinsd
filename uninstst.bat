cd %programfiles%\jwinsd\
md "%TEMP%\jwinsd\" 2>nul
copy /Y "uninst.bat" "%TEMP%\jwinsd\"
start "" "%TEMP%\jwinsd\uninst.bat"
exit