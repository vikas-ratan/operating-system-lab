#include<bits/stdc++.h>
using namespace std;
int gantChart[1000];
int sumbt=0;
struct processNode
{
	int prn,at,pr,bt,wt,tat,prid,ct,temp;
	
};
bool comp(processNode p1,processNode p2)
{
	if(p1.at<p2.at)
		return true;
	if(p1.at==p2.at)
		if(p1.pr<p2.pr)
			return true;
		else
			return false;
	return false;
}
int findX(std::vector<processNode> v,int Time)
{
	int i=0;int prior=1000;int x=v[0].prid;int index;
	while(v[i].at<=Time  && v[i].at<=sumbt)
	{
		if(v[i].pr<prior && v[i].temp<v[i].bt)
		{
			index=i;
			prior=v[i].pr;
			x=v[i].prid;
		}
		i++;
	}
	v[index].temp++;
	return index;
}
void calParam(std::vector<processNode> &v,int num){
	sort(v.begin(), v.end(),comp);
	for(int Time=0;Time<=sumbt;Time++)
	{
		int x=findX(v,Time);
		gantChart[Time]=x;
	}

}
int main()
{
    int num;
    cout<<"Enter number of process : ";cin>>num;
    std::vector<processNode> v(num);sumbt=0;
    for(int i=0;i<num;i++)
    {
    	v[i].prn=i+1;
    	cout<<"...Process "<<i+1<<"...\n"; 
        cout<<"Enter Process Id: ";
        cin>>v[i].prid;
        cout<<"Enter Priority: ";
        cin>>v[i].pr; 
        cout<<"Enter Arrival Time: "; 
        cin>>v[i].at; 
        cout<<"Enter Burst Time: "; 
        cin>>v[i].bt;
        v[i].ct=0;v[i].wt=0;v[i].tat=0;v[i].temp=v[i].bt;
        sumbt+=v[i].bt;
    }
    float avgWt=0,avgTat=0;
    calParam(v,num);
    for(auto e:v)
    {
    	for(int i=0;i<=sumbt;i++)
    	{
    		if(gantChart[i]==e.prid)
    			v[e.prid].ct=i;
    	}
    	cout<<"TAT for process "<<e.prid<<" "<<v[e.prid].ct-v[e.prid].at<<endl;
    }
	return 0;
}