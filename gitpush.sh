#!/bin/bash


git add .
git commit -m $(date +20%y.%m.%d-%H:%M)
git push origin master
