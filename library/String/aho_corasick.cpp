struct node{
     node *f, *p, *l; //funcao de fail, primeiro filho, irmao
     int o; //marca se há uma string acabando
     char c; //letra
     void reset(){
	p=l=NULL;
	o=0;
     }
     node* son( char c ){ //retorna filho 'c'
	node* it;
	for( it=p ; it!=NULL ; it=it->l ){
		if( it->c==c ){
			return it;	
		}	
	}
	return NULL;
     }
     void add( char c, node* it ){ //adiciona filho
	it->c=c;
	it->l=p;
	p=it;
     }
};

struct word{
	int ini, len;
};

node data[MAXD], *tree;
int d_cnt, n;
char s[MAXD+MAXN];
word v[MAXN];
queue<node*> q;
int dist[MAXN];

node* new_node(){
	data[d_cnt].reset();
	return &data[d_cnt++];
}

void free_all(){
	d_cnt=0;	
}

bool comp( word a, word b ){
	return (a.len<b.len);	
}

//problema growing strings do spoj br
int main(){
     int i, j, k, resp;
     char c;
     node *p, *it, *jt, *kt;
     while( scanf("%d",&n)>0 && n>0 ){
	k=0;
	for( i=1 ; i<=n ; i++ ){ //le n strings
		scanf("%s",s+k);
		v[i].ini=k;
		v[i].len=strlen(s+k);
		k+=v[i].len+1;
	}
	free_all();
	tree=new_node();
	sort(v+1,v+1+n,comp);
	for( i=1 ; i<=n ; i++ ){ //monta arvore
		p=tree;
		for( j=v[i].ini ; (c=s[j])!='\0' ; j++ ){
			it=p->son(c);
			if( it==NULL ){
				p->add(c,it=new_node());
			}
			p=it;
		}
		p->o=i;
	}
	while( !q.empty() ){
		q.pop();	
	}
	it=tree->p;
	for( it=tree->p ; it!=NULL ; it=it->l ){
		q.push(it);
		it->f=tree;
	}
	while( !q.empty() ){ //calcula os fail
	     p=q.front();
	     q.pop();
	     for( it=p->p ; it!=NULL ; it=it->l ){
	          q.push(it);
	          for( jt=p->f ; (kt=jt->son(it-c))==NULL ; jt=jt->f ){
		if( jt==tree ){
			kt=tree;
			break;	
		}
	          }
	          it->f=kt;
	          if( it->o==0 ){
		it->o=kt->o;	
	          }
	     }
	}	
	resp=0;
	for( i=1 ; i<=n ; i++ ){ //problema growing strings
	     dist[i]=1;
	     p=tree;
	     for( j=v[i].ini ; (c=s[j])!='\0' ; j++ ){
		p=p->son(c);
		if( p->o!=0 && p->o!=i ){ 
			//achou string p->o
			dist[i]=max(dist[i],dist[p->o]+1);	
		}
	     }
	     p=p->f; //da fail pra nao achar propria string
	     if( p->o!=0 ){ //achou p->o na ultima letra
		dist[i]=max(dist[i],dist[p->o]+1);	
	     }
	     resp=max(dist[i],resp);	
	}
	printf("%d\n",resp);	
     }
     return 0;	
}
