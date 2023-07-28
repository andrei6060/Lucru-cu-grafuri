#include <string.h>
#include "graph.h"
Graph initGraph(int V)
{
	Graph g;
	int i;
	g = (Graph) malloc(sizeof(struct graph));
	g->V = V;
	g->adjLists = (List*) malloc(V * sizeof(List));
	for (i = 0; i < V; i++) {
		g->adjLists[i] = NULL;
	}
	g->visited = calloc(V, sizeof(int));
	return g;
}


int util(Graph graph, char chestie[30]){
	int pam[100];
	for(int i=0; i<graph->V; i++)
	pam[i]=graph->visited[i];
	int curr;
	for(int i=0; i<graph->V; i++)
	if(strcmp(graph->adjLists[i]->data,chestie)==0)
		curr=i;
	if(graph->visited[curr]==1)
		return 1;
	graph->visited[curr]=1;
	List temp=graph->adjLists[curr];
	int ok=0;
	while(temp!=NULL){
			temp=temp->next;
			if(temp){
			ok=util(graph,temp->data);
			if(ok==1)
				return 1;}
		}
		for(int i=0; i<graph->V; i++)
		graph->visited[i]=pam[i];
		return 0;
}

int c1 (Graph graph){
	int ok=0;
	for(int i= 0; i<graph->V; ++i){
		graph->visited[i]=1;
		List temp=graph->adjLists[i];
		while(temp!=NULL){
			temp=temp->next;
			if(temp)
			{ok=util(graph,temp->data);
			if(ok==1)
				return 1;}
		}
		
		graph->visited[i]=0;
	}
	return 0;

	
}

void dfshelp(Graph graph, int* visited, char node[20]){
	int x;
	for(int i=0; i<graph->V; i++)
		if(strcmp(graph->adjLists[i]->data,node)==0)
		x=i;
		
	visited[x]=1;
	List aux=graph->adjLists[x];
	while(aux!=NULL){
		
		for(int i=0; i<graph->V; i++)
			if(strcmp(aux->data,graph->adjLists[i]->data)==0)
				x=i;
		if(visited[x]==0)
			dfshelp(graph,visited,aux->data);
		aux=aux->next;
	}
}

void dfs(Graph graph, char node[20], char node2[20], int vector[100]){
	int x;
	for(int i=0; i<graph->V; i++)
		if(strcmp(graph->adjLists[i]->data,node)==0)
		x=i;
	int y;
	for(int i=0; i<graph->V; i++)
		if(strcmp(graph->adjLists[i]->data,node2)==0)
		y=i;
	
	int nr=graph->V;
	 int *visited = malloc(nr*sizeof(int));
	//  if(visited==NULL)
	//  printf("da nma\n");  
	  for(int i=0; i<nr; i++)
	visited[i]=0;
	dfshelp(graph,visited,node);

	if(visited[y]==1)
		vector[x]=1;	
}

