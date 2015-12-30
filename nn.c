#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define L1 10
#define L2 10
#define L3 10

#define log_e 2.718281828459

float sigmoid(float t);

void print_network(float (*layer)[]);
void feed_forward1(float (*weights)[], float inlayer[L1], float outlayer[L2]);

int main(int argc, char *argv[]) {


	float r = 0.0;

	float layer1[L1]  = {0.1,0.0,0.3,0.0,0.4,0.0,0.3,0.0,0.2,0.0};
	float layer2[L2];
	float layer3[L3];

	int w1 = L1 * L2;
	int w2 = L2 * L3;

	float weights1[L1][L2];
	float weights2[L2][L3];

    int i = 0;
    int j = 0;

	srand(getpid());

	/* populate first layer of weights */
	for(i=0; i<L1; i++) {
		for(j=0; j<L2; j++) {
			weights1[i][j] = sigmoid((float)rand()/(float)(RAND_MAX * 1.0));

	//		printf("weights1[%d][%d] = %f\n",i,j,weights1[i][j]);
		}
	}


	/* populate second layer of weights */
	for(i=0; i<L2; i++) {
		for(j=0; j<L3; j++) {
			weights2[i][j] = sigmoid((float)rand()/(float)(RAND_MAX * 1.0));

		//	printf("weights2[%d][%d] = %f\n",i,j,weights2[i][j]);
		}
	}



	print_network(weights1);
	print_network(weights2);

	feed_forward1(weights1, layer1, layer2);
	feed_forward1(weights2, layer2, layer3);


    for(i=0; i< 10; i++ ) {
        printf("layer1[%d] = %f\n",i,layer1[i]);
    }

    for(i=0; i< 10; i++ ) {
        printf("layer2[%d] = %f\n",i,layer2[i]);
    }

    for(i=0; i<10; i++) {
        printf("layer3[%d] = %f\n",i,layer3[i]);
    }
}


float sigmoid(float t) {

	float x;
	x = 1 / ( 1 + pow(log_e, (-1 * t) ) );
	return x;

}

void print_network(float (*layer)[]) {
    int i = 0;
    int j = 0;

	for(i=0;i<L1;i++) {
		for(j=0;j<L2;j++) {
			printf("weights1 ffd[%d][%d]: %f\n",i,j,(*layer+i)[j]);
		}
	}
}

void feed_forward1(float (*weights)[], float inlayer[L1], float outlayer[L2]) {

    int i = 0;
    int j = 0;

	float output[10]; // keep in case want to do further operations on in future
	float node_sum = 0.0;


// feed forward from one layer to the next
	for(i=0;i<10;i++) {
		for(j=0; j<10;j++) {
			node_sum += ((*weights+i)[j] * inlayer[i]);
		}
		output[i] = sigmoid(node_sum);
        outlayer[i] = output[i];
		node_sum = 0.0;
	}



// if want to print output.
//	for(int i=0;i<10;i++) {
//		printf("output[%d]: %f\n",i,output[i]);
//	}

}
