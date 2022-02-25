#include <iostream>
#include<string>
using namespace std;
void split(int n, int N[]) {
    N[0] = n / 1000;
    N[1] = (n / 100) % 10;
    N[2] = (n / 10) % 10;
    N[3] = n % 10;
}
bool isRepeat(int N[]) {
    if (N[0] == N[1] || N[0] == N[2] || N[0] == N[3] || N[1] == N[2] || N[1] == N[3] || N[2] == N[3])
        return false;
    else
        return true;
}
int main()
{
  cout<<"1092044"<<endl;
  cout<<"林悅福"<<endl;
  cout<<"------------------------------"<<endl;
  cout<<"so easy"<<endl;
  
  
  int N[4];
    int M[4];
    int T[3025];
    int S[3025];
    int set = 1000;
    int count = 1;
    for (int i = 0; i < 3024; i++) {
            T[i] = set;
            split(T[i], N);
            while (isRepeat(N) == false || N[0] == 0 || N[1] == 0 || N[2] == 0 || N[3] == 0) {
               
                    T[i] = ++set;
                    split(T[i], N);
                
            }
            set++;
        }
    
    int input;
    cin >> input;
    int Avalue[3024];
    int Bvalue[3024];
    int A=0;
    int B=0; 
    
    bool finish = false;
    split(input, M);

    
    while (finish == false) {
        int set2 = 0;
        //--------------------------------calA
        for (int count = 0; count < 3024; count++) {
            split(T[count], N);
            if (N[0] == M[0])
                A++;
            if (N[1] == M[1])
                A++;
            if (N[2] == M[2])
                A++;
            if (N[3] == M[3])
                A++;
            Avalue[count] = A;
            A = 0;

        }
        //--------------------------------calB
        for (int count = 0; count < 3024; count++) {
            split(T[count], N);
            if (M[0] == N[1])
                B++;
            if (M[0] == N[2])
                B++;
            if (M[0] == N[3])
                B++;
            if (M[1] == N[0])
                B++;
            if (M[1] == N[2])
                B++;
            if (M[1] == N[3])
                B++;
            if (M[2] == N[0])
                B++;
            if (M[2] == N[1])
                B++;
            if (M[2] == N[3])
                B++;
            if (M[3] == N[0])
                B++;
            if (M[3] == N[1])
                B++;
            if (M[3] == N[2])
                B++;
            Bvalue[count] = B;
            B = 0;
        }
        cout << "第"<<count<<"次猜" << T[0]<<"   ";
        int tempA = Avalue[0];
        int tempB = Bvalue[0];
        cout << tempA << "A" << "   " << tempB << "B" << endl;
        for (int x = 1; x < 3024; x++) {
            if (Avalue[x] >= tempA)   
            {

                T[set2] = T[x];
                Avalue[set2] = Avalue[x];
                Bvalue[set2] = Bvalue[x];
                ++set2;

            }
        }

        if (tempA == 4)
        {
            finish = true;
        }
        count++;
    }
}
