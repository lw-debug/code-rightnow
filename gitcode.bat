@echo off
git add .
set datetime=%date:~0,4%-%date:~5,2%-%date:~8,2% %time:~0,2%:%time:~3,2%
git commit -m "%datetime%"
git push -u origin master
