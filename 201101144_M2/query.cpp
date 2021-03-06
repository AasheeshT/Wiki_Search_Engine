#include<dirent.h>
#include<iostream>
#include<ctype.h>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<iterator>
#include<cmath>
#include<climits>
#include <bitset>
#include <fstream>
#include "rapidxml-1.13/rapidxml.hpp"

using namespace rapidxml;
using namespace std;

#define FOR(i,a,b) for(int i= (int)a; i< (int)b; ++i)
#define REP(i,n) FOR(i,0,n)

#define LL long long int 
#define PII pair<int,int> 
#define PB push_back
#define MP make_pair
#define INF 1000000000
#define mod 1000000007
#define MX 100005
#define QMX 1000

FILE* fout;
FILE* fin;
FILE* f1, *f2 ,*f3;
FILE* fdtitle1,*fdtitle2;

class docWeight
{
	public: 
		int docId;
		double w;
		bool operator<( const docWeight& i ) const
		{
			return this->docId < i.docId;
		}
};

FILE* ff;
map < string, long long int > idx;
map < string, long long int >::iterator itidx;

map <string,char> query;
map <string,char>::iterator itq;

map <string, vector< docWeight > > wordpostings;
map <string, vector< docWeight > >::iterator itwp;

priority_queue< docWeight > heap;

vector< docWeight> results;
vector< docWeight>::iterator itresults;

map<LL,LL> doctitle;
map<LL,LL>::iterator itdoctitle;
extern int stem( char* s, int i, int j);

