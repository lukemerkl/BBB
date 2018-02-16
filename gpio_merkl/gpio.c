#include<stdio.h>
#include<unistd.h>
#include<assert.h>

int on(int pinNum){
	FILE *afile = NULL;
	FILE *dir = NULL;
	char export_p[] = "/sys/class/gpio/export";
	char unexport[] = "/sys/class/gpio/unexport";

	char high[] = "high";
	char pnum[10] = "";
	snprintf(pnum, sizeof(pinNum), "%d", pinNum);
	char base_dest[150] = "/sys/class/gpio/gpio";
	char dest[100] = "";
	//printf("%s\n", base_dest);
	snprintf(dest, sizeof(dest), "%s%s/direction", base_dest,pnum);
	printf("%s\n", dest);
	//printf("%s\n", pnum);

	// returns correct destination!


	afile = fopen(export_p, "w");
	assert(afile);
	fwrite(pnum, 1, sizeof(pnum), afile);
	fclose(afile);

	// breaks here. maybe dest isn't actually a string?
	dir = fopen(dest, "w");
	assert(dir);
	fwrite(high, 1, sizeof(high), dir);
	fclose(dir);

	afile = fopen(unexport, "w");
	assert(afile);
	fwrite("low", 1, sizeof("low"), afile);
	

return 0;
}

int off(pinNum){
	FILE *afile = NULL;
	FILE *dir = NULL;
	char export_p[] = "/sys/class/gpio/export";
	char unexport[] = "/sys/class/gpio/unexport";

	char pnum[10] = "";
	snprintf(pnum, sizeof(pinNum), "%d", pinNum);
	char base_dest[150] = "/sys/class/gpio/gpio";
	char dest[100] = "";
	//printf("%s\n", base_dest);
	snprintf(dest, sizeof(dest), "%s%s/direction", base_dest,pnum);
	printf("%s\n", dest);
	//printf("%s\n", pnum);

	// returns correct destination!


	afile = fopen(export_p, "w");
	assert(afile);
	fwrite(pnum, 1, sizeof(pnum), afile);
	fclose(afile);

	// breaks here. maybe dest isn't actually a string?
	dir = fopen(dest, "w");
	assert(dir);
	fwrite("low", 1, sizeof("low"), dir);
	fclose(dir);

	afile = fopen(unexport, "w");
	assert(afile);
	fwrite("low", 1, sizeof("low"), afile);


return 0;
}


main() {

int A = 23;
int C = 31;
int B = 0;

for (int i =0;i<5;i++) {
	B = on(A);
	sleep(1);
	off(A);
	sleep(1);
}
printf("SWITCHING COLORSSSSS\n");
for (int i =0;i<5;i++) {
	B = on(C);
	sleep(1);
	off(C);
	sleep(1);
}


return 0;
}
