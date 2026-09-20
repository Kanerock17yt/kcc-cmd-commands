@echo off
setlocal

:: Grab argument if passed, otherwise ask the user directly
set "source=%~1"
if "%source%"=="" (
    set /p "source=Enter the C file name to compile (e.g., main.c): "
)

:: If they just hit enter without typing anything, fall back to timeused.c
if "%source%"=="" set "source=timeused.c"

call :Compile "%source%"
exit /b %ERRORLEVEL%

:Compile
set "source=%~1"

for %%F in ("%source%") do set "output=%%~nF"

:: Safety check: ensure source file actually exists
if not exist "%source%" (
    echo Error: File "%source%" not found in this folder.
    call :Pause
    exit /b 1
)

echo Compiling "%source%"...
gcc "%source%" -o "%output%.exe"
if errorlevel 1 (
    echo Error: failed to compile "%source%".
    call :Pause
    exit /b 1
)

:: Ensure the core folders exist before moving things
if not exist "build" mkdir "build"
if not exist "build\commands" mkdir "build\commands"

:: Sorts your main compiler tool and sub-commands automatically
if /i "%output%.exe"=="kcc.exe" (
    move "%output%.exe" "build\" >nul 2>&1
) else (
    move "%output%.exe" "build\commands\" >nul 2>&1
)

echo Compilation complete.
call :Pause
exit /b 0

:Pause
timeout /t 2 /nobreak >nul
exit /b
