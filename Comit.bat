@echo off
cls
echo [102;93m Github Commit [0m
echo ^<Console^> [92mCommit to github starting...[0m
set /p message= [91mEnter Message: 
git add .
git commit -m "%message%"
SET c = git push
echo %c%
if (c==true) echo [92mCommit Successful!![0m
else echo [31mCommit Unsuccessful!![0m
pause