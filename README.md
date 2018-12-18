# Medicao de Escalonadores em um sistema Linux
Medição de desempenho de uma carga de trabalho usando diferentes escalonadores no linux

## Execução na máquina
- Para executar visualizar a saída, via terminal, basta executar *gcc main.c -o main* e depois *./main nome_escalonador*

## Obtenção do gráfico
- Primeiramente, basta executar *./run.sh* (pode ser necessário o comando *chmod +777 run.sh*)
    - Os resultados estarão em output/results.FIFO.out, por exemplo
    - O resultado pode demora alguns minutos
- Para obter o gráfico, executasse o comando *./plot_results.sh* e basta, no diretório /output, abrir o arquivo *output.mem.plot.png*
