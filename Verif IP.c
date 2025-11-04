// Verificador de conexão IP : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(65001); // Define a codificação UTF-8 para o console para uso de caracteres especiais
	const char* ip = "165.152.227.53"; //Especificar o IP que deseja verificar no local das aspas

	// Comando Bash para verificar se o IP esta ESTABILISHED
	char command[256]; // Buffer para armazenar o comando
	snprintf(command, sizeof(command), "netstat -an | findstr %s | findstr ESTABLISHED", ip); // Substitua por "grep" se estiver usando um ambiente Unix/Linux
	printf("Executando comando: \n");
	printf(" %s\n", command);
	// Executa o comando e verifica o resultado

	int result = system(command); // Executa o comando no sistema
	printf("\n");

	// Verifica o resultado do comando
	if (result == 0) {
		printf("O IP %s está ESTABLISHED.\n", ip);
	}
	else {
		printf("O IP %s NÃO está ESTABLISHED.\n", ip);
	}
	// Se o comando retornar 0, significa que o IP está ESTABLISHED caso contrário, não está.

	return 0;

}
