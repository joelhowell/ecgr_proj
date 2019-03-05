@echo off
git status
pause
git add . 
set /p message=Commit Message:
git commit -m %message%
git push