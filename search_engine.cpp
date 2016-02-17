// given a string ....take out all words from that string and store them in different strings
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int count_words(string in);
void parse(string in,vector<char> *w);
bool operator==(vector<char> w,string r)
{
    int s1=w.size();
    int s2=r.length();
    if(s1!=s2) return false;
    int i;
    for(i=0;i<s1;i++)
    {
        if(w[i]!=r[i]) return false;
    }
    return true;
}
ostream& operator<<(ostream& stream,vector<char> w)
{
    int s=w.size();
    int i;
    for(i=0;i<s;i++)
    {
        stream<<w[i];
    }

    return stream;
}

int main()
{
     int i;
     cout<<"Enter first char of the city name as capital letter........please "<<endl;
     string s;
     getline(cin,s);                       //in-- input
     int words=count_words(s);
     int len=s.length();
     vector<char> *w=new vector<char>[words];
     parse(s,w);
     ofstream out("history.txt",ios::app);

     if(!out)
     {
         cout<<"cannot open file"<<endl;
     }

     out<<s;
     out<<"\n";
     string r;          // for reading the file
             //
     //out<<"my name is shrey"<<endl;
     out.close();
     int cnt=0;
     //cout<<"Rank	Name	District	Type*	Population 2011[9][10]	Male[11]	Female[11]	Population below 5 yrs[11]	Literacy Rate[11]"<<endl;
     cout<<"Rank 	City	Population(2011)	Population(2001)	State or Union Territory"<<endl;
     for(i=0;i<words;i++)
     {
       //cout<<"w[i] "<<w[i]<<endl;
        ifstream in("cities_india.txt");

        while(!in.eof())
        {
            char str[1500];
            in.getline(str,1500);
            //cout<<str<<endl;
            //cout<<"now"<<endl;
            int words2=count_words(str);
            //cout<<"words2 "<<words2<<endl;
            vector<char> *w2=new vector<char>[words2];
            parse(str,w2);
            int j;
            //cout<<"w2[1]"<<w2[1]<<endl;
            for(j=0;j<words2;j++)
            {
                //  cout<<w2[j];
                if(w[i]==w2[j])
                {
                    cout<<str<<endl;
                    break;
                }
            }
            //cout<<endl;
        }
      /*      if(w[i]==r)
            {
                in.seekg(-(int)r.length(),ios::cur);
                in.getline(str,255);
                cout<<str<<endl;
                //get to the start of line and print that line;
            }           */
            //if(r=="\n") cout<<"gotcha";


        in.close();
     }
     /*for(i=0;i<words;i++)                //by operator overloading
     {
         cout<<w[i]<<endl;
     }  */

}

int count_words(string in)
{
    int words=0;
    int flag_w=0;
    int len=in.length();
    int i;
    for(i=0;i<len;i++)                //for counting words
    {
        if(in[i]==' ' || in[i]=='\t')       //opening the flag..after this when there is char --> words++
        {
            flag_w=0;
            continue;        // if multiple blank spaces are there
        }
        if(flag_w==0)        //if encountered anything except ' '
        {
            words++;
            flag_w=1;       // closing the flag..let it traverse through all chars
        }
       //cout<<in[i];
    }
    //cout<<"lll "<<words;
    return words;
}

void parse(string in,vector<char> *w)
{
     int i=0;
     int j=0;                     //keep track of jth word
     bool flag_newword=1;
     int len=in.length();
     while(i<len)
     {
         if(in[i]==' ' || in[i]=='\t')
         {
             if(flag_newword==0)
             {
                 j++;
                 flag_newword=1;       //close the flag so that j is not incremented
             }
             i++;
             continue;                      //pass all the spaces
         }
         w[j].push_back(in[i]);
         flag_newword=0;              //open
         i++;
     }

}
