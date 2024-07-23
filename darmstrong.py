n=int(input("enter n value="))
sum=0
x=n
while n>0:
  rem=n%10
  sum=sum+rem**3
  n=n//10
if sum==x:
  print(x,"is armstrong number")
else:
  print(x,"is not armstrong number")
