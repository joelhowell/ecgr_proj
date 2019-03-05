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
set /p msg=Commit Message: 
git commit -m %msg%
git push

call :colorEcho a0 "[Push Complete]"
echo.
ping 127.0.0.1 -n 1 > nul
exit
:colorEcho
<nul set /p ".=%DEL%" > "%~2"
findstr /v /a:%1 /R "^$" "%~2" nul
del "%~2" > nul 2>&1i
