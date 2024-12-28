reset
set term gif size 800,300 animate delay 10
set output "anim1.gif"
n=50    #liczba klatek
set view map # widok z gory
set size ratio -1
set cbr [0:]

do for [i=1:n] {
  file = sprintf("zad_it_0.000000=%i.txt",i)
  splot file u 1:2:3 w pm3d  title sprintf("t=%i",i)
}

reset
set term gif size 800,300 animate delay 10
set output "anim2.gif"
n=50    #liczba klatek
set view map # widok z gory
set size ratio -1
set cbr [0:]

do for [i=1:n] {
  file = sprintf("zad_it_0.100000=%i.txt",i)
  splot file u 1:2:3 w pm3d  title sprintf("t=%i",i)
}