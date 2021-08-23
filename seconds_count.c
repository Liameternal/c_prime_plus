//calculate secondes between two given times.
#include <stdio.h>

typedef struct Time{
    int hour;
    int minute;
    int second;
}Time;
//transfer time into seconds.
int TimeToSeconds(Time time);
//return the time diff.
int SecondsDiff(int second1,int second2);
//show time
void ShowTime(Time time);

void ShowDiff(Time time1,Time time2,int diff);

int main(void){
    Time time[2];

    for(int i=0;i<=1;i++){
        printf("Please enter the %dst(ed) time(H:M:S): ", i+1);
        scanf("%d:%d:%d",&time[i].hour,&time[i].minute,&time[i].second);
        getchar();
    }
    int seconds1,seconds2;
    seconds1=TimeToSeconds(time[0]);
    seconds2=TimeToSeconds(time[1]);

    int diff;
    diff = SecondsDiff(seconds1,seconds2);

    ShowDiff(time[0],time[1],diff);

    return 0;
}

int TimeToSeconds(Time time){
    return time.hour*3600+time.minute*60+time.second;
}

int SecondsDiff(int seconds1,int seconds2){
    return seconds1-seconds2;
}
void ShowTime(Time time){
    printf("%d:%d:%d",time.hour,time.minute,time.second);
}
void ShowDiff(Time time1,Time time2,int diff){
    printf("The difference between ");
    ShowTime(time1);
    printf(" and ");
    ShowTime(time2);
    printf(" is %d.\n",diff);
}
