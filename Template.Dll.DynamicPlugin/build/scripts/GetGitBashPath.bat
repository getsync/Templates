@echo off

:: Get Python executable path. This is usefull where
:: there is multiple Python installation on the machine

set GIT_PATH=""
if exist  "C:\Programs\Git\bin\bash.exe" (
    set GIT_PATH="C:\Programs\Git\bin\bash.exe"
    goto :found
)

if exist  "C:\Program Files (x86)\Git\bin\bash.exe" (
    set GIT_PATH="C:\Program Files (x86)\Git\bin\bash.exe"
    goto :found
)

if exist  "C:\Program Files\Git\bin\bash.exe" (
    set GIT_PATH="C:\Program Files\Git\bin\bash.exe"
    goto :found
)

:notfound
set GIT_PATH=""
EXIT /B 1


:found
EXIT /B 0