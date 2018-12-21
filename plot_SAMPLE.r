library("ggplot2")

args = commandArgs(trailingOnly=TRUE)
data = read.csv(args[1], header = TRUE)

summary(data)

p <- ggplot(data, aes(x=Replicação, y=Tempo, color=Algoritmo))
p <- p + geom_line() + coord_trans(y="log10")
ggsave(p, file=paste(args[1], "png", sep="."))
