#include <cstdio>
struct frame
{
    int pno;
    int counter;
}frame[5];
struct Page{
    int pgNo;

};
int Ref_string[]={12,13,12,14,12,14,13,15,15,17,12};//this holds the queue for demand pages
int np= 11, n,i,j,currtime;
//pn holds the number of page string
int page_found(int pno)
{
    int i;
    for (i=0;i<n;i++)
        if(frame[i].pno==pno)
            return i;//returns the frame number of that perticular page
    return -1; //which means page not found
}
int get_LRU()
{
    int min=0;
    for(i=0;i<n;i++)
    {
        if(frame[i].counter<frame[min].counter)
            min = i;
    }
    return min;
}
int main(){
    int i,j,pno,p,page_fault=0,flag;
    printf("\n Enter the number of frames: \t");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        frame[i].pno=-1;
        frame[i].counter=-1;

    }
    printf("\n Page Number\t\t\t\t Frames \t\t\t\t Page Fault");
    currtime=1;
    for(p=0;p<np;p++)
        //now p checks each page from the Reference String which holds demanded page
    {
        flag=0;
        pno=Ref_string[p];
        j=page_found(pno);
        if(j==-1)
        {
            page_fault++;
            j=get_LRU();
            frame[j].pno=pno;
            flag=1;
        }

        frame[j].counter=currtime;
        currtime++;
        printf("\n\t%5d\t\t",pno);
        for(i=0;i<n;i++)
        {printf(" %2d:%2d\t", frame[i].pno,frame[i].counter);}
        if(flag==1)
        {printf("\t\t\t  YES");}
        else
        {printf("\t\t\t  NO ");}
    }
    printf("\nNo. of page fault: %d \n", page_fault);
    return 0;
}