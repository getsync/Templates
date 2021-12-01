@echo off

:: Get Python executable path. This is usefull where
:: there is multiple Python installation on the machine

SET PYVER="3.8"
if /i "%~1"=="2.7" ( SET PYVER="2.7" )

python --version | find %PYVER% > nul
if %ERRORLEVEL% == 0 (
for /f "delims=" %%a in ('where python') do call set PYTHON_PATH=%%a
) else (
	set PYTHON_PATH=""
    EXIT /B 1
)

EXIT /B 0