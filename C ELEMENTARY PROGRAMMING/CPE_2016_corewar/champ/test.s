.name "nielsticot"
.comment "no"

l2: sti r1,%:live,%01
and r1,%0,r1

fork %:setup
zjmp %:live

zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000
zjmp %5000


live:
    live %23
    zjmp %:live


setup:
   ld %:fourbe, r2


fourbe:
    live %23
    st r2, 8
    fork %:fourbe
    fork %:wall


wall:
    live %23
    st r3, -300
    st r3, -310
    st r3, -320
    st r3, -330
    st r3, -340
    st r3, -350
    st r3, -360
    st r3, -370
    st r3, -380
    st r3, -390
    st r3, -400
    st r3, -410
    st r3, -420
    st r3, -430
    st r3, -440
    st r3, -450
    st r3, -460
    st r3, -470
    st r3, -480
    st r3, -490
    st r3, -500
    zjmp %:wall