vector<string> split(string x, string d)
{
	vector<string> res;
	int prev = 0, found = x.find(d);
	while(found!=std::string::npos)
	{
		res.push_back(x.substr(prev,found-prev));
		prev = found+1;
		found = x.find(d, found+1);
	}           
	res.push_back(x.substr(prev,x.size()-prev));
	return res;
}
void multiLevelInd(char* infile, char* outfile , int gaps)
{
	//printf("making multilevel ind\n");
	fin = fopen(infile,"r");
	fout = fopen(outfile , "w");

	char word[1000];
	LL pos;
	int i;
	char c;
	int docId;
	int counter = 0;
	char cat[1000];
	while(1)
	{
		pos = ftell( fin );
		if( fscanf(fin , "%s",word) == EOF )
			break;
		while(1)
		{
			fscanf(fin,"%c",&c);
			if( c == '\n')
				break;
			if( fscanf(fin,"%s",cat) == EOF)
				break;
		}
		// secondary index, word & position in file 
		if(counter%gaps==0)
			fprintf(fout,"%s %lld\n",word , pos ); 
		counter++;
	}
	fprintf(fout,"%s %lld\n","{}",pos);
	fclose(fin);
	fclose(fout);
	//printf("Done  multilevel ind\n");
}
void multiLevelInd2(char* infile, char* outfile , int gaps)
{
	//printf("making multilevel ind\n");
	fin = fopen(infile,"r");
	fout = fopen(outfile , "w");
	char word[1000];
	LL pos;
	LL temp;
	int i;
	char c;
	int counter = 0;
	while(1)
	{
		pos = ftell( fin );
		if( fscanf(fin,"%s",word) == EOF )
			break;
		fscanf(fin,"%lld",&temp);
		fscanf(fin,"%c",&c);
		if(counter%gaps==0)
			fprintf(fout,"%s %lld\n",word , pos ); 
		counter++;
	}
	fprintf(fout,"%s %lld\n","{}",pos);
	fclose(fin);
	fclose(fout);
	//printf("Done  multilevel ind\n");
}
void loadIndexInMem( char* ind )
{
	fin = fopen(ind,"r");
	char word[1000];
	LL pos;
	int i;
	char c;
	while(1)
	{
		if( fscanf(fin,"%s",word) == EOF )
			break;
		fscanf(fin,"%lld",&pos);
		string tword = word;
		// 3rd level map
		idx[tword] = pos;
	}
	fclose(fin);
	//printf("loadded\n");
}
void makeDocTitleIndex()
{
	int gaps=100;
	FILE* fdtitle1 = fopen("titleind2","w");
	FILE* fdtitle2 = fopen("titleind","r");
	if( fdtitle1 == NULL || fdtitle2 == NULL )
	{
		printf("fail\n");
	}
	LL docId;
	LL pos;
	int temp;
	int i;
	char c;
	int counter = 0;
	char buf[1000];
	//printf("Making Doc max index\n");
	while(1)
	{
		pos = ftell( fdtitle2 );
		if( fscanf(fdtitle2,"%x",&docId) == EOF )
			break;
		//printf("%lld\n",docId);
		fscanf(fdtitle2,"%[^\n]",buf);
		fscanf(fdtitle2,"%c",&c);
		if(counter%gaps==0)
			fprintf(fdtitle1,"%lld %lld\n",docId,pos); 
		counter++;
	}
	fclose(fdtitle1);
	fclose(fdtitle2);
	printf("Done  multilevel ind\n");
}
void loadTitleInMem()
{
        fin = fopen("titleind2","r");
        char word[1000];
        LL pos;
        int i;
        char c;
	LL mm;
        while(1)
        {
                if( fscanf(fin,"%lld",&mm) == EOF )
                        break;
                fscanf(fin,"%lld",&pos);
                // 3rd level map
                doctitle[mm] = pos;
        }
        fclose(fin);
        //printf("loadded\n");
}
void search1(LL x)
{
	FILE* fp2=fopen("titleind","r");
	itdoctitle = doctitle.lower_bound( x );
	LL pos = -1;
	LL mi;
	char buff[10000];
	if( itdoctitle->first == x )
	{
		fseek( fp2, itdoctitle->second , SEEK_SET);
		fscanf(fp2,"%lld",&mi);
		fscanf(fp2,"%[^\n]",buff);
		printf("%s\n",buff);
	}
	else
	{
		if( itdoctitle != doctitle.begin())
		{
			itdoctitle--;
			//printf("%d\n",itidx->second);
			fseek( fp2, itdoctitle->second , SEEK_SET);
			//printf("Else\n");
			while(1)
			{

				if( fscanf(fp2,"%lld",&mi) == EOF ) break;
				fscanf(fp2,"%[^\n]",buff);
				//printf("%s\n", word);
				int flag;
				if(mi==x)
				{
					printf("%s\n",buff);
					break;
				}
			}   
		}
	}
}
void search( string w )
{
	itidx = idx.lower_bound( w );
	//printf("%s %lld\n", itidx->first.c_str() , itidx->second );        
	LL pos = -1;
	LL temppos;
	char word[1000] = {'\0'};
	if( itidx->first == w )
	{
		fseek( f2, itidx->second , SEEK_SET);
		fscanf(f2,"%s",word);
		fscanf(f2,"%lld",&pos);
	}
	else
	{
		if( itidx != idx.begin())
		{
			itidx--;
			//printf("%d\n",itidx->second);
			fseek( f2, itidx->second , SEEK_SET);
			//printf("Else\n");
			while(1)
			{

				if( fscanf(f2,"%s",word) == EOF ) break;
				fscanf(f2,"%lld",&temppos);
				//printf("%s\n", word);
				int flag = strcmp( word , w.c_str());
				if( flag > 0 )
					break;
				if( flag == 0 )
				{
					pos = temppos;
					break;
				}
			}   
		}
	}
	//printf("%s %lld\n",word,pos);
	if( pos != -1 )
	{

		vector<docWeight> postings;    
		fseek( f3 , pos , SEEK_SET );
		fscanf(f3 , "%s",word);
		int docId;
		char c;
		while( 1 )
		{
			char cat[100];
			//printf("outer loop\n");
			fscanf(f3,"%x",&docId);
			fscanf(f3,"%s",cat);
			fscanf(f3,"%c",&c);

			//printf("%x %s\n",docId, cat); 

			char* p = cat;
			int freq;
			while( *p != '\0' )
			{
				//printf("%c %s\n",query[w], p );
				if( (*p+32) == query[w] )
				{
					freq = 0;
					p++;
					while( *p !='\0' && *p >='0' && *p<='9')
					{
						freq = 10*freq + *p - 48;
						p++;
					}
					//printf("Freq : %c %d\n",*p , freq );
					if( query[w] == 't' )
					{
						freq *= 20;   
					}
					else if( query[w] == 'i')
					{
						freq *= 15;   
					}
					else if( query[w] == 'c')
					{
						freq *= 10;   
					}
					else if( query[w] == 'o')
					{
						freq *= 5;   

					}

					docWeight docpair;
					docpair.docId  = docId ;
					docpair.w = (double ) freq;
					postings.PB( docpair );
				}
				else p++;
			}
			if( c == '\n') break;
		}
		wordpostings[ w ] = postings;
	}
}
void foo(string s)
{
	//cout << "came " << s <<  endl;
	vector<string>  S = split(s," ");
	//cout << "came " << s <<  endl;
	int l=S.size();
	//cout << "came " << s  << " " << l <<  endl;
	query.clear();
	wordpostings.clear();
	for(int i=0;i<l;i++)
	{
		LL l1=S[i].size();
		for(int j=0;j<l1;j++)
		{
			S[i][j]=tolower(S[i][j]);
		}
		//cout << S[i] << endl;
		char tchar[1000];
		int j;
		for(j=0;j<l1;j++)
		{
			tchar[j]=S[i][j];
		}
		tchar[j]='\0';
		string temp;
		tchar[ stem( tchar,0,j-1 ) + 1 ] = '\0';
		for(int j=0;j<strlen(tchar);j++)
			temp+=tchar[j];
		query[temp] = 'x';
	}
}
bool prompt()
{
	printf("query> ");
	char q[QMX];
	if( scanf("%[^\n]",q) == EOF )
		return 1;
	getchar();
	bool myflag=false;
	string mytemp;
	REP(i,strlen(q))
	{
		mytemp+=q[i];
		if(q[i]==':')
		{
			myflag=true;
			break;
		}
	}
	if(!myflag)
	{
		foo(mytemp);
		return 0;
	}
	char* pch = strtok (q," :");
	int i=0;
	char tchar[1000];
	char attr;
	query.clear();
	wordpostings.clear();
	while(pch != NULL)
	{   
		i++;
		strcpy( tchar , pch );
		int len = 0;
		for(char* temp = tchar; *temp!='\0';temp++,len++)
		{
			if( *temp >='A' && *temp<='Z') *temp += 32;
		}
		// printf("%s %d\n",tchar,len);
		tchar[ stem( tchar,0,len-1 ) + 1 ] = '\0';
		// printf("stemmed wrd: %s\n",tchar);

		if( i&1 )
		{
			attr = tchar[0];
			if( attr == 'b' ) attr = 'x';
		}
		else
		{
			string temp = tchar;
			query[temp] = attr;
		}
		pch = strtok (NULL," :");
	}
	return 0;
}

