#!/bin/bash
#Se asigna al trabajo el nombre SumaVectoresC_vlocales
#PBS -N SumaVectoresC_vlocales #pongo el nombre de salida que me interese
#Se asigna al trabajo la cola ac
#PBS -q ac
#Se imprime información del trabajo usando variables del entorno PBS
echo "Id. usuario del trabajo: $PBS_O_LOGNAME"
echo "Id. del trabajo: $PBS_JOBID"
echo "Nombre del trabajo especificado por usuario: $PBS_JOBNAME"
echo "Nodo que ejecuta qsub: $PBS_O_HOST"
echo "Directorio en el que se ha ejecutado qsub: $PBS_O_WORKDIR"
echo "Cola: $PBS_QUEUE"
echo "Nodos asignados al trabajo:"
cat $PBS_NODEFILE
#Se ejecuta SumaVectorC, que está en el direcctorio en el que se ha ejecutado qsub.
#para N potencia de 2 desde 2^16 hasta 2^26
for ((N=65536;N<67108865;N=N*2))
do
    $PBS_O_WORKDIR/sumavectoreslocal $N #hay que poner el nombre del ejecutable que queremos que lance
done
