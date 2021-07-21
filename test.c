#include <stdio.h>

#define ROWS 3

void get_data(double [][5],int);

void GroupAverage(const double [][5],int);

double TotalAverage(const double [][5],int);

double MaxValue(const double [][5],int);

void ShowResulet(double,int);

void ShowArray(const double [][5],int);

int main(void){
    double data[3][5];
    get_data(data,ROWS);
    ShowArray(data,ROWS);

    GroupAverage(data,ROWS);

    double total_average;
    total_average=TotalAverage(data,ROWS);
    ShowResulet(total_average,1);

    double max_value;
    max_value=MaxValue(data,ROWS);
    ShowResulet(max_value,2);

    return 0;
}


void get_data(double data[][5],int rows){
    printf("Please enter 15 float number below.\n");
    for(int i=0; i<rows; i++){
        for(int j=0;j<5;j++)
            scanf("%lf",&data[i][j]);
    }
}

void GroupAverage(const double data[][5],int rows){
    for(int i=0;i<ROWS;i++){
        double group_value=0;
        for (int j=0;j<5;j++){
            group_value += data[i][j];
        }
        printf("\n%d#:%-.2f\n",i+1,group_value/(double)5);
    }
}

double TotalAverage(const double data[][5],int rows){
    double total_value;
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<5;j++)
            total_value += data[i][j];

    return total_value/(double)15;
    //It's me again!
}

double MaxValue(const double data[][5],int rows){
    double max=0;
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<5;j++)
            max=(max>data[i][j])?max:data[i][j];

    return max;
}

void ShowResulet(double value,int flag){
    char total_average[]="Total averages :";
    char max_value[]="Max value :";
    
    if(1==flag)
        printf("\n%s%-.2f\n",total_average,value);
    else
        printf("\n%s%-.2f\n",max_value,value);
}
void ShowArray(const double data[][5],int rows){
    putchar('\n');
    for(int i=0; i<rows; i++){
        for(int j=0;j<5;j++)
            printf("%-.2f\t",data[i][j]);
        putchar('\n');
    }
}
//It's me!
