#!/usr/bin/gnuplot

set term png enhanced size 600,300 

set size ratio -1

set o "S-1000.png"
set contour
set cntrparam levels increment -55,0.2,-50
set cbr [-55:-50]
unset surface
set view map
unset key
sp "zad_-1000.000000.txt" u 1:2:3:3 w l lt -1 palette  t '' 



set term png enhanced size 600,300

set size ratio -1

set o "W-1000.png"
set contour
set cntrparam levels increment -200,10,350
set cbr [-200:350]
unset surface
set view map
unset key
sp "zad_-1000.000000.txt" u 1:2:4:4 w l lt -1 palette  t ''





set term png enhanced size 600,300

set size ratio -1

set o "S-4000.png"
set contour
set cntrparam levels increment -218,1,-202
set cbr [-218:-202]
unset surface
set view map
unset key
sp "zad_-4000.000000.txt" u 1:2:3:3 w l lt -1 palette  t ''



set term png enhanced size 600,300

set size ratio -1

set o "W-4000.png"
set contour
set cntrparam levels increment -700,20,1100
set cbr [-700:1100]
unset surface
set view map
unset key
sp "zad_-4000.000000.txt" u 1:2:4:4 w l lt -1 palette  t ''





set term png enhanced size 600,300

set size ratio -1

set o "S4000.png"
set contour
set cntrparam levels increment 202,1,218
set cbr [202:218]
unset surface
set view map
unset key
sp "zad_4000.000000.txt" u 1:2:3:3 w l lt -1 palette  t ''