sum=0
i=0
n=4
x=30
print("Hello")
for i in range(1,x+1):
    sum+=n**i
    print(sum,"\t",(float((sum-n**i)/sum)))
    
