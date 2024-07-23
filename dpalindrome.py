n=int(input("enter the n value="))
rev=0
x=n
while n>0:
  rem=n%10
  rev=rev*10+rem
  n=n//10
if rev==x:
  print(x,"is palindrome")
else:
  print(x,"is not palindrome")
  
