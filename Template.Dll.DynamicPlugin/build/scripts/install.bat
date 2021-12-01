@::!/dos/rocks
@echo off
goto :init

:header
    echo %__NAME% v%__VERSION%
    echo This script is part of the Module project. 
    echo.
    echo INSTALLATION SCRIPT
    echo.
    goto :eof

:usage
    echo USAGE:
    echo   %__BAT_NAME% [flags] "required argument" "optional argument" 
    echo.
    echo.  /?, --help           shows this help
    echo.  /v, --version        shows the version
    echo.  /e, --verbose        shows detailed output
    echo.  -f, --flag value     specifies a named parameter value
    goto :eof

:version
    if "%~1"=="full" call :header & goto :eof
    echo %__VERSION%
    goto :eof

:missing_argument
    call :header
    call :usage
    echo.
    echo ****                                   ****
    echo ****    MISSING "REQUIRED ARGUMENT"    ****
    echo ****                                   ****
    echo.
    goto :eof

:init
    set "__NAME=%~n0"
    set "__VERSION=1.23"
    set "__YEAR=2017"

    set "__BAT_FILE=%~0"
    set "__BAT_PATH=%~dp0"
    set "__BAT_NAME=%~nx0"

    set "OptHelp="
    set "OptVersion="
    set "OptVerbose="

    set "Operation="
    set "OperationOptionalArg="
    set "OperationOptionalArg2="
    set "NamedFlag="

:parse
    if "%~1"=="" goto :validate

    if /i "%~1"=="/?"         call :header & call :usage "%~2" & goto :end
    if /i "%~1"=="-?"         call :header & call :usage "%~2" & goto :end
    if /i "%~1"=="--help"     call :header & call :usage "%~2" & goto :end

    if /i "%~1"=="/v"         call :version      & goto :end
    if /i "%~1"=="-v"         call :version      & goto :end
    if /i "%~1"=="--version"  call :version full & goto :end

    if /i "%~1"=="/e"         set "OptVerbose=yes"  & shift & goto :parse
    if /i "%~1"=="-e"         set "OptVerbose=yes"  & shift & goto :parse
    if /i "%~1"=="--verbose"  set "OptVerbose=yes"  & shift & goto :parse

    if /i "%~1"=="-p"     set "ROOTPATH=%~2"   & shift & shift & goto :parse
    if /i "%~1"=="/p"     set "ROOTPATH=%~2"   & shift & shift & goto :parse

    if /i "%~1"=="-t"     set "TARGET=%~2"   & shift & shift & goto :parse
    if /i "%~1"=="/t"     set "TARGET=%~2"   & shift & shift & goto :parse


    shift
    goto :parse

:validate
    if not defined ROOTPATH call :missing_argument & goto :end
:deploy
    echo --------- DEPLOY INITIATED! ---------
    set DEPLOYPATH=D:\Development\cybercastor\Work\loaddll\loaddll\plugins
    set BINARYPATH=%ROOTPATH%\bin\%TARGET%
    set SOURCEPATH=%ROOTPATH%\src
    pushd %BINARYPATH%
    echo Deploying target %TARGET% to directory: %DEPLOYPATH%
    if not exist "%DEPLOYPATH%" mkdir "%DEPLOYPATH%"
    if not exist "%DEPLOYPATH%\inc" mkdir "%DEPLOYPATH%\inc"
    if not exist "%DEPLOYPATH%\bin" mkdir "%DEPLOYPATH%\bin"

    echo.                                                                    

    dir /D /B *.dll
    xcopy *.dll "%DEPLOYPATH%\bin" /R /F /Y
    xcopy *.lib "%DEPLOYPATH%\bin" /R /F /Y
    xcopy *.bsc "%DEPLOYPATH%\bin" /R /F /Y
    pushd %SOURCEPATH%
    xcopy Module*.h "%DEPLOYPATH%\inc" /R /F /Y
    popd
    popd
    echo --------- DEPLOY COMPLETED! ---------
    goto :end
:main
    if defined OptVerbose (
        echo **** DEBUG IS ON
    )

    echo ROOTPATH:    "%ROOTPATH%"
    echo TARGET:     "%TARGET%"
    if /i "%Operation%"=="deploy"       call :deploy      & goto :end


:end
    call :cleanup
    exit /B

:cleanup
    REM The cleanup function is only really necessary if you
    REM are _not_ using SETLOCAL.
    set "__NAME="
    set "__VERSION="
    set "__YEAR="

    set "__BAT_FILE="
    set "__BAT_PATH="
    set "__BAT_NAME="

    set "OptHelp="
    set "OptVersion="
    set "OptVerbose="

    set "Operation="
    set "Operation2="
    set "NamedFlag="

    goto :eof