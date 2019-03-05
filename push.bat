@echo off
title git push

setlocal EnableDelayedExpansion
for /F "tokens=1,2 delims=#" %%a in ('"prompt #$H#$E# & echo on & for %%b in (1) do     rem"') do (
  set "del=%%a"
)

call :colorEcho e0 "[Git Status]"
echo.

git status
echo.

set /p i="Type e to cancel, otherwise press enter: "
if /i "%i%"=="e" exit

git add . 

:cmsg
set /p msg="Commit Message: "
echo.
if "%msg%"=="" goto e
call :colorEcho 40 "[Processing...]"
echo.
git commit -m "%msg%"
echo.
git push 
echo.
call :colorEcho a0 "[Push Complete]"
echo.
ping localhost -n 2 > nul
exit

:e
echo You must input a commit message.
goto cmsg

:colorEcho
<nul set /p ".=%DEL%" > "%~2"
findstr /v /a:%1 /R "^$" "%~2" nul
del "%~2" > nul 2>&1i
