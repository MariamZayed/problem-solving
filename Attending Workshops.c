#include<bits/stdc++.h>

using namespace std;
struct Workshop{
    int start,duration,end;
};

struct Available_Workshops{
    int n;
    Workshop** workshops;
    Available_Workshops(int _num){
        n = _num;
        workshops = new Workshop*[_num];
    }
    ~Available_Workshops(){
        for(int i =0;i<n;i++){
            delete workshops[i];
        }
    }
};

Available_Workshops* initialize (int start_time[], int duration[], int n){
    Available_Workshops* aws=new Available_Workshops(n) ;
    for(int i=0;i<n;i++){
        Workshop* ws= new Workshop;
        ws->start=start_time[i];
        ws->duration=duration[i];
        ws->end=start_time[i]+duration[i];
        aws-> workshops[i]=ws;
    }
    return aws;
}

bool compare(Workshop* one, Workshop* two) {
    return one->end < two->end;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    sort(ptr->workshops, ptr->workshops + ptr->n, compare);

    int valid = 0;
    int attending_end = 0;
    for (int i = 0; i < ptr->n; ++i) {
        if (ptr->workshops[i]->start >= attending_end) {
            valid++;
            attending_end = ptr->workshops[i]->end;
        }
    }

    return valid;
}

