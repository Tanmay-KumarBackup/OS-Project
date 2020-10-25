#include <cstdio>
#include <iostream>
//#include <mysql_connection.h>
struct Page{
    int pgNo;
    int TNR_num;
};
struct frame
{
public:
    Page* pno;
    int counter;
}frame[3];

int  n=3,currtime;
//pn holds the number of page string
int page_found(Page pNo)
{
    int i;
    for (i=0;i<n;i++)
        if(frame[i].pno== nullptr)
        {continue;}
        else
        {
            if(frame[i].pno->pgNo==pNo.pgNo) {
                frame[i].pno->TNR_num++;//at the time when the page is found the TNR of that page is been incremented
                return i;//returns the frame number of that particular page
            }
        }
    return -1; //which means page not found
}

int get_LRU()
{//considering that LRU is directly proportional to the (counter*TNR) of that page
    int i,min=0;
    for (i=0;i<n;i++)
    {
        if(frame[i].pno== nullptr)
        {
            return i;
        }
    }
    for(i=0;i<n;i++)
    {
        if((frame[i].counter)*(frame[i].pno->TNR_num)<(frame[min].counter)*frame[min].pno->TNR_num)
            min = i;
    }
    return min;
}
int main(){
    int i,j,p,size,page_fault=0,flag;
    Page* pno;
    printf("\n Enter the number of pages being referenced: \t");
    scanf("%d",&size);
    Page *ref_str;
    ref_str=(Page *)malloc(sizeof(Page)*size);
    for (i=0;i<size;i++)
    {
        std::cout<<"Enter page number ( " <<i<<" )\t";
        std::cin>>ref_str[i].pgNo;
        ref_str[i].TNR_num=1;
    }
    //constructing the frames to be empty at the initial stage
    for (i=0;i<n;i++)
    {
        frame[i].pno= nullptr;
        frame[i].counter=-1;

    }
    printf("\n Page Number\t\t\t\t Frames \t\t\t\t Page Fault");
    currtime=1;
    for(p=0;p<size;p++)
        //now p checks each page from the Reference String which holds demanded page
    {
        flag = 0;

        j = page_found(ref_str[p]);
        if (j == -1) {
            page_fault++;
            j = get_LRU();
            frame[j].pno = &ref_str[p];
            flag = 1;
        }

        frame[j].counter = currtime;
        currtime++;

        printf("\n\t%5d\t\t", ref_str[p].pgNo);
        for (i = 0; i < n; i++) {
            if (frame[i].pno == nullptr) {printf(" %2d:%2d\t", -1, frame[i].counter);}
            else {printf(" %2d:%2d\t", (frame[i].pno)->pgNo, frame[i].counter);}
        }
        if (flag == 1) { printf("\t\t\t  YES"); }
        else { printf("\t\t\t  NO "); }
    }
    printf("\nNo. of page fault: %d \n", page_fault);
    return 0;
}