def improve(x,y,z,p):
    itcm=(4*x+4*p*y+5*z)/(1+4*x+4*p*y+5*z)
    nop=(2*x+2*p*y+2*z)/(1+2*x+2*p*y+2*z)
    cycle=(1*x+2*p*y+2*z)/(1+1*x+2*p*y+2*z)
    return (itcm, nop, cycle)

x=0.1
y=0.13
z=0.1
p=0.25

(i,n,c)=improve(x,y,z,p)

print(i*100, n*100, c*100)