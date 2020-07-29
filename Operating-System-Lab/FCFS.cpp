//Gaurav Rai 1706019

#include<bits/stdc++.h>
using namespace std;
class PCB
{
    public :
    static float avgWt,avgTat,avgCt;
    int pid;
    int pri;
    float bt,at,ct,tat,wt;
    bool operator <(const PCB p) const
    {
        return (at<p.at);
    }
    bool operator >(const PCB p) const
    {
        return (at>p.at);
    }
};
float PCB::avgWt =0;
float PCB::avgTat =0;
float PCB::avgCt =0;
void FCFS(vector<PCB>& P)
{
    for(int i=0;i<P.size();i++)
    {
        if(i==0)
        {
            P[0].ct=P[0].at+P[0].bt;
            P[0].tat=P[0].ct-P[0].at;
            P[0].wt=0;
        }
        else
        {
            if(P[i].at<=P[i-1].ct)
            {
                P[i].ct=P[i-1].ct+P[i].bt;
                P[i].tat=P[i].ct-P[i].at;
                P[i].wt=P[i].tat-P[i].bt;
            }
            else
            {
                P[i].ct=P[i].at+P[i].bt;
                P[i].tat=P[i].ct-P[i].at;
                P[i].wt=P[i].tat-P[i].bt;
            }
        }
    }
    for(int i=0;i<P.size();i++)
    {
        PCB::avgWt +=P[i].wt;
        PCB::avgTat+=P[i].tat;
        PCB::avgCt+=P[i].ct;
    }
    PCB::avgWt/=P.size();
    PCB::avgTat/=P.size();
    PCB::avgCt/=P.size();
}
int main()
{
    int n;
    cout<<"Enter the number of processes ...";cin>>n;
    vector<PCB> P(n);

    for(int i=0;i<n;i++)
    {
        cout<<"Process Id : ";cin>>P[i].pid;
        cout<<"Arrival Time : ";cin>>P[i].at;
        cout<<"Burst Time : ";cin>>P[i].bt;
    }
    sort(P.begin(),P.end());
    FCFS(P);
    cout<<"\t\t\tFCFS CPU SCHEDULING\n";
    cout<<"PID\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++)
    cout<<P[i].pid<<"\t"<<P[i].at<<"\t"<<P[i].bt<<"\t"<<P[i].ct<<"\t"<<P[i].tat<<"\t"<<P[i].wt<<endl;
    cout<<"\tAverage Waiting Time : "<<PCB::avgWt<<endl;
    cout<<"\tAverage TurnAround Time : "<<PCB::avgTat<<endl;
    cout<<"\tAverage Completion Time : "<<PCB::avgCt<<endl;
    return 0;
}