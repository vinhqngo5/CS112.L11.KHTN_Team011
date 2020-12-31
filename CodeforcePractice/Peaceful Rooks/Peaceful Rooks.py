import sys
input=sys.stdin.readline
for _ in range(int(input())):
	n,m=map(int,input().split())
	ans=m
	g=[0 for i in range(n+1)]
	l=0
	for i in range(m):
		x,y=map(int,input().split())
		if x==y:
			l+=1
			continue
		g[x]=y
	ans-=l
	for i in range(1,n+1):
		if g[i]>0:
			t=i
			while g[i]>0:
				x=g[i]
				g[i]=0
				i=x
				if i==t:
					ans+=1
					break
	print(ans)