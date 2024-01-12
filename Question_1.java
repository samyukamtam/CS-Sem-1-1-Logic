import java.util.*;
class Main{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        int n=sc.nextInt();
        sc.nextLine();
        String s[]=new String[n];
        int nt[]=new int[n];
        for(int i=0;i<n;i++)
        {
            s[i]=sc.nextLine();
            nt[i]=s[i].length()/2;
        }
        char rhs[]=new char[n];
        String lhs[]=new String[n];
        for(int i=0;i<n;i++)
        {
            rhs[i]=(s[i].charAt(s[i].length()-1));
            lhs[i]="";
            for(int j=0;j<s[i].length()-2;j+=2)
                lhs[i]=lhs[i]+(s[i].charAt(j));
        }
        for(int i=0;i<n;i++)
        {
            System.out.print("(");
            for(int j=0;j<nt[i];j++)
            {
                if(lhs[i].charAt(j)=='T'||lhs[i].charAt(j)=='F')
                        System.out.print(lhs[i].charAt(j));
                else
                {    
                    if(j==(nt[i]-1))
                        System.out.print("p"+lhs[i].charAt(j));
                    else
                        System.out.print("p"+lhs[i].charAt(j)+"^");
                }
            }
            if(rhs[i]=='T'||rhs[i]=='F')
                System.out.print(">"+rhs[i]);
            else
                System.out.print(">p"+rhs[i]);
            if(i==(n-1))
                System.out.print(")");
            else
                System.out.print(")^");
        }
        System.out.println();
        int k=0,l=0;
        char newc[]=new char[20];
        newc[0]='T';
        while(newc[k]!='F'&& k<10)
        {
            for(int i=0;i<n;i++)
            {
                String h="";
                int t=nt[i];
                for(int j=0;j<t;j++)
                {
                    if(lhs[i].charAt(j)==newc[k])
                    {
                        nt[i]-=1;
                        continue;
                    }
                    h=h+lhs[i].charAt(j);
                }
                lhs[i]=h;
                if(rhs[i]==newc[k])
                    rhs[i]='Q';
                if(nt[i]==0 && rhs[i]!='Q')
                {
                    newc[++l]=rhs[i];
                }
            }
            k++;
        }
        if(newc[k]=='F')
            System.out.println("Unsatisfiable");
        else
            System.out.print("Satisfiable");
    }
}
