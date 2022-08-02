#!/bin/sh

cd /home/jinglei/Codes/
git add *
d=$(date)
git commit -m "$d"
git push
