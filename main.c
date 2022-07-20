void intercambiar(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void ordenar(int array[], int primero, int ultimo) {
	int fulcro = ultimo;
	int i_iz = primero;
	int i_der = fulcro - 1;

	if(primero >= ultimo) return;

	while(i_iz < i_der) {
		while(array[i_iz]  < array[fulcro] && i_iz < i_der) i_iz++;
		while(array[i_der] > array[fulcro] && i_iz < i_der) i_der--;
		intercambiar(array+i_iz, array+i_der);
	}

	intercambiar(array+i_iz, array+fulcro);
	fulcro = i_iz;
	
	ordenar(array, primero, fulcro - 1);
	ordenar(array, fulcro + 1, ultimo);
}

int main() {
	int array[] = {3, 5, 1, 2, 7, 1, 3, 2};
	
	for(size_t i=0; i<sizeof(array)/sizeof(array[0]); ++i) {
		printf("%d ", array[i]);
	}

	ordenar(array, 0, sizeof(array)/sizeof(array[0]) - 1);
	
	puts("\n\nORDENADO\n");
	
	for(size_t i=0; i<sizeof(array)/sizeof(array[0]); ++i) {
		printf("%d ", array[i]);
	}
}
