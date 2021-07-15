
#!/bin/bash

for ((N=65536;N<=67108864;N=N*2))
do   
    time ./a $N  #hay que poner el nombre del ejecutable que queremos que lance
done