int main(int argc, char **argv){
	printf("%d\n",argc);
	FILE *file;
	FILE *file2;
file=fopen("test0.in","r");
file2=fopen("blockdag.out","w");
int n;
fscanf(file,"%d",&n);
Graph graph=initGraph(n);
char string[256];
int i=0;
for(i=0; i<n; i++){
	fscanf(file,"%s",string);
	graph->adjLists[i]=malloc(sizeof(List));
	strcpy(graph->adjLists[i]->data,string);
	graph->adjLists[i]->prev=NULL;
	graph->adjLists[i]->next=NULL;
	
}

char garbage[20];
char garbage2[20];
char line[256];
fscanf(file,"%s",garbage);
	fscanf(file, "%s", garbage2);
int aparitii[100];
for(int i=0; i<n; i++)
aparitii[i]=0;
for(i=1; i<n; i++){
	fscanf(file,"%s",garbage);
	fscanf(file, "%s", garbage2);
	fscanf(file,"%[^\n]%*c",line);
	int g=strlen(line);
	char gogu[256]="";
	strncpy(gogu,line,g);
	char *cuv=strtok(gogu," ");
	int x;
	for(int j=0; j<n; j++)
	if(strcmp(graph->adjLists[j]->data,garbage)==0)
	x=j;
	List temp=graph->adjLists[x];
	while(cuv!=NULL){
		for(int i=0; i<n; i++)
		if(strcmp(cuv,graph->adjLists[i]->data)==0)
			aparitii[i]++;
		temp->next=malloc(sizeof(List));
		strcpy(temp->next->data,cuv);
		temp->next->prev=temp;
		temp=temp->next;
		cuv=strtok(NULL, " ");
	}


}
i=0;
if(argc==2){
if(c1(graph)==1)
	fprintf(file2, "impossible\n");
else fprintf(file2, "correct\n");}
else if(strcmp(argv[1],"-c2")==0){

int sir[100];
for(int i=0; i<graph->V; i++)
	sir[i]=0;
for(int i=0; i<graph->V; i++)

	dfs(graph,graph->adjLists[i]->data,argv[2],sir);

int visited[100];
	 for(int i=0; i<n; i++)
	 	visited[i]=0;
char array2[100][100];
char aux[100];
fprintf(file2,"past(%s) : ",argv[2]);

int k=0;
dfshelp(graph,visited,argv[2]);
for(int i=0; i<graph->V; i++)
	if((visited[i]==1)&&(strcmp(argv[2],graph->adjLists[i]->data)!=0))
		{
		strcpy(array2[k],graph->adjLists[i]->data);
		k++;}

for(int i=0; i<k-1; i++)
	for(int j=i+1; j<k; j++)
	if(strcmp(array2[i],array2[j])>0){
		strcpy(aux,array2[i]);
		strcpy(array2[i],array2[j]);
		strcpy(array2[j],aux);
	}
fprintf(file2,"Genesis ");

for(int i=0; i<k; i++)
	if(strcmp(array2[i],"Genesis")!=0)
		fprintf(file2,"%s ",array2[i]);
	
fprintf(file2,"\n");


k=0;
char array[100][100];

for(int i=0; i<graph->V; i++)
	if((strcmp(argv[2],graph->adjLists[i]->data)!=0)&&(sir[i]==1))
		{
		strcpy(array[k],graph->adjLists[i]->data);
		k++;}

for(int i=0; i<k-1; i++)
	for(int j=i+1; j<k; j++)
	if(strcmp(array[i],array[j])>0){
		strcpy(aux,array[i]);
		strcpy(array[i],array[j]);
		strcpy(array[j],aux);
	}


fprintf(file2,"future(%s) : ",argv[2]);

for(int i=0; i<k; i++)
	fprintf(file2,"%s ",array[i]);
	
fprintf(file2,"\n");


k=0;
for(int i=0; i<graph->V; i++)
	if(visited[i]+sir[i]==0)
		{
		strcpy(array[k],graph->adjLists[i]->data);
		k++;}
//char aux[100];
for(int i=0; i<k-1; i++)
	for(int j=i+1; j<k; j++)
	if(strcmp(array[i],array[j])>0){
		strcpy(aux,array[i]);
		strcpy(array[i],array[j]);
		strcpy(array[j],aux);
	}
fprintf(file2,"anticone(%s) : ",argv[2]);

for(int i=0; i<k; i++)
	fprintf(file2,"%s ",array[i]);
fprintf(file2,"\n");
k=0;
for(int i=0; i<n; i++)
if(aparitii[i]==0)
{
		strcpy(array[k],graph->adjLists[i]->data);
		k++;}
for(int i=0; i<k-1; i++){
	for(int j=i+1; j<k; j++)
	if(strcmp(array[i],array[j])>0){
		strcpy(aux,array[i]);
		strcpy(array[i],array[j]);
		strcpy(array[j],aux);
	}}
	fprintf(file2,"tips(G) : ");
	for(int i=0; i<k; i++)
	fprintf(file2,"%s ",array[i]);
	
fprintf(file2,"\n");

}

}