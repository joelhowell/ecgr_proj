@echo off
title git
SETLOCAL EnableDelayedExpansion
for /F "tokens=1,2 delims=#" %%a in ('"prompt #$H#$E# & echo on & for %%b in (1) do     rem"') do (
  set "DEL=%%a"
)
call :colorEcho e0 "[Git Status]"
echo.

git status
pause
git add . 
set /p m=Commit Message: 
git commit -m %m%
git push

call :colorEcho a0 "[Push Complete]"
echo.
SLEEP 1

:colorEcho
echo off
<nul set /p ".=%DEL%" > "%~2"
findstr /v /a:%1 /R "^$" "%~2" nul
del "%~2" > nul 2>&1i
