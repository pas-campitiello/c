// Chiamando questo programma dal DOS specificando uno o pi� parametri in questo modo: >ParametriMain 131.175.23.1
// Si otterr�:
// Il valore di argc e� 2
//
// Parametro 0 = prova1
// Parametro 1 = 131.175.23.1

void main(int argc, char *argv[])
{ 
   int i;

   printf("Il valore di argc e' %d\n\n", argc);
   
   for (i=0; i<argc; i++) printf("Parametro %i = %s\n",i,argv[i]);
   
   printf("\n");
   system("PAUSE");
}
