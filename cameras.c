#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

struct Interval {
    double distance, radius;
};

struct Interval circles[10000];

void merge(struct Interval *v, int l, int m, int r){
	struct Interval *c=malloc(sizeof(struct Interval)*(r-l+1));
	int i=l,j=m+1,k=0;

	while(i<=m && j<=r){
	    if(v[i].distance <= v[j].distance)
		    c[k++]=v[i++];
    	else
    		c[k++]=v[j++];
  	}

  	while(i<=m)
    	c[k++]=v[i++];
  	while(j<=r)
      	c[k++]=v[j++];

  	k=0;
  	for(i=l;i<=r;i++)
    	v[i]=c[k++];
  	free(c);
}

void merge_sort(struct Interval *v, int l, int r){
	if(l>=r)return;
	int m = (l+r)/2;
	
	merge_sort(v, l, m);
	merge_sort(v, m+1, r);
	
	merge(v, l, m, r);
}

int main() {

    int num_cameras, length, width;
    while (scanf("%d %d %d", &num_cameras, &length, &width),
           num_cameras > 0) {
        for (size_t i = 0; i < num_cameras; ++i) {
            int position, radius;
            scanf("%d %d", &position, &radius);
            // Calculate this circle's effective interval [L, R].
            circles[i].distance = position - radius;
            circles[i].radius = position + radius;
        }
    
        merge_sort(circles, 0, num_cameras-1);

        size_t i = 0;
        int curL = 0, rReach = 0;
        int total_cameras = 0; 
        while (rReach < length) {
            int newCurL = curL;
            int farthest = -1;
            // Take the interval that covers as the biggest area.
            for (; i < num_cameras; ++i) {
                if (circles[i].distance > curL)
                    break;
                if (circles[i].radius >= newCurL) {
                    newCurL = circles[i].radius;
                    farthest = i;
                }
            }
            if (farthest == -1)
                break;
            ++total_cameras;
            rReach = curL = newCurL;
        }
        if (rReach < length)
            printf("Tera que comprar mais cameras.\n");
        else
            printf("%d\n", total_cameras);
    }
    return 0;
}

// URI - questão 1978
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=15&page=show_problem&problem=1323