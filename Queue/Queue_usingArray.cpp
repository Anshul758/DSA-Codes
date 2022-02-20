#include <bits/stdc++.h> 
// #include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
// using namespace __gnu_pbds;
// Policy based data structure 
// template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
#define ll long long int
#define pii pair<ll,ll>
#define rep(i,st,en) for(ll i=st;i<en;i++)
#define vi vector<ll>
#define vii vector<pii>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define eb emplace_back
#define yes cout<<"YES"<<endl; return;
#define no cout<<"NO"<<endl; return;
#define flus fflush(stdout);
#define gin(x) cerr<<#x<<" : "<<x<<" ";
#define fin cerr<<endl;
#define F first
#define S second
#define np next_permutation
#define inf 1e18
#define mod 1000000007
#define N 200009
#define PI 3.14159265358979323846
#define minpq priority_queue <ll, vector<ll>, greater<ll>>
#define maxpq priority_queue<ll> 
void sout(){
	cout<<endl;
}
template <typename T,typename... Types>
void sout(T var1,Types... var2){
	cout<<var1<<" ";
	sout(var2...);
}

class Queue {
public:
	int front, rear, size; 
	unsigned capacity;
	int* array;
};

Queue* createQueue(unsigned capacity) 
{
	Queue* queue = new Queue();
	queue->capacity = capacity;
	queue->front = 0;
	queue->rear = capacity - 1;
	queue->array = new int[(queue->capacity*sizeof(int))];

	return queue;
}

int isFull(Queue* queue) {
	return(queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
	return(queue->size == 0);
}

void enqueue(Queue* queue, int item) {
	if(isFull(queue))
		return;

	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;

	cout<< item <<" Item is enqueued to the queue"<<endl;
}

int dequeue(Queue* queue) {
	if(isEmpty(queue)) 
		return INT_MIN;

	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;

	return item;
}

int front(Queue* queue) {
	if(isEmpty(queue))
		return INT_MIN;

	return queue->array[queue->front];
}

int rear(Queue* queue) {
	if(isEmpty(queue))
		return INT_MIN;

	return queue->array[queue->rear];
}

void solve(){
	Queue* queue = createQueue(1000); 

    enqueue(queue, 10); 
    enqueue(queue, 20); 
    enqueue(queue, 30); 
    enqueue(queue, 40); 

    cout<<dequeue(queue)<<" dequeued from queue\n"; 

    cout << "Front item is " << front(queue) << endl; 
    cout << "Rear item is " << rear(queue) << endl; 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t t1=clock();
	int t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
	cerr<<"Time elapsed: "<<(double)(clock()-t1)/1000<<" s"<<endl;
}