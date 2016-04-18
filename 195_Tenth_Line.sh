#How would you print just the 10th line of a file?
awk 'NR == 10 {print; exit;}' file.txt
