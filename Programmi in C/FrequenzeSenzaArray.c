#include <stdio.h>

int main ()
{
    int x,i,voto,fr1,fr2,fr3,fr4,fr5,MaxFr,somma;
    
    do
    {
        printf("Quanti voti vuoi inserire? ");
        scanf("%d",&x);
    }
    while (x<0);
                            
    i=1;                    //  / Quest'assegnamento per l'algoritmo in questione non è proprio corretto: nel caso x<5
    fr1=fr2=fr3=fr4=fr5=0;  //<=  e voti inseriti tutti diversi, NON restituirà "La frequenza di tutti i voti e' uguale"
    somma=0;                //  \ perchè le ultime variabili ...fr4,fr5 non verranno aggiornate e saranno sempre 0.
    
    while (i<=x)
    {
          do
          {
                printf("Inserisci il voto num. %d (MAX=5 MIN=1): ",i);
                scanf("%d",&voto);
          }
          while ((voto<0) || (voto>5));
          
          if (voto==1) fr1++;
          else if (voto==2) fr2++;
               else if (voto==3) fr3++;
                    else if (voto==4) fr4++;
                         else if (voto==5) fr5++;
          
          somma=somma+voto;
          i++;
    }
    
    MaxFr=0;

    if ((fr1==fr2) && (fr1==fr3) && (fr1==fr4) && (fr1==fr5)) MaxFr=-1;
    else {
          if (fr1>MaxFr) MaxFr=fr1;
          if (fr2>MaxFr) MaxFr=fr2;
          if (fr3>MaxFr) MaxFr=fr3;
          if (fr4>MaxFr) MaxFr=fr4;
          if (fr5>MaxFr) MaxFr=fr5;
                    
          if (MaxFr==fr1) printf("\nIl voto a maggior frequenza e' 1");
          if (MaxFr==fr2) printf("\nIl voto a maggior frequenza e' 2");
          if (MaxFr==fr3) printf("\nIl voto a maggior frequenza e' 3");
          if (MaxFr==fr4) printf("\nIl voto a maggior frequenza e' 4");
          if (MaxFr==fr5) printf("\nIl voto a maggior frequenza e' 5");
         }

    if (MaxFr==-1) printf("\nLa frequenza di tutti i voti e' uguale");
    
    printf("\n\nLa media dei voti e' %.3f",((float)somma)/x);
                        
    printf("\n\n");
    system("Pause");
}
