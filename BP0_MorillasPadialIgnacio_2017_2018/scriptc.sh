
#!/bin/bash

for ((N=65536;N<67108865;N=N*2))
do   
    ./sumavectoreslocal $N  #hay que poner el nombre del ejecutable que queremos que lance
done
