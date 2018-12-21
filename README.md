# Medicao de Escalonadores em um sistema Linux
Medição de desempenho de uma carga de trabalho usando diferentes escalonadores no linux

## Execução na máquina
- Para executar visualizar a saída, via terminal, basta executar *gcc main_1.c -o main_1* e depois *./main nome_escalonador numero_de_processos*

## Obtenção do gráfico
- Primeiramente, basta executar *./run.sh* (pode ser necessário o comando *chmod +777 run.sh*)
    - Os resultados estarão em output_1/results.FIFO.10.out, por exemplo
    - O resultado pode demora alguns minutos
- Para gerar alguns gráficos, executasse o comando *./plot_results_SAMPLE.sh* e basta, no diretório /output_SAMPLE, abrir o arquivo *output.SAMPLE.plot.png*
	- Lembrando que para atender ao dado analisado, devesse alterar comandos no script citado acima
