

set terminal png nocrop enhanced font "/usr/share/fonts/truetype/msttcorefonts/arial.ttf" 11 size 620,420 
set output 'cpu_baseline1_1to100.png'

set datafile missing '-'
set style data linespoints
set title "CPU Baseline1 with Changing Thread Number"

set xrange [1:100]
set yrange [0:1200]

set xlabel "Thread Number"
set ylabel "Elapsed Time (ms)"

set xtics 10 nomirror
set ytics 200 nomirror

set mxtics 2
set mytics 2


plot 'cpu_baseline1_1to100.dat' using 2 t "RGL1", '' using 3 t "IRGL1", '' using 4 t "BAY", '' using 5 t "SW1" 

pause -1