bool func(docWeight i,docWeight j)
{
	return (i.w > j.w);
}
void mergeDocIds()
{
	results.clear();
	for(itwp=wordpostings.begin();itwp!=wordpostings.end();itwp++)
	{
		for(int i=0;i<itwp->second.size();i++)
		{
			heap.push( itwp->second[i] );
		}
	}
	while( !heap.empty() )
	{
		docWeight cur = heap.top();
		heap.pop();
		while( !heap.empty() && heap.top().docId == cur.docId )
		{
			docWeight sub = heap.top();
			heap.pop();
			cur.w += sub.w;
		}
		results.PB( cur );
	}
	sort( results.begin() , results.end() , func );
	// printf("results size : %d\n", results.size());
}
void displayTitle( int d)
{
	//   printf("searching for %x\n",d);
	char buffer[1000];
	int docId;
	char c;
	fseek ( fdtitle1 , 0 , SEEK_SET);
	while(1)
	{
		if(fscanf(fdtitle1, "%x%c",&docId, &c)== EOF)
			break;
		fscanf(fdtitle1, "%[^\n]",buffer);
		if(docId==d)
		{
			//cout << d << endl;
			//printf("%x\n",docId);
			printf("%s\n",buffer);
			break;
		}
	}
}
void displayResults()
{
	fdtitle1 = fopen("titleind","r");
	int i =0;
	for( itresults = results.begin() ; itresults != results.end() ; itresults++)
	{

		displayTitle( itresults->docId  );
		//cout << itresults->docId  << endl;
		//search1(itresults->docId);
		i++;
		if( i == 15 ) break;
	}   
	fclose( fdtitle1 );
}
void getPostings()
{
	for(itq = query.begin(); itq != query.end() ; itq++)
	{
		search( itq->first );
	}
}
void processQueries()
{
	while(1)
	{
		if( prompt() )
			break;
		getPostings();
		mergeDocIds();
		displayResults();
	}
}
int main(int argc , char* argv[])
{
	f3 = fopen( argv[3] , "r" );
	f2 = fopen( argv[2] , "r" );
	f1 = fopen( argv[1] , "r" );
	multiLevelInd( argv[3] , argv[2] , 1);
	multiLevelInd2( argv[2] , argv[1] , 100 );
	loadIndexInMem( argv[1] );
	processQueries();
	return 0;
}
