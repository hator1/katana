#include<stdio.h>
#include<stdio.h>
struct alumno{
	int matricula;
	char nombre[10];
	char carrera[12];
	float promedio;
};

struct alumno alus[30];

int i,cont;


void llena();
void imprime();
void ordenar();

void main(){
	
	printf("..::: Registro de Alumnos :::..");
	printf("\n");
	printf("\n");
	FILE *archivo;
	FILE *reprobados;
	FILE *ordenado;
	reprobados = fopen("reprobados.txt","a+");
	archivo = fopen("datos.dat","a+");
	ordenado = fopen("ordenado-texto.txt","a+");
	if(archivo || reprobados != NULL)
		llena(archivo,reprobados);
	else
		printf("\nEl archivo no se puede crerar. . .\n");


	fclose(archivo);
	fclose(reprobados);

	imprime();
	ordenar(ordenado);

	fclose(ordenado);
}

void llena(FILE *archivo, FILE *reprobados){

	int r;
	float *rep;
	rep = &alus[i].promedio;
	printf("Desea ingresar un registro de alumno?\n\n");
	printf("..::: Si 1 <=======> No 0:::...\n\n");
	scanf("%d",&r);

	while(r){
		printf("Ingrese la matricula del alumno\n");
		scanf("%d",&alus[i].matricula);
		fflush(stdin);
		
		printf("Escribe el nombre del alumno %d:\n",i+1);
		scanf("%s",alus[i].nombre);
		fflush(stdin);

		printf("Escribe la carrera:\n");
		scanf("%s",alus[i].carrera);
		fflush(stdin);
		
		printf("Ingrese el promedio del alumno\n");
		scanf("%f",&alus[i].promedio);
		
		fwrite(&alus[i],sizeof(struct alumno),1,archivo);
		
		if(alus[i].promedio < 5.9){
			fprintf(reprobados,"Matricula: %d Nombre: %s  Carrera: %s  Promedio: %.2f\n",alus[i].matricula,alus[i].nombre,alus[i].carrera,alus[i].promedio);
		}
		i++;
		
		printf("¿Desea agregar otro registro?\n");
		printf("..::: Si 1 <=======> No 0 :::..\n");
		scanf("%d",&r);
	}
	
}

void imprime(){

	printf("..:::: Leyendo archivo de datos creado . . .\n");
	printf(" # | Matricula  | Nombre  | Carrera | Promedio\n ");
	for(cont = 0; cont < i; cont++){
		printf(" %d.- %d   %s  ,  %s  ,  %.2f \n",cont+1,alus[cont].matricula,alus[cont].nombre,alus[cont].carrera,alus[cont].promedio);
	}
}


void ordenar(FILE *ordenado){
	
	int k,f,h;
	struct alumno aux,aux2;
	do{
		for(h = 0; h < i-1; h++){
			if(alus[h].matricula < alus[h+1].matricula){
			
			}else{
				aux = alus[h+1];
				aux2 = alus[h];
				alus[h] = aux;
				alus[h+1] = aux2;
			}
		
		}
		k++;
	}while(k < i);
	
	for(f = 0; f < i; f++){
	
		//printf("Nombre: %s"  "Carrera: %s"  "Promedio: %.2f\n",alus[f].nombre,alus[f].carrera,alus[f].promedio);
		fprintf(ordenado,"Matricula: %d Nombre: %s  Carrera: %s  Promedio: %.2f\n",alus[f].matricula,alus[f].nombre,alus[f].carrera,alus[f].promedio);
	}


}
