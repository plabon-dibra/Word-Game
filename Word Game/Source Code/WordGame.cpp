#include<bits/stdc++.h>
using namespace std;

vector<string>word,word_input;
string name1,name2,s,X,Y,S;
int x,y,count1=0,score1=0,score2=0,V[20][20];
char c,v[20][20];
void instruction()
{
    cout<<"\n                 W E L C O M E     T O     W O R D     G A M E !   \n\n"<<endl;
    cout<<"                               GAMES INSTRUCTIONS\n\nThere   are   two  Players,  Firstly   need  to   give   thier   names. \n\n"<<endl;
    cout<<"How to play?\n____________The game start with the turn of first person, then second ,again first and so on.\n";
    cout<<"Taking input two integers \"Row and Column\"(0<Row<=10,0<column<=15) then  input  a \"Character\" "<<endl;
    cout<<"to  create a word ,and also have to enter a \"String\" which word considered.  \n\n";
    cout<<"If the input word matches with any word from file and find the pattern in the matrix then the player will have points"<<endl;
    cout<<"Otherwise the player will have not point."<<endl;
    cout<<"\nAll the input will be \"small case\" letter\n"<<endl;
    cout<<"If anytime want to end the game , Please enter \"# # # #\" \n\n";
    cout<<"Points Distribution:\n____________________Points will be count with the length of word \nThe word have to \"Up to Down\" or \"Left to Right\"(Horaizontal or vertically)\n";
    cout<<"\n\n To Play the Game \n\n Press Enter\n";
    getchar();
}
void setup()
{
    system("CLS");
    cout<<"Enter First Player name: "<<endl;
    getline(cin,name1);
    cout<<"Enter Second Player name: "<<endl;
    getline(cin,name2);
    cout<<"\n\n\nEnter Any key to Play.\n";
    word_input.push_back(".");
    getchar();
}
void input()
{
    cin>>X>>Y>>S>>s;
    if(X.size()==2)
        x=(X[0]-48)*10+X[1]-48;
    else
        x=X[0]-48;
    if(Y.size()==2)
        y=(Y[0]-48)*10+Y[1]-48;
    else
        y=Y[0]-48;
    c=S[0];
}
void print()
{
    system("CLS");
    cout<<"|=================================================================|\n";
    cout<<"|     | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10 |11 |12 |13 |14 |15 |\n";
    cout<<"|=====|===|===|===|===|===|===|===|===|===|===|===|===|===|===|===|\n";
    for(int i=1; i<=10; i++)
    {
        for(int j=0; j<=15; j++)
        {
            if(j==0)
            {
                if(i==10)
                    cout<<"|"<<i<<"-> | ";
                else
                    cout<<"| "<<i<<"-> | ";
            }
            else if(V[i][j]==0)

                cout<<"  | ";
            else
                cout<<v[i][j]<<" | ";
        }
        if(i==10)
            break;
        cout<<"\n|-----|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n";
    }
    cout<<"\n|=================================================================|\n";
    cout<<"                                                            SCORE :\n\n";
    cout.setf(ios::left);
    cout<<"                                                            ";
    cout.width(20);
    cout<<name1<<" : "<<score1<<endl;
    cout<<"                                                            ";
    cout.width(20);
    cout<<name2<<" : "<<score2<<endl;
}

void get_word()
{
    ifstream f;
    f.open("words_small.txt");
    char op[200];
    if (f.is_open())
        while (!f.eof())
        {
            f >> op;
            word.push_back(op);
        }
    else
    {
        cout<<"File Error !"<<endl;
        system("pause");
    }
    f.close();
}
int check()
{
    int lnt=s.size();
    int left=y,right=y,up=x,down=x,d;
    for(int i=y+1; i<=15; i++)
    {
        if(V[x][i]==1)
            right=i;
        else
            break;
    }
    for(int i=y-1; i>0; i--)
    {
        if(V[x][i]==1)
            left=i;
        else
            break;
    }
    for(int i=x+1; i<=10; i++)
    {
        if(V[i][y]==1)
            down=i;
        else
            break;
    }
    for(int i=x-1; i>0; i--)
    {
        if(V[i][y]==1)
            up=i;
        else
            break;
    }
    string ck,tp;
    if(right-left+1>=lnt)
    {
        /// y diye kaj korte hobe
        int i=y-lnt+1;
        if(i<=left)
        {
            i=left;
        }
        for(i; (i<=right-lnt+1)&&(i<=y); i++)
        {
            ck.clear();
            for(int j=i; j<=i+lnt-1; j++)
            {
                tp=v[x][j];
                ck+=tp;
            }
            if(ck==s)
            {
                return 1;
            }
        }
    }
    if(down-up+1>=lnt)
    {
        /// x diye kaj korte hobe
        int i=x-lnt+1;
        if(i<=up)
        {
            i=up;
        }
        for(i; (i<=down-lnt+1)&&(i<=x); i++)
        {
            ck.clear();
            for(int j=i; j<=i+lnt-1; j++)
            {
                tp=v[j][y];
                ck+=tp;
            }
            if(ck==s)
                return 1;
        }
    }
    return 0;
}
void loop()
{
    print();
    if(count1%2==0)
        cout<<name1<<"'s  term :"<<endl;
    else
        cout<<name2<<"'s  term :"<<endl;
    if(count1==0)
        cout<<"Hint: 4 5 a a"<<endl;
    input();
    if(X=="#")
        return ;
    if(x>0&&x<11&&y<16&&y>0)
    {
        if(V[x][y]==0)
        {
            count1++;
            V[x][y]=1;
            v[x][y]=c;
            if(find(word.begin(),word.end(),s)!=word.end())
            {
                if(find(word_input.begin(),word_input.end(),s)!=word_input.end())
                {
                    print();
                    cout<<"Sorry !\nAlready Pointed!"<<endl;
                }
                else
                {
                    int checker=check();
                    if(checker==1)
                    {
                        if(count1%2==1)
                            score1+=s.size();
                        else
                            score2+=s.size();
                        print();
                        cout<<"Succesful !    You have got "<<s.size()<<" points."<<endl;
                        word_input.push_back(s);
                    }
                    else
                        cout<<"Pattern Not Matched! "<<endl;
                }
            }
            else
                cout<<"Word Not Found !"<<endl;
        }
        else
            cout<<"Sorry!\nAlready placed!\nplease try to another place?"<<endl;
    }
    else
        cout<<"Invalid term!"<<endl;
    if(count1==150)
        return;
    cout<<"\n\nPress Enter !";
    getchar();
    getchar();
    print();
    loop();
}
void result()
{
    system("CLS");
    cout.setf(ios::left);
    cout<<"\n\nPoints :"<<endl;
    cout.width(20);
    cout<<name1<< " Get Points : "<<score1<<endl;
    cout.width(20);
    cout<<name2<< " Get Points : "<<score2<<endl;
    cout<<"\n\n\n"<<endl;
    if(score1>score2)
        cout<<name1<<" Winner !"<<endl;
    else if(score1<score2)
        cout<<name2<<" Winner !\n\n"<<endl;
    else
        cout<<"Match Draw !"<<endl;
    getchar();
}
int main()
{
    system("color C");
    get_word();
    instruction();
    setup();
    print();
    loop();
    result();
    getchar();
    return 0;
}
