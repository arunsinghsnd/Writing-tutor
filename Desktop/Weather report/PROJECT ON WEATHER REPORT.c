#include<stdio.h>     //headers files
#include<conio.h>
struct weather      // parameters 
{  
	 int sr;
	char city[20];
	float temp;
	float humidity;
	float wind;
	
}wet[5],final;
 edit()
{  	
FILE *fl;
int i;        //this is for entering the data in file
	fl=fopen("weather.txt","w");    //open text in write mood
	for(i=0;i<5;i++)        //loop for diffrents types of data
    {
	printf("Serial no.:\t\t\n");
    scanf("%d",&wet[i].sr);
       printf("City:\t\t\n");
    scanf("%s",wet[i].city);
       printf("Temperature:\t\t\n");
    scanf("%f",&wet[i].temp);
       printf("Humidity:\t\t\n");
    scanf("%f",&wet[i].humidity);
       printf("wind:\t\t\n");
    scanf("%f",&wet[i].wind);
    fwrite(&wet[i],sizeof(wet[i]),1,fl);
	}
	fclose(fl); //closing the file
    
}
void main()
{  
	 int  i ,ch, a[20];	
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t'WELCOME'  \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t TO \n\n");
	printf("\t\t THE PROJECT ON 'WEATHER REPORT' OF FIVE CITIES\n\n");
	printf("\t this is normal weather  in winter season months of 'NOVEMBER'\n\n");
	printf("\n 1.To find weather of a city\n 2.To Edit Record \n");
	scanf("%d",&ch);
    
    if(ch==2)       //condition for if we entering 2 then it will storing the  data 
    {
    	edit();
	}
	else
	{
		
	FILE *f;
	f=fopen("weather.txt","r");    //this is the weather file where data is store
	i=0;
	while(fread(&wet[i],sizeof(wet[i]),1,f)!=NULL)
	{ 
		
	i++;
	}
	fclose(f);
		
	printf("ENTER THE CITY AS SHOWN : \n");
	for(i=0;i<5;i++)
	{
	
	printf("%d.%s \n",i+1,wet[i].city);
}
	printf("6.Show All \n");
		scanf("%d",&ch);
	
	if(ch==6)                    //condition for if we entering 6 then it will show all data
	{
		for(i=0;i<5;i++)
		{
				printf("Serial:\t\t\t%d\nCity:\t\t\t%s\nTemperature:\t\t%.2f'C\nHumidity:\t\t%.2f%%\nWind:\t\t\t%.2fKm/hr\n\n\n",wet[i].sr,wet[i].city,wet[i].temp,wet[i].humidity,wet[i].wind);
		}
	}
	else
	{
	final=wet[ch-1];
	printf("\nCity:\t\t\t%s\nTemperature:\t\t%.2f'C\nHumidity:\t\t%.2f%%\nWind:\t\t\t%.2fkm/hr",final.city,final.temp,final.humidity,final.wind);
}
}

}

