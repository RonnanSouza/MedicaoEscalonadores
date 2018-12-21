library("ggplot2")

args = commandArgs(trailingOnly=TRUE)
data = read.csv(args[1], header = TRUE)

summary(data)

p <- ggplot(data, aes(x=Tempo_Inicial_Final, y=Numero_Processo, color=Id_Processo))
p <- p + geom_line() 
ggsave(p, file=paste(args[1], "png", sep="."))
