.name "Random"
.comment "YOLO"

	sti r1, %:test, %01
	sti r1, %:test2, %01
start:	  and %0, %1, r2
live:	   fork %:industrie
test2:	  live %1
	fork %:live
test:	   live %1
	zjmp %:live

industrie:	fork %:industrie
	fork %1
	zjmp %:industrie
