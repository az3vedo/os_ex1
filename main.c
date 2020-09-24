#include<sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    // Declaração da variável pid do tipo pid_t(id do processo)
    pid_t pid;
    // Cria um processo filho dentro do processo de execução desse código
    pid = fork();

    //Verificando se o processo foi criado
    if(pid < 0){
        // Exibir uma mensagem de erro padrão para dizer que o processo filho não foi criado
        fprintf(stderr, "Fork Failed");
        /* Encerra a execução com código de saída 1 para informar
        o sistema operacional de que o programa foi encerrado de maneira inesperada*/
        exit(-1);
    }
    /* Verifica qual processo está executando para pid == 0, é o
    processo filho que está executando*/
    else if (pid == 0){
        // Exibe na tela o id do processo filho
        execl("/bin/bash", "echo", getpid());

    }
    else {
        // Aguarda a execução do processo filho
        wait(NULL);
        // Exibe na tela o id do processo pai
        printf("Esse é o processo pai, PID: %d", getpid());
        /* Encerra a execução com código de saída 0 para informar
        o sistema operacional de que o programa foi encerrado corretamente*/
        exit(0);
    }
}
