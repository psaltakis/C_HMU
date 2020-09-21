#include<stdio.h>
#define maxSize 1000

int n;

float tempRangeL = 26.50, tempRangeH = 32.50;
// orizoume tis parametrous protou anixoyme to arxio 
char date[maxSize][11];
char time[maxSize][9];
int registrationNumber[maxSize];
float batteryVoltage[maxSize];
float recorderTemp[maxSize];
float solarRadiation[maxSize];
float horizontalDensity[maxSize];
float diffuseDensity[maxSize];
float ambientTemp[maxSize];

//xekinao ftiaxnontas diafores sinartisis analoga ta erotimata 

void powerDensityForDirectComponent(){
    printf("isxis gia tin amesi iliaki aktinovolia : ");
    float sum = 0;
    float epsilon, G;
    //diavazei kanei praxis petai to teliko 
    for (int i = 0; i < n; i++){
        epsilon = 10.0 * 10 - 6;
        G = solarRadiation[i] / epsilon;
        sum += G;
    }
    printf("%f W/m^2\n\n", sum);
}

void powerDensityForTotalDensity(){
    printf("isxis sto orizontio pedio : ");
    float sum = 0;
    float epsilon, G;
    //paromoio analoga to kathe pou zita i askisi 
    for (int i = 0; i < n; i++){
        epsilon = 8.0 * 10-6;
        G = solarRadiation[i] / epsilon;
        sum += G;
    }
    printf("%f W/m^2\n\n", sum);
}

void powerDensityForHorizontalDiffusiveDensity(){
    printf("diaxiti sto orizontio isxis : ");
    float sum = 0;
    float epsilon, G;
    //to idio pragma alla gia tin diaxiti 
    for (int i = 0; i < n; i++){
        epsilon = 9.0 * 10 - 6;
        G = solarRadiation[i] / epsilon;
        sum += G;
    }
    printf("%f W/m^2\n\n", sum);
}
//gia na elenxi an ine ektos pediou i thermokrasia
void ambientTemperaturesOutsideRange(){
    printf("thermokrasia ektos tou pediou:\n");
    int f = 0;
    diavazi kai tsekarei an ine an ine petaei to sfalma
    for (int i = 0; i < n; i++){
        if (ambientTemp[i] < tempRangeL || ambientTemp[i] > tempRangeH);
                printf("%s %s %f C\n", date[i], time[i], ambientTemp[i]), f = 1;
    }
    if (!f)
        printf("None\n");
    printf("\n");
}


int main (){
    //anoigei to arxeio me tiw metriseis kai petaei tis metriseis 
    freopen("DataMeteoE4.txt", "r", stdin);
// xekinaei na lamvanei ta dedomena kai ta petaei me tis sinartiseis 
    for (int i = 0; scanf("%s", date[i]) != EOF; i++){
        n++;
        scanf("%s%d", time[i], &registrationNumber[i]);
        scanf("%f%f", &batteryVoltage[i], &recorderTemp[i]);
        scanf("%f%f", &solarRadiation[i], &horizontalDensity[i]);
        scanf("%f%f", &diffuseDensity[i], &ambientTemp[i]);
    }
//klisimo ton sinartiseon
    ambientTemperaturesOutsideRange();
    powerDensityForDirectComponent();
    powerDensityForTotalDensity();
    powerDensityForHorizontalDiffusiveDensity();

}
