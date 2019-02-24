#include <stdio.h>

struct Process { 
    char pid[20]; 	// Process ID 
    int bt; 		// Burst Time 
    int art; 		// Arrival Time
	int rmn;		// Remaining Time 
}; 


int main()
{
	
	struct Process process[100];
	int n; // Process sayisi
	int i;
	printf("Enter the total no of processes: ");
		scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter p_name: ");
		scanf("%s",process[i].pid);
		printf("Enter p_arrival: ");
		scanf("%d",&process[i].art);
		printf("Enter p_burst: ");
		scanf("%d",&process[i].bt);
		process[i].rmn = process[i].bt;
	}
		
/*	process[0].bt = 1;
	process[0].art = 8;
	process[0].rmn = 1;
	process[1].bt = 1;
	process[1].art = 5;
	process[1].rmn = 1;
	process[2].bt = 7;
	process[2].art = 2;
	process[2].rmn = 7;
	process[3].bt = 3;
	process[3].art = 4;
	process[3].rmn = 3;
	process[4].bt = 8;
	process[4].art = 2;
	process[4].rmn = 8;
	process[5].bt = 2;
	process[5].art = 4;
	process[5].rmn = 2;
	process[6].bt = 5;
	process[6].art = 3;
	process[6].rmn = 5; 
	
	n = 7; */
	
	int time = 0;		// Hangi zamanda bulundugumuz
	int flag = 0;		// O anda calisan process'in o zamanda degisip degismedigini tutmak icin	
	int j;
	int minm = 1000;	// Sonsuz degeri
	int current = 0; 	// O anda calisan process; 
	int done = 0;		// Tamamlanan process sayisi
	int wait[100];		// Waiting timelarýn tutuldugu dizi
	int totalwait = 0;	// Toplam waiting time tutuldugu degisken
	double averagewait = 0.0;	// Average waiting time tutuldugu degisken  
		
	while(done < n)	// Tüm processler tamamlanana kadar
	{
			
	 for (j = 0; j < n; j++) { 								// Ready'e gelmis ve en kýsa remaning time bulmak icin
            if ((process[j].art <= time) && 
            (process[j].rmn < minm) && process[j].rmn > 0) { 
                minm = process[j].rmn; 
                current = j; 								// Calismasi gereken process'in indisi
                flag = 1; 									// Degisim olmus
            } 
        } 
	
	if (flag!=0)				//	Degisim olmus ise
	{
		process[current].rmn--;	// Process'in remaining time'ý 1 azalir
		
		if(process[current].rmn > 0)		// process bitmediyse min'i güncelle
			minm = process[current].rmn;
		else								// Process bittiyse min'i güncelle bitmis process sayisini arttir flagi tekrar 0la ve wait'i hesapla
		{
			minm = 1000;
			done++;
			flag = 0;
			wait[current] = time - process[current].bt - process[current].art + 1;
		}				
	}	
		
	time++;								// Zamani bir attýrma
	
}
	printf("time passed: %d ",time);
	for(j = 0; j < n; j++)
		totalwait+=wait[j]; 
	
	averagewait = (double) totalwait / n;
		
	printf("\nProcessName\tArrivalTime\tBurstTime\tWaitingTime");	
		for(i=0;i<n;i++)
		{
			printf("\n%s\t\t%d\t\t%d\t\t%d",process[i].pid,process[i].art,process[i].bt,wait[i]);
		}
	
	printf("\nTotal waiting time: %d \nAverage waiting time: %f",totalwait,averagewait);
		
	return 0;
}


