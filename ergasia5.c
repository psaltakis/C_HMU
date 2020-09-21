#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (a<b?a:b)

int n,j;
//Vazoume pali to evros ton thermokrasion
float tempRangeL = 26.50, tempRangeH = 32.50;


typedef struct{
    int year, month, day;
    int hour, minute, second;
}Timestamp;

typedef struct{
    Timestamp timestamp;
    int registrationNumber;
    float batteryVoltage;
    float recorderTemp;
    float directComponentOfSolarRadiation;
    float horizontalPowerDensity;
    float diffuseComponent;
    float ambientTemperature;
}entry;
//morfopoioisi opos zitaei i askisi 
void desplay(){
    FILE *fp = fopen ("myfile.bin", "w");
    entry *rec1 = (entry *) malloc (j * sizeof (entry));
    fread (rec1, sizeof (entry), j, fp);

    printf("====================================\n");
    for (int i = 0; i < min(10, j); i++)
        printf("| %d: %d: %d | %.2f | %.2f | %.2f | %.2f |\n",
               rec1[i].timestamp.hour, rec1[i].timestamp.minute, rec1[i].timestamp.second,
                rec1[i].ambientTemperature, rec1[i].directComponentOfSolarRadiation,
                rec1[i].horizontalPowerDensity, rec1[i].diffuseComponent);
    printf("====================================\n");

    fclose (fp);
}
//anigma tou arxeiou

int main (){
    freopen("DataMeteo-E5.txt", "r", stdin);
    Timestamp t;
    entry e;
    // i desmefsi me tin malloc 
    entry *rec = (entry*) malloc (sizeof (entry));

    for (int i = 0; scanf("%d-%d-%d", &(e.timestamp.year), &(e.timestamp.month), &(e.timestamp.day)) != EOF; i++){
        n++;
        scanf("%d:%d:%d", &(e.timestamp.hour), &(e.timestamp.minute), &(e.timestamp.second));
        scanf("%d%f", &(e.registrationNumber), &(e.batteryVoltage));
        scanf("%f%f", &(e.recorderTemp), &(e.directComponentOfSolarRadiation));
        scanf("%f%f", &(e.horizontalPowerDensity), &(e.diffuseComponent));
        scanf("%f", &(e.ambientTemperature));
        if(e.ambientTemperature < tempRangeL || e.ambientTemperature > tempRangeH){
            rec[j] = e;
            //printf("%d %d %d\n", rec[j].timestamp.year, rec[j].timestamp.month, rec[j].timestamp.day);
            j++;
            rec = (entry *) realloc (rec, (j+1) * sizeof (entry));
        }
    }
    FILE *fp = fopen ("myfile.bin", "w");
    fwrite (rec, sizeof (entry), j, fp);
    fclose (fp);

    desplay();
}
