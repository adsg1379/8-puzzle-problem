#include<iostream>
#include <map>
#include <iterator>
using namespace std;
class puz
{
    public:
    int hello[3][3];
    int operator +(puz p1)
    {
        int i,j,k=0;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(hello[i][j]==p1.hello[i][j])
                    k++;
            }
        }
        if(k!=9)
            return 0;
        if(k==9)
            return 1;

    }
};

puz up(int i,int j,puz p)
{
    int k;
    k=p.hello[i][j];
    p.hello[i][j]=p.hello[i-1][j];
    p.hello[i-1][j]=k;
    return p;

}
puz down(int i,int j,puz p)
{
    int k;
    k=p.hello[i][j];
    p.hello[i][j]=p.hello[i+1][j];
    p.hello[i+1][j]=k;
    return p;

}
puz right(int i,int j,puz p)
{
    int k;
    k=p.hello[i][j];
    p.hello[i][j]=p.hello[i][j+1];
    p.hello[i][j+1]=k;
    return p;

}
puz left(int i,int j,puz p)
{
    int k;
    k=p.hello[i][j];
    p.hello[i][j]=p.hello[i][j-1];
    p.hello[i][j-1]=k;
    return p;

}
int compare(puz p[],puz p1,int q)
{
    int i;
    for(i=0;i<q;i++)
    {
        if(p[i]+p1)
            return 0;
    }
    return 1;
}
int Count(int a[][3])
{
    int i,j,h=0,check[3][3]={{1,2,3},{8,0,4},{7,6,5} };
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(check[i][j]!=a[i][j])
            {
                if(a[i][j]==0)
                    continue;
                else
                h++;
            }
        }

    }
    return h;
}
int Count2(int a[][3],int b[][3])
{
    int i,j,h=0,l1,l2,m1,m2,check[3][3]={{1,2,3},{8,0,4},{7,6,5} };
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(b[i][j]!=a[i][j])
            {
                h++;
                if(a[i][j]==0)
                {
                    l1=i;
                    m1=j;
                }
                if(b[i][j]==0)
                {
                    l2=i;
                    m2=j;
                }
            }
        }

    }
    if(l1==l2)
    {
        if(m1-1==m2 || m1+1==m2)
        {
            return h;
        }
    }
    if(m1==m2)
    {
        if(l1-1==l2 || l1+1==l2)
        {
            return h;
        }

    }
    return 0;
}
void print(puz p,int a)
{
    int i,j;
    cout<<"\tnot in place="<<a<<"\n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<p.hello[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void print(int p[][3],int a)
{
    int i,j;
    cout<<"\tnot in place="<<a<<"\n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void arrange(int g,int a[][3])
{
    int joker=0;
    int j,i,l,m,check[3][3]={{1,2,3},{8,0,4},{7,6,5}} ;
    multimap<int,puz> puzzle;
    multimap<int,puz>puzzle2;
    multimap<int,puz>puzzle3;
    multimap<int,puz> :: iterator itr;
    multimap<int,bool> :: iterator itr2;

     puz p,p2;
     puz* comp=new puz[999999];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            p.hello[i][j]=a[i][j];
        }
    }
    puzzle.insert(pair <int,puz> (Count(p.hello)+g,p));
    p2=p;
    int q=0;

    while(Count(p2.hello)!=0)
    {

    itr=puzzle.begin();
    p2=itr->second;
    joker++;
    g=(itr->first)-(Count(p2.hello));
    puzzle2.insert(pair<int,puz>(g,p2));
    puzzle.erase(puzzle.begin());
    comp[q]=p2;
    q++;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(p2.hello[i][j]==0)
            {
                switch(i)
                {
                case 2:
                    switch(j)
                    {
                    case 2:
                        p=up(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        p=left(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        break;
                    case 1:
                        p=up(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        p=left(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        p=right(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        break;
                    case 0:
                        p=up(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        p=right(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        break;
                    }
                    break;
                    case 1:
                        switch(j)
                    {
                    case 2:
                        p=up(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        p=left(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        p=down(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        break;
                    case 1:
                        p=down(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        p=up(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        p=left(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        p=right(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        break;
                    case 0:
                        p=up(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        p=right(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        p=down(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        break;
                    }
                    break;
                    case 0:
                        switch(j)
                    {
                    case 2:
                        p=left(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        p=down(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        break;
                    case 1:
                        p=left(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        p=right(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        p=down(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        break;
                    case 0:
                        p=right(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        p=down(i,j,p2);
                        if(compare(comp,p,q))
                        puzzle.insert(pair <int,puz> (Count(p.hello)+g+1,p));
                        break;
                    }
                    break;

                }
            }
        }
    }
    itr=puzzle.begin();

    }
    cout<<"\nTotal moves="<<g;
    puz bye;

    itr=puzzle2.end();
    itr--;
    bye=itr->second;
    for(;itr!=puzzle2.begin();itr--)
    {
       if(Count2(itr->second.hello,bye.hello)==2 )
       {
           puzzle3.insert(pair<int,puz>(itr->first,itr->second));
           joker--;
           bye=itr->second;
       }

    }
    puzzle3.insert(pair<int,puz>(itr->first,itr->second));

    for(itr=puzzle3.begin();itr!=puzzle3.end();itr++)
    {
        cout<<"\ng="<<itr->first;
        print(itr->second,Count(itr->second.hello));
    }
    itr--;
    cout<<"\ng="<<itr->first+1;
    print(check,0);

}


int main()
{
    int a[3][3],i,j;
    cout<<"Enter the Initial State row wise\n";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<Count(a)<<"\n";
    arrange(0,a);

}
