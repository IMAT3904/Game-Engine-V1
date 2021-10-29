@echo off
cls
echo [102;93m Github Commit [0m
echo ^<Console^> [92mCommit to github starting...[0m
set /p message= [91mEnter Message: 
git add .
git commit -m "%message%"
echo git push
echo [92mCommit Finished!![0m
pause