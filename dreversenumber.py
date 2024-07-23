n=int(input("enter n value="))
rev=0
while n>0:
  rem=n%10
  rev=rev*10+rem
  n=n//10
print("reversed number=",rev)
