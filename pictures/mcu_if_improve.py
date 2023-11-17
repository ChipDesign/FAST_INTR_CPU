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

# sbp improve
def cpi_sbp_total(load, branch, jal):
    base=5
    # origin=load*(1+base)+branch*(3+base)+jal*(3+base)+(1-load-branch-jal)*base 
    # current=load*(1+base)+branch*(2+base)+jal*(2+base)+(1-load-branch-jal)*base
    origin=load*(1+base)+branch*(2+base)+jal*(2+base)+(1-load-branch-jal)*base 
    current=load*(1+base)+branch*(0+base)+jal*(0+base)+(1-load-branch-jal)*base
    return (origin-current)/origin 


load=0.25
branch=0.11
jal=0.02

imp=cpi_sbp_total(load,branch,jal)

print("total improvement=", imp*100,"%")


