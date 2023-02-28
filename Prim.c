typedef struct lst{
    double weight; // weight of edge
    int v;       //vertex number
    struct next;
}lst;

void Prim(int V, lst* adj_ar[V], lst* adj_ar_res[V]){
    int p[V], d[V], i, v1;
    lst* tmp;
    for(i=0;i<V;i++){
        p[i]=-1;
        d[i]=INF;
    }
    
    d[0]=0;
    tmp=adj_ar[0];
    while(tmp->next!=NULL){
        d[tmp->v]=tmp->weight;
        p[tmp->v]=0;
        tmp=tmp->next;
    }
    
    for(i=1;i<V;i++)
        if(p[i]==-1)
            push(i,d[i]);

    while(!is_empty()){
        v1=extract_min();
        
        lst* new=(lst*)malloc(sizeof(lst));
        new->v=v1;
        new->weight=d[v1];
        new->next=adj_ar_res[p[v1]]->next;
        adj_ar_res[p[v1]]->next=new;
        
        tmp=adj_ar[v1];
        while((tmp!=NULL)&&(d[tmp->v]>(tmp->weight))&&(in_queue(tmp->v))){
            d[tmp->v]=tmp->weight;
            p[tmp->v]=v1;
            tmp=tmp->next;
        }
        
        update();
    }
    return;
}