struct tklijent{
	char imeprez[50];
	int godr;
	int stanjer;
	char vrstT;
};

struct tred{
	tklijent e[10000];
	int f,r;
};

typedef struct tred Queue;
typedef struct tklijent element;

tred* InitQ(tred *Q){
    Q = new tred;
	Q->f = 0;
	Q->r = 9999;
	return Q;
}

int AddOne(int n) {
	return ((n+1)%10000);
}

element FrontQ(tred *Q){
    return Q->e[Q->f];    
}

void EnQueueQ(element x, tred *Q){
    Q->r=AddOne(Q->r);
    Q->e[Q->r] = x;
}

void DeQueueQ(tred *Q){
	  Q->f=AddOne(Q->f);
}

bool IsEmptyQ(tred *Q){
	if(AddOne(Q->r)==Q->f)
		return true;
	return false;
}
