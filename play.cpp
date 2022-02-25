#include <iostream>
using namespace std;
bool noZero(int i);
bool noRepeat(int i);
void split(int i,int arr[]);
void check(int target,int test,int* checkA,int* checkB);

int main() {
    int a=0;
    int b=0;
    int allNumbers[3024]={0};
    int num=1234;
    for(int i=0;num<=9876;num++)
    {
        if(noZero(num) && noRepeat(num))
        {
            allNumbers[i]=num;
            i++;
        }
    }
    int guess;
    while(a!=4)
    {
        for(int i=0;i<3024;i++)
        {
           if(allNumbers[i]!=-1)
           {
               guess=allNumbers[i];
               cout<<"電腦預測："<<guess<<endl;
               allNumbers[i]=-1;
               break;
           }
        }
        
        cout<<"輸入AorB"<<endl;
        cout<<"Ａ:";
        cin>>a;
        cout<<"B：";
        cin>>b;
        
        int checkA,checkB;
        for(int i=0;i<3024;i++)
        {
            if(allNumbers[i]!=-1)
            {
                check(guess, allNumbers[i], &checkA, &checkB);
                if(checkA!=a||checkB!=b)
                    allNumbers[i]=-1;
            }
        }
        
    }
    cout<<"the answer is："<<guess<<endl;
  cout<<1102052楊承恩<<endl;
    return 0;
}

bool noZero(int i)
    {
        int arr[4];
        split(i,arr);
        return arr[0]!=0 && arr[1]!=0 && arr[2]!=0 && arr[3]!=0;
    }

bool noRepeat(int i)
{
    int arr[4];
    split(i,arr);
    int compare[10]={0,1,2,3,4,5,6,7,8,9};
        for(int j=0;j<4;j++)
        {
            if(compare[arr[j]]== -1)
                return false;
            else
                compare[arr[j]]= -1;
        }
    return true;
}

void split(int i,int arr[])
{
    arr[0]=i/1000;
    arr[1]=i/100%10;
    arr[2]=i/10%10;
    arr[3]=i%10;
}

void check(int target,int test,int* checkA,int* checkB)
{
    *checkA=0;
    *checkB=0;
    int targetArray[4];
    int testArray[4];
    split(target,targetArray);
    split(test,testArray);
    
    int compare[10]={0,1,2,3,4,5,6,7,8,9};
    for(int i=0;i<4;i++)
        compare[targetArray[i]]=-1;
    
    for(int i=0;i<4;i++)
    {
        if(compare[testArray[i]]==-1)
        {
            if(testArray[i]==targetArray[i])
                *checkA +=1;
            else
                *checkB +=1;
        }
    }
}

