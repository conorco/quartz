tab$espece=as.factor(tab$espece)
tab$regime=as.factor(tab$regime)
tab$wingl=as.factor(tab$wingl)
tab$taill=as.factor(tab$taill)
tab$culml=as.factor(tab$culml)
tab$bilh=as.factor(tab$bilh)
tab$billw=as.factor(tab$billw)
tab$tarsl=as.factor(tab$tarsl)
tab$midtl=as.factor(tab$midtl)
tab$weig=as.factor(tab$weig)


data=read.table("anov.txt",header=T)
data$regime=as.factor(data$regime)
boxplot(data$rapport~data$regime)
mod1=aov(data$rapport~data$regime)

data2=read.table("anov2.txt",header=T)
data2$regime=as.factor(data2$regime)
boxplot(data2$rapport~data2$regime)
mod2=aov(data2$rapport2~data2$regime)

pass=read.table("passeriforme.txt",header=T)
pass$Ordre=as.factor(pass$Ordre)
